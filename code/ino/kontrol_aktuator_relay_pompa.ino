const int pinRelay = 10;

void setup() {
    Serial.begin(115200);
    pinMode(pinRelay, OUTPUT);
    digitalWrite(pinRelay, HIGH); // Pastikan relay dalam keadaan mati (HIGH)
    Serial.println("Kontrol Pompa Siap!");
}

void loop() {
    // Menyalakan pompa
    Serial.println("Menyalakan Pompa...");
    digitalWrite(pinRelay, LOW); // Relay aktif (LOW)
    delay(5000); // Pompa menyala selama 5 detik

    // Mematikan pompa
    Serial.println("Mematikan Pompa...");
    digitalWrite(pinRelay, HIGH); // Relay mati (HIGH)
    delay(5000); // Pompa mati selama 5 detik
}