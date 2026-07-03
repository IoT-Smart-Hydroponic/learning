# Frontend Mini

Di modul ini kamu akan membuat dashboard kecil.

Targetnya: frontend bisa mengambil data dari API dan menampilkannya di layar.

## Yang Akan Kamu Buat

Satu halaman sederhana dengan:

- judul,
- tombol refresh,
- tabel data sensor,
- pesan loading atau error.

## Mulai Dari HTML Kecil

Buat file:

```text
mini_frontend/index.html
```

Isi:

```html
<!doctype html>
<html lang="id">
  <head>
    <meta charset="UTF-8" />
    <title>Dashboard Sensor Mini</title>
  </head>
  <body>
    <h1>Dashboard Sensor Mini</h1>
    <button id="refresh">Refresh</button>
    <pre id="output">Belum ada data.</pre>

    <script>
      const output = document.querySelector("#output");
      const button = document.querySelector("#refresh");

      async function loadHealth() {
        output.textContent = "Mengambil data...";

        try {
          const response = await fetch("http://127.0.0.1:8000/health");
          const data = await response.json();
          output.textContent = JSON.stringify(data, null, 2);
        } catch (error) {
          output.textContent = "Gagal mengambil data dari backend.";
        }
      }

      button.addEventListener("click", loadHealth);
    </script>
  </body>
</html>
```

## Quick Win

Jalankan Backend Mini, lalu buka file HTML ini di browser.

Klik tombol **Refresh**.

Kalau muncul:

```json
{
  "status": "ok"
}
```

berarti frontend kamu berhasil bicara dengan backend.

## Coba Ubah Sedikit

Ubah teks tombol:

```html
Refresh
```

menjadi:

```html
Cek Backend
```

Kecil, tapi penting. Kamu baru saja mengubah UI.

## Menuju Vue

Di proyek asli, dashboard tidak ditulis sebagai satu file HTML saja. Dashboard memakai Vue agar halaman dan komponen lebih rapi.

Tapi polanya tetap sama:

```text
tombol diklik -> frontend fetch API -> data tampil di layar
```

## Menemukan Pola

Buka repo AIoT nyata. Smart Hydroponic bisa dipakai sebagai contoh pertama:

```text
frontend-vue/src/views/
frontend-vue/src/components/
frontend-vue/src/api/
```

Coba cari:

- File mana yang terlihat seperti halaman dashboard?
- Folder mana yang berisi komponen yang dipakai ulang?
- Folder mana yang dipakai untuk memanggil backend?

Kamu baru saja membuat versi kecil dari pola itu.
