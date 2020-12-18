#include <Wire.h>
#include <MPU6050.h>
 
MPU6050 mpu;
bool buzzer_state = false;

void setup_gyro(){
  // Kalibracja żyroskopu
  mpu.calibrateGyro();
 
  // Ustawienie czułości
  mpu.setThreshold(3);
}

void setup()
{
  Serial.begin(115200);
 
  Serial.println("Inicjalizacja MPU6050");
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Nie mozna znalezc MPU6050 - sprawdz polaczenie!");
    delay(500);
  }
  setup_gyro();
  pinMode(4, OUTPUT);
}

int map_position_to_frequency(long int position){
  long int pos = position + 18000;
  return 100 + (pos / 20);
}

int get_gyro_value(){
  Vector rawAccel = mpu.readRawAccel();
  return rawAccel.XAxis;
}

void set_tone_frequency(int frequency){
  tone(4, frequency);
}

void loop(){
  int gyro_val =  get_gyro_value();
//  Serial.println(gyro_val);
  int freq = map_position_to_frequency(gyro_val);
  set_tone_frequency(freq);
}
