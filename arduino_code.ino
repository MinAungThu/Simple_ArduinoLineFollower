#include <Servo.h>

#define e1 10
#define m1 5
#define m2 4
#define e2 9
#define m3 2
#define m4 3

#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4

const int trig = 7;
const int echo = 6;

const int servoPin = 12;
Servo myServo;
bool servoActivated = false;

int stopCounter = 0;
bool allSensorsBlack = false;
bool carStarted = false;

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myServo.attach(servoPin);
  myServo.write(0);
}

void loop() {
  if (!carStarted && detectObject()) {
    delay(8000);
    carStarted = true;
  }

  if (!carStarted) {
    stopMotors();
    return;
  }

  if (stopCounter >= 30) {
    stopMotors();
    myServo.write(180);
    return;
  }

  int s1 = digitalRead(ir1);
  int s2 = digitalRead(ir2);
  int s3 = digitalRead(ir3);
  int s4 = digitalRead(ir4);
  int s5 = digitalRead(ir5);

  if ((s1 == 1) && (s2 == 1) && ((s3 == 0) || (s3 == 1)) && (s4 == 1) && (s5 == 1)) {
    driveMotors(200, 200, HIGH, LOW, HIGH, LOW);
  } else if ((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1)) {
    driveMotors(250, 250, HIGH, LOW, LOW, LOW);
  } else if ((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1)) {
    driveMotors(250, 250, HIGH, LOW, LOW, HIGH);
  } else if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1)) {
    driveMotors(250, 250, LOW, LOW, HIGH, LOW);
  } else if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0)) {
    driveMotors(250, 250, LOW, HIGH, HIGH, LOW);
  } else if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1)) {
    driveMotors(250, 250, LOW, LOW, HIGH, LOW);
  } else if ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1)) {
    driveMotors(250, 250, HIGH, LOW, LOW, LOW);
  } else if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1)) {
    driveMotors(250, 250, HIGH, LOW, LOW, LOW);
  } else if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0)) {
    driveMotors(250, 250, LOW, LOW, HIGH, LOW);
  } else if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0)) {
    stopMotors();
    if (!allSensorsBlack) {
      stopCounter++;
      allSensorsBlack = true;
      myServo.write(180);
    }
  } else {
    allSensorsBlack = false;
  }
}

void driveMotors(int speed1, int speed2, int dir1, int dir2, int dir3, int dir4) {
  analogWrite(e1, speed1);
  analogWrite(e2, speed2);
  digitalWrite(m1, dir1);
  digitalWrite(m2, dir2);
  digitalWrite(m3, dir3);
  digitalWrite(m4, dir4);
}

void stopMotors() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

bool detectObject() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  int distance = duration * 0.034 / 2;
  return distance > 0 && distance <= 10;
}
