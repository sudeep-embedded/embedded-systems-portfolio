#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

#define trig1 2
#define echo1 3
#define trig2 4
#define echo2 5

#define green1 A0
#define red1   A1
#define green2 A2
#define red2   A3

#define IR_IN_PIN   13
#define IR_OUT_PIN   6

long duration;
int distance1, distance2;

volatile long peopleCount = 0;

bool inLatched = false;
bool outLatched = false;

unsigned long inLastChange = 0;
unsigned long outLastChange = 0;
const unsigned long debounceMs = 30;

bool systemActive = false;

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0); lcd.print(" SMART PARKING ");
  lcd.setCursor(0, 1); lcd.print(" SYSTEM LOADING ");
  delay(1500);
  lcd.clear();

  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  pinMode(green1, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(red2, OUTPUT);

  pinMode(IR_IN_PIN, INPUT_PULLUP);
  pinMode(IR_OUT_PIN, INPUT_PULLUP);

  digitalWrite(green1, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(green2, HIGH);
  digitalWrite(red2, LOW);

  lcd.display();
}

void sensorsOff() {
  digitalWrite(green1, LOW);
  digitalWrite(red1, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(trig1, LOW);
  digitalWrite(trig2, LOW);
  lcd.noDisplay();
}

void sensorsOn() {
  lcd.display();
}

void handleIR() {
  unsigned long now = millis();

  int inState = digitalRead(IR_IN_PIN);
  if (inState == LOW) {
    if (!inLatched && (now - inLastChange) > debounceMs) {
      peopleCount++;
      inLatched = true;
      inLastChange = now;
    }
  } else {
    if (inLatched && (now - inLastChange) > debounceMs) {
      inLatched = false;
      inLastChange = now;
    }
  }

  int outState = digitalRead(IR_OUT_PIN);
  if (outState == LOW) {
    if (!outLatched && (now - outLastChange) > debounceMs) {
      if (peopleCount > 0) peopleCount--;
      outLatched = true;
      outLastChange = now;
    }
  } else {
    if (outLatched && (now - outLastChange) > debounceMs) {
      outLatched = false;
      outLastChange = now;
    }
  }
}

int readDistance(uint8_t trig, uint8_t echo) {
  digitalWrite(trig, LOW); delayMicroseconds(2);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long dur = pulseIn(echo, HIGH, 30000);
  if (dur == 0) return 999;
  return (int)(dur * 0.034 / 2);
}

void updateUI() {
  distance1 = readDistance(trig1, echo1);
  distance2 = readDistance(trig2, echo2);

  lcd.setCursor(0, 0);
  lcd.print("S1:");
  if (distance1 > 0 && distance1 < 21) {
    lcd.print("OCCUPIED ");
    digitalWrite(red1, HIGH);  digitalWrite(green1, LOW);
  } else {
    lcd.print("EMPTY    ");
    digitalWrite(red1, LOW);   digitalWrite(green1, HIGH);
  }

  lcd.setCursor(0, 1);
  lcd.print("S2:");
  if (distance2 > 0 && distance2 < 21) {
    lcd.print("OCCUPIED ");
    digitalWrite(red2, HIGH);  digitalWrite(green2, LOW);
  } else {
    lcd.print("EMPTY    ");
    digitalWrite(red2, LOW);   digitalWrite(green2, HIGH);
  }

  lcd.setCursor(11, 0);
  lcd.print("Cnt:");
  lcd.setCursor(14, 0);
  int shown = abs(peopleCount) % 100;
  if (shown < 10) lcd.print(" ");
  lcd.print(shown);

  Serial.print("S1: "); Serial.print(distance1);
  Serial.print(" cm | S2: "); Serial.print(distance2);
  Serial.print(" cm | Cnt: "); Serial.println(peopleCount);
}

void loop() {
  handleIR();

  bool shouldBeActive = (peopleCount > 0);

  if (shouldBeActive && !systemActive) {
    systemActive = true;
    sensorsOn();
    lcd.clear();
  } else if (!shouldBeActive && systemActive) {
    systemActive = false;
    sensorsOff();
  }

  if (systemActive) {
    updateUI();
    delay(50);
  } else {
    delay(10);
  }
}
