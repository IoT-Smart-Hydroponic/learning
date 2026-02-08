# How to contribute

Untuk berkontribusi pada dokumentasi ini, diharapkan kamu memiliki pemahaman dasar tentang sistem kontrol versi (Git) dan platform GitHub. Berikut adalah langkah-langkah untuk memulai:

1. Fork repository ini ke akun GitHub kamu.

    ![alt text](./images/fork-button.png)

2. Clone repository hasil fork ke komputer lokal kamu.

    ```bash
    git clone https://github.com/username/repository.git
    ```

3. Buat branch baru untuk perubahan yang akan kamu lakukan.

    ```bash
    git checkout -b nama-branch-baru
    ```

4. Lakukan perubahan pada file dokumentasi sesuai kebutuhan.

5. Setelah selesai, commit perubahan tersebut dengan pesan yang jelas.

    ```bash
    git add .
    git commit -m "Deskripsi perubahan yang dilakukan"
    ```

    !!! warning "Perhatian"
        Pastikan mengikuti aturan conventional commit untuk menjaga konsistensi riwayat dan menjaga workflow CI/CD tetap berjalan lancar.

6. Push branch baru ke repository fork di GitHub.

    ```bash
    git push origin nama-branch-baru
    ```

7. Buka Pull Request (PR) dari branch baru di repository fork ke repository utama.
8. Tunggu hingga PR kamu ditinjau dan digabungkan oleh maintainer.
9. Setelah PR digabungkan, kamu bisa menghapus branch lokal dan remote yang sudah tidak diperlukan lagi.

    ```bash
    git branch -d nama-branch-baru
    git push origin --delete nama-branch-baru
    ```

10. Lakukan sinkronisasi repository fork dengan repository utama secara berkala untuk mendapatkan pembaruan terbaru.

    ```bash
    git remote add upstream <URL-repository-utama>
    git fetch upstream
    git checkout main
    git pull --rebase upstream main
    git push origin main
    ```

Ulangi langkah 3 hingga 10 untuk kontribusi selanjutnya.

Selamat! Kamu telah berhasil berkontribusi pada dokumentasi ini. Terima kasih atas partisipasimu! 🎉
