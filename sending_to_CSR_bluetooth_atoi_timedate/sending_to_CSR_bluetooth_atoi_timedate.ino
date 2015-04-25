#include <Time.h>  
int incomingByte=0;
void setup(){
Serial.begin(9600);
}
void loop(){
  char buffer[20];
  uint8_t bufMidi[4]={'1','6','.','0'};
 uint16_t buf=atof((char *)bufMidi)*18;
 //sprintf(buf, "%d", atoi(bufMidi));
// Serial.print(buf);
// Serial.print("In byte: ");
 Serial.write("abc"); 
 //Serial.print("Hello world");
 
 if(buf<255){
 Serial.write(0);
 }
 else{
 Serial.write(buf>>8);
 }
 Serial.write(buf);

 if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte, HEX);
        }
  delay(100);
 
tmElements_t tm;
tm.Month = 12;
tm.Hour = 23;
tm.Minute = 45;
tm.Year = 2015-1970;
tm.Second = 30;
tm.Day = 12;
time_t t = makeTime(tm);
uint32_t timeint = t;
//Serial.println(timeint);

uint8_t timeH = timeint>>24;
Serial.write(timeH);
uint8_t timeM1 = (timeint & 0xFF0000)>>16;
Serial.write(timeM1);
uint8_t timeM2 = (timeint & 0xFF00)>>8;
Serial.write(timeM2);
uint8_t timeL = timeint & 0xFF;
Serial.write(timeL);

while(1){};
 
}
