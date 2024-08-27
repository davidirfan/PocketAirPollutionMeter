#include <AverageValue.h>

int senpin = A7;
const long MAX_VALUES_NUM = 60;
AverageValue<float> averageValue(MAX_VALUES_NUM);

int An;
float zero = 0;
int callibration;
float volt;
float res;
float expval;
float ppm;
float ppmavr;

void setup() {
  Serial.begin(9600);
  for(callibration = 180; callibration > 0; callibration--){
    delay(1000);
  }
}

void loop() {
  An = analogRead(senpin);
  volt = An*5.0/1023.0;
  expval = (volt*3.0)/5.0;
  ppm = pow(10.0,expval);
  averageValue.push(ppm);
  ppmavr = averageValue.average();
  Serial.println(ppm);
  Serial.print("|");
  Serial.print(ppmavr);
  delay(1000);
}
