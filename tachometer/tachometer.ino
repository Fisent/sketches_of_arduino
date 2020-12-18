#include <TM1637Display.h>

//#include "tm1637.h"
//#include "tm1637.c"

int MEASUREMENT_INTERVAL = 1000; //in miliseconds

volatile unsigned int counter = 0;
unsigned long lastTimestamp;
unsigned long currentTimestamp;
TM1637Display display(3, 4);

//void display_number(int number) {
//  int first_digit = number % 10;
//  int second_digit = number / 10 % 10;
//  int third_digit = number / 100 % 10;
//  int fourth_digit = number / 1000 % 10;
//
//  TM1637_display_digit(0, fourth_digit);
//  TM1637_display_digit(1, third_digit);
//  TM1637_display_digit(2, second_digit);
//  TM1637_display_digit(3, first_digit);
//}

void setup() {
  display.setBrightness(15);
  // put your setup code here, to run once:
//  TM1637_init(1, 5);
//  TM1637_display_colon(0);

  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), SingleRotation, FALLING);

  unsigned long lastTimestamp = millis();
}

void loop() {
  currentTimestamp = millis();
  if (currentTimestamp - lastTimestamp >= MEASUREMENT_INTERVAL) {
    int rpm = counter;
//    display_number(rpm);
display.showNumberDec(rpm,true,4,0);
    

    counter = 0;
    lastTimestamp = millis();
  }
}

void SingleRotation () {
  counter++;
}
