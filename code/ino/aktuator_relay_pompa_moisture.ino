#define MOISTURE_PIN 34
#define RELAY_PIN 18

int moistureAnalog = 0;
int moisture = 0;

#define MOISTURE_ON 30
#define MOISTURE_OFF 45

void readMoistureSensor() {
    moistureAnalog = analogRead(MOISTURE_PIN);
    moisture = 100 - ((moistureAnalog / 4095.0) * 100);
    moisture = constrain(moisture, 0, 100);
}

void setup() {
    Serial.begin(115200);
    pinMode(MOISTURE_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);

    digitalWrite(RELAY_PIN, HIGH); // Pastikan relay dalam keadaan mati (HIGH)
    Serial.println("=== Sistem Kontrol Pompa Berbasis Moisture (%) ===");
}

void loop() {

    readMoistureSensor();
    Serial.print("Moisture Analog: ");
    Serial.print(moistureAnalog);
    Serial.print(" | Moisture (%): ");
    Serial.print(moisture);
    Serial.println(" %");

    if (moisture < MOISTURE_ON) {
        Serial.println("Tanah Kering -> Pompa MENYALA");
        digitalWrite(RELAY_PIN, LOW); // Relay aktif (LOW)
    } else if (moisture > MOISTURE_OFF) {
        Serial.println("Tanah Lembap -> Pompa MATI");
        digitalWrite(RELAY_PIN, HIGH); // Relay mati (HIGH)
    }
    Serial.println("-----------------------------------");
    delay(2000); // Delay untuk pembacaan berikutnya
}