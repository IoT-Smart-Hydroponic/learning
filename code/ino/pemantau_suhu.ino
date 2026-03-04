# include <DHT.h>

#define DHTPIN 5 // Pin digital yang terhubung ke sensor DHT11
#define DHTTYPE DHT11 // Tipe sensor DHT yang digunakan (DHT11)
DHT dht(DHTPIN, DHTTYPE);

#define BUZZER_PIN 13 // Pin untuk buzzer

// ----- Thresholds -----
const float SUHU_MAKSIMUM = 32.0;
const float KELEMBAPAN_MAKSIMUM = 70.0;


// ----- Variabel Waktu-----
unsigned long sebelumnya = 0;
const unsigned long intervalPembacaan = 2000; // interval 2 detik

void setup() {
    Serial.begin(115200);
    dht.begin();
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    unsigned long sekarang = millis();

    if (sekarang - sebelumnya >= intervalPembacaan) {
        sebelumnya = sekarang;

        // Membaca suhu dan kelembapan dari sensor DHT11
        float suhu = dht.readTemperature();
        float kelembapan = dht.readHumidity();

        // Memeriksa apakah pembacaan berhasil
        if (isnan(suhu) || isnan(kelembapan)) {
        Serial.println("Gagal membaca dari sensor DHT11!");
        return;
        }

        // Menampilkan hasil pembacaan di Serial Monitor
        Serial.print("Suhu: ");
        Serial.print(suhu);
        Serial.print(" °C, Kelembapan: ");
        Serial.print(kelembapan);
        Serial.println(" %");

        // Memeriksa apakah suhu atau kelembapan melebihi threshold
        if (suhu > SUHU_MAKSIMUM || kelembapan > KELEMBAPAN_MAKSIMUM) {
        tone(BUZZER_PIN, 2000); // Nyalakan buzzer dengan frekuensi 1000 Hz
        delay(1000); // Buzzer menyala selama 1 detik
        noTone(BUZZER_PIN); // Matikan buzzer
        delay(1000); // Jeda sebelum pembacaan berikutnya
        } else {
        noTone(BUZZER_PIN); // Pastikan buzzer mati jika kondisi normal
        }
    }
}