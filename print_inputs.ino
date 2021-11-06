
// DEFINE PINS

// analog inputs
#define JOYSTICK_LEFT_X   A9
#define JOYSTICK_LEFT_Y   A8
#define JOYSTICK_RIGHT_X  A12
#define JOYSTICK_RIGHT_Y  A13
#define LINEAR_POT_LEFT   A4
#define LINEAR_POT_RIGHT  A3
#define ROTARY_POT_TOP    A5
#define ROTARY_POT_MID    A6
#define ROTARY_POT_BOTTOM A7
// digital inputs
#define LEVER_SWITCH_LEFT  5 
#define LEVER_SWITCH_MID   7
#define LEVER_SWITCH_RIGHT 4 
#define PUSH_BUTTON_lEFT   6
#define PUSH_BUTTON_RIGHT  8

void setup() {
  Serial.begin(9600);

  pinMode(JOYSTICK_LEFT_X, INPUT);
  pinMode(JOYSTICK_LEFT_Y, INPUT);
  pinMode(JOYSTICK_RIGHT_X, INPUT);
  pinMode(JOYSTICK_RIGHT_Y, INPUT);
  pinMode(LINEAR_POT_LEFT, INPUT);
  pinMode(LINEAR_POT_RIGHT, INPUT);
  pinMode(ROTARY_POT_TOP, INPUT);
  pinMode(ROTARY_POT_MID, INPUT);
  pinMode(ROTARY_POT_BOTTOM, INPUT);

  pinMode(LEVER_SWITCH_LEFT, INPUT_PULLUP);
  pinMode(LEVER_SWITCH_MID, INPUT_PULLUP);
  pinMode(LEVER_SWITCH_RIGHT, INPUT_PULLUP);
  pinMode(PUSH_BUTTON_lEFT, INPUT_PULLUP);
  pinMode(PUSH_BUTTON_RIGHT, INPUT_PULLUP);
}

void loop() {
  delay(50);
  Serial.print(digitalRead(LEVER_SWITCH_LEFT));
  Serial.print(" , ");
  Serial.print(digitalRead(LEVER_SWITCH_MID));
  Serial.print(" , ");
  Serial.print(digitalRead(LEVER_SWITCH_RIGHT));
  Serial.print(" , ");
  Serial.print(digitalRead(PUSH_BUTTON_lEFT));    
  Serial.print(" , ");
  Serial.print(digitalRead(PUSH_BUTTON_RIGHT));    
  Serial.print(" , ");
  Serial.print(analogRead(JOYSTICK_LEFT_X));
  Serial.print(" , ");
  Serial.print(analogRead(JOYSTICK_LEFT_Y));
  Serial.print(" , ");
  Serial.print(analogRead(JOYSTICK_RIGHT_X));
  Serial.print(" , ");
  Serial.print(analogRead(JOYSTICK_RIGHT_Y));
  Serial.print(" , ");
  Serial.print(analogRead(LINEAR_POT_LEFT));
  Serial.print(" , ");
  Serial.print(analogRead(LINEAR_POT_RIGHT));
  Serial.print(" , ");
  Serial.print(analogRead(ROTARY_POT_TOP));
  Serial.print(" , ");
  Serial.print(analogRead(ROTARY_POT_MID));
  Serial.print(" , ");
  Serial.print(analogRead(ROTARY_POT_BOTTOM));
  Serial.println();
}
