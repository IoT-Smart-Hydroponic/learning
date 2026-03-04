#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

const char* ssid = "UBAH SSID KONEKSI WIFI YANG TERHUBUNG";
const char* password = "PASSWORD WIFI YANG TERHUBUNG";

const char* serverName = "UBAH DENGAN URL SERVER";

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(1000);

  Serial.println("\nMenghubungkan ke Wi-Fi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nIP ESP32: " + WiFi.localIP().toString());

  Serial.println("");
  Serial.println("Berhasil Terhubung!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Data dummy
    // float suhu = 25.0 + (random(0, 100) / 10.0);
    // float kelembapan = 60.0 + (random(0, 100) / 10.0);

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // Penggunaan data dummy
    // String httpRequestData = "{\"suhu\":\"" + String(suhu) + "\",\"kelembapan\":\"" + String(kelembapan) + "\"}";

    String httpRequestData = "{\"suhu\":\"" + String(t) + "\",\"kelembapan\":\"" + String(h) + "\"}";

    Serial.print("Suhu: "); 
    Serial.print(t);
    Serial.print(" | Lembap: ");
    Serial.println(h);

    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.POST(httpRequestData);

    if (httpResponseCode > 0) {
      Serial.print("Data Terkirim, Respon: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error saat kirim: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("Koneksi Terputus!");
  }
  delay(5000);
}