#include <Servo.h>

const int QRD1114_PIN = A0;
const int sampleRate = 150;
const int servoRestTime = 300;
const float threshold = 0.03;
const int bufSize = 10;

float circBuf[bufSize];
int currIndex = 0;

Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(QRD1114_PIN, INPUT);
  servo.attach(4);
  for (int i=0; i < bufSize; i++) {
    circBuf[i] = 10.0;
  }
}

void loop() {
// Read in the ADC and convert it to a voltage:
  int proximityADC = analogRead(QRD1114_PIN);
  float proximityV = (float)proximityADC * 5.0 / 1023.0;
  Serial.println(proximityV);
  
  float maxVoltage = bufMin();
  if (maxVoltage - proximityV > threshold) {
    servo.write(45);
    delay(servoRestTime);
    servo.write(0);
  }
  bufWrite(proximityV);
  delay(sampleRate);
}

float bufMin() {
  float res = 10.0;
  for (int i=0; i < bufSize; i++) {
    if (circBuf[i] < res) {
      res = circBuf[i];
    }
  }
  return res;
}

void bufWrite(float val) {
  circBuf[currIndex] = val;
  currIndex = (currIndex + 1) % bufSize;
}
