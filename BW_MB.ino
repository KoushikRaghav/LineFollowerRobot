#define lmotorf 9
#define lmotorb 8
#define rmotorf 10
#define rmotorb 11
const int buzzer = 4;
//HIGH white
//LOW black

void setup() {


pinMode(lmotorf,OUTPUT);
pinMode(rmotorf,OUTPUT);
pinMode(lmotorb,OUTPUT);
pinMode(rmotorb,OUTPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {

// dynamic line follower code
// if the sensor is on white it returns LOW value to the Arduino
// if it is on black it returns a HIGH value to the Arduino
int lsensor=digitalRead(6);
int rsensor=digitalRead(7);
if((lsensor==LOW)&&(rsensor==LOW))
{
//both sensors on white
// go forward
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,HIGH);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,LOW);
}
else if((lsensor==LOW)&& (rsensor==HIGH))
{
//right sensor on black line
// turn right
digitalWrite(lmotorf,HIGH);
digitalWrite(rmotorf,LOW);
digitalWrite(lmotorb,LOW);
digitalWrite(rmotorb,HIGH);
}
else if((lsensor==HIGH)&&(rsensor==LOW))
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
