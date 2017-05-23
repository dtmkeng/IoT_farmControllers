void Display(){
  switch(showDis){
    case 1:{ 
      showDisplay1();
     
      break;}
    case 2:{ 
      showDisplay2();
      break;}
    }
  }
void showDisplay1(){
      lcd.setCursor(5, 0);
      lcd.print("SMART FARM");
      lcd.setCursor(0, 1);
      //lcd.print("Temperature:");
      lcd.write(0);
      lcd.setCursor(2, 1);
      lcd.print(AVGcurrentTemp);
      lcd.setCursor(7, 1);
      lcd.write(2);
      lcd.setCursor(8, 1);
      lcd.print("C");
      lcd.setCursor(12, 1);
      //lcd.print("Humidity:");
      lcd.write(1);
      lcd.setCursor(14, 1);
      lcd.print(AVGcurrentHumi);
      lcd.setCursor(19, 1);
      lcd.print("%");

      lcd.setCursor(12, 3);
      lcd.print(str);
 }
 void showDisplay2(){
      lcd.setCursor(5, 0);
      lcd.print("OPPTIONS");
      lcd.setCursor(0, 1);
      //lcd.print("Temperature:");
      lcd.write(0);
      lcd.setCursor(1,1);
      lcd.print("HIGH");
      lcd.setCursor(6, 1);
      lcd.print(tempHigh);
      lcd.setCursor(8, 1);
      lcd.write(2);
      lcd.setCursor(9, 1);
      lcd.print("C");
      lcd.setCursor(11, 1);
      //lcd.print("Humidity:");
      lcd.write(1);
      lcd.setCursor(12, 1);
      lcd.print("HIGH");
      lcd.setCursor(17, 1);
      lcd.print(humiHigh);
      lcd.setCursor(19, 1);
      lcd.print("%");

      lcd.setCursor(5, 0);
      lcd.print("OPPTIONS");
      lcd.setCursor(0, 2);
      //lcd.print("Temperature:");
      lcd.write(0);
      lcd.setCursor(1,2);
      lcd.print("LOW");
      lcd.setCursor(6, 2);
      lcd.print(tempLow);
      lcd.setCursor(8, 2);
      lcd.write(2);
      lcd.setCursor(9, 2);
      lcd.print("C");
      lcd.setCursor(11, 2);
      //lcd.print("Humidity:");
      lcd.write(1);
      lcd.setCursor(12, 2);
      lcd.print("LOW");
      lcd.setCursor(17, 2);
      lcd.print(humiLow);
      lcd.setCursor(19, 2);
      lcd.print("%");

      lcd.setCursor(12, 3);
      lcd.print(str);
 }
