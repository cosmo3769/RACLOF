#define lc 0
#define sc 1

//Pins specified for right motor
const int motorRPin1 = 3;
const int motorRPin2 = 5;


//Pins specified for left motor
const int motorLPin1 = 10;
const int motorLPin2 = 11;

int s1, s2, s3, s4, s5, s6, s7, s8;

int left = 0;
int right = 0;
//int leftthres=300;
//int rightthres=30.0;
int breakcount = 0;
int brakethres = 50;

//Setup for line following robot
void setup() {
  //for pinMode for right motor
  pinMode(motorRPin1, OUTPUT);
  pinMode(motorRPin2, OUTPUT);

  //for pinMode for left motor
  pinMode(motorLPin1, OUTPUT);
  pinMode(motorLPin2, OUTPUT);
}

void loop() {

  readsensors();


  if (s1 == lc && s2 == lc) {
    left = 5;
    right = 0;
  }
  if (s7 == lc && s8 == lc) {
    right = 5;
    left = 0;
  }

  if ((s3 == sc) && (s4 == lc) && (s5 == lc) && (s6 == sc)) {
    go();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }

  else if ((s3 == lc) && (s4 == lc) && (s5 == lc) && (s6 == sc))
  {
    left_05();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s3 == sc) && (s4 == lc) && (s5 == lc) && (s6 == lc)) {
    right_05();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s3 == sc) && (s4 == lc) && (s5 == sc) && (s6 == sc)) {
    left_10();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s3 == sc) && (s4 == sc) && (s5 == lc) && (s6 == sc)) {
    right_10();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s2 == sc) && (s3 == lc) && (s4 == lc) && (s5 == sc)) {
    left_15();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s4 == sc) && (s5 == lc) && (s6 == lc) && (s7 == sc)) {
    right_15();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s2 == lc) && (s3 == lc) && (s4 == lc) && (s5 == sc)) {
    left_20();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s4 == sc) && (s5 == lc) && (s6 == lc) && (s7 == lc)) {
    right_20();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s2 == sc) && (s3 == lc) && (s4 == sc) && (s5 == sc)) {
    left_25();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s4 == sc) && (s5 == sc) && (s6 == lc) && (s7 == sc)) {
    right_25();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }

  else if ((s1 == sc) && (s2 == lc) && (s3 == lc) && (s4 == sc)) {
    left_30();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s5 == sc) && (s6 == lc) && (s7 == lc) && (s8 == sc)) {
    right_30();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s1 == lc) && (s2 == lc) && (s3 == lc) && (s4 == sc)) {
    left_35();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s5 == sc) && (s6 == lc) && (s7 == lc) && (s8 == lc)) {
    right_35();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s1 == sc) && (s2 == lc) && (s3 == sc) && (s4 == sc)) {
    left_40();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s5 == sc) && (s6 == sc) && (s7 == lc) && (s8 == sc)) {
    right_40();
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s1 == lc) && (s2 == lc) && (s3 == sc)) {
    left_45;
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  else if ((s6 == sc) && (s7 == lc) && (s8 == lc)) {
    right_45;
    if (breakcount > 0) {
      breakcount = 0;
    }
  }

  if ((s1 == lc) && (s2 == sc) && (s8 == sc)) {
    left_50;
    if (breakcount > 0) {
      breakcount = 0;
    }
  }
  if ((s1 == sc) && (s7 == sc) && (s8 == lc)) {
    right_50;
    if (breakcount > 0) {
      breakcount = 0;
    }
  }



  //   INTERSECTION
  if (s1 == lc && s2 == lc && s7 == lc && s8 == lc) {
    breakcount++;
    go();
    readsensors();
    if (breakcount >= 1000) { //for braking
      stopme();
      delay(10000);
    }
  }


  //   BIG TURNS
  if ((s1 != lc) && (s2 != lc) && (s3 != lc) && (s4 != lc) && (s5 != lc) && (s6 != lc) && (s7 != lc) && (s8 != lc)) {
    stopme();
    if (right == 5 && left == 0)
    {
      readsensors();
      while ((s4 != lc) && (s5 != lc))
      {
        right = 0;
        right_turn();
        readsensors();
      }
    }
    if (left == 5 && right == 0)
    {
      readsensors();
      while ((s4 != lc) && (s5 != lc))
      {
        left = 0;
        left_turn();
        readsensors();
      }
    }
  }
}


