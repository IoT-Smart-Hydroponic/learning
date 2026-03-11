import json
import os
from datetime import datetime
from http.server import BaseHTTPRequestHandler, HTTPServer

import psycopg2
from dotenv import load_dotenv

load_dotenv() # Memuat variabel lingkungan dari file .env

connection = psycopg2.connect(
    host="localhost",
    port=5432,
    database="mahasiswa_db",
    user="postgres",
    password=os.environ.get("password")
)

# Membuat tabel jika belum ada.
with connection.cursor() as cursor:
    cursor.execute("""
        CREATE TABLE IF NOT EXISTS data_sensor (
            id SERIAL PRIMARY KEY,
            waktu TIMESTAMP,
            jarak INTEGER,
            buzzer INTEGER
        )
    """)
connection.commit() # Commit untuk menyimpan perubahan ke database

class SimpleHTTPRequestHandler(BaseHTTPRequestHandler):
    # CORS headers untuk mengizinkan akses dari domain lain (misal: frontend di localhost:3000)
    def _set_cors_headers(self):
        self.send_header('Access-Control-Allow-Origin', '*')
        self.send_header('Access-Control-Allow-Methods', '*')
        self.send_header('Access-Control-Allow-Headers', 'Content-Type')

    # OPTIONS: Untuk menangani preflight request dari browser saat melakukan CORS
    def do_OPTIONS(self):
        self.send_response(204)
        self._set_cors_headers()
        self.end_headers()

    # ===== GET : tampilkan data =====
    def do_GET(self):
        if self.path == '/':
            self.send_response(200)
            self._set_cors_headers()
            self.send_header('Content-type', 'text/html')
            self.end_headers()
            html_content = """
                <html>
                    <head><title>Data Sensor</title></head>
                    <body>
                        <h1>Data Sensor</h1>
                        <p>Gunakan endpoint <code>/tampil-data</code> untuk melihat data sensor dalam format JSON.</p>
                    </body>
                </html>
            """
            self.wfile.write(html_content.encode('utf-8'))
        elif self.path == '/tampil-data':
            try:
                with connection.cursor() as cursor:
                    cursor.execute(
                        """
                        SELECT id, waktu, jarak, buzzer
                        FROM data_sensor
                        ORDER BY id DESC
                        """
                    )
                    rows = cursor.fetchall()

                payload = [
                    {
                        "id": row[0],
                        "waktu": row[1].strftime("%Y-%m-%d %H:%M:%S") if row[1] else None,
                        "jarak": row[2],
                        "buzzer": row[3],
                    }
                    for row in rows
                ]

                self.send_response(200)
                self._set_cors_headers()
                self.send_header('Content-type', 'application/json')
                self.end_headers()
                self.wfile.write(json.dumps(payload).encode('utf-8'))
            except Exception as e:
                print("Error GET:", e)
                self.send_response(500)
                self._set_cors_headers()
                self.send_header('Content-type', 'application/json')
                self.end_headers()
                self.wfile.write(b'{"status":"error","message":"Gagal mengambil data"}')
        else:
            self.send_error(404, "Endpoint tidak ditemukan. Gunakan /tampil-data")

    # ===== POST : menerima data dari ESP32 =====
    def do_POST(self):

        if self.path == '/data':

            content_length = int(self.headers['Content-Length'])
            post_data = self.rfile.read(content_length)

            try:
                data = json.loads(post_data.decode('utf-8'))

                # Mengambil data jarak dan buzzer dari payload JSON
                jarak = data.get('jarak')
                buzzer = data.get('buzzer')

                if jarak is None or buzzer is None:
                    self.send_response(400)
                    self._set_cors_headers()
                    self.send_header('Content-type', 'application/json')
                    self.end_headers()
                    self.wfile.write(b'{"status":"error","message":"Field jarak dan buzzer wajib diisi"}')
                    return

                jarak = int(jarak)
                buzzer = int(buzzer)

                # Mengambil waktu saat data diterima dan menyimpannya ke database
                waktu_obj = datetime.now()
                waktu = waktu_obj.strftime("%Y-%m-%d %H:%M:%S")

                with connection.cursor() as cursor:
                    cursor.execute(
                        "INSERT INTO data_sensor (waktu, jarak, buzzer) VALUES (%s, %s, %s)",
                        (waktu_obj, jarak, buzzer)
                    )
                connection.commit()

                print(f"[{waktu}] Jarak: {jarak} cm | Buzzer: {buzzer}")

                # Mengirim respons sukses ke ESP32
                self.send_response(200)
                self._set_cors_headers()
                self.send_header('Content-type', 'application/json')
                self.end_headers()

                self.wfile.write(b'{"status":"success"}')

            # Jika gagal maka rollback transaksi dan kirim respons error ke ESP32
            except Exception as e:
                connection.rollback()

                print("Error:", e)

                self.send_response(400)
                self._set_cors_headers()
                self.send_header('Content-type', 'application/json')
                self.end_headers()
                self.wfile.write(b'{"status":"error","message":"Data tidak valid atau gagal disimpan"}')

        else:
            self.send_error(404)


def run(server_class=HTTPServer, handler_class=SimpleHTTPRequestHandler, port=5001): # Ubah port jika tidak bisa digunakan

    server_address = ('', port)
    httpd = server_class(server_address, handler_class)

    print(f"Server HTTP berjalan di port {port}")
    print(f"Lihat data: http://localhost:{port}/tampil-data")
    print("Menunggu data dari ESP32...\n")

    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        print("\nServer dihentikan.")
    finally:
        connection.close()


if __name__ == '__main__':
    run()