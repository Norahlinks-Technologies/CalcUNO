#include <Arduino.h>
#include "LiquidCrystal.h"
#include "calculator.h"
#include "keyPad.h"



LiquidCrystal lcd (4, 5, 6, 7, 8, 9);


void setup() 
{
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Norahlinks Tech");
  lcd.setCursor(0,1);
  lcd.print("Basic Calculator");
  delay(3000);
  lcd.setCursor(0,0);
  lcd.print("choose option");
  delay(2000);
  lcd.setCursor(0,0);
  
}

void loop() 
{

}