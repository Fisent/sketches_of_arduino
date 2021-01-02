const int OUTPUT_PWM_PIN = 5;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  TCCR0B = (TCCR0B & ~((1 << CS02) | (1 << CS01) | (1 << CS00))) | 1;
  pinMode(OUTPUT_PWM_PIN, OUTPUT);
}

void sawCycle(int delay_val, int duration = 10) {
  for (int j = 0; j < duration; j++) {
    for (int i = 100; i < 240; i += 1) {
      analogWrite(OUTPUT_PWM_PIN, i);
      delay(delay_val);
    }
  }
}

void loop() {
  Serial.println("DUPA");
  // put your main code here, to run repeatedly:
  sawCycle(1);
  //   sawCycle(100);
  //   sawCycle(500, 3);
  //   sawCycle(5, 100);
}

