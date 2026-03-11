import json
import csv
import os
from datetime import datetime
from http.server import BaseHTTPRequestHandler, HTTPServer

FILE_NAME = "data_sensor_http.csv"

class SimpleHTTPRequestHandler(BaseHTTPRequestHandler):

    # ===== GET : Tampilkan data =====
    def do_GET(self):
        if self.path == '/tampil-data':
            self.send_response(200)
            self.send_header('Content-type', 'text/plain')
            self.end_headers()

            if os.path.isfile(FILE_NAME):
                with open(FILE_NAME, mode='r') as f:
                    content = f.read()
                self.wfile.write(content.encode('utf-8'))
            else:
                self.wfile.write(b"Belum ada data sensor di file CSV.")
        else:
            self.send_error(404, "Endpoint tidak ditemukan. Gunakan /tampil-data")

    # ===== POST : Menerima data JSON dari ESP32 =====
    def do_POST(self):
        if self.path == '/data':
            content_length = int(self.headers['Content-Length'])
            post_data = self.rfile.read(content_length)

            try:
                # Parse JSON yang dikirim ESP32
                data = json.loads(post_data.decode('utf-8'))

                # Ambil data sesuai format baru
                device_id = data.get('device_id', 'Unknown') # Menangkap device_id
                jarak = data.get('jarak')
                buzzer = data.get('buzzer')
                waktu = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

                file_exists = os.path.isfile(FILE_NAME)

                # Simpan ke CSV
                with open(FILE_NAME, mode='a', newline='') as f:
                    writer = csv.writer(f)
                    
                    # Tambahkan kolom Device ID di header jika file baru dibuat
                    if not file_exists:
                        writer.writerow(["Waktu", "Device ID", "Jarak (cm)", "Status Buzzer"])

                    writer.writerow([waktu, device_id, jarak, buzzer])

                # Log ke Console Server
                print(f"[{waktu}] ID: {device_id} | Jarak: {jarak} cm | Buzzer: {buzzer}")

                # Kirim respon balik ke ESP32
                self.send_response(200)
                self.send_header('Content-type', 'application/json')
                self.end_headers()
                self.wfile.write(b'{"status":"success"}')

            except Exception as e:
                print("Error parsing data:", e)
                self.send_response(400)
                self.end_headers()
                self.wfile.write(f'{{"status":"error", "message":"{str(e)}"}}'.encode())
        else:
            self.send_error(404)

def run(server_class=HTTPServer, handler_class=SimpleHTTPRequestHandler, port=5000): # Ubah port jika tidak bisa digunakan
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)

    print(f"Server HTTP berjalan di port {port}")
    print(f"Lihat data: http://localhost:{port}/tampil-data")
    print("Menunggu data dari ESP32...\n")

    httpd.serve_forever()

if __name__ == '__main__':
    run()