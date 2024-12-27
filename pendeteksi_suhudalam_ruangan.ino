#include <DHT.h>
#include <LiquidCrystal_I2C.h>

// Definisikan pin sensor DHT11
#define DHTPIN 2      // Pin sensor DHT11 terhubung ke pin digital 2 pada Arduino
#define DHTTYPE DHT11 // Menentukan tipe sensor yang digunakan (DHT11)

// Inisialisasi objek sensor DHT
DHT dht(DHTPIN, DHTTYPE);

// Inisialisasi objek LCD (gunakan alamat I2C default 0x27 untuk LCD 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Memulai komunikasi serial untuk debugging
  Serial.begin(9600);

  // Inisialisasi sensor DHT
  dht.begin();

  // Inisialisasi LCD
  lcd.begin();
  lcd.backlight();  // Menyalakan backlight LCD
  lcd.setCursor(0, 0);
  lcd.print("Suhu Ruangan:");
}

void loop() {
  // Membaca suhu dalam derajat Celsius
  float suhu = dht.readTemperature();

  // Mengecek apakah pembacaan suhu gagal
  if (isnan(suhu)) {
    Serial.println("Gagal membaca sensor!");
    lcd.setCursor(0, 1);
    lcd.print("Sensor Error");
    return;
  }

  // Menampilkan hasil pembacaan suhu di LCD
  lcd.setCursor(0, 1);
  lcd.print("Suhu: ");
  lcd.print(suhu);
  lcd.print(" C");

  // Menampilkan data ke Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println(" C");

  // Tunggu 2 detik sebelum pembacaan selanjutnya
  delay(2000);
}
