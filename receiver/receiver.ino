#include <RH_ASK>
int x_axis = 0;
int y_axis = 0;
int hLed = 11;
int tLed = 10;
int wLed = 9;
int heLed = 8;
RH_ASK driver;
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
uint8_t buf{2];
uint8_t buflen = sizeof(buf)
char msg = (char*)buf
19
 if (msg == "hu"){
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("I Am Hungry");
 delay(10000)

 lcd.clear();
 }
else if (msg == "tu"){
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("I Am Thirsty");
 delay(10000)
 lcd.clear();
 }
else if (msg == "wa"){
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("I want to go ");
 lcd.setCursor(0,1);
 lcd.print("Washroom");
 delay(10000)
 lcd.clear();
 }
else if (msg == "he"){
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Emergency!!!");
 delay(10000)
 lcd.clear();
 }
driver.send(uint8_t *)msg
driver.waitPacketSent();
}
