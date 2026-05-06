# Frontend Fundamental

## Tujuan

Membekali peserta dengan dasar frontend untuk menampilkan data sensor dari backend secara jelas, responsif, dan mudah dipahami.

## Prasyarat

- Dasar HTML, CSS, dan JavaScript
- Memahami konsep request API sederhana
- Backend endpoint sudah dapat diakses

## Capaian Belajar

- Membuat halaman dashboard sederhana
- Mengambil data dari API dengan Fetch API
- Menampilkan state loading, sukses, dan error
- Memahami konsep komponen dasar Vue

## Materi Inti

### 1. Struktur Halaman Dasar

- Buat layout dashboard: header, ringkasan, tabel data
- Styling dasar agar data mudah dibaca

### 2. Ambil Data dari Backend

- Gunakan `fetch` untuk memanggil endpoint sensor
- Parse response JSON dan render ke tabel

### 3. State Dasar UI

- Loading: tampilkan indikator saat request berjalan
- Error: tampilkan pesan jika request gagal
- Empty state: tampilkan pesan jika data kosong

### 4. Pengenalan Vue Fundamental

- Konsep component sederhana
- Props dan event dasar
- Re-render data menggunakan state reaktif

## Hands-on

1. Buat dashboard HTML sederhana berisi tabel sensor.
2. Tambahkan script untuk memanggil endpoint backend.
3. Render daftar data ke dalam tabel.
4. Tambahkan tombol refresh manual.
5. Migrasikan tampilan dasar ke komponen Vue sederhana.

## Error Umum dan Debug

- CORS error: aktifkan CORS middleware di backend
- Data tidak muncul: cek URL endpoint dan format response JSON
- JavaScript error di browser: cek console dan perbaiki typo variabel

## Checklist Selesai

- Dashboard menampilkan data dari API
- Tersedia indikator loading dan error
- Tombol refresh bekerja
- Versi Vue dasar berjalan untuk komponen utama

[Kembali ke Overview Frontend](overview.md)