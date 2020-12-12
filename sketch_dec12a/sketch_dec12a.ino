#include "SD.h"

#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup(){
pinMode(10, OUTPUT);
digitalWrite(10, HIGH);
tmrpcm.speakerPin = 9;
Serial.begin(9600);
if (!SD.begin()) {
Serial.println("SD fail");
return;
}

tmrpcm.setVolume(6);
tmrpcm.play("rain.wav");
}

void loop(){  }
