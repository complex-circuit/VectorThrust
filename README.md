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

Bug Fixes:
----------
* The previous version of vectorthrustvar.ino was a bit glitchy and would occasionally do something a bit wonky
when I turned the thrust vector to full and pulled full elevator. I found out that it was because it passed a number
greater than the max to elevVec.write() and there were overflow problems sending the servo in the wrong direction.
I fixed this by adding safeties that pull values that are beyond a full extend to the closest full extend.
