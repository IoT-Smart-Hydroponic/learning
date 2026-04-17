# Docker and Container Basics

## Apa itu Container?

Container adalah paket aplikasi yang berisi:

- Kode aplikasi.
- Runtime dan dependency.
- Konfigurasi yang dibutuhkan aplikasi.

Dengan container, aplikasi bisa berjalan lebih konsisten di laptop, server, atau cloud.

## Apa itu Docker?

Docker adalah platform untuk membuat, menjalankan, dan mengelola container.

Komponen utama yang sering dipakai:

- Dockerfile: resep untuk membangun image aplikasi.
- Image: template hasil build.
- Container: instance yang berjalan dari image.
- Docker Compose: menjalankan banyak service sekaligus.

## Bedanya Docker dan Container

| Istilah | Arti singkat |
| --- | --- |
| Container | Konsep/teknologi untuk membungkus aplikasi + dependency agar portable. |
| Docker | Tools/platform untuk build dan mengelola container. |

## Command Docker yang sering dipakai

| Kebutuhan | Command |
| --- | --- |
| Cek versi Docker | `docker --version` |
| Lihat image lokal | `docker images` |
| Build image | `docker build -t myapp:latest .` |
| Jalankan container | `docker run -d -p 8000:8000 --name myapp myapp:latest` |
| Lihat container berjalan | `docker ps` |
| Lihat semua container | `docker ps -a` |
| Lihat log container | `docker logs -f myapp` |
| Masuk ke shell container | `docker exec -it myapp sh` |
| Stop container | `docker stop myapp` |
| Hapus container | `docker rm myapp` |
| Hapus image | `docker rmi myapp:latest` |

## Command Docker Compose yang sering dipakai

| Kebutuhan | Command |
| --- | --- |
| Jalankan semua service | `docker compose up -d` |
| Lihat status service | `docker compose ps` |
| Lihat log service | `docker compose logs -f` |
| Rebuild dan jalankan ulang | `docker compose up -d --build` |
| Hentikan semua service | `docker compose down` |

## Kenapa relevan untuk AIoT?

- Environment tim jadi seragam.
- Setup backend, database, dan dashboard lebih cepat.
- Lebih mudah dipindah dari development ke production.

## Ringkasannya

- Container memudahkan portabilitas aplikasi.
- Docker memudahkan manajemen container.
- Mulai dari command dasar di atas sebelum masuk ke deployment multi-service yang lebih kompleks.
