# OOP Python untuk Backend

OOP adalah singkatan dari **Object-Oriented Programming**.

Di Python, OOP sering muncul dalam bentuk `class`. Kamu akan sering melihatnya saat membaca backend, terutama pada Pydantic, SQLAlchemy, service, dan konfigurasi aplikasi.

Tujuan halaman ini bukan membuatmu hafal semua istilah OOP. Tujuannya sederhana: kamu bisa membaca class tanpa merasa asing.

## Kenapa OOP Muncul di Backend?

Backend sering punya banyak bentuk data dan aturan.

Contoh:

- data sensor,
- data user,
- konfigurasi aplikasi,
- koneksi database,
- logic service.

Class membantu kita mengelompokkan data dan perilaku yang saling berkaitan.

## Contoh Paling Dasar: Class `Car`

Sebelum masuk ke backend, kita pakai contoh yang lebih dekat dulu: mobil.

Mobil bisa punya merek berbeda, tetapi karakteristiknya mirip.

Contoh karakteristik:

- merek,
- warna,
- jumlah pintu,
- kecepatan.

Dalam OOP, kita bisa membuat satu class `Car` sebagai cetakan umum.

```python
class Car:
    def __init__(self, brand, color, doors):
        self.brand = brand
        self.color = color
        self.doors = doors
        self.speed = 0

    def accelerate(self):
        self.speed += 10

    def brake(self):
        self.speed = max(0, self.speed - 10)


toyota = Car("Toyota", "white", 4)
honda = Car("Honda", "black", 4)
tesla = Car("Tesla", "red", 2)

toyota.accelerate()
honda.accelerate()
honda.accelerate()

print(toyota.brand, toyota.speed)
print(honda.brand, honda.speed)
print(tesla.brand, tesla.speed)
```

Pada contoh ini:

- `Car` adalah class,
- `toyota`, `honda`, dan `tesla` adalah object,
- semua object punya karakteristik yang sama,
- nilai tiap object bisa berbeda.

Itu ide utama OOP:

> satu cetakan, banyak object, masing-masing membawa datanya sendiri.

Pola ini nanti terasa mirip dengan data backend.

Misalnya satu class `SensorReading` bisa dipakai untuk banyak data sensor dari device berbeda.

## Class dan Object

**Class** adalah cetakan.

**Object** adalah hasil dari cetakan itu.

```python
class SensorReading:
    def __init__(self, device_id, sensor_type, value):
        self.device_id = device_id
        self.sensor_type = sensor_type
        self.value = value


reading = SensorReading("device-01", "temperature", 28.5)

print(reading.device_id)
print(reading.value)
```

Pada contoh di atas:

- `SensorReading` adalah class,
- `reading` adalah object,
- `device_id`, `sensor_type`, dan `value` adalah atribut.

## Method

Method adalah fungsi yang berada di dalam class.

```python
class SensorReading:
    def __init__(self, device_id, sensor_type, value):
        self.device_id = device_id
        self.sensor_type = sensor_type
        self.value = value

    def is_high_temperature(self):
        return self.sensor_type == "temperature" and self.value > 30


reading = SensorReading("device-01", "temperature", 32.1)

print(reading.is_high_temperature())
```

Method membantu object melakukan sesuatu dengan data yang ia punya.

## Apa Itu `self`?

`self` menunjuk ke object yang sedang dipakai.

Kalau kamu menulis:

```python
reading.value
```

Di dalam class, nilai itu diakses lewat:

```python
self.value
```

Untuk awal, cukup ingat:

> `self` berarti "object ini".

## OOP dalam Pydantic

Pydantic memakai class untuk mendefinisikan bentuk data.

```python
from pydantic import BaseModel


class SensorIn(BaseModel):
    device_id: str
    sensor_type: str
    value: float
```

Class ini bukan class biasa sepenuhnya. Ia mewarisi kemampuan dari `BaseModel`.

Karena itu Pydantic bisa:

- membaca field,
- mengecek tipe data,
- memberi error jika payload salah,
- mengubah data menjadi JSON.

## Inheritance

Inheritance berarti satu class mewarisi kemampuan dari class lain.

```python
class SensorIn(BaseModel):
    device_id: str
    sensor_type: str
    value: float
```

Pada contoh ini:

- `SensorIn` adalah class buatan kita,
- `BaseModel` adalah class dari Pydantic,
- `SensorIn` mendapatkan fitur validasi dari `BaseModel`.

Kamu tidak harus langsung membuat inheritance sendiri. Tetapi kamu perlu mengenali pola ini saat membaca kode.

## OOP dalam SQLAlchemy

SQLAlchemy sering memakai class untuk merepresentasikan tabel database.

Contoh sederhana:

```python
class SensorReading:
    __tablename__ = "sensor_readings"

    id = "kolom id"
    device_id = "kolom device_id"
    value = "kolom value"
```

Di proyek asli, bentuknya akan lebih panjang karena memakai tipe kolom SQLAlchemy.

Idenya tetap sama:

> satu class mewakili satu tabel atau konsep data.

## Kapan Perlu Membuat Class?

Untuk latihan kecil, fungsi biasa sering cukup.

Class mulai berguna ketika:

- data dan perilakunya sering dipakai bersama,
- kode mulai panjang,
- kamu ingin mengelompokkan logic,
- kamu membaca library yang memang berbasis class.

Jangan memaksakan semua hal menjadi class. Pakai class ketika ia membuat kode lebih mudah dibaca.

## Quick Check

Saat menemukan class di backend, tanyakan:

- class ini mewakili data apa?
- atributnya apa saja?
- method-nya melakukan apa?
- class ini mewarisi dari class lain atau tidak?
- class ini dipakai di file mana?

## Menemukan Pola

Buka backend proyek AIoT nyata.

Cari kata:

```text
class
BaseModel
Model
Service
```

Pilih satu class, lalu isi catatan ini:

```text
Nama class:
File:
Class ini mewakili:
Atribut penting:
Method penting:
Hal yang membuatku penasaran:
```

Kamu tidak harus langsung paham semua. Yang penting kamu mulai bisa mengenali bentuknya.

[Kembali ke Overview Backend](overview.md)
