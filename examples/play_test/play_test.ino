#include <SoftwareSerial.h>
#include <SOMO_II.h>

// set up a new serial object
SoftwareSerial mySerial = SoftwareSerial(8, 9);

SOMO_II mp3 = SOMO_II(mySerial);

void setup() {
  mySerial.begin(9600);
  mp3.begin();

  Serial.begin(9600);
  Serial.println(F("starting play_test"));
}

void loop() {
  Serial.println(F("playing countdown"));
  mp3.playFile(1,5);
  delay(1000);
  mp3.playFile(1,4);
  delay(1000);
  mp3.playFile(1,3);
  delay(1000);
  mp3.playFile(1,2);
  delay(1000);
  mp3.playFile(1,1);
  delay(1000);
  mp3.playFile(1,6);
  delay(1000);
}

