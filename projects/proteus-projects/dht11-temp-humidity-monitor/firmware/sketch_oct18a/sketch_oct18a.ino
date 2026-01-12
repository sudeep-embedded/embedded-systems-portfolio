#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// New pins
#define FAN_PIN 9
#define BUZZER_PIN 10

void setup() {
  lcd.begin(16, 2);
  dht.begin();

  pinMode(FAN_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(FAN_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.print("DHT11 Weather");
  delay(2000);
  lcd.clear();
}

void beep3s() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(3000);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.print("Sensor Error!");
    return;
  }

  // Display
  lcd.setCursor(0, 0);
  lcd.print("T = ");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C   ");

  lcd.setCursor(0, 1);
  lcd.print("H = ");
  lcd.print(h);
  lcd.print("%   ");

  // Control logic
  if (t > 25) {
    beep3s();
    digitalWrite(FAN_PIN, HIGH); // Turn fan on
  } else {
    beep3s();
    digitalWrite(FAN_PIN, LOW); // Turn fan off
  }

  delay(1000);
}
