#include <Servo.h>

// Constants
const int QRD1114_PIN = A0;
const int sampleRate = 25;
const int servoRestTime = 300;
const float threshold = 0.03;
const int bufSize = 10;

// Globals
float circBuf[bufSize];
int currIndex;
int dodgeCounter;
Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(QRD1114_PIN, INPUT);
  servo.attach(4);
  for (int i=0; i < bufSize; i++) {
    circBuf[i] = 10.0;
  }
  currIndex = 0;
  dodgeCounter = 0;
}

void loop() {
  // Read in the ADC and convert it to a voltage:
  int proximityADC = analogRead(QRD1114_PIN);
  float proximityV = (float)proximityADC * 5.0 / 1023.0;
  
  // Only trigger a servo movement if the
  // observed voltage is more than threshold
  // less than the minimum recent voltage
  float minVoltage = bufMin();
  if (minVoltage - proximityV > threshold) {
    servo.write(55);
    Serial.print("\rDodged ");
    Serial.print(dodgeCounter);
    Serial.print(" bolts");
    delay(servoRestTime);
    servo.write(0);
  }
  // Write value into the circular buffer
  bufWrite(proximityV);
  delay(sampleRate);
}

/**
*  Finds the min value in the circular buff
*/
float bufMin() {
  float res = 10.0;
  for (int i=0; i < bufSize; i++) {
    if (circBuf[i] < res) {
      res = circBuf[i];
    }
  }
  return res;
}

/**
*  Writes a value into the current position
*  and increments to the next index
*/
void bufWrite(float val) {
  circBuf[currIndex] = val;
  currIndex = (currIndex + 1) % bufSize;
}
