// ================= BLYNK CONFIG =================
#define BLYNK_TEMPLATE_ID "sda"
#define BLYNK_TEMPLATE_NAME "dada"
#define BLYNK_AUTH_TOKEN "dada"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ================= WIFI =================
const char* ssid = "dadad";
const char* password = "defer";

// ================= PIN =================
#define TRIG_PIN    5
#define ECHO_PIN    18
#define BUZZER_PIN  19

// ================= CONFIG =================
const float JARAK_MINIMUM = 10.0;
const unsigned long intervalPembacaan = 5000;

unsigned long sebelumnya = 0;

// ================= STATE =================
bool manualBuzzer = false;

// ================= BLYNK HANDLER =================
// Switch manual buzzer (V3)
BLYNK_WRITE(V3) {
  manualBuzzer = param.asInt(); // 0 atau 1
}

// ================= SETUP =================
void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Koneksi ke Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}

// ================= LOOP =================
void loop() {
  Blynk.run();

  unsigned long sekarang = millis();

  if (sekarang - sebelumnya >= intervalPembacaan) {
    sebelumnya = sekarang;

    // ===== BACA SENSOR ULTRASONIK =====
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG_PIN, LOW);

    long durasi = pulseIn(ECHO_PIN, HIGH);
    float jarak = durasi * 0.034 / 2;

    // Validasi jarak
    if (jarak > 400 || jarak <= 0) {
      jarak = 0;
    }

    // ===== LOGIKA BUZZER =====
    bool kondisiAuto = (jarak < JARAK_MINIMUM && jarak > 0);
    bool isBuzzerActive = false;

    if (kondisiAuto || manualBuzzer) {
      tone(BUZZER_PIN, 500); // frekuensi default
      isBuzzerActive = true;
    } else {
      noTone(BUZZER_PIN);
      isBuzzerActive = false;
    }

    // ===== KIRIM KE BLYNK =====
    Blynk.virtualWrite(V1, jarak);                  // Jarak
    Blynk.virtualWrite(V2, isBuzzerActive ? 1 : 0); // Status buzzer

    // ===== DEBUG SERIAL =====
    Serial.printf(
      "Jarak: %.2f cm | Auto: %d | Manual: %d | Buzzer: %d\n",
      jarak,
      kondisiAuto,
      manualBuzzer,
      isBuzzerActive
    );
  }
}