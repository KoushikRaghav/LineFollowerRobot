#define lmotorf 10
#define lmotorb 9
#define rmotorf 11
#define rmotorb 12
int enA = 6;
int enB = 5;
const int buzzer = 2;

//HIGH white
//LOW black

void setup() {
  
pinMode(lmotorf,OUTPUT);
pinMode(rmotorf,OUTPUT);
pinMode(lmotorb,OUTPUT);
pinMode(rmotorb,OUTPUT);
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(8,INPUT);
pinMode(7,INPUT);
pinMode(4,INPUT);
pinMode(3,INPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {

// dynamic line follower code
// if the sensor is on white it returns LOW value to the Arduino
// if it is on black it returns a HIGH value to the Arduino
int lsensor=digitalRead(8);
int rsensor=digitalRead(7);
int tsensor=digitalRead(4);
int fsensor=digitalRead(3);
if(fsensor==LOW)
{
tone(buzzer, 1000);
delay(1000);
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
noTone(buzzer);
}
else if(tsensor==HIGH)
{
tone(buzzer, 1000);
delay(1000);
analogWrite(enA,200);
analogWrite(enB,200);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
noTone(buzzer);
}
else if((lsensor==HIGH)&&(rsensor==HIGH))
{
//both sensors on white
// go forward
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((lsensor==HIGH)&& (rsensor==LOW))
{
//right sensor on black line
// turn right
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,HIGH);
}
else if((lsensor==LOW)&&(rsensor==HIGH))
{
//left sensor on black line
// turn left
digitalWrite(lmotorf,LOW);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,HIGH);
digitalWrite(rmotorb,LOW);
}
else
{
tone(buzzer, 1000);
delay(1000);
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
noTone(buzzer);
}
}