void readsensors() {
  s1 = digitalRead(A0);
  s2 = digitalRead(A1);
  s3 = digitalRead(A2);
  s4 = digitalRead(A3);
  s5 = digitalRead(A4);
  s6 = digitalRead(A5);
  s7 = digitalRead(2);
  s8 = digitalRead(4);
}

void go() {

  Serial.println("\tforward ");
  analogWrite(motorRPin1, 130);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 130);
  analogWrite(motorLPin2, 0);
}

void right_05() {

  Serial.println("\tleft turn");

  analogWrite(motorRPin1, 140);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 120);
  analogWrite(motorLPin2, 0);
}

void left_05() {

  Serial.println("\tright turn");

  analogWrite(motorRPin1, 120);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 140);
  analogWrite(motorLPin2, 0);
}

void right_10() {

  Serial.println("\tleft turn");

  analogWrite(motorRPin1, 145);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 115);
  analogWrite(motorLPin2, 0);
}

void left_10() {

  Serial.println("\tright turn");

  analogWrite(motorRPin1, 115);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 145);
  analogWrite(motorLPin2, 0);
}

void right_15() {

  Serial.println("\tleft turn");

  analogWrite(motorRPin1, 150);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 110);
  analogWrite(motorLPin2, 0);
}

void left_15() {

  Serial.println("\tright turn");

  analogWrite(motorRPin1, 110);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 150);
  analogWrite(motorLPin2, 0);
}

void right_20() {

  Serial.println("\tleft turn");

  analogWrite(motorRPin1, 155);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 105);
  analogWrite(motorLPin2, 0);
}

void left_20() {

  Serial.println("\tright turn");

  analogWrite(motorRPin1, 105);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 155);
  analogWrite(motorLPin2, 0);
}

void right_25() {

  Serial.println("\tleft turn");

  analogWrite(motorRPin1, 160);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 100);
  analogWrite(motorLPin2, 0);
}

void left_25() {

  Serial.println("\tright turn");

  analogWrite(motorRPin1, 100);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 160);
  analogWrite(motorLPin2, 0);
}

void right_30() {

  Serial.println("\tleft turn");

  analogWrite(motorRPin1, 165);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 95);
  analogWrite(motorLPin2, 0);
}

void left_30() {

  Serial.println("\tright turn");

  analogWrite(motorRPin1, 95);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 165);
  analogWrite(motorLPin2, 0);
}

void right_35() {

  Serial.println("\tleft turn");

  analogWrite(motorRPin1, 170);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 90);
  analogWrite(motorLPin2, 0);
}

void left_35() {

  Serial.println("\tright turn");

  analogWrite(motorRPin1, 90);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 170);
  analogWrite(motorLPin2, 0);
}

void right_40() {

  Serial.println("\tleft turn");

  analogWrite(motorRPin1, 175);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 85);
  analogWrite(motorLPin2, 0);
}

void left_40() {

  Serial.println("\tright turn");

  analogWrite(motorRPin1, 85);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 175);
  analogWrite(motorLPin2, 0);
}

void right_45() {

  Serial.println("\tleft turn");

  analogWrite(motorRPin1, 180);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 80);
  analogWrite(motorLPin2, 0);
}

void left_45() {

  Serial.println("\tright turn");

  analogWrite(motorRPin1, 80);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 180);
  analogWrite(motorLPin2, 0);
}

void right_50() {

  Serial.println("\tleft turn");

  analogWrite(motorRPin1, 185);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 75);
  analogWrite(motorLPin2, 0);
}

void left_50() {

  Serial.println("\tright turn");

  analogWrite(motorRPin1, 75);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 185);
  analogWrite(motorLPin2, 0);
}

void left_turn() {

  Serial.println("\tleft turn");

  analogWrite(motorRPin1, 0);
  analogWrite(motorRPin2, 110);

  analogWrite(motorLPin1, 110);
  analogWrite(motorLPin2, 0);
}

void right_turn() {

  Serial.println("\tright turn");

  analogWrite(motorRPin1, 110);
  analogWrite(motorRPin2, 0);

  analogWrite(motorLPin1, 0);
  analogWrite(motorLPin2, 110);
}

void stopme() {

  Serial.println("\tstop");

  analogWrite(motorRPin1, 255);
  analogWrite(motorRPin2, 255);

  analogWrite(motorLPin1, 255);
  analogWrite(motorLPin2, 255);
}
