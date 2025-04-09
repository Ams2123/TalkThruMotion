#include <RH_ASK>
int x_axis = 0;
int y_axis = 0;
int hLed = 11;
int tLed = 10;
int wLed = 9;
int heLed = 8;
RH_ASK driver;
char *msg = "h";
void setup() {
Serial.begin(9600);
if (!driver.init()){
 Serial.println("init failed")
}
pinMode(A0,INPUT);//X AXIS
pinMode(A1,INPUT);//Y-AXIS
pinMode(hLed,OUTPUT);
pinMode(tLed,OUTPUT);
pinMode(wLed,OUTPUT);
pinMode(heLed,OUTPUT);
}
void loop() {
 x_axis = analogRead(A0);
 y_axis = analogRead(A3);
 Serial.print(" X = ");
 Serial.println(x_axis);
 Serial.print(" Y = ");
 Serial.println(y_axis);
if (y_axis >= 390) {
 char *msg = "hu";
 Serial.println("I am Hungry");
 digitalWrite(hLed, HIGH);
 }
else if (y_axis <= 310) {
 char *msg = "tu";
 Serial.println("I am Thirsty");
 digitalWrite(tLed, HIGH);
 }
else if (x_axis >= 380) {
 char *msg = "wa";
 Serial.println("I Want to go Washroom");
 digitalWrite(wLed, HIGH);
 }
18
else if (x_axis <= 320) {
 char *msg = "he";
 Serial.println("Emergency !");
 digitalWrite(heLed, HIGH);
 }
Serial.println(" ");
delay(200);
if (x_axis > 320 && x_axis < 380 && y_axis > 310 && y_axis < 390) {
 digitalWrite(hLed, LOW);
 digitalWrite(tLed, LOW);
 digitalWrite(wLed, LOW);
 digitalWrite(heLed, LOW);
 }
}

