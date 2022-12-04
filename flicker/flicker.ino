int gatePin=10;
int delTim=20;

const long interval = 30000;
unsigned long previousMillis = 0;

long minTim=60000; //in ms for minimum random time 60000 is 1mn
long maxTim=180000; //in ms fo maximum random time 350000 is 5mn
long delTimRand;

int val = 0;              //flicker table and integers
int maxCount = 80;
int countTwo = 0;
byte flickerTable[] = { 180, 10, 20, 130, 30, 30, 40, 50, 60, 70, 70, 
                           60, 255, 50, 50, 50, 60, 70, 80, 90, 100,
                           120,140,160,240,250,100,150,250,250,140,
                           240,230,220, 0, 70, 80, 80,
                           140,130,120,110,200,210, 90,
                            255, 240, 100, 125, 150, 200, 255 };


void setup() {
Serial.begin(9600);
pinMode(gatePin,OUTPUT);

randomSeed(analogRead(0));
delTimRand=random(minTim,maxTim);

for (int k=0;k<=3;k=k+1){               //startup blink 2 sec
digitalWrite(gatePin,LOW);
delay(250);
digitalWrite(gatePin,HIGH);
delay(250);
}
}


void loop() {
unsigned long currentMillis = millis();

 if (currentMillis - previousMillis >= interval) {      // init glitch
  previousMillis = currentMillis;
for (int j=0;j<=50;j=j+1){
analogWrite(gatePin,140);
delay(delTim);
analogWrite(gatePin,130);
delay(delTim);
}

for (int i=0;i<=3;i=i+1){                                 //init seq
Serial.print("loop ")  ;
Serial.println(i);
Serial.print("random time ");
Serial.println(delTimRand);

if (val == HIGH) {                                         //flicker table
 } else {
      delay(delTim);
   for ( int i=0; i <= 150; i++) {
   analogWrite(gatePin, flickerTable[countTwo]);
     countTwo++;
     if(countTwo > maxCount ){
     countTwo = 0;
   }
   delay(delTim);
   analogWrite(gatePin, 170);
   }
 }
digitalWrite(gatePin,HIGH);                               //stabilization
delay(delTimRand);

delTimRand=random(minTim,maxTim);
delay(delTim);
}

Serial.println("__________");
Serial.println("pause");

for (int j=0;j<=99;j=j+1){                              //secondary glitches
analogWrite(gatePin, 110);
delay(delTim);
analogWrite(gatePin, 100);
delay(delTim);
}
Serial.println("__________");
analogWrite(gatePin,LOW);
delay(delTimRand);
 }

for (int j=0;j<=499;j=j+1){
analogWrite(gatePin, 0);
 delay(delTim);
 analogWrite(gatePin, 1);
 delay(delTim);
}
}
