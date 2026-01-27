# Branching Concepts

Percabangan pada Git berfungsi untuk mengelola berbagai versi dari sebuah proyek secara bersamaan. Dengan menggunakan cabang (branch), developer dapat mengerjakan fitur baru, memperbaiki bug, atau bereksperimen tanpa mengganggu kode utama (main/master).

## Membuat Cabang Baru

Untuk membuat cabang baru, gunakan perintah:

```bash
git branch <nama_cabang>
```

## Berpindah Antar Cabang

Untuk berpindah ke cabang yang sudah ada, gunakan perintah:

```bash
git checkout <nama_cabang>
```

Kamu juga bisa membuat dan langsung berpindah ke cabang baru dengan perintah:

```bash
git checkout -b <nama_cabang>
```

## Menggabungkan Cabang (Merging)

Setelah selesai mengerjakan fitur pada cabang baru, kamu mungkin ingin menggabungkan perubahan tersebut ke cabang utama. Untuk menggabungkan cabang, pertama-tama pindah ke cabang utama (main/master) dengan perintah:

```bash
git checkout main
```

Kemudian, gunakan perintah merge untuk menggabungkan cabang:

```bash
git merge <nama_cabang>
```

## Menghapus Cabang

Setelah cabang tidak lagi diperlukan, kamu bisa menghapusnya dengan perintah:

```bash
git branch -d <nama_cabang>
```
