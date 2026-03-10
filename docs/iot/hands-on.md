# Hands-On IoT

## Rangkaian Pemantau Suhu dan Kelembapan

Alat-alat:

- [ESP32](microcontrollers.md#esp32)
- [Sensor DHT11](sensors.md#sensor-dht11)
- [Buzzer](actuators.md#buzzer)

??? example "Kode program untuk ESP32"
    ```cpp
    --8<-- "code/ino/pemantau_suhu.ino"
    ```

## Rangkaian Kontrol Aktuator Dengan Relay

Alat-alat:

- [ESP32](microcontrollers.md#esp32)
- [Relay](actuators.md#relay)
- [Pompa DC](actuators.md#pompa-dc)

??? example "Kode program untuk ESP32"
    ```cpp
    --8<-- "code/ino/kontrol_aktuator_relay_pompa.ino"
    ```

## Rangkaian Kontrol Aktuator Pompa DC Dengan Relay

Alat-alat:

- [ESP32](microcontrollers.md#esp32)
- [Relay](actuators.md#relay)
- [Pompa DC](actuators.md#pompa-dc)
- [Moisture Sensor](sensors.md#soil-moisture-sensor)

??? example "Kode program untuk ESP32"
    ```cpp
    --8<-- "code/ino/aktuator_relay_pompa_moisture.ino"
    ```

## Rangkaian Sensor Ultrasonic dan Buzzer

Alat-alat:

- [ESP32](microcontrollers.md#esp32)
- [Sensor Ultrasonic](sensors.md#ultrasonic-sensor)
- [Buzzer](actuators.md#buzzer)

??? example "Kode program untuk ESP32"
    ```cpp
    --8<-- "code/ino/buzzer_ultrasonic.ino"
    ```

## Rangkaian Sensor Ultrasonic, Buzzer, dan Penyimpanan Data di Server

Alat-alat:

- [ESP32](microcontrollers.md#esp32)
- [Sensor Ultrasonic](sensors.md#ultrasonic-sensor)
- [Buzzer](actuators.md#buzzer)

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
