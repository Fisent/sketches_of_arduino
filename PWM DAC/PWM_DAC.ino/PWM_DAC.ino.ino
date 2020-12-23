const int OUTPUT_PWM_PIN = 5;

void setup() {
  // put your setup code here, to run once:
  TCCR0B = (TCCR0B & ~((1 << CS02) | (1 << CS01) | (1 << CS00))) | 1;
  pinMode(OUTPUT_PWM_PIN, OUTPUT);
}

void sawCycle(int delay_val, int duration=10){
  for(int j = 0; j<duration; j++){
   for(int i =0; i<255; i+=10){
    analogWrite(OUTPUT_PWM_PIN, i);
    delay(delay_val);
  }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
   sawCycle(50);
   sawCycle(100);
   sawCycle(500, 3);
   sawCycle(5, 100);
}
