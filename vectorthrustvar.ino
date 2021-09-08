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
    double V=(v-994)/994.0;
    if(V>1)
      V=1;
    if(V<0)
      V=0;
  
    int elev=(pulseIn(4,HIGH)-994)*180*V/994;
    int rudd=(pulseIn(11,HIGH)-994)*180*V/994;
    elev+=90*(1-V);
    rudd+=90*(1-V);
    //V is between 0 and 1. 1 is centered thrust, and 0 is vectored thrust.
    //The next 4 one-line if statements are safeties because the elevator was glitching
    //and would have resulted in the plane being unable to fly safely.
    elev=elev/2+45;
    rudd=rudd/2+45;
    if(elev>135)elev=135;
    if(elev< 45)elev= 45;
    if(rudd>135)rudd=135;
    if(rudd< 45)rudd= 45;
    
    elevVec.write(elev);
    ruddVec.write(rudd);
 
  

}
