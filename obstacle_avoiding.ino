
#include<AFMotor.h>
#include<Servo.h>

AF_DCMotor motor1 (1);
AF_DCMotor motor2 (2);
AF_DCMotor motor3 (3);
AF_DCMotor motor4 (4);
Servo servo;
int trig = A0;
int echo = A2;
int pingTravelTime,e=5;
float d, a, b, c;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(10);
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  for (int j = 0; j < 10; j++) {
    digitalWrite(trig, LOW);
    delayMicroseconds(10);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    pingTravelTime = pulseIn(echo, HIGH);
    d = (340. * pingTravelTime) * 100. / (2. * pow(10, 6));
    a = a + d;
    delay(25);
  }
  a = a / 10;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
    for (int j = 0; j < e; j++) {
      digitalWrite(trig, LOW);
      delayMicroseconds(10);
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);
      pingTravelTime = pulseIn(echo, HIGH);
      d = ((340. * pingTravelTime) * 100.) / (2. * pow(10, 6));
      a = a + d;
//      delay(25);
    }
    a = a / e;
  Serial.print("a = ");
  Serial.println(a);
    
  
  if (a <= 50) {
    motor1.setSpeed(0);
    motor2.setSpeed(0);
    motor3.setSpeed(0);
    motor4.setSpeed(0);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    servo.write(0);
    delay(100);
    for (int j = 0; j < e; j++) {
      digitalWrite(trig, LOW);
      delayMicroseconds(10);
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);
      pingTravelTime = pulseIn(echo, HIGH);
      d = ((340. * pingTravelTime) * 100.) / (2. * pow(10, 6));
      b = b + d;
      delay(50);
    }
    b = b / e;
//    Serial.print("b = ");
//    Serial.println(b);
    servo.write(180);
    for (int j = 0; j < e; j++) {
      digitalWrite(trig, LOW);
      delayMicroseconds(10);
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);
      pingTravelTime = pulseIn(echo, HIGH);
      d = ((340. * pingTravelTime) * 100.) / (2. * pow(10, 6));
      c = c + d;
      delay(50);
    }
    c = c / e;
//    Serial.print("c = ");
//    Serial.println(c);
    if (b > c) {
      motor1.setSpeed(255);
      motor2.setSpeed(255);
      motor3.setSpeed(255);
      motor4.setSpeed(255);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
      servo.write(90);
      delay(1000);
    } else if (b < c) {
      motor1.setSpeed(255);
      motor2.setSpeed(255);
      motor3.setSpeed(255);
      motor4.setSpeed(255);
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      servo.write(90);
      delay(1000);
    }
    for (int j = 0; j < e; j++) {
    digitalWrite(trig, LOW);
    delayMicroseconds(10);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    pingTravelTime = pulseIn(echo, HIGH);
    d = ((340. * pingTravelTime) * 100.) / (2. * pow(10, 6));
    a = a + d;
    delay(25);
  }
  a = a / e;
  if (a >= b || a >= c) {
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  }
  


}
