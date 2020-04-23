#include <Arduino.h>

#define I2C_DTA	20
#define I2C_SCK	21
//
#define MLED 13



void setup() {
  pinMode(MLED,OUTPUT);
}

void loop() {
	digitalWrite(MLED,LOW);
    delay (1000);
    digitalWrite(MLED,HIGH);
    delay (1000);
}
