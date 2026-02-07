#include <Servo.h>

// ---------- Ultrasonic Pins ----------
#define trigPin 12
#define echoPin 13

// ---------- Motor Driver Pins ----------
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENA 5
#define ENB 6

// ---------- Servo Pin ----------
#define servoPin 3

// ---------- Variables ----------
long duration;
int distance;
int threshold = 20;

int forwardSpeed = 160;
int turnSpeed = 140;

Servo scanServo;

// ---------- Setup ----------
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  scanServo.attach(servoPin);
  scanServo.write(90);   // Center servo

  analogWrite(ENA, forwardSpeed);
  analogWrite(ENB, forwardSpeed);

  stopRobot();
}

// ---------- Main Loop ----------
void loop() {
  distance = readDistance();

  if (distance > threshold) {
    moveForward();
  } else {
    avoidObstacle();
  }
}

// ---------- Distance Measurement ----------
int readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 25000);

  if (duration == 0) return 100;

  return duration * 0.034 / 2;
}

// ---------- Movement Functions ----------
void moveForward() {
  analogWrite(ENA, forwardSpeed);
  analogWrite(ENB, forwardSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  analogWrite(ENA, forwardSpeed);
  analogWrite(ENB, forwardSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  analogWrite(ENA, turnSpeed);
  analogWrite(ENB, turnSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {
  analogWrite(ENA, turnSpeed);
  analogWrite(ENB, turnSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// ---------- Obstacle Avoidance Logic ----------
void avoidObstacle() {
  stopRobot();
  delay(200);

  moveBackward();
  delay(350);

  stopRobot();
  delay(200);

  // Look Left
  scanServo.write(150);
  delay(400);
  int leftDistance = readDistance();

  // Look Right
  scanServo.write(30);
  delay(400);
  int rightDistance = readDistance();

  // Center Sensor
  scanServo.write(90);
  delay(200);

  // Decide direction
  if (leftDistance > rightDistance) {
    turnLeft();
    delay(500);
  } else {
    turnRight();
    delay(500);
  }

  stopRobot();
}
