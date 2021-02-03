// Chill Chameleon

const int sensorPin = A1;
const int ledPin = 0;

int lightCal;
int lightVal;



void setup() {

  pinMode(ledPin, OUTPUT);
  lightCal = analogRead(sensorPin);


}


void loop() {

  lightVal = analogRead(sensorPin);

  if (lightVal < lightCal - 50) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}
