# Backend Mini

Di modul ini kamu akan membuat API kecil.

Targetnya bukan menjadi ahli backend. Targetnya: kamu melihat endpoint hidup dan bisa mengirim data sensor sederhana.

## Yang Akan Kamu Buat

Kamu akan membuat dua endpoint:

```text
GET /health
POST /sensors
```

`/health` dipakai untuk mengecek apakah server hidup.

`/sensors` dipakai untuk menerima data sensor dummy.

## Siapkan File

Buat file:

```text
mini_backend/main.py
```

Isi dengan kode ini:

```python
from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()


class SensorIn(BaseModel):
    device_id: str
    sensor_type: str
    value: float


@app.get("/health")
def health():
    return {"status": "ok"}


@app.post("/sensors")
def receive_sensor(data: SensorIn):
    return {
        "message": "Data sensor diterima",
        "data": data,
    }
```

## Jalankan

Dari folder yang berisi `mini_backend`, jalankan:

```bash
uv run --with fastapi fastapi dev mini_backend/main.py
```

Kalau server hidup, buka:

```text
http://127.0.0.1:8000/health
```

## Quick Win

Kamu harus melihat:

```json
{"status":"ok"}
```

Itu tanda API kecilmu sudah hidup.

## Kirim Data Sensor

Buka halaman docs otomatis FastAPI:

```text
http://127.0.0.1:8000/docs
```

Coba endpoint `POST /sensors` dengan contoh JSON:

```json
{
  "device_id": "esp32-01",
  "sensor_type": "temperature",
  "value": 28.5
}
```

## Coba Ubah Sedikit

Tambahkan field baru:

```python
unit: str
```

Lalu kirim data seperti:

```json
{
  "device_id": "esp32-01",
  "sensor_type": "temperature",
  "value": 28.5,
  "unit": "celsius"
}
```

Perhatikan: kalau JSON tidak sesuai, FastAPI akan memberi error. Itu bukan gagal. Itu validasi sedang bekerja.

## Menemukan Pola

Kamu baru saja membuat:

- `main.py`
- endpoint `/health`
- endpoint `/sensors`
- model input dengan Pydantic

Sekarang buka repo AIoT nyata. Smart Hydroponic bisa dipakai sebagai contoh pertama:

```text
backend/main.py
backend/routes/
backend/schemas/
```

Coba cari pola yang mirip:

- Di mana aplikasi FastAPI dibuat?
- Di mana endpoint dikelompokkan?
- Di mana bentuk data request dan response ditulis?

Kamu belum harus paham semuanya. Cukup temukan kemiripannya.
