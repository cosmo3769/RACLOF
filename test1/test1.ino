#define lc 0
#define sc 1

//Pins specified for right motor
const int motorRPin1=3;
const int motorRPin2=5;


//Pins specified for left motor
const int motorLPin1=10;
const int motorLPin2=11;

int s1,s2,s3,s4,s5,s6,s7,s8;

int left=0;
int right=0;
int leftthres=20;
int rightthres=20;
int breakcount=0;
int brakethres=100;

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
 
  if((s3==sc)&&(s4==lc)&&(s5==lc)&&(s6==sc))
   go();
  else if((s3==lc)&&(s4==lc)&&(s5==lc)&&(s6==sc))
   left_05();
  else if((s3==sc)&&(s4==lc)&&(s5==lc)&&(s6==lc))
   right_05();
  else if((s2==sc)&&(s3==lc)&&(s4==lc)&&(s5==sc))
   left_10(); 
  else if((s4==sc)&&(s5==lc)&&(s6==lc)&&(s7==sc))
   right_10();
  
  else if((s2==lc)&&(s3==lc)&&(s4==lc)&&(s5==sc))
   left_15();
  else if((s4==sc)&&(s5==lc)&&(s6==lc)&&(s7==lc))
   right_15();
  else if((s1==sc)&&(s2==lc)&&(s3==lc)&&(s4==sc))
   left_20();
  else if((s5==sc)&&(s6==lc)&&(s7==lc)&&(s8==sc))
   right_20();
  
  else if((s1==lc)&&(s2==lc)&&(s3==lc)&&(s4==sc))
   left_25();
  else if((s5==sc)&&(s6==lc)&&(s7==lc)&&(s8==lc))
   right_25();   

  if (s1==lc){
    left = 0;
  }
  if (s8==lc){
    right = 0;
  }
   
  if(s1==lc && s2==lc && s7==lc && s8==lc) {
    go();
    breakcount++;
    if(breakcount>=brakethres){ //for braking
      stopme();
      breakcount=0;
    }
  }

  if ((s1!=lc)&&(s2!=lc)&&(s3!=lc)&&(s4!=lc)&&(s5!=lc)&&(s6!=lc)&&(s7!=lc)&&(s8!=lc)){
    stopme();
//delay(1000);
    if ((left>leftthres)&&(right<rightthres)){//right sharp turns

//    delay(2000);
//right_turn();
//    readsensors();
    while((s4!=lc)&&(s5!=lc)){
      right_turn();
      readsensors();
    }
    //delay(10);
    }
    else if ((left<leftthres)&&(right>rightthres)){//left sharp turn
//      stopme();
//      delay(2000);
        left_turn();

      readsensors();
      while((s4!=lc)&&(s5!=lc)){
        left_turn();
        readsensors();
      }
    }

  left=left+1;
  right=right+1;
}
}

void readsensors() {
  s1=digitalRead(A0);
  s2=digitalRead(A1);
  s3=digitalRead(A2);
  s4=digitalRead(A3);
  s5=digitalRead(A4);
  s6=digitalRead(A5);
  s7=digitalRead(2);
  s8=digitalRead(4);
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
 
  analogWrite(motorRPin1, 150);
  analogWrite(motorRPin2, 0);
     
  analogWrite(motorLPin1, 110);
  analogWrite(motorLPin2, 0);
}

void left_10() {
  
  Serial.println("\tright turn");
  
  analogWrite(motorRPin1, 110);
  analogWrite(motorRPin2, 0);
     
  analogWrite(motorLPin1, 150);
  analogWrite(motorLPin2, 0);
}

void right_15() {

  Serial.println("\tleft turn");
 
  analogWrite(motorRPin1, 160);
  analogWrite(motorRPin2, 0);
     
  analogWrite(motorLPin1, 100);
  analogWrite(motorLPin2, 0);
}

void left_15() {
  
  Serial.println("\tright turn");
  
  analogWrite(motorRPin1, 100);
  analogWrite(motorRPin2, 0);
     
  analogWrite(motorLPin1, 160);
  analogWrite(motorLPin2, 0);
}

void right_20() {

  Serial.println("\tleft turn");
 
  analogWrite(motorRPin1, 165);
  analogWrite(motorRPin2, 0);
    
  analogWrite(motorLPin1, 85);
  analogWrite(motorLPin2, 0);
}

void left_20() {
  
  Serial.println("\tright turn");
  
  analogWrite(motorRPin1, 85);
  analogWrite(motorRPin2, 0);
     
  analogWrite(motorLPin1, 165);
  analogWrite(motorLPin2, 0);
}

void right_25() {

  Serial.println("\tleft turn");
 
  analogWrite(motorRPin1, 170);
  analogWrite(motorRPin2, 0);
     
  analogWrite(motorLPin1, 90);
  analogWrite(motorLPin2, 0);
}

void left_25() {
  
  Serial.println("\tright turn");
  
  analogWrite(motorRPin1, 90);
  analogWrite(motorRPin2, 0);
     
  analogWrite(motorLPin1, 170);
  analogWrite(motorLPin2, 0);
}

void left_turn() {

  Serial.println("\tleft turn");
 
  analogWrite(motorRPin1, 0);
  analogWrite(motorRPin2, 125);
     
  analogWrite(motorLPin1, 125);
  analogWrite(motorLPin2, 0);
}

void right_turn() {
  
  Serial.println("\tright turn");
  
  analogWrite(motorRPin1, 125);
  analogWrite(motorRPin2, 0);
     
  analogWrite(motorLPin1, 0);
  analogWrite(motorLPin2, 125);
}

void stopme() {
  
  Serial.println("\tstop");
     
  analogWrite(motorRPin1, 255);
  analogWrite(motorRPin2, 255);
  
  analogWrite(motorLPin1, 255);
  analogWrite(motorLPin2, 255);
  
}


  

  
