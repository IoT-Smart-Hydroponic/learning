#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

// ================= WIFI =================
const char* ssid = "nama wifi";
const char* password = "pw wifi";

// ================= MQTT =================
const char* mqtt_server = "url broker mqtt";
const int mqtt_port = port mqtt;
const char* mqtt_user = "usd mqtt";
const char* mqtt_pass = "password mqtt";

// ================= PIN =================
#define TRIG_PIN 5
#define ECHO_PIN 18
#define BUZZER_PIN 19

// ================= MQTT CLIENT =================
WiFiClientSecure espClient;
PubSubClient client(espClient);

// ================= PARAMETER =================
const float JARAK_MINIMUM = 10.0;

unsigned long sebelumnya = 0;
const unsigned long intervalPembacaan = 2000;
bool modeManual = false;
bool buzzerManualState = false;

// ================= WIFI =================
void setup_wifi() {
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
}

// ================= CALLBACK MQTT =================
void callback(char* topic, byte* payload, unsigned int length) {
  String msg;

  for (int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }

  if (String(topic) == "kontrol/buzzer") {
    modeManual = true;

    if (msg == "ON") {
      buzzerManualState = true;
      tone(BUZZER_PIN, 500);
    } else if (msg == "OFF") {
      buzzerManualState = false;
      noTone(BUZZER_PIN);
    }
  }

  if (String(topic) == "kontrol/mode") {
    if (msg == "AUTO") {
      modeManual = false;
    }
  }
}

// ================= RECONNECT MQTT =================
void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");

    if (client.connect("ESP32Client-123", mqtt_user, mqtt_pass)) {
      Serial.println("Connected!");

      client.subscribe("kontrol/buzzer");

    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" coba lagi 5 detik");
      delay(5000);
    }
  }
}

// ================= SETUP =================
void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  setup_wifi();

  espClient.setInsecure();  // untuk TLS tanpa sertifikat (belajar)

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

// ================= LOOP =================
void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  unsigned long sekarang = millis();

  if (sekarang - sebelumnya >= intervalPembacaan) {
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

    // ================= MQTT PUBLISH =================
    char msg[10];
    sprintf(msg, "%.2f", jarak);
    client.publish("sensor/jarak", msg);

    // ================= LOGIKA BUZZER =================
    if (!modeManual) {
      if (jarak < JARAK_MINIMUM && jarak > 0) {
        tone(BUZZER_PIN, 500);
        client.publish("sensor/status", "NYALA, TERDETEKSI OBJEK");
      } else {
        noTone(BUZZER_PIN);
        client.publish("sensor/status", "MATI, TIDAK ADA OBJEK");
      }
    }
  }
}