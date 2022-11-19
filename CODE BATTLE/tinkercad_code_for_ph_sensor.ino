#include<LiquidCrystal.h>
const int rs =13,en = 12,d4 =11,d5 =10,d6 =9,d7 =8;
LiquidCrystal lcd(rs,en, d4,d5,d6,d7);
int Contrast = 0;

int minTemp = 5;
int maxTemp = 25;
int minph = 6.5;
int maxph = 8.5;

int celsius = 0;

void setup()
{
  Serial.begin(9600);
  analogWrite (6,Contrast);
  lcd.begin(16,2);
  lcd.setCursor(4,0);
  lcd.print("pH Value:");
  
  pinMode(A1, INPUT);
}

void loop() {
  
  int sensorValue = analogRead(A0);
  float ph = sensorValue * (14.0/1023.0);
  //Serial.println(ph);
  lcd.setCursor(6,1);
  lcd.print (ph);

  
  // measure temperature in Celsius
  celsius = map(((analogRead(A1) - 20) * 3.04), 0, 1023, -40, 125);
 
  Serial.println(celsius);
  
  delay(1000);
  
  
  //ideal temperature for aquatic animals 5-25 degrees
  //ideal ph 6.5 to 8.5
  if (celsius <= maxTemp && celsius >= minTemp && ph >= minph && ph <= maxph) {
    
    Serial.println("Temperature and ph level ideal");
  }
  
  else {
    Serial.println("Temperature and pH level are not ideal");
  }
  
}
