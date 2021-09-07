My brother asked me to write a program for an Arduino Nano to control the vectored thrust on his model F-16.
After accidentally clicking on a reading on how standard servo commands work, while trying to find info on
how to control a specific non-standard servo, I was able to accomplish this goal by making the arduino nano essentially eavesdrop on the servo commands.

Pinout:
=======
The pinout is the same regardless of which .ino file you compile for your arduino or arduino compatible development board.

The input pins are listening for servo commands within a range of 90deg centered on 90deg. Each output pin has a Servo object attached.

* Pin 5 is an input, for the switch or knob to toggle or adjust the vector thrust.
* Pin 4 is the elevator input, aka elev.
* Pin 11 is the rudder input aka rudd.
* Pin 8 is the elevator thrust vector output aka elevVec.
* Pin 7 is the rudder thrust vector output aka ruddVec.

Wiring suggestions:
-------------------
* I suggest that the channel that the Arduino gets the power line from the channel that connects to pin 5.
* For the elevator and rudder wires, it is best if you don't cut the power lines of the Y-harness.
After one branches off to the control surface, the other one will be for the vectored thrust.
This is where you cut the data line.
* Reruote the channel from the Y-harness to the pin on the Arduino
* The line that goes to the servo is the corresponding output pin on the Arduino. Reference the pinout section or photo of the table. 

Warning:
--------
The system is a little bit glitchy, and if you give it full elevator, it sometimes moves the vectored thrust more than it is supposed to.
With vectorthrustvar.ino, this sometimes happens even if you turn the vector thrust completely off.
I don't know why it is doing this. If you do, then please leave a comment on this repository.
