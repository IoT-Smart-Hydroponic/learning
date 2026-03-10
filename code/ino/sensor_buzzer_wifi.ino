#include <WiFi.h>
#include <HTTPClient.h>

// ----- WIFI -----
const char *ssid = "Nama_wifi";
const char *password = "password";

// ----- SERVER -----
const char *serverURL = "http://ip-device:5000/data";

// ----- DEVICE ID -----
const char *device_id = "IoT-1";

// ----- Pin Ultrasonik -----
#define TRIG_PIN 5
#define ECHO_PIN 18

// ----- Pin Buzzer -----
#define BUZZER_PIN 13

// ----- Threshold -----
const float JARAK_MINIMUM = 10.0;

// ----- Waktu -----
unsigned long sebelumnya = 0;
const unsigned long intervalPembacaan = 5000;

void setup()
{

    Serial.begin(115200);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    WiFi.begin(ssid, password);

    Serial.print("Menghubungkan WiFi");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi Terhubung");
}

void loop()
{

    unsigned long sekarang = millis();

    if (sekarang - sebelumnya >= intervalPembacaan)
    {

        sebelumnya = sekarang;

        // Trigger ultrasonik
        digitalWrite(TRIG_PIN, LOW);
        delayMicroseconds(2);

        digitalWrite(TRIG_PIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIG_PIN, LOW);

        long durasi = pulseIn(ECHO_PIN, HIGH);

        float jarak = durasi * 0.034 / 2;

        Serial.print("Jarak: ");
        Serial.print(jarak);
        Serial.println(" cm");

        // ----- STATUS BUZZER -----
        String statusBuzzer = "OFF";

        if (jarak < JARAK_MINIMUM && jarak > 0)
        {
            tone(BUZZER_PIN, 2000);
            statusBuzzer = "ON";
        }
        else
        {
            noTone(BUZZER_PIN);
            statusBuzzer = "OFF";
        }

        // ----- KIRIM DATA KE SERVER -----
        if (WiFi.status() == WL_CONNECTED)
        {

            HTTPClient http;

            http.begin(serverURL);
            http.addHeader("Content-Type", "application/json");

            String json = "{";
            json += "\"device_id\":\"";
            json += device_id;
            json += "\",";
            json += "\"jarak\":";
            json += jarak;
            json += ",";
            json += "\"buzzer\":\"";
            json += statusBuzzer;
            json += "\"}";

            Serial.println("Data dikirim:");
            Serial.println(json);

            int httpResponseCode = http.POST(json);

            Serial.print("Response: ");
            Serial.println(httpResponseCode);

            http.end();
        }
    }
}