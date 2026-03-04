import json
import csv
import os
from datetime import datetime
from http.server import BaseHTTPRequestHandler, HTTPServer

FILE_NAME = "data_sensor_http.csv"

class SimpleHTTPRequestHandler(BaseHTTPRequestHandler):
    
    # METHOD GET: Untuk mengambil/menampilkan data di browser
    def do_GET(self):
        if self.path == '/tampil-data':
            self.send_response(200)
            self.send_header('Content-type', 'text/plain') # Mengirim sebagai teks mentah
            self.end_headers()
            
            if os.path.isfile(FILE_NAME):
                with open(FILE_NAME, mode='r') as f:
                    content = f.read()
                self.wfile.write(content.encode('utf-8'))
            else:
                self.wfile.write(b"Belum ada data sensor di file CSV.")
        else:
            self.send_error(404, "Endpoint tidak ditemukan. Gunakan /tampil")

    # METHOD POST: Untuk menerima data dari ESP32
    def do_POST(self):
        if self.path == '/data':
            content_length = int(self.headers['Content-Length'])
            post_data = self.rfile.read(content_length)
            
            try:
                data = json.loads(post_data.decode('utf-8'))
                suhu = data.get('suhu')
                kelembapan = data.get('kelembapan')
                waktu = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

                file_exists = os.path.isfile(FILE_NAME)
                with open(FILE_NAME, mode='a', newline='') as f:
                    writer = csv.writer(f)
                    if not file_exists:
                        writer.writerow(["Waktu", "Suhu", "Kelembapan"])
                    writer.writerow([waktu, suhu, kelembapan])

                print(f"[{waktu}] Berhasil Simpan: Suhu {suhu}, Lembap {kelembapan}")

                self.send_response(200)
                self.send_header('Content-type', 'application/json')
                self.end_headers()
                self.wfile.write(b'{"status":"success"}')

            except Exception as e:
                print(f"Error: {e}")
                self.send_response(400)
                self.end_headers()
        else:
            self.send_error(404)

def run(server_class=HTTPServer, handler_class=SimpleHTTPRequestHandler, port=5000):
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    print(f"Server HTTP berjalan di port {port}...")
    print(f"Akses http://localhost:{port}/tampil-data untuk melihat data CSV.")
    print("\n")
    httpd.serve_forever()

if __name__ == '__main__':
    run()