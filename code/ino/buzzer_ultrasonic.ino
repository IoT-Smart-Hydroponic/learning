// ----- Pin Ultrasonik -----
#define TRIG_PIN 5
#define ECHO_PIN 18

// ----- Pin Buzzer -----
#define BUZZER_PIN 13

// ----- Threshold Jarak (cm) -----
const float JARAK_MINIMUM = 10.0; // Jika objek lebih dekat dari 10 cm, buzzer bunyi

// ----- Variabel Waktu -----
unsigned long sebelumnya = 0;
const unsigned long intervalPembacaan = 2000; // 2 detik

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  unsigned long sekarang = millis();

  if (sekarang - sebelumnya >= intervalPembacaan) {
    sebelumnya = sekarang;

    // Kirim trigger 10 mikrodetik
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Baca durasi pantulan
    long durasi = pulseIn(ECHO_PIN, HIGH);

    // Hitung jarak (cm)
    float jarak = durasi * 0.034 / 2;

    Serial.print("Jarak: ");
    Serial.print(jarak);
    Serial.println(" cm");

    // Cek apakah jarak kurang dari threshold
    if (jarak < JARAK_MINIMUM && jarak > 0) {
      tone(BUZZER_PIN, 2000);  // Bunyi 2000 Hz
      delay(1000);
      noTone(BUZZER_PIN);
      delay(1000);
    } else {
      noTone(BUZZER_PIN);
    }
  }
}