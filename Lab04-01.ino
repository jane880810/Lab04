//Lab04-01
#include "SevSeg.h"
SevSeg sevseg;
byte numDigits = 4;
byte digitPins[] = {16, 3, 4, 5};//3 2 1 0
byte segmentPins[] = { 7, 8, 9, 10, 11, 12, 13, 14};
int Hour=0,Min=0,j;
const int SW = 6;
void setup() {
  
  pinMode(SW, INPUT);
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);//亮度

}

void loop() {
  
  sevseg.setNumber(Hour * 100 + Min, 4);
    Min = Min + 1;
    j = digitalRead(SW);
    if (j == 1) 
        Hour=0,Min=0;

    if (Min == 60) {
        Min = 0;
        if (Hour == 23)
            Hour=0;
        else
            Hour++;
      }
    j = digitalRead(SW);
    if (j == 1) 
        Hour=0,Min=0;
        
    for(int i = 0 ; i<=499524 ; i++){
        sevseg.refreshDisplay();//delay
    j = digitalRead(SW);
    if (j == 1) 
        Hour=0,Min=0;}
 
}
