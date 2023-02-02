#include <LiquidCrystal.h>
int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int sensorPin = A0;
int sensorValue = 0;
int percentValue = 0;
int sensorValueConstrain;

void setup() {
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  analogWrite(6, Contrast);
  lcd.begin(16, 2);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void ekrans() {
  sensorValue = analogRead(sensorPin);
  sensorValueConstrain = constrain(sensorValue, 229, 658);
  percentValue = ((sensorValueConstrain - 658) / (-4.4));
  Serial.print(sensorValue);
  String percentValueString = String(percentValue);
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  lcd.setCursor(0, 1);  
  lcd.print("Percent: ");
  lcd.print(percentValueString);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}

void gaismina() {
  digitalWrite(7, HIGH);
}

void motors() {
  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(200);
  digitalWrite(6, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  delay(200);
  digitalWrite(6, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  delay(200);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  delay(200);  
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW); 
}

void loop() {

  if (percentValue > 40) {
    digitalWrite(7, LOW);
    ekrans();
  }
  
  else if (percentValue < 40) {
    gaismina();
    ekrans();
    motors();
  }

  else if (percentValue == 40) {
    digitalWrite(7, LOW);
    ekrans();
  }

}
