#include <SCoop.h>
defineTask(TaskTest1);//定义子线程1
defineTask(TaskTest2);//定义子线程2

const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

const int s1Pin = 2;
const int s2Pin = 3;
const int s3Pin = 4;
const int s4Pin = 5;
const int s5Pin = 6;
const int s6Pin = 7;
const int s7Pin = 8;
const int s8Pin = 9;
const int s9Pin = 10;
const int s10Pin = 11;
const int s11Pin = 12;
const int s12Pin = 13;

const int PWMPin = A4;
const int TestPin = A4;
const int outLED = A1;
const int outSEG = A2;

const int pwmPeriod = 1;

int s1State = 0;     
int s2State = 0; 
int s3State = 0; 
int s4State = 0; 
int s5State = 0; 
int s6State = 0; 
int s7State = 0; 
int s8State = 0; 
int s9State = 0; 
int s10State = 0; 
int s11State = 0; 
int s12State = 0; 

int lastState = 0; 
int nowState = 0;
int loopp = 0;


void TaskTest1::setup()//线程1设定
{
  // initialize the button pin as a input:
  pinMode(s1Pin, INPUT);
  pinMode(s2Pin, INPUT);
  pinMode(s3Pin, INPUT);
  pinMode(s4Pin, INPUT);
  pinMode(s5Pin, INPUT);
  pinMode(s6Pin, INPUT);
  pinMode(s7Pin, INPUT);
  pinMode(s8Pin, INPUT);
  pinMode(s9Pin, INPUT);
  pinMode(s10Pin, INPUT);
  pinMode(s11Pin, INPUT);
  pinMode(s12Pin, INPUT);
  

  // initialize serial communication:
  Serial.begin(9600);
}


void checkState(){

  // read the pushbutton input pin:
  s1State = digitalRead(s1Pin);
  s2State = digitalRead(s2Pin);
  s3State = digitalRead(s3Pin);
  s4State = digitalRead(s4Pin);
  s5State = digitalRead(s5Pin);
  s6State = digitalRead(s6Pin);
  s7State = digitalRead(s7Pin);
  s8State = digitalRead(s8Pin);
  s9State = digitalRead(s9Pin);
  s10State = digitalRead(s10Pin);
  s11State = digitalRead(s11Pin);
  s12State = digitalRead(s12Pin);
  
  if(s1State == HIGH){
    nowState = 1;
    Serial.println("nowState == 1");
  }else if(s2State == HIGH){
    nowState = 2;  
    Serial.println("nowState == 2");
  }else if(s3State == HIGH){
    nowState = 3;  
    Serial.println("nowState == 3");
  }else if(s4State == HIGH){
    nowState = 4;  
    Serial.println("nowState == 4");
  }else if(s5State == HIGH){
    nowState = 5;  
    Serial.println("nowState == 5");
  }else if(s6State == HIGH){
    nowState = 6;  
    Serial.println("nowState == 6");
  }else if(s7State == HIGH){
    nowState = 7;  
    Serial.println("nowState == 7");
  }else if(s8State == HIGH){
    nowState = 8; 
    Serial.println("nowState == 8"); 
  }else if(s9State == HIGH){
    nowState = 9;  
    Serial.println("nowState == 9");
  }else if(s10State == HIGH){
    nowState = 10;  
    Serial.println("nowState == 10");
  }else if(s11State == HIGH){
    nowState = 11;  
    Serial.println("nowState == 11");
  }else if(s12State == HIGH){
    nowState = 12;  
    Serial.println("nowState == 12");
  }else{  
    Serial.println("check State nowState");
    Serial.println(nowState);
  }
}

void TaskTest1::loop()//线程1循环
{
   checkState();
 
  // compare the buttonState to its previous state
  if (nowState != lastState) {
    Serial.println("laststate!=nowState");
    analogWrite(outSEG, 0);
    for(loopp = 0; loopp<20; loopp++){

      checkState();
      
      if(nowState == lastState){
        Serial.println("goback");
      }else{
        analogWrite(outLED, 255);
        sleep(500);
        analogWrite(outLED, 0);
        sleep(500);        
      }
    }
    lastState = nowState;
    
    Serial.println(lastState);
    analogWrite(outSEG, 255);
    
    
  }else{
    analogWrite(outSEG, 255);
    Serial.println("laststate====nowState");
  }

}

void TaskTest2::setup()//线程2设定
{
  
}
void TaskTest2::loop()//线程2循环
{

    analogWrite(PWMPin, 255);
    sleep(2);
    analogWrite(PWMPin, 0);
    sleep(1);

}
void setup() {
  mySCoop.start();
}

void loop()
{
  yield();
}
