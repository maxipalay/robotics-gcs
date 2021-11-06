#include <ros.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle  nh;

geometry_msgs::Twist twist;

ros::Publisher pub_joy("cmd_vel", &twist);
bool switches[5];
uint16_t pots[9];
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


unsigned long millis_prev;
unsigned long millis_now;

void setup() {
  

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

  nh.getHardware()->setBaud(57600);
  nh.initNode();
  nh.advertise(pub_joy);
  
  //Serial.begin(00);

  millis_now = millis();
  millis_prev = millis_now;
}


void loop() {
  millis_now = millis();
  if (millis_now - millis_prev >= 25){
    millis_prev = millis_now;
   

    twist.linear.x = analogRead(JOYSTICK_LEFT_Y)-500;
    if ((twist.linear.x > -50) && (twist.linear.x < 50)){
      twist.linear.x = 0;
    }
    twist.angular.z = analogRead(JOYSTICK_LEFT_X)-500;
        if ((twist.angular.z > -50) && (twist.angular.z < 50)){
      twist.angular.z = 0;
    }
    pub_joy.publish(&twist);
    nh.spinOnce();
    delayMicroseconds(20);
  }
  
}
