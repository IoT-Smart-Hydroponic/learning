# Remote Repositories

Remote repositories merupakan sebuah repositori Git yang disimpan pada sebuah server atau layanan hosting yang berfungsi untuk menyimpan dan berkolaborasi pada suatu proyek. Dengan menggunakan remote repositories, developer dapat berbagi kode, berkolaborasi dengan tim, dan mengelola versi proyek secara efisien. Contoh platform hosting remote repositories ada GitHub, GitLab, dan Bitbucket.

Pada penjelasan ini, kita akan membahas dan belajar perintah-perintah yang digunakan untuk mengelola code pada remote repositories. Secara umum, penggunaan perintah yang akan dibahas diikuti oleh sintaks yang sudah dijelaskan pada bagian sebelumnya.

- Basic Git Commands: [docs/version-control/basic-git-commands.md](basic-git-commands.md)
- Branching Concepts: [docs/version-control/branching-concepts.md](branching-concepts.md)

## Menambahkan Remote Repository

Jika kamu memiliki repository lokal dan ingin menghubungkannya dengan remote repository, kamu harus menambahkan URL remote repository tersebut agar dapat mengirim perubahan ke remote repository. Untuk melakukan hal tersebut, kamu dapat menggunakan perintah berikut:

```bash
git remote add origin <url_repository>
```

??? info "Nama Remote Repository"
    Biasanya `origin` adalah nama default untuk remote repository utama. Pada saat melakukan `clone`, Git secara otomatis menambahkan remote dengan nama `origin`.

??? info "Terhubung 2 Remote Repository"
    Kamu juga dapat menambahkan lebih dari satu remote repository pada repository lokal dengan memberikan nama yang berbeda pada setiap remote repository yang ditambahkan. Contoh:

    ```bash
    git remote add upstream <url_repository_upstream>
    ```

    Pada contoh di atas, `upstream` adalah nama remote repository tambahan.

Setelah menambahkan URL remote repository, kamu dapat mengecek remote repository yang sudah ditambahkan dengan perintah:

```bash
git remote -v
```

??? info
    Perintah di atas akan menampilkan daftar remote repository beserta URL-nya. Terdapat dua jenis URL yang ditampilkan, yaitu `fetch` (untuk mengambil perubahan dari remote repository) dan `push` (untuk mengirim perubahan ke remote repository).

## Bekerja dengan Remote Repository

1. **Clone Repository**

    Untuk menyalin (clone) repository dari remote server ke lokal, gunakan perintah:

    ```bash
    git clone <url_repository>
    ```

2. **Melakukan Push ke Remote Repository**

    Ketika kamu telah melakukan commit di repository lokal, kamu bisa mengirimkan perubahan tersebut ke remote repository dengan perintah:

    ```bash
    git push -u origin <nama_cabang>
    ```

    Saat kamu melakukan push ke remote repository pertama kali, kamu perlu mengatur upstream branch dengan menambahkan opsi `-u` pada perintah di atas. Setelah itu, pada push berikutnya kamu hanya perlu menggunakan perintah:
    
    ```bash
    git push origin <nama_cabang>
    ```

3. **Melakukan Pull dari Remote Repository**

    Untuk mengambil perubahan terbaru dari remote repository dan menggabungkannya ke repository lokal, gunakan perintah:

    ```bash
    git pull origin <nama_cabang>
    ```

    ??? Warning "Konflik Merge"
        Saat melakukan `pull`, terkadang dapat terjadi konflik merge jika ada perubahan yang bertentangan antara repository lokal dan remote. Jika hal ini terjadi, kamu perlu menyelesaikan konflik tersebut secara manual sebelum melanjutkan proses merge.

4. **Melakukan sinkronisasi dengan Remote Repository**

    Untuk memastikan repository lokal selalu up-to-date dengan remote repository, disarankan untuk sering melakukan `pull` sebelum memulai pekerjaan baru. Hal ini dapat membantu mengurangi kemungkinan terjadinya konflik saat melakukan `push` nanti.

## Menghapus Remote Repository

Jika kamu ingin menghapus remote repository yang sudah ditambahkan, kamu dapat menggunakan perintah berikut:

```bash
git remote remove <nama_remote>
```

## Perbedaan antara `git fetch` dan `git pull`

Terdapat dua perintah yang sering digunakan untuk mengambil perubahan dari remote repository, yaitu `git fetch` dan `git pull`. Berikut adalah perbedaan antara keduanya:

- `git fetch`: Perintah ini digunakan untuk mengambil perubahan terbaru dari remote repository tanpa menggabungkannya ke branch lokal. Setelah melakukan `fetch`, kamu perlu melakukan merge secara manual untuk menggabungkan perubahan tersebut ke branch lokal.
- `git pull`: Perintah ini digunakan untuk mengambil perubahan terbaru dari remote repository dan langsung menggabungkannya ke branch lokal. `git pull` pada dasarnya merupakan kombinasi dari `git fetch` diikuti dengan `git merge`.
