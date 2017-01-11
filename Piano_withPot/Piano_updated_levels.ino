

#include <CapacitiveSensor.h>
#include "pitches.h"

#define COMMON_PIN      2    // The common 'send' pin for all keys
#define BUZZER_PIN      A4   // The output pin for the piezo buzzer
#define NUM_OF_SAMPLES  30   // Higher number whens more delay but more consistent readings
#define CAP_THRESHOLD   60  // Capactive reading that triggers a note (adjust to fit your needs)
#define NUM_OF_KEYS     4   // Number of keys that are on the keyboard
#define pot_pin A2
// This macro creates a capacitance "key" sensor object for each key on the piano keyboard:
#define CS(Y) CapacitiveSensor(2, Y)


int notes[]={NOTE_B0,NOTE_C1,NOTE_CS1,NOTE_D1,NOTE_DS1,NOTE_E1,NOTE_F1,NOTE_FS1,NOTE_G1,NOTE_GS1,NOTE_A1,NOTE_AS1};

// Defines the pins that the keys are connected to:
CapacitiveSensor keys[] = {CS(3), CS(4), CS(5), CS(6)};

int powint(int x, int y);
 void Music(int level);

void setup() { 
  // Turn off autocalibrate on all channels:
  for(int i=0; i<4; ++i) {
    keys[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
  // Set the buzzer as an output:
  pinMode(BUZZER_PIN, OUTPUT); 
  Serial.begin(9600);
  pinMode(pot_pin,INPUT);
}

void loop() {

int pot_level =analogRead(pot_pin);
Serial.println(pot_level);
  
  if (pot_level >896){ 
    Music(powint(2,7));
  }
  else if(pot_level>768){
    Music(powint(2,6));
  }
  
  else if(pot_level>640){
    Music(powint(2,5));
  }
  
  else if(pot_level>512){
    Music(powint(2,4));
  }
  
  else if(pot_level>384){
    Music(powint(2,3));
  }
  
  else if(pot_level>256){
    Music(powint(2,2));
  }
  
  else if(pot_level>128){
    Music(powint(2,1));
  }

 else{
    Music(powint(2,0));
  }

}


void Music(int level){
    unsigned int keysPlaying = 0;

// Loop through each key:

for (int i = 0; i < NUM_OF_KEYS; ++i) {

// If the capacitance reading is greater than the threshold, play a note:

long c = keys[i].capacitiveSensor(NUM_OF_SAMPLES);

if(c > CAP_THRESHOLD) {

tone(BUZZER_PIN, notes[i]*level); // Plays the note corresponding to the key pressed

keysPlaying++;

}

}

if (keysPlaying == 0) {

noTone(BUZZER_PIN);

}
}

    
int powint(int x, int y)
{
 int val=x;
 for(int z=0;z<=y;z++)
 {
   if(z==0)
     val=1;
   else
     val=val*x;
 }
 return val;
}
