# IoT Simulator Mini

Di modul ini kamu akan berpura-pura menjadi perangkat sensor.

Kita belum memakai ESP32 dulu. Kita mulai dari script Python kecil yang mengirim data dummy ke backend.

## Yang Akan Kamu Buat

Script yang mengirim data:

```text
device_id: esp32-01
sensor_type: temperature
value: angka dummy
```

## Buat Script

Buat file:

```text
mini_iot/send_sensor.py
```

Isi:

```python
import random
import urllib.request
import json

payload = {
    "device_id": "esp32-01",
    "sensor_type": "temperature",
    "value": round(random.uniform(25, 32), 2),
}

request = urllib.request.Request(
    "http://127.0.0.1:8000/sensors",
    data=json.dumps(payload).encode("utf-8"),
    headers={"Content-Type": "application/json"},
    method="POST",
)

with urllib.request.urlopen(request) as response:
    print(response.read().decode("utf-8"))
```

## Jalankan

Pastikan Backend Mini hidup, lalu jalankan:

```bash
uv run python mini_iot/send_sensor.py
```

## Quick Win

Kamu akan melihat response dari backend.

Setiap kali script dijalankan, nilai `value` bisa berubah.

Itulah ide dasar simulator: membuat data palsu yang terasa seperti data sensor.

## Coba Ubah Sedikit

Ubah `sensor_type`:

```python
"temperature"
```

menjadi:

```python
"ph"
```

Lalu ubah rentang random menjadi:

```python
random.uniform(5.5, 7.5)
```

Sekarang script kamu berpura-pura menjadi sensor pH.

## Menemukan Pola

Buka repo AIoT nyata. Smart Hydroponic bisa dipakai sebagai contoh pertama:

```text
backend/test/
esp/
```

Coba cari:

- Script mana yang mengirim data seperti perangkat?
- Folder mana yang berisi program ESP32 atau ESP8266?
- Apa bedanya simulator Python dengan firmware ESP?

Simulator ini bukan pengganti perangkat asli. Simulator adalah latihan agar kamu paham alurnya sebelum menyentuh hardware.
