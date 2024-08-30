/*
*This is a very basic code for Arduino based Line Follower Robot
*/

#define IR_SENSOR_RIGHT 2
#define IR_SENSOR_LEFT 4
#define MOTOR_SPEED 30

int enableRightMotor=6;
int rightMotorPin1=8;
int rightMotorPin2=7;

//Left motor
int enableLeftMotor=9;
int leftMotorPin1=10;
int leftMotorPin2=11;



void setup() {
  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);


  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);

  if (rightIRSensorValue == LOW && leftIRSensorValue == LOW)
  {
    Serial.println("Straight");
    rotateMotor(1, 1);
  }
  else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH)
  {
    Serial.println("Left");
    rotateMotor(1, 0);
  }
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW)
  {
    Serial.println("Right");
    rotateMotor(0, 1);
  }
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == HIGH)
  {
    Serial.println("Test");
    rotateMotor(0, 0);
  }
}


void rotateMotor(int rightMotor, int leftMotor)
{

  analogWrite(enableRightMotor, abs(50));
  analogWrite(enableLeftMotor, abs(50));   
  //Right Motor
  if (rightMotor < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotor > 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }


  //Left Motor
  if (leftMotor < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotor > 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }
  else 
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  } 
}