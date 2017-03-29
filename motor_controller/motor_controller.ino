//motor A connected between A01 and A02
//motor B connected between B01 and B02

int STBY = 11; //standby

//Motor A
int PWMA = 9; //Speed control 
int AIN1 = 5; //Direction
int AIN2 = 6; //Direction

//Motor B
int PWMB = 10; //Speed control
int BIN1 = 7; //Direction
int BIN2 = 8; //Direction

void setup(){
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

void loop(){
  go_forward(255);
  delay(1000); //go for 1 second
  stop(); //stop
  delay(250); //hold for 250ms until move again

  go_backward(128);
  delay(1000);
  stop();
  delay(250);
  
  go_left(200);
  delay(1000);
  stop();
  delay(250);

  go_right(200);
  delay(1000);
  stop();
  delay(250);

}

void go_forward(int speed){
  move(1, speed, 1); 
  move(2, speed, 1); 
}

void go_backward(int speed){
  move(1, speed, 0);
  move(2, speed, 0);
}

void go_left(int speed){
  move(1, speed,1);
}

void go_right(int speed){
  move(2, speed,1);
}

void move(int motor, int speed, int direction){
//Move specific motor at speed and direction
//motor: 0 for B 1 for A
//speed: 0 is off, and 255 is full speed
//direction: 0 clockwise, 1 counter-clockwise

  digitalWrite(STBY, HIGH); //disable standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }else{
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }
}

void stop(){
//enable standby  
  digitalWrite(STBY, LOW); 
}
