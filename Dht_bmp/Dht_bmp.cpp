#include <Arduino.h>

#include <LiquidCrystal.h>
#include <DHT.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>

#define DHTPIN 22
#define DHTTYPE DHT11

//Adafruit_BMP280 bmp;

class Sensor:public DHT{
 public:
  Sensor (int parm1,int parm2):DHT (parm1,parm2){}

};
Sensor sensor(DHTPIN, DHTTYPE);

class Bmp:public Adafruit_BMP280{
  public:
  Bmp():Adafruit_BMP280(){}

};
Bmp bmp ;
class ShowCrystal : public LiquidCrystal{
 public:
 ShowCrystal(int p1,int p2,int p3,int p4,int p5,int p6):LiquidCrystal(p1,p2,p3,p4,p5,p6){}
 void show(Sensor s,Bmp b){
    setCursor(0,0);
    print("T=");
    float temp = s.readTemperature();
    print(temp);
    setCursor(0,1);
    print("H=");
    float hum = s.readHumidity();
    print(hum);
    setCursor(7,0);
    print("T2=");
    float tempBmp = b.readTemperature();
    print(tempBmp);
    setCursor(7,1);
    print("Pa=");
    float presBmp = b.readPressure();
    print(presBmp);
   };
} lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
lcd.show(sensor,bmp);
}
