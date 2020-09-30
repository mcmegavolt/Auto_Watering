#define VERSION "v0.12"

#define CLK 6
#define DT 5
#define SW 4

#define PUMP_PIN 7
#define COMP_PIN 8
#define OZONE_PIN 9

#include "GyverEncoder.h"
#include "GyverTimer.h"
Encoder enc1(CLK, DT, SW, TYPE2);
GTimer backlightTimer(MS);

// Midi to Arduino Converter
// https://www.extramaster.net/tools/midiToArduino/
// Tone settings
int tonePin = 2;
float toneScale = 0.5;
int toneLength = 145;
int uptimeInSeconds;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int releaseVar = 0;
int holdVar = 0;

bool pumpEnabled = false;
bool compEnabled = false;
bool ozoneEnabled = false;

void setup()
{
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(COMP_PIN, OUTPUT);
  pinMode(OZONE_PIN, OUTPUT);

  digitalWrite(COMP_PIN, HIGH);
  digitalWrite(OZONE_PIN, HIGH);

  //    Serial.begin(9600);
  playIntro();

  backlightTimer.setTimeout(8000);
  backlightTimer.start();
  initDisplayIntro();
  //    beep(3);
}

void loop()
{

  lcd.setCursor(0, 1);

  enc1.tick();

  if (enc1.isTurn())
  {
    //      lcd.clear();
    beep(1);
    lcd.backlight();
    backlightTimer.start();
  }

  if (enc1.isRight())
  {
    lcd.clear();
    //      lcd.print("Right");
    releaseVar++;
  }

  if (enc1.isLeft())
  {
    lcd.clear();
    //      lcd.print("Left");
    releaseVar--;
  }

  if (enc1.isRightH())
  {
    holdVar++;
    lcd.clear();
    //      lcd.print("Right holded");
  }

  if (enc1.isLeftH())
  {
    holdVar--;
    lcd.clear();
    //      lcd.print("Left holded");
  }

  if (enc1.isPress())
  {
    lcd.clear();
    lcd.backlight();
    backlightTimer.start();
    //      lcd.print("Press");
    beep(1);
  }

  if (enc1.isRelease())
  {
    lcd.clear();
    lcd.backlight();
    backlightTimer.reset();
    //      lcd.print("Release");
  }

  if (enc1.isHolded())
  {
    lcd.clear();
    lcd.backlight();
    backlightTimer.start();
    //      lcd.print("Holded");
    ozoneEnabled = !ozoneEnabled;
    beep(2);
  }

  lcd.setCursor(0, 0);
  lcd.print("r:");
  lcd.print(releaseVar);
  lcd.setCursor(5, 0);
  lcd.print("h:");
  lcd.print(holdVar);

  printUpTime();

  if (backlightTimer.isReady())
    lcd.noBacklight();

  if (releaseVar > 0)
  {
    pumpEnabled = true;
  }
  else
  {
    pumpEnabled = false;
  }

  if (holdVar > 0)
  {
    compEnabled = true;
  }
  else
  {
    compEnabled = false;
  }

  if (pumpEnabled)
  {
    digitalWrite(PUMP_PIN, HIGH);
  }
  else
  {
    digitalWrite(PUMP_PIN, LOW);
  }

  if (compEnabled)
  {
    digitalWrite(COMP_PIN, LOW);
  }
  else
  {
    digitalWrite(COMP_PIN, HIGH);
  }

  if (ozoneEnabled)
  {
    digitalWrite(OZONE_PIN, LOW);
  }
  else
  {
    digitalWrite(OZONE_PIN, HIGH);
  }

  int sensorValue = analogRead(A1);
  float voltage = sensorValue * (5.0 / 1023.0);
  lcd.setCursor(10, 0);
  lcd.print("v");
  lcd.print(voltage);
}

void playIntro()
{
  tone(tonePin, 2093 * toneScale);
  delay(toneLength);
  tone(tonePin, 2349 * toneScale);
  delay(toneLength);
  tone(tonePin, 2637 * toneScale);
  delay(toneLength);
  tone(tonePin, 2093 * toneScale);
  delay(toneLength);
  tone(tonePin, 2793 * toneScale);
  delay(toneLength);
  tone(tonePin, 2637 * toneScale);
  delay(toneLength);
  tone(tonePin, 2349 * toneScale);
  delay(toneLength);
  tone(tonePin, 2093 * toneScale, toneLength * 3);
}

void printUpTime()
{
  long days = 0;
  long hours = 0;
  long mins = 0;
  long secs = 0;

  secs = millis() / 1000;      //convect milliseconds to seconds
  mins = secs / 60;            //convert seconds to minutes
  hours = mins / 60;           //convert minutes to hours
  days = hours / 24;           //convert hours to days
  secs = secs - (mins * 60);   //subtract the coverted seconds to minutes in order to display 59 secs max
  mins = mins - (hours * 60);  //subtract the coverted minutes to hours in order to display 59 minutes max
  hours = hours - (days * 24); //subtract the coverted hours to days in order to display 23 hours max

  // lcd.setCursor(0, 0);
  // lcd.print("Uptime");

  if (days > 0)
  {
    lcd.print(days);
    lcd.print(" d ");
  }

  lcd.setCursor(0, 1);
  lcd.print(hours);
  lcd.print(" h ");
  lcd.print(mins);
  lcd.print(" m ");
  lcd.print(secs);
  lcd.print(" s ");
}

void initDisplayIntro()
{
  lcd.init();
  //    lcd.noBacklight();
  lcd.backlight();
  lcd.print("Auto Watering");
  lcd.setCursor(0, 1);
  lcd.print(VERSION);
  delay(1000);
  lcd.clear();
}

void beep(int times)
{
  for (int i = 0; i < times; i++)
  {
    tone(tonePin, 2093 * toneScale, 20);
    delay(80);
  }
}
