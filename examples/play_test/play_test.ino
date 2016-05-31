#include <SoftwareSerial.h>
#include <SOMO_II.h>

// set up a new serial object
SoftwareSerial mySerial = SoftwareSerial(8, 9);

SOMO_II mp3 = SOMO_II(mySerial);

void setup() {
  mySerial.begin(SOMO_BAUD);
  mp3.begin();

  Serial.begin(115200);
  Serial.println(F("starting play_test"));
}

void loop() {
  Serial.println(F("playing countdown"));
  int playlist[6] = {5, 4, 3, 2, 1, 6};
  for (int i=0; i<6; i++) {
    Serial.print(F("playing: "));
    Serial.print(playlist[i]);
    int err = mp3.playFile(1,playlist[i]);
    if (err != 0) {
      Serial.print(F(", err: "));
      Serial.print(err);
    }
    Serial.println();
    delay(1000);
  }
  // play a game file
  mp3.playFile(1,random(10, 13));
  // for 30 seconds
  delay(30000);
  // go boom
  mp3.playFile(1, 8);
  delay(5000);
}
