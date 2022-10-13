int gatePin=10;
int delTim=20;
int minTim=10000;
int maxTim=20000;
long delTimRand;

int val = 0;
int maxCount = 80;
int countTwo = 0;
byte flickerTable[] = { 10, 10, 20, 30, 30, 30, 40, 50, 60, 70, 80, 70, 70, 
                           60, 60, 50, 50, 50, 60, 70, 80, 90, 100,
                           120,140,160,240,250,100,150,250,250,140,
                           240,230,220,100, 80,70,70, 70, 80, 80,
                           140,130,120,110,200,210,220,220,100, 90,
                            40, 30, 30, 30, 20, 10, 10 };


void setup() {
Serial.begin(9600);
randomSeed(analogRead(0));
pinMode(gatePin,OUTPUT);

delTimRand=random(minTim,maxTim);

digitalWrite(gatePin,HIGH);
}


void loop() {

for (int i=0;i<=3;i=i+1){
Serial.println(i);
digitalWrite(gatePin,HIGH);
delay(delTimRand);

  if (val == HIGH) {            // check if the input is HIGH
 } else {
      delay(delTim);
   for ( int i=0; i <= 150; i++) {  // This for loop runs untill the flicker table finishes
   analogWrite(gatePin, flickerTable[countTwo]);
     countTwo++;
     if(countTwo > maxCount ){
     countTwo = 0;  // Helps makes sure our next flicker doesnt start in an arbitrary place on the table
   }
   delay(delTim);  // the delay for our flicker, make it faster to to make it flicker a little more violently
   digitalWrite(gatePin, HIGH);
   }
 }

delTimRand=random(minTim,maxTim);
delay(delTim);
}

Serial.println("__________");
Serial.println("pause");

for (int j=0;j<=199;j=j+1){
analogWrite(gatePin, 110);
delay(delTim);
analogWrite(gatePin, 100);
delay(delTim);
}
Serial.println("__________");
delay(delTimRand);
}
