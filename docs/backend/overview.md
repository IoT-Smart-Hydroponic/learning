# Backend Development

Halaman backend berisi jalur belajar terkait pengembangan layanan API untuk sistem AIoT, mulai dari fundamental hingga integrasi lanjutan.

## Gambaran Topik

- Dasar API dengan FastAPI
- Validasi request dan response
- Error handling dan HTTP status code
- Integrasi backend dengan database dan AI service

## Prasyarat

- Python 3.14+ terpasang
- Dasar terminal dan virtual environment
- Paham konsep JSON dasar

## Capaian Belajar

- Menjalankan server FastAPI secara lokal
- Membuat endpoint GET dan POST
- Melakukan validasi input sederhana dengan Pydantic
- Menangani error dasar dan status code HTTP

## Cakupan Fundamental

- Python relevan backend (typing, async dasar)
- FastAPI routing, validation, error handling
- HTTP dan status code

## Format Materi di Halaman Ini

Halaman fundamental ini bukan hanya plan. Struktur materi di bawah berisi:

- Ringkasan konsep inti
- Langkah praktik (hands-on) yang bisa langsung dijalankan
- Error umum dan cara debug
- Checklist hasil akhir

## Materi Inti

### 1. Setup Project FastAPI

- Buat virtual environment
- Install fastapi dan uvicorn
- Jalankan server dengan perintah `uvicorn main:app --reload`

### 2. Endpoint Dasar

- GET /health untuk health check
- POST /sensor untuk menerima data sensor (`device_id`, `value`, `timestamp`)
- Kembalikan response JSON yang konsisten

### 3. Validasi dan Error Handling

- Gunakan model Pydantic untuk validasi payload
- Pahami error 422 Unprocessable Entity
- Gunakan status code sesuai kebutuhan (200, 201, 400, 500)

### 4. Uji API

- Coba endpoint melalui browser, curl, atau Postman
- Verifikasi response body dan status code

## Hands-on

1. Buat file `main.py` dan inisialisasi FastAPI.
2. Tambahkan endpoint GET /health.
3. Tambahkan model payload sensor dengan Pydantic.
4. Tambahkan endpoint POST /sensor.
5. Uji beberapa skenario: payload benar, field kurang, tipe data salah.

## Error Umum dan Debug

- Port dipakai proses lain: jalankan di port lain, contoh `--port 8001`
- ModuleNotFoundError: aktifkan virtual environment sebelum menjalankan app
- Request gagal validasi: cek nama field dan tipe data payload

## Checklist Selesai

- API berjalan stabil di lokal
- Endpoint health check merespons dengan benar
- Endpoint sensor menerima payload valid
- Memahami beda error client (4xx) dan server (5xx)

## Daftar Halaman (Path)

- [Overview](overview.md)
- [Fundamental](fundamental.md)


[Kembali ke Home](../index.md)
