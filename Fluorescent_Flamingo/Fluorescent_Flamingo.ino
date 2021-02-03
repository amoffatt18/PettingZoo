// Fluorescent Flamingo

#include <Adafruit_NeoPixel.h>

const int tR = 0;
int potPin = A1;
int npCount = 8;
int npPin = 0;

int numPix;
int potVal;
int analogVal;
int brightness;

Adafruit_NeoPixel strip(npCount, npPin);

uint32_t c1 = strip.Color (255, 100, 50);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(50);
  strip.clear();

  pinMode(potPin, INPUT);

}

void loop() {
  potVal = analogRead(tR);
  numPix = map(potVal,500,600,0,strip.numPixels());

  for (int i = 0; i < numPix; i++) {
    strip.setPixelColor(i, c1);
  }
  strip.show();
  strip.clear();
}
