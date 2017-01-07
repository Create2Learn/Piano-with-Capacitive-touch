
#include <CapacitiveSensor.h>
#include "pitches.h"

#define COMMON_PIN      2    // The common 'send' pin for all keys
#define BUZZER_PIN      9   // The output pin for the piezo buzzer
#define NUM_OF_SAMPLES  30   // Higher number whens more delay but more consistent readings
#define CAP_THRESHOLD   60  // Capactive reading that triggers a note (adjust to fit your needs)
#define NUM_OF_KEYS     8    // Number of keys that are on the keyboar


//// Each key corresponds to a note, which are defined here. Uncomment the scale that you want to use:
////int notes[]={NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5}; // C-Major scale
////int notes[]={NOTE_A4,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_A5}; // A-Minor scale
int notes[]={NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_FS4,NOTE_G4,NOTE_AS4,NOTE_C5,NOTE_DS5}; // C Blues scale

CapacitiveSensor   cs_3_2 = CapacitiveSensor(2,3);

CapacitiveSensor   cs_4_2 = CapacitiveSensor(2,4);
CapacitiveSensor   cs_5_2 = CapacitiveSensor(2,5);

CapacitiveSensor   cs_6_2 = CapacitiveSensor(2,6);

void setup()
{
   cs_3_2.set_CS_AutocaL_Millis(0xFFFFFFFF); //Calibrate the sensor... 
   cs_5_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
   
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); //Calibrate the sensor... 
   cs_6_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
   pinMode(BUZZER_PIN, OUTPUT);
   Serial.begin(9600);
}

void loop()                    
{
    long total1 =  cs_3_2.capacitiveSensor(30);
    long total2 =  cs_4_2.capacitiveSensor(30);
long total3 =  cs_5_2.capacitiveSensor(30);
    long total4 =  cs_6_2.capacitiveSensor(30);
    
    
if(total1>60){
  tone(BUZZER_PIN, notes[5]);
}
else if(total2>60){
  tone(BUZZER_PIN, notes[6]);
}

else if(total3>60){
  tone(BUZZER_PIN, notes[7]);
}
else if(total4>60){
  tone(BUZZER_PIN, notes[8]);
}
delay(200);
noTone(BUZZER_PIN);
}

