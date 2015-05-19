#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C  lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


void setupLCD() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);

  lcd.print("LCD ready.");
  delay(500);
}

void setupSD() {
  pinMode(10, OUTPUT);

  lcd.clear();
  lcd.print("Initializing SD...");
  lcd.setCursor(0, 1);
  if (!SD.begin(4)) {
    lcd.print("SD init failed!");
  } else {
    lcd.print("SD ready");
  }  delay(500);
}

void performSDDemo() {
  File sampleFile = SD.open("demo.txt", FILE_WRITE);


  if (sampleFile) {
    lcd.clear();
    sampleFile.println("Sample demo with SD card writing");
    sampleFile.close();
    lcd.clear();
    lcd.print("Done.");
  } else {
    lcd.clear();
    lcd.print("File creation/opening failed!");
  }


}

void setup() {
  setupLCD();
  setupSD();
  performSDDemo();
}

void loop() {
  // put your main code here, to run repeatedly:


}
