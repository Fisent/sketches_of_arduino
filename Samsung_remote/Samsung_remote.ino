#include <IRremote.h>
#include <Rotary.h>

/*
    Rotary Encoder - Polling Example
    
    The circuit:
    * encoder pin A to Arduino pin 4
    * encoder pin B to Arduino pin 5
    * encoder ground pin to ground (GND)
    
*/

// Power ON/OFF
const unsigned int S_pwr[68]={4600,4350,700,1550,650,1550,650,1600,650,450,650,450,650,450,650,450,700,400,700,1550,650,1550,650,1600,650,450,650,450,650,450,700,450,650,450,650,450,650,1550,700,450,650,450,650,450,650,450,650,450,700,400,650,1600,650,450,650,1550,650,1600,650,1550,650,1550,700,1550,650,1550,650};

// source
const unsigned int S_scr[68]={4600,4350,700,1550,650,1550,700,1500,700,450,650,450,700,400,700,400,700,400,700,1550,700,1500,700,1550,700,400,700,400,700,400,700,400,700,400,700,1550,700,400,700,450,650,450,650,450,700,400,700,400,700,400,700,450,650,1550,700,1500,700,1550,650,1550,700,1500,700,1550,700,1500,700};

// volume up
const unsigned int S_vup[68]={4600,4350,650,1550,700,1500,700,1550,700,400,700,400,700,450,650,450,700,400,700,1500,700,1550,650,1550,700,400,700,400,700,450,650,450,700,400,700,1500,700,1550,650,1550,700,400,700,450,700,400,700,400,700,400,700,450,650,450,650,450,650,1550,700,1500,700,1550,700,1500,700,1550,650};

// volume down
const unsigned int S_vdown[68]={4600,4350,700,1550,650,1550,700,1500,700,450,650,450,700,400,700,400,700,400,700,1550,700,1500,700,1550,700,400,700,400,700,400,700,450,650,450,650,1550,700,1500,700,450,650,1550,700,400,700,400,700,450,700,400,700,400,700,400,700,1550,700,400,700,1500,700,1500,700,1550,700,1500,700};

// mute
const unsigned int S_mute[68]={4650,4350,650,1550,650,1550,700,1550,700,400,700,400,700,400,700,450,650,450,650,1550,700,1500,700,1550,700,400,700,450,650,400,700,450,700,400,700,1500,700,1550,650,1550,700,1500,700,450,700,400,700,400,700,400,700,400,700,450,650,450,700,400,700,1500,700,1550,650,1550,700,1500,700};

IRsend IrSender;
Rotary r = Rotary(4, 5);
const int MUTE_PIN = 6;
const int POWER_PIN = 8;
const int SOURCE_PIN = 7;

void setup() {
  Serial.begin(9600);
  r.begin(true);
  pinMode(MUTE_PIN, INPUT_PULLUP);
  pinMode(POWER_PIN, INPUT_PULLUP);
  pinMode(SOURCE_PIN, INPUT_PULLUP);
}

void send_command(const unsigned int command){
  IrSender.sendRaw(command,68,38);
    delay(30);
}

void loop() {
  if(!digitalRead(MUTE_PIN)){
    Serial.println("press");
    send_command(S_mute);
  }
  if(!digitalRead(POWER_PIN)){
    send_command(S_pwr);
  }
  if(!digitalRead(SOURCE_PIN)){
    send_command(S_scr);
  }
  unsigned char result = r.process();
  if (result) {
    if(result == DIR_CW)
    {
      Serial.println("left");
      send_command(S_vdown);
    }
    else 
    {
      Serial.println("right");
      send_command(S_vup);
    }
  }
}
