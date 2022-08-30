/*
  Based on Tom Igoe's code
  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

static int led = 5;


static int lig = 6;

static int big = 13;

static int lag = A1;

static int dog = A5;

static int tag = A7;
const int buzzerPin = 2;
const int buttonPin = 7;
int buttonState = 0;
// notes in the melody:
// use 0 for a rest
// put each measure on its own line
int melody[] = {
 233,233,277,311,277,311,349,311,277,233
 
  
};

// note durations: 1 = whole note, 4 = quarter note, 8 = eighth note, etc.:
// be sure each note or rest in the melody above has a corresponding duration below
// put each measure on its own line
int noteDurations[] = {
  8,8,8,3,8,8,8,8,8,2
};

// set the tempo
// a tempo of 60 is one beat per second
// a tempo of 120 would be twice as fast
int beatsPerMinute = 45;

void setup() {
 pinMode(buttonPin, INPUT);
 pinMode(led,OUTPUT);
 pinMode(lig,OUTPUT);
pinMode(big,OUTPUT);
pinMode(lag,OUTPUT);
pinMode(dog,OUTPUT);
pinMode(tag,OUTPUT);

}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) { 
    playSong();
    digitalWrite(led,HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);                       // wait for a second
  digitalWrite(led,LOW);    // turn the LED off by making the voltage LOW
  delay(0);                      // wait for a second

  



  digitalWrite(lig,HIGH);
  delay(300);
  digitalWrite(lig,LOW);
  delay(0);






  digitalWrite(big,HIGH);
  delay(300);
  digitalWrite(big,LOW);
  delay(0);





  digitalWrite(lag,HIGH);
  delay(300);
  digitalWrite(lag,LOW);
  delay(0);





  digitalWrite(dog,HIGH);
  delay(300);
  digitalWrite(dog,LOW);
  delay(0);





  digitalWrite(tag,HIGH);
  delay(300);
  digitalWrite(tag,LOW);
  delay(0);

  }
  
}


void playSong(){
  // iterate over the notes of the melody:
  int len = sizeof(melody)/sizeof(melody[0]);
  for (int thisNote = 0; thisNote < len; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = static_cast<int>(1000 / noteDurations[thisNote] * 60 / beatsPerMinute);
    tone(buzzerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
  // Pause before playing again
  delay(1000);
}
