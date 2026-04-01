# Hands-On IoT

## Rangkaian Pemantau Suhu dan Kelembapan

Alat-alat:

- [ESP32](../iot/microcontrollers.md#esp32)
- [Sensor DHT11](../iot/sensors.md#sensor-dht11)
- [Buzzer](../iot/actuators.md#buzzer)

??? example "Kode program untuk ESP32"
    ```cpp
    --8<-- "code/ino/pemantau_suhu.ino"
    ```

## Rangkaian Kontrol Aktuator Dengan Relay

Alat-alat:

- [ESP32](../iot/microcontrollers.md#esp32)
- [Relay](../iot/actuators.md#relay)
- [Pompa DC](../iot/actuators.md#pompa-dc)

??? example "Kode program untuk ESP32"
    ```cpp
    --8<-- "code/ino/kontrol_aktuator_relay_pompa.ino"
    ```

## Rangkaian Kontrol Aktuator Pompa DC Dengan Relay

Alat-alat:

- [ESP32](../iot/microcontrollers.md#esp32)
- [Relay](../iot/actuators.md#relay)
- [Pompa DC](../iot/actuators.md#pompa-dc)
- [Moisture Sensor](../iot/sensors.md#soil-moisture-sensor)

??? example "Kode program untuk ESP32"
    ```cpp
    --8<-- "code/ino/aktuator_relay_pompa_moisture.ino"
    ```

## Rangkaian Sensor Ultrasonic dan Buzzer

Alat-alat:

- [ESP32](../iot/microcontrollers.md#esp32)
- [Sensor Ultrasonic](../iot/sensors.md#ultrasonic-sensor)
- [Buzzer](../iot/actuators.md#buzzer)

??? example "Kode program untuk ESP32"
    ```cpp
    --8<-- "code/ino/buzzer_ultrasonic.ino"
    ```

## Rangkaian Sensor Ultrasonic, Buzzer, dan Penyimpanan Data di Server

Alat-alat:

- [ESP32](../iot/microcontrollers.md#esp32)
- [Sensor Ultrasonic](../iot/sensors.md#ultrasonic-sensor)
- [Buzzer](../iot/actuators.md#buzzer)

??? example "Kode program untuk ESP32"
    ```cpp
    --8<-- "code/ino/sensor_buzzer_wifi.ino"
    ```

??? example "Kode program untuk server (Python) tanpa penyimpanan data ke database"
    ```python
    --8<-- "code/python/example_server2.py"
    ```

??? example "Kode program untuk server (Python) dengan penyimpanan data ke database PostgreSQL"
    ```python
    --8<-- "code/python/example_postgres_server.py"
    ```

??? example "Kode program untuk client (Python) untuk mengambil data dari server"
    ```python
    --8<-- "code/python/example_client_get.py"
    ```

??? example "Kode program untuk client (Python) untuk mengirim data ke server"
    ```python
    --8<-- "code/python/example_client_post.py"
    ```

## Blynk Sensor Ultrasonic dan Buzzer

Alat-alat:

- [ESP32](../iot/microcontrollers.md#esp32)
- [Sensor Ultrasonic](../iot/sensors.md#ultrasonic-sensor)
- [Buzzer](../iot/actuators.md#buzzer)

??? example "Kode program untuk ESP32"
    ```cpp
    --8<-- "code/ino/blynk_buzzer_ultrasonic.ino"
    ```