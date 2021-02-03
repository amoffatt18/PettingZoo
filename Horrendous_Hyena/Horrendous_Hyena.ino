// Horrendous Hyena

int but = A1;
int buzzer = 0;

boolean butState = false; // sets the button state to false
boolean prevState = false; // sets the previous state to false

int switchVal = 2;

unsigned long startTime;
unsigned long endTime;
unsigned long interval = 100;


void setup() {

  Serial.begin(9600);
  pinMode (but, INPUT);
  pinMode (buzzer, OUTPUT);

}

void loop() {
  /*
  butState = debounce(but, prevState);

  if (butState == HIGH && prevState == LOW) {
    switchVal = switchVal + 1;

    if (switchVal == 3) {
      switchVal = 0;
    }
  }
*/

  int raw = digitalRead(but);
  if(raw == 0){
    switchVal = (switchVal + 1) % 3; 
    Serial.println("push"); delay(200);
    }
 
 
  switch (switchVal) {
    case 0:
      tone (buzzer, 2000);
      delay (1000);
      noTone (buzzer);
      delay (100);
      Serial.println ("pressed");
      break;

    case 1:
      tone (buzzer, 8000);
      delay (500);
      noTone (buzzer);
      delay (100);
      Serial.println ("unpressed");
      break;

    case 2:
      //tone (0, 0);
      //delay (500);
      noTone (buzzer);
      Serial.println ("off");
      
      break;

  }

  prevState = butState;
  
}

boolean debounce(int aRandomButtonPin, boolean aPrevButtonState) {

  boolean aButtonState = digitalRead(aRandomButtonPin);

  if (aButtonState != aPrevButtonState) {
    delay(5);
    aButtonState = digitalRead(aRandomButtonPin);
  }

  return aButtonState;



}
