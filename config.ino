void systemConfig(){
  unsigned int varmanu =1;
  char*mymanu[]={"<Set Temp>>>",
                 "<1.1 TempLow>>",
                 "<<1.2 TempHigh",
                 "<Set Humi>>",
                 "<2.1 HumiLow>>",
                 "<<2.2 HumiHigh"
    
  };
  int i =1;
  lcd.clear();
  lcd.setCursor(4,1);
  lcd.print("System Config");
  delay(1000);
  lcd.clear();
  
  digitalWrite(FanOut,OFF);
  digitalWrite(FanIn,OFF);
  digitalWrite(Pump,OFF); 
  digitalWrite(PumpWater,OFF);
  while(i==1){
    switch(varmanu){
      case 1:{
        lcd.setCursor(4,0);
        lcd.print(mymanu[0]);
        break;
        }
      case 11:{
        lcd.setCursor(4,0);
        lcd.print(mymanu[0]);
        lcd.setCursor(3,1);
        lcd.print(mymanu[1]);
        lcd.setCursor(10,3);
        if(tempLow<10)lcd.print("0");
        lcd.print(tempLow);
        lcd.setCursor(13, 3);
         lcd.print("C");
        lcd.setCursor(14, 3);
        lcd.write(2);
        lcd.setCursor(16, 3);
        lcd.print("SET");
        break;
        }
       case 111:{
        unsigned long j = millis()/390;
        lcd.setCursor(4,0);
        lcd.print(mymanu[0]);
        lcd.setCursor(10,3);
        if((j%2)==0){
        if(tempLow<10)lcd.print("0");
        lcd.print(tempLow);
        }
        lcd.setCursor(13, 3);
        lcd.print("C");
        lcd.setCursor(14, 3);
        lcd.write(2);
        break;
        }
        case 12:{
        lcd.setCursor(4,0);
        lcd.print(mymanu[0]);
        lcd.setCursor(3,1);
        lcd.print(mymanu[2]);
        lcd.setCursor(10,3);
        if(tempLow<10)lcd.print("0");
        lcd.print(tempHigh);
        lcd.setCursor(14, 3);
        lcd.write(2);
        lcd.setCursor(13, 3);
        lcd.print("C");
        lcd.setCursor(16, 3);
        lcd.print("SET");
        break;
        }
        case 121:{
        unsigned long j = millis()/390;
        lcd.setCursor(4,0);
        lcd.print(mymanu[0]);
        if((j%2)==0){
        if(tempHigh<10)lcd.print("0");
        lcd.setCursor(10,3);
        lcd.print(tempHigh);  
        }
        lcd.setCursor(14, 3);
        lcd.write(2);
        break;
        }
        case 2:{
          lcd.setCursor(4,0);
          lcd.print(mymanu[3]);
          break;
          }
         case 21:{
        lcd.setCursor(4,0);
        lcd.print(mymanu[3]);
        lcd.setCursor(3,1);
        lcd.print(mymanu[4]);
        lcd.setCursor(10,3);
        if(humiLow<10)lcd.print("0");
        lcd.print(humiLow);
        lcd.setCursor(12, 3);
        lcd.print("%");
        lcd.setCursor(14, 3);
        lcd.print("SET");
        break;
        }
        case 22:{
        lcd.setCursor(4,0);
        lcd.print(mymanu[3]);
        lcd.setCursor(3,1);
        lcd.print(mymanu[5]);
        lcd.setCursor(10,3);
        if(humiHigh<10)lcd.print("0");
        lcd.print(humiHigh);
        lcd.setCursor(12, 3);
        lcd.print("%");
        lcd.setCursor(14, 3);
        lcd.print("SET");
        break;
        }
         case 211:{
         unsigned long j = millis()/390;
        lcd.setCursor(4,0);
        lcd.print(mymanu[4]);
        if((j%2)==0){
        lcd.setCursor(10,3);
        if(humiLow<10)lcd.print("0");
        lcd.setCursor(10,3);
        lcd.print(humiLow);
        }
        lcd.setCursor(12, 3);
        lcd.print("%");
        break; 
        }
        case 221:{
         unsigned long j = millis()/390;
        lcd.setCursor(4,0);
        lcd.print(mymanu[5]);
        if((j%2)==0){
        lcd.setCursor(10,3);
        if(humiHigh<10)lcd.print("0");
         lcd.setCursor(10,3);
        lcd.print(humiHigh);
        }
        lcd.setCursor(12, 3);
        lcd.print("%");
        break; 
        }
      }
      key_in=readkey();
      switch(key_in){
         ///======================================================btnEnter=========================================///
        case btnEnter:{
          lcd.clear();
          if(varmanu==1){
             varmanu=varmanu*10+1;
            break;
          }
          if(varmanu==11){
            varmanu=varmanu*10+1;
            break;
          }
          if(varmanu==12){
            varmanu=varmanu*10+1;
            break;
          }
          if(varmanu==2){
            varmanu=varmanu*10+1;
            break;
           }
          if(varmanu==21){
            varmanu=varmanu*10+1;
            break;
            }
           if(varmanu==22){
            varmanu=varmanu*10+1;
            break;
            }
           if(varmanu==111||varmanu==121){
              if(varmanu==111)EEPROM.write(addtempLow,tempLow);
              if(varmanu==121)EEPROM.write(addtempHigh,tempHigh);
              lcd.setCursor(5,2);
              lcd.print("SAVE");
              delay(200);
              varmanu=varmanu/10;
              lcd.clear();
              break;
            }
            if(varmanu==211||varmanu==221){
              if(varmanu==211)EEPROM.write(addhumiLow,humiLow);
              if(varmanu==221)EEPROM.write(addhumiHigh,humiHigh);
              lcd.setCursor(5,2);
              lcd.print("SAVE");
              delay(200);
              varmanu=varmanu/10;
              lcd.clear();
              break;
            }
            break;
         }
         ///======================================================btnUp=========================================///
          case btnUp:{
            lcd.clear();
            if(varmanu==1){
              varmanu++;
              if(varmanu>2)varmanu=1;
              break;
              }
             if(varmanu==2){
              varmanu--;
              if(varmanu<1)varmanu=1;
              break;
              }
            if(varmanu==11){
              varmanu++;
              if(varmanu>12)varmanu=11;
              break;
              }
            if(varmanu==21){
              varmanu++;
              if(varmanu>22)varmanu=21;
              break;
              }
             if(varmanu==22){
              varmanu--;
              if(varmanu<21)varmanu=21;
              break;
              }
            if(varmanu==111||varmanu==121){
            if(varmanu==121){
              tempHigh++;
              if(tempHigh>99)tempHigh=1;
              }
            if(varmanu==111){
              tempLow++;
              if(tempLow<1){
                tempLow=1;
                }
              }
             
               break;   
            }
            if(varmanu==211||varmanu==221){
            if(varmanu==221){
              humiHigh++;
              if(humiHigh>99)humiHigh=1;
              }
            if(varmanu==211){
              humiLow++;
              if(humiLow>humiHigh){
                 humiLow=humiHigh-2;
                }
              }
               break;   
            }
            if(varmanu>=11&&varmanu<=12){
              varmanu--;
              if(varmanu<11)varmanu=11;
              break;
              } 
             if(varmanu==1){
              varmanu--;
              if(varmanu<1)varmanu=1;
              break;
              }
             break;
          }
          //==============================================btnDown========================================///
           case btnDown:{
            lcd.clear();
              if(varmanu==111||varmanu==121){
                  if(varmanu==111){
                    tempLow--;
                      if(tempLow<1){tempLow=1;
                      break;}
                    }
                   if(varmanu==121){
                      tempHigh--;
                      if(tempHigh<tempLow){
                        tempHigh=tempLow+2;
                        break;
                       }
                    }
                     break;
                }
             
                if(varmanu==211||varmanu==221){
                    if(varmanu==211){
                      humiLow--;
                      if(humiLow<1){
                         humiLow = 1;
                         break;
                        }
                      }
                     if(varmanu==221){
                      humiHigh--;
                      if(humiHigh<humiLow){
                        humiHigh=humiLow+10;
                        break;
                        }
                      }
                     break;
                  }
                  
               
             }
          //==============================================btnESC========================================///
            case btnEsc:{
              lcd.clear();
              if(varmanu==111||varmanu==121){
                if(varmanu==111){
                    tempLow = EEPROM.read(addtempLow);
                    varmanu =varmanu/10;
                    lcd.clear();
                  }
                 if(varmanu==121){
                    tempHigh = EEPROM.read(addtempHigh);
                    varmanu =varmanu/10;
                    lcd.clear();
                  }
                 break;
              }
              if(varmanu==211||varmanu==221){
                 if(varmanu==211){
                  humiLow = EEPROM.read(addhumiLow);
                  varmanu =varmanu/10;
                  lcd.clear();
                  }
                 if(varmanu==221){
                  humiHigh = EEPROM.read(addhumiHigh);
                  varmanu =varmanu/10;
                  lcd.clear();
                  }
                break;
              }
              if(varmanu==21||varmanu==22){
                varmanu=varmanu/10;
                 break;
              }
              if(varmanu==11||varmanu==12){
                varmanu=varmanu/10;
                 break;
              }
              if(varmanu==1){
                i=0;
                lcd.clear();
                break;
                }
               if(varmanu==2){
                i=0;
                lcd.clear();
                break;
               }
             
          }
        break;
    }
    Serial.println(varmanu);
  }
}
