#include <RTClib.h>
#include <LiquidCrystal.h>
int Contrast=75;
char buffer[12];
char buffer2[12];
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
RTC_DS1307 rtc;

void setup () {
  Serial.begin(9600);
  lcd.begin(16, 2);
  // SETUP RTC MODULE
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1);
  }
  rtc.adjust(DateTime(F(DATE), F(TIME)));
}

void loop () {
  DateTime now = rtc.now();
  snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
  lcd.setCursor(4, 0);
  lcd.print(buffer);
  snprintf(buffer2, sizeof(buffer), "%02d/%02d/%4d",now.day(), now.month(), now.year());
  lcd.setCursor(3, 1);
  lcd.print(buffer2);
  delay(1000);
  lcd.clear();
  //DateTime now = rtc.now();
  //Serial.print("Date & Time: ");
  //Serial.print(now.year(), DEC);
  //Serial.print('/');
  //Serial.print(now.month(), DEC);
  //Serial.print('/');
  //Serial.print(now.day(), DEC);
  //Serial.print(" (");
  //Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  //Serial.print(") ");
  //Serial.print(now.hour(), DEC);
  //Serial.print(':');
  //Serial.print(now.minute(), DEC);
  //Serial.print(':');
  //Serial.println(now.second(), DEC);

  //lcd.setCursor(0, 0);
  //lcd.print(now.hour(), DEC);
  //lcd.print(':');
  //lcd.print(now.minute(), DEC);
  //lcd.print(':');
  //lcd.print(now.second(), DEC);
  //delay(1000);
  //lcd.clear();
}