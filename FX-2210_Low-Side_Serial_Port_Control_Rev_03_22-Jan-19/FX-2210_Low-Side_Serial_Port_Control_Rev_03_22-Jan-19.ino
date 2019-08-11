//DUT: FX-2210 Low-Side SW Module.

//TEST EQUIPMENT: F/U/W FX-2000 Test Set 2000-05300x Rev 01 and FX-2000 Electronic Load

//CONFIGURATION: FX-2210 DUT installed at location FX-2100 UMC J2 

//PROCEDURE: Open the serial port monitor and select the desired operating function


void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);

Serial.begin(9600);
Serial.println("SW-1 ON:1 SW-2 ON:2 SW-3 ON:3 SW-4 ON:4");
Serial.println("SW-1 OFF:q SW-2 OFF:w SW-3 OFF:e SW 4 OFF:r");
Serial.println("SW-1 thru SW-4 ON:9");
Serial.println("SW-1 thru SW-4 OFF:0");
Serial.println("SW-1 thru SW-4 pulse ON x-second then OFF:p");

}
void loop() {

while (Serial.available()>0){

char ser =Serial.read();
    
if (ser=='1')digitalWrite (2, HIGH);
if (ser=='q')digitalWrite (2, LOW);

if (ser=='2') digitalWrite (3, HIGH);
if (ser=='w') digitalWrite (3, LOW);

if (ser=='3') digitalWrite (4, HIGH);
if (ser=='e') digitalWrite (4, LOW);

if (ser=='4') digitalWrite (5, HIGH);
if (ser=='r') digitalWrite (5, LOW);

if (ser=='9'){
  digitalWrite (2, HIGH);
  digitalWrite (3, HIGH);
  digitalWrite (4, HIGH);
  digitalWrite (5, HIGH);

}

if (ser=='0'){
  digitalWrite (2, LOW);
  digitalWrite (3, LOW);
  digitalWrite (4, LOW);
  digitalWrite (5, LOW);

}

if (ser=='p'){
  
  digitalWrite (2, HIGH);
  digitalWrite (3, HIGH);
  digitalWrite (4, HIGH);
  digitalWrite (5, HIGH);

delay(100);

  digitalWrite (2, LOW);
  digitalWrite (3, LOW);
  digitalWrite (4, LOW);
  digitalWrite (5, LOW);

}
}
}



  
