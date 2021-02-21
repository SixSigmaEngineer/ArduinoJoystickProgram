// Script Name: Joystick Relay Control: Control Relay with Switch Type Joystick
// First define Inputs
#define NORTH 2 // the pin for NORTH Input
#define SOUTH 3 // the pin for SOUTH Input
#define EAST 4 // the pin for EAST Input
#define WEST 5 // the pin for WEST Input 
//Now define outputs
#define RF 6 // the pin for RF
#define RB 7 // the pin for RB
#define LF 8 // the pin for LF
#define LB 9 // the pin for LB

// Joystick is connected so define initial values below

int NORTHINP1 = 0; // val will be used to store the state of the input pin 1
int SOUTHINP1 = 0; // val will be used to store the state of the input pin 2
int EASTINP1 = 0; // val will be used to store the state of the input pin 3
int WESTINP1 = 0; // val will be used to store the state of the input pin 4

// Now run the setup script
void setup() {
pinMode(RF, OUTPUT); // tell Arduino Right Joy Forwards is an output for Relay
pinMode(RB, OUTPUT); // tell Arduino Right Joy Backwards is an output for Relay
pinMode(LF, OUTPUT); // tell Arduino Left Joy Forwards is an output for Relay
pinMode(LB, OUTPUT); // tell Arduino Left Joy Backwards is an output for Relay
pinMode(NORTH, INPUT); // and NORTH is an input
pinMode(SOUTH, INPUT); // and SOUTH is an input
pinMode(EAST, INPUT); // and EAST is an input
pinMode(WEST, INPUT); // and WEST is an input
}

void loop(){
  // Check NORTH Input and Trigger Output.
NORTHINP1 = digitalRead(NORTH); // read input value and store it
// check whether the input is HIGH (button pressed or joy triggered)
if (NORTHINP1 == HIGH) {
digitalWrite(RF, HIGH); // turn RF ON
digitalWrite(LF, HIGH); // turn LF ON
// Both RF and LF turn on both motors and propel forwards. 
} else {
digitalWrite(RF, LOW);
digitalWrite(LF, LOW);
}
  // Check SOUTH Input and Trigger Output.
SOUTHINP1 = digitalRead(SOUTH); // read input value and store it
// check whether the input is HIGH (button pressed or joy triggered)
if (SOUTHINP1 == HIGH) {
digitalWrite(RB, HIGH); // turn RB ON
digitalWrite(LB, HIGH); // turn LB ON
// Both RB and LB turn on both motors and propel backwards. 
} else {
digitalWrite(RB, LOW);
digitalWrite(LB, LOW);
}
  // Check EAST Input and Trigger Output.
EASTINP1 = digitalRead(EAST); // read input value and store it
// check whether the input is HIGH (button pressed or joy triggered)
if (EASTINP1 == HIGH) {
digitalWrite(RB, HIGH); // turn RB ON
digitalWrite(LF, HIGH); // turn LF ON
// Both RB and LF turn on both motors and turn right to go East.
} else {
digitalWrite(RB, LOW);
digitalWrite(LF, LOW);
}
  // Check WEST Input and Trigger Output.
WESTINP1 = digitalRead(WEST); // read input value and store it
// check whether the input is HIGH (button pressed or joy triggered)
if (WESTINP1 == HIGH) {
digitalWrite(RF, HIGH); // turn RF ON
digitalWrite(LB, HIGH); // turn LB ON
// Both RF and LB turn on both motors and turn Left or West.
} else {
digitalWrite(RF, LOW);
digitalWrite(LB, LOW);
}
}
