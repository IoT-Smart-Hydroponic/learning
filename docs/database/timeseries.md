# Time-Series dan TimescaleDB

Time-series adalah data yang dicatat berdasarkan waktu.

Data sensor adalah contoh time-series karena nilainya berubah dari waktu ke waktu.

## Contoh Time-Series

```text
10:00 -> suhu 28.5
10:01 -> suhu 28.7
10:02 -> suhu 28.6
```

Yang penting bukan hanya nilainya, tetapi juga urutan waktunya.

## Kenapa PostgreSQL Saja Kadang Belum Cukup?

PostgreSQL kuat untuk banyak kebutuhan.

Namun data IoT bisa sangat banyak dan sering ditanya berdasarkan rentang waktu:

```text
tampilkan data 1 jam terakhir
tampilkan rata-rata per 5 menit
tampilkan device yang tidak kirim data hari ini
```

TimescaleDB adalah ekstensi PostgreSQL yang membantu menangani pola data time-series.

Dokumentasi resmi yang berguna:

- [Timescale Documentation](https://docs.timescale.com/)
- [Create hypertables](https://docs.timescale.com/use-timescale/latest/hypertables/)
- [TimescaleDB API: create_hypertable](https://docs.timescale.com/api/latest/hypertable/create_hypertable/)

## Hypertable

Di TimescaleDB, tabel time-series bisa diubah menjadi **hypertable**.

Secara sederhana, hypertable membantu database mengatur data berdasarkan waktu agar query lebih efisien.

```sql
SELECT create_hypertable('sensor_readings', 'recorded_at');
```

## Continuous Aggregate

Continuous aggregate membantu menyimpan ringkasan data secara berkala.

Misalnya dashboard hanya butuh rata-rata suhu per 5 menit, bukan semua data mentah.

```text
data mentah banyak -> ringkasan per 5 menit -> dashboard lebih ringan
```

## Kapan Perlu TimescaleDB?

Gunakan TimescaleDB ketika:

- data sensor masuk terus-menerus,
- query sering berdasarkan waktu,
- dashboard butuh ringkasan historis,
- data mulai terlalu besar untuk query biasa.

Untuk latihan awal, PostgreSQL biasa sudah cukup.

## Menemukan Pola

Saat melihat proyek AIoT nyata, cari apakah ada:

```text
hypertable
continuous aggregate
retention
compression
```

Kalau belum ada, tanyakan: apakah data proyek ini cukup besar untuk butuh time-series optimization?

[Kembali ke Overview Database](overview.md)
