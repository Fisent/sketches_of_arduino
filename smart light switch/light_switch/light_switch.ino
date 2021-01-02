const int SERVO_PIN = 0;
const int BUTTON_PIN = 3;
const int DEEGRE_OFFSET = 50;

const int PWM_MICROSECONDS_PERIOD = 1200;

const int ON_DELAY_LEFT_MICROSECONDS = 120;
const int ON_DELAY_RIGHT_MICROSECONDS = 65;
const int ON_DELAY_CENTER_MICROSECONDS = 90;

constexpr int OFF_DELAY_LEFT_MICROSECONDS = PWM_MICROSECONDS_PERIOD - ON_DELAY_LEFT_MICROSECONDS;
constexpr int OFF_DELAY_RIGHT_MICROSECONDS = PWM_MICROSECONDS_PERIOD - ON_DELAY_RIGHT_MICROSECONDS;
constexpr int OFF_DELAY_CENTER_MICROSECONDS = PWM_MICROSECONDS_PERIOD - ON_DELAY_CENTER_MICROSECONDS;

const int ITERATIONS = 10;

bool position_up = true;

void setup() {
  pinMode(SERVO_PIN, OUTPUT);

  for (long int i; i < ITERATIONS; i++) {
    digitalWrite(SERVO_PIN, true);
    delayMicroseconds(ON_DELAY_CENTER_MICROSECONDS );
    digitalWrite(SERVO_PIN, false);
    delayMicroseconds(OFF_DELAY_CENTER_MICROSECONDS);
  }
  delay(100);
}

void write_servo(bool up) {
  if (up) {
    for (long int i; i < ITERATIONS; i++) {
      digitalWrite(SERVO_PIN, true);
      delayMicroseconds(ON_DELAY_LEFT_MICROSECONDS );
      digitalWrite(SERVO_PIN, false);
      delayMicroseconds(OFF_DELAY_LEFT_MICROSECONDS);
    }
  } else {
    for (long int i; i < ITERATIONS; i++) {
      digitalWrite(SERVO_PIN, true);
      delayMicroseconds(ON_DELAY_RIGHT_MICROSECONDS );
      digitalWrite(SERVO_PIN, false);
      delayMicroseconds(OFF_DELAY_RIGHT_MICROSECONDS);
    }
  }
}

void loop() {
  //  bool button_pressed = !digitalRead(SERVO_PIN);
  write_servo(true);
  delay(100);
  write_servo(false);
  delay(100);

  for (long int i; i < ITERATIONS; i++) {
    digitalWrite(SERVO_PIN, true);
    delayMicroseconds(ON_DELAY_CENTER_MICROSECONDS );
    digitalWrite(SERVO_PIN, false);
    delayMicroseconds(OFF_DELAY_CENTER_MICROSECONDS);
  }
  delay(100);
}
