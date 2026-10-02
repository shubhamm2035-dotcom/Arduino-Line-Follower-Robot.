/*
 * Project: Basic Arduino Line Follower Robot
 * Hardware: Arduino UNO, L298N Motor Driver, 2x IR Sensors, 2x BO Motors
 * 
 * Description: 
 * This code controls a robot to follow a black line on a white surface.
 * It reads data from two IR sensors and commands the motor driver 
 * to steer left, right, or go straight based on the sensor logic.
 */

// --- Pin Definitions ---

// Motor Driver (L298N) Pins - IN1 to IN4 control the motor directions
const int in1 = 8;   // Right Motor Forward
const int in2 = 9;   // Right Motor Backward
const int in3 = 10;  // Left Motor Backward
const int in4 = 11;  // Left Motor Forward

// IR Sensor Pins
const int leftSensor = 2;   // Left IR sensor connected to Digital Pin 2
const int rightSensor = 3;  // Right IR sensor connected to Digital Pin 3

// --- Setup Function ---
// Runs once when the Arduino is powered on or reset.
void setup() {
  // Set motor pins as OUTPUTs (we send commands out to the motor driver)
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Set sensor pins as INPUTs (we read data in from the sensors)
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  
  // Optional: Start Serial Monitor for debugging
  Serial.begin(9600);
  Serial.println("Line Follower Robot Started!");
}

// --- Main Loop Function ---
// Runs repeatedly as long as the Arduino has power.
void loop() {
  // Read sensor values (HIGH or LOW)
  int leftValue = digitalRead(leftSensor);
  int rightValue = digitalRead(rightSensor);

  /* 
   * LOGIC EXPLANATION:
   * (Assuming Black Line = HIGH (1), White Surface = LOW (0))
   * Note: Some IR sensors work in reverse (Black = LOW). 
   * If your robot acts weird, swap HIGH and LOW in the if conditions.
   */

  // Condition 1: Both sensors on White -> Go Straight
  if (leftValue == LOW && rightValue == LOW) {
    moveForward();
  }
  // Condition 2: Left sensor on Black line -> Turn Left
  else if (leftValue == HIGH && rightValue == LOW) {
    turnLeft();
  }
  // Condition 3: Right sensor on Black line -> Turn Right
  else if (leftValue == LOW && rightValue == HIGH) {
    turnRight();
  }
  // Condition 4: Both sensors on Black line -> Stop (End of line/intersection)
  else if (leftValue == HIGH && rightValue == HIGH) {
    stopRobot();
  }
}

// --- Movement Functions ---

void moveForward() {
  // Right Motor Forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Left Motor Forward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  // Note: in3 and in4 logic depends on how you wired your left motor. 
  // If one side spins backward, swap its HIGH/LOW here.
}

void turnLeft() {
  // Right Motor Forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Left Motor Stop (or spin backward for sharper turn)
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void turnRight() {
  // Right Motor Stop (or spin backward)
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // Left Motor Forward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopRobot() {
  // All motors stop
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
