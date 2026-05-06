# Database Fundamental

## Tujuan

Membekali peserta dengan pondasi database untuk menyimpan data sensor AIoT secara terstruktur menggunakan PostgreSQL.

## Prasyarat

- Dasar konsep tabel dan baris data
- PostgreSQL sudah terpasang dan berjalan
- Dasar SQL (SELECT sederhana)

## Capaian Belajar

- Membuat schema tabel sensor dasar
- Menjalankan query CRUD
- Menulis query ringkasan sederhana dengan GROUP BY
- Memahami indeks dasar untuk performa awal

## Materi Inti

### 1. Desain Tabel Sensor

- Struktur tabel contoh: `sensor_readings`
- Kolom minimal: `id`, `device_id`, `value`, `recorded_at`
- Pilih tipe data yang tepat (`text`, `numeric`, `timestamp`)

### 2. CRUD Dasar

- INSERT untuk menambah data
- SELECT untuk membaca data
- UPDATE untuk koreksi data
- DELETE untuk menghapus data uji

### 3. Query Ringkasan

- Hitung rata-rata nilai per device
- Gunakan GROUP BY device_id
- Tambahkan filter waktu sederhana

### 4. Indeks Dasar

- Buat indeks pada kolom yang sering dipakai filter
- Contoh: `device_id` dan `recorded_at`

## Hands-on

1. Buat database latihan untuk data sensor.
2. Buat tabel sensor_readings.
3. Masukkan minimal 20 data contoh.
4. Jalankan query CRUD dan query ringkasan.
5. Tambahkan indeks, lalu bandingkan performa query sederhana.

## Error Umum dan Debug

- Gagal koneksi: cek host, port, username, password, dan service PostgreSQL
- Tipe data tidak cocok: sesuaikan tipe kolom dengan nilai yang disimpan
- Query lambat: evaluasi filter dan cek apakah indeks sudah dipakai

## Checklist Selesai

- Tabel sensor berhasil dibuat
- Data contoh berhasil dimasukkan
- Query ringkasan berjalan benar
- Indeks dasar sudah diterapkan pada kolom penting

[Kembali ke Overview Database](overview.md)