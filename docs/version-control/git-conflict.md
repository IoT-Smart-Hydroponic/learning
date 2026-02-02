# Konflik pada Git

Konflik pada Git terjadi ketika ada perubahan pada file yang sama dan di bagian yang sama oleh dua sumber yang berbeda, misalnya antara repository lokal dan remote, atau antara dua cabang yang berbeda. Konflik ini biasanya muncul saat melakukan operasi seperti `merge`, `rebase`, atau `pull`.

## Penyebab Konflik

Beberapa penyebab umum terjadinya konflik pada Git antara lain:

- Dua developer mengubah baris yang sama pada file yang sama di cabang yang berbeda.
- Melakukan `pull` dari remote repository yang memiliki perubahan yang bertentangan dengan perubahan lokal.
- Melakukan `merge` antara dua cabang yang memiliki perubahan yang bertentangan.

## Menyelesaikan Konflik

Saat terjadi konflik, Git akan menandai file yang bermasalah dan menghentikan proses `merge` atau `rebase` sehingga tidak perlu khawatir file asli akan rusak atau berantakan. Dalam penyelesaian konflik, kita dapat menggunakan fitur dari Visual Studio Code (VS Code) untuk membantu mengatasi konflik tersebut.

1. Buka file yang mengalami konflik di VS Code. Kamu akan melihat bagian-bagian yang ditandai dengan indikator konflik, seperti `<<<<<<<`, `=======`, dan `>>>>>>>`.

2. Pilih perubahan yang ingin dipertahankan. VS Code sudah menyediakan tombol-tombol seperti "Accept Current Change", "Accept Incoming Change", atau "Accept Both Changes" untuk memudahkan dalam memilih perubahan yang diinginkan.

3. Pastikan bagian yang dipilih sudah sesuai dengan yang diinginkan, lalu simpan file tersebut (biasanya ada tombol "Solve Conflict" di bawah editor).

4. Lakukan cara yang sama pada setiap file yang mengalami konflik.

5. Setelah semua konflik diselesaikan, tambahkan file yang sudah diperbaiki ke staging area dengan perintah:

   ```bash
   git add <nama_file>
   ```

6. Setelah semua file yang mengalami konflik sudah ditambahkan ke staging area, lanjutkan proses `merge` atau `rebase` dengan perintah:

   ```bash
    git commit
    ```

7. Lakukan sinkronisasi dengan remote repository jika diperlukan, dengan menggunakan perintah:

   ```bash
   git push origin <nama_cabang>
   ```

## Tips Menghindari Konflik

Mengalami konflik adalah hal yang umum dalam pengembangan perangkat lunak, tetapi ada beberapa cara untuk mengurangi kemungkinan terjadinya konflik:

- Sering melakukan `pull` dari remote repository ketika ingin melakukan perubahan untuk memastikan versi selalu up-to-date.
- Berkomunikasi dengan tim pengembang untuk menghindari perubahan besar pada file yang sama secara bersamaan.
- Membagi tugas pengembangan sehingga setiap developer bekerja pada bagian yang berbeda dari kode.
