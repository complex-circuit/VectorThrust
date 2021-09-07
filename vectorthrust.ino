#include <Servo.h>
Servo elevVec;
Servo ruddVec;
void setup() {
  pinMode(5,INPUT);
  pinMode(4,INPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(11,INPUT);
  elevVec.attach(8);
  ruddVec.attach(7);

}
int v=0;
void loop() {int l=pulseIn(5,HIGH,30000);
  if(l>100)
    v=l;
  if(v>1900){
    int elev=(pulseIn(4,HIGH)-994)*180/994;
    int rudd=(pulseIn(11,HIGH)-994)*180/994;
    elevVec.write(elev/2+45);
    ruddVec.write(rudd/2+45);
  }else{
    elevVec.write(90);
    ruddVec.write(90);
  }

}
