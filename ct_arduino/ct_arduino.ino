#include <LiquidCrystal.h>
#include <string.h>
#include "ct_arduino.h"

int LCD_RS = 12;
int LCD_E = 11;
int LCD_D4 = 5;
int LCD_D5 = 4;
int LCD_D6 = 3;
int LCD_D7 = 2;

//button input
int buttonPin = 7;
//temp sensor input - it's an analog pin
int baseTempPin = 0;
int slurryTempPin = 0;

LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);


buttonState button = INIT;
const int NUMSTATES = 5;

int offset =0;
int timesarray[NUMSTATES];


void setup(){
//  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(buttonPin, INPUT);
}

void loop(){
  if( button != OFF) {
    float voltage = getVoltage(baseTempPin);
    float tempBase = (voltage - 0.5) * 100;
    voltage = getVoltage(slurryTempPin);
    float tempSlurry = (voltage - 0.5) * 100;

    lcd.print(tempBase);
    lcd.setCursor(8,0);
    lcd.print(tempSlurry);
    
    lcd.setCursor(0,1);
    lcd.print(millis()/1000);
    lcd.setCursor(8,1);
    lcd.print(stateToName(button));
  }
}

float getVoltage(int pin){
  return (analogRead(pin) * 0.004882814);
}

const char* stateToName(buttonState b){
  switch(b){
    case INIT: return "INIT";
    case RISE: return "RISE";
    case BREW: return "BREW";
    case DOWN: return "DOWN";
    default: return "OFF";
  }
}
