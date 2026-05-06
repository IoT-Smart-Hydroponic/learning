# AI Fundamental

## Tujuan

Membekali peserta dengan pemahaman dasar AI berbasis data sensor: memilih use case, menyiapkan data, dan membuat baseline model atau rule sederhana.

## Prasyarat

- Dasar Python untuk data processing
- Dasar statistik sederhana (rata-rata, sebaran)
- Dataset sensor awal tersedia

## Capaian Belajar

- Menentukan use case AI awal yang relevan
- Menyiapkan data untuk eksperimen awal
- Membuat baseline sederhana (rule-based atau model ringan)
- Mengevaluasi hasil dengan metrik dasar

## Materi Inti

### 1. Pilih Use Case

- Pilih satu masalah yang jelas, contoh deteksi anomali sensor
- Tentukan input, output, dan dampak bisnis sederhana

### 2. Persiapan Data

- Cek missing value dan nilai tidak valid
- Lakukan normalisasi atau scaling jika diperlukan
- Bagi data untuk eksperimen dan evaluasi

### 3. Baseline AI

- Mulai dari baseline rule-based (threshold)
- Opsional: gunakan model ringan seperti Isolation Forest
- Simpan log hasil prediksi untuk analisis

### 4. Evaluasi Awal

- Gunakan metrik dasar: precision, recall, atau akurasi sesuai use case
- Catat false positive dan false negative
- Tentukan langkah perbaikan awal

## Hands-on

1. Siapkan dataset sensor dalam format CSV.
2. Lakukan pembersihan data minimum.
3. Buat baseline deteksi anomali sederhana.
4. Evaluasi hasil dan dokumentasikan metrik awal.
5. Ekspor hasil prediksi untuk ditampilkan di dashboard.

## Error Umum dan Debug

- Data terlalu sedikit: tambahkan data historis atau data simulasi
- Label tidak konsisten: definisikan kriteria anomali sejak awal
- Model tidak stabil: gunakan baseline rule-based terlebih dahulu

## Checklist Selesai

- Use case AI sudah dipilih dan didokumentasikan
- Dataset bersih siap eksperimen
- Baseline dapat dijalankan ulang
- Ada metrik awal dan catatan evaluasi

[Kembali ke Overview AI](overview.md)