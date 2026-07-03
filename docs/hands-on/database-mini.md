# Database Mini

Di modul ini kamu akan membuat tabel kecil untuk menyimpan data sensor.

Targetnya sederhana: data yang tadinya hanya lewat API bisa disimpan dan dilihat lagi.

## Yang Akan Kamu Buat

Satu tabel:

```text
sensor_readings
```

Isinya:

```text
id
device_id
sensor_type
value
created_at
```

## Buat Tabel

Masuk ke PostgreSQL, lalu jalankan:

```sql
CREATE TABLE sensor_readings (
    id SERIAL PRIMARY KEY,
    device_id TEXT NOT NULL,
    sensor_type TEXT NOT NULL,
    value DOUBLE PRECISION NOT NULL,
    created_at TIMESTAMPTZ DEFAULT now()
);
```

## Quick Win

Masukkan satu data:

```sql
INSERT INTO sensor_readings (device_id, sensor_type, value)
VALUES ('esp32-01', 'temperature', 28.5);
```

Lalu baca:

```sql
SELECT * FROM sensor_readings;
```

Kalau muncul satu baris data, kamu sudah punya database sensor mini.

## Coba Ubah Sedikit

Masukkan data kedua:

```sql
INSERT INTO sensor_readings (device_id, sensor_type, value)
VALUES ('esp32-01', 'ph', 6.2);
```

Lalu cari hanya data `ph`:

```sql
SELECT * FROM sensor_readings
WHERE sensor_type = 'ph';
```

## Pertanyaan Kecil

Kenapa data sensor perlu punya `created_at`?

Karena data sensor tanpa waktu itu seperti foto tanpa tanggal. Kita tahu nilainya, tapi tidak tahu kapan terjadi.

## Menemukan Pola

Kamu baru saja membuat tabel sensor sederhana.

Sekarang buka repo AIoT nyata. Smart Hydroponic bisa dipakai sebagai contoh pertama:

```text
backend/models/
backend/migrations/
backend/config/
```

Coba cari pola:

- File mana yang menggambarkan tabel?
- Folder mana yang menyimpan riwayat perubahan tabel?
- File mana yang mengatur koneksi database?

Di proyek asli, tabel tidak dibuat manual terus-menerus. Perubahannya dicatat agar bisa dijalankan ulang oleh tim.
