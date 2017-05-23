#include <DS1302.h>
#include <Keypad.h>
#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
//set timer
LiquidCrystal_I2C lcd(0x27, 20, 4);
byte termometer[8] = //icon for termometer
{
    0b00100,
    0b01010,
    0b01010,
    0b01010,
    0b01110,
    0b11111,
    0b11111,
    0b01110
};
byte humi[8] ={
    0b00100,
    0b00100,
    0b01010,
    0b01010,
    0b10001,
    0b10001,
    0b10001,
    0b01110,
};
byte degree[8]={
    0b00111,
    0b00101,
    0b00111,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
  };
uint8_t CE_PIN = 24;
uint8_t IO_PIN = 23;
uint8_t SCLK_PIN = 22;
DS1302  rtc(CE_PIN,IO_PIN,SCLK_PIN);
Time timeGet;
String str,check;
unsigned long timeCount=0;
unsigned long timeCountStart=0;
unsigned long readTime=3;
unsigned long sensorReadtime = 3;
int Timedelay = 5;
int settimepump=10;//delay ....ms
unsigned long previousMillis = 0;
int CheckTime;
#define FanOut 30
#define FanIn  31
#define Pump   32
#define PumpWater   33

#define OFF HIGH
#define ON  LOW
int key_in;
#define btnUp 1
#define btnDown 2
#define btnEnter 3
#define btnEsc 4
#define btnNon 5

boolean conFanOut;
boolean conFanIn;
boolean conPump;
boolean conPumpWater;
boolean onLED = true;

boolean EvenTempHigh;
boolean EvenTempLow;
boolean EvenHumiHigh;
boolean EvenHumiLow;
boolean EvenPumpWater;

#define DHT_1_PIN 26
#define DHT_2_PIN 27
#define DHT_3_PIN 28
#define DHTTYPE DHT22 

DHT dht0(DHT_1_PIN, DHTTYPE);
DHT dht1(DHT_2_PIN, DHTTYPE);
DHT dht2(DHT_3_PIN, DHTTYPE);
float currentTemp0,currentTemp1,currentTemp2;
float currentHumi0,currentHumi1,currentHumi2;
float AVGcurrentTemp,AVGcurrentHumi;
//set temp&humi
int tempHigh = 31;
int tempLow = 10;
int humiHigh = 80;
int humiLow = 10;

unsigned int addtempHigh = 21;
unsigned int addtempLow = 22;
unsigned int addhumiHigh = 41;
unsigned int addhumiLow = 42;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2};
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','U'},
  {'4','5','6','D'},
  {'7','8','9','E'},
  {'*','0','#','C'}
};
int LEDtime=10;
int showDis = 1; 
boolean Display_on(boolean i){
  if(i==true){
    lcd.backlight();
    return onLED=i;
    }
    if(i==false){
    lcd.noBacklight();
    return onLED = i;  
    }
  }
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
char keyRead;
void Display();
void setup() {
  lcd.clear();
  Serial.begin(9600);
  lcd.begin();
  lcd.createChar(0, termometer);
  lcd.createChar(1, humi);
  lcd.createChar(2, degree);
  pinMode(DHT_1_PIN,INPUT);
  pinMode(DHT_2_PIN,INPUT);
  pinMode(DHT_3_PIN,INPUT);
  pinMode(FanOut,OUTPUT);
  pinMode(FanIn,OUTPUT);
  pinMode(Pump,OUTPUT);
  pinMode(PumpWater,OUTPUT);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);

  digitalWrite(FanOut,OFF);
  digitalWrite(FanIn,OFF);
  digitalWrite(Pump,OFF); 
  digitalWrite(PumpWater,OFF);
  lcd.write(byte(0)); 
  lcd.print(" Arduino! ");
  lcd.write((byte) 1);
  Display_on(true);
  //rtc.setDOW(TUESDAY);        // Set Day-of-Week to FRIDAY
  //rtc.setTime(0, 1, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(23, 5, 2017);
 tempHigh = EEPROM.read(addtempHigh);
  tempLow =EEPROM.read(addtempLow);
  humiHigh = EEPROM.read(addhumiHigh);
 humiLow = EEPROM.read(addhumiLow);
}
void loop() {
   if(timeCountStart>millis()){
    timeCountStart=0;
   }
  if(timeCount<millis()&&onLED==1){
    timeCountStart++;
   }
   if(timeCountStart>(LEDtime*60)&&onLED!=0){
    timeCountStart=0;
    showDis=1;
    Display_on(false);
   }
   timeCount=millis()/1000;
   if(timeCount>readTime){
    readTime = timeCount+(sensorReadtime-1);
    currentTemp0 = dht0.readTemperature();
    currentTemp1 = dht1.readTemperature();
    currentTemp2 = dht2.readTemperature();
    currentHumi0 = dht0.readHumidity(); 
    currentHumi1 = dht1.readHumidity(); 
    currentHumi2 = dht2.readHumidity(); 
    AVGcurrentTemp =(currentTemp0+currentTemp1+currentTemp2)/3;
    AVGcurrentHumi = (currentHumi0+currentHumi1+currentHumi2)/3;
   }
   timeRead();
   Display();
  //Serial.println(AVGcurrentTemp);
  //Serial.println(AVGcurrentHumi);
  if(AVGcurrentTemp>tempHigh)EvenTempHigh = 1;
  if(AVGcurrentTemp<tempLow)EvenTempLow = 1;
  if(AVGcurrentHumi>humiHigh)EvenHumiHigh =1;
  if(AVGcurrentHumi<humiLow)EvenHumiLow =1;
  CheckTime = check.toInt();
  if(CheckTime==settimepump)EvenPumpWater=1;
  if(AVGcurrentTemp>tempHigh&&EvenTempHigh == 1){
    conFanIn = ON;
    }else{
    EvenTempHigh = 0;
    conFanIn = OFF;
   }
  if(AVGcurrentTemp<tempLow&&EvenTempLow == 1){
    conFanOut =ON;
    }else{
       EvenTempLow = 0;
       conFanOut =OFF;
    }
   if(AVGcurrentHumi>humiHigh&&EvenHumiHigh ==1){
    conFanOut =ON;
    }else{
      EvenHumiHigh =0;
      conFanOut =OFF;
    }
    if(AVGcurrentHumi<humiLow&&EvenHumiLow ==1){
      conPump =ON;
     }else{
        EvenHumiLow =0;
        conPump =OFF;
     }
    if(EvenPumpWater){
      conPumpWater = ON;
     if(CheckTime>settimepump+Timedelay){
        conPumpWater = OFF;
        EvenPumpWater=0;
       }
    }else{
      conPumpWater = OFF;
        EvenPumpWater=0;
      }
    EventStart();
    key_in=readkey();
    
    switch(key_in){
      case btnUp:{
        if(onLED==false){
          Display_on(true);
          timeCountStart=0;
        }else{
        lcd.clear();
        showDis++;
        if(showDis>2)showDis=1; 
        }
         break;
      }
       case btnDown:{
        if(onLED==false){
          Display_on(true);
          timeCountStart=0;
        }else{
           lcd.clear();
        showDis--;
        if(showDis<1)showDis=2;
        }
         break;
      }
      case btnEnter:{
        if(onLED==false){
          Display_on(true);
          timeCountStart=0;
        }else{
          systemConfig();
          }
        break; 
      }
      case btnEsc:{
        showDis=1;
        break;
      }
      case btnNon:{
        break;
      }
    
   }
  

}
