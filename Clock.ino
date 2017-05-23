String timeRead(){
  timeGet = rtc.getTime();
  str=rtc.getTimeStr();
  check=timeGet.sec;
 //check=timeGet.min;
 //check=timeGet.hour;
 // Serial.println(timeGet.sec, DEC);
  //erial.println("s");
  return check;
  lcd.setCursor(5, 3);
  lcd.print(str);
}
