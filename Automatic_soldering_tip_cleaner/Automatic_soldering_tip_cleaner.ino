const int STATUS_LED_PIN = 3;
const int INPUT_SENSOR_PIN = 1;
const int MOTOR_OUTPUT_PIN = 2;

const int TIME_OF_CLEANING = 4;
const int AFTER_CLEANING_DELAY = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(INPUT_SENSOR_PIN, INPUT_PULLUP);
  pinMode(MOTOR_OUTPUT_PIN, OUTPUT);
  pinMode(STATUS_LED_PIN, OUTPUT);
  
  digitalWrite(MOTOR_OUTPUT_PIN, 0);
  digitalWrite(STATUS_LED_PIN, 1);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(INPUT_SENSOR_PIN)){
    digitalWrite(MOTOR_OUTPUT_PIN, 1);
    digitalWrite(STATUS_LED_PIN, 0);
    delay(TIME_OF_CLEANING * 1000);
    digitalWrite(MOTOR_OUTPUT_PIN, 0);
    delay(AFTER_CLEANING_DELAY * 1000);
    digitalWrite(STATUS_LED_PIN, 1);
  }
}
