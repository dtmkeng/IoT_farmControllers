void systemConfig(){
  unsigned int varmanu =1;
  char*mymanu[]={"<1.Set Temp>>>",
                 "<1.1 TempLow>>",
                 "<<1.2 TempHigh",
                 "<2.Set Humi>>",
                 "<2.1 HumiLow>>",
                 "<<2.2 HumiHigh",
                 "<3.Set Time>>",
                 "<3.1 Time LCD>",
                 "<3.2 Time On Pump>>",
                 "<<3.2.1 Time On 1>>",
                 "<<3.2.2 Time On 2>>",
                 "<<3.2.3 Time On 3>>",
                 "<<3.3 Time Delay>"
    
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
        case 3:{
           lcd.setCursor(4,0);
           lcd.print(mymanu[6]);
           break;
        }
        case 31:{
          lcd.setCursor(4,0);
          lcd.print(mymanu[6]);
          lcd.setCursor(4,1);
          lcd.print(mymanu[7]);
          lcd.setCursor(10,3);
          if(LCDtime<1)lcd.print("0");
          lcd.print(LCDtime);
          lcd.setCursor(13, 3);
          lcd.print("Sec");
          lcd.setCursor(17, 3);
          lcd.print("SET");
          break;
        }
        case 32:{
          lcd.setCursor(4,0);
          lcd.print(mymanu[6]);
          lcd.setCursor(1,1);
          lcd.print(mymanu[8]);
          lcd.setCursor(10,3);
          lcd.setCursor(14, 3);
          lcd.print("SET");
          break;
        }
        case 33:{
          lcd.setCursor(4,0);
          lcd.print(mymanu[6]);
          lcd.setCursor(1,1);
          lcd.print(mymanu[12]);
          lcd.setCursor(10,3);
          if(Timedelay<1)lcd.print("0");
          lcd.print(Timedelay);
          lcd.setCursor(13, 3);
          lcd.print("Sec");
          lcd.setCursor(17, 3);
          lcd.print("SET");
          break;
        }
        case 320:{
          lcd.setCursor(6,0);
          lcd.print(" Time Work");
          lcd.setCursor(7,2);
          lcd.print(state);
          lcd.setCursor(9,2);
          lcd.print("time");
          break;
          }
        case 311:{
          unsigned long j = millis()/390;
          lcd.setCursor(4,0);
          lcd.print(mymanu[7]);
          if((j%2)==0){
          lcd.setCursor(10,3);
          if(LCDtime<10)lcd.print("0");
          lcd.setCursor(10,3);
          lcd.print(LCDtime);
          }
          lcd.setCursor(13, 3);
          lcd.print("Sec");
          break; 
         }
          case 321:{
          unsigned long j = millis()/390;
          lcd.setCursor(1,0);
          lcd.print(mymanu[9]);
          if((j%2)==0){
          lcd.setCursor(10,3);
          if(settime_1_pump<1)lcd.print("0");
          lcd.setCursor(10,3);
          lcd.print(settime_1_pump);
          }
          lcd.setCursor(14, 3);
          lcd.print("Sec");
          break;
          }
          case 322:{
          unsigned long j = millis()/390;
          lcd.setCursor(1,0);
          lcd.print(mymanu[10]);
           if((j%2)==0){
          lcd.setCursor(10,3);
          if(settime_2_pump<1)lcd.print("0");
          lcd.setCursor(10,3);
          lcd.print(settime_2_pump);
          }
          lcd.setCursor(14, 3);
          lcd.print("Sec");
          break;
          }
          case 323:{
          unsigned long j = millis()/390;
          lcd.setCursor(1,0);
          lcd.print(mymanu[11]);
           if((j%2)==0){
          lcd.setCursor(10,3);
          if(settime_3_pump<1)lcd.print("0");
          lcd.setCursor(10,3);
          lcd.print(settime_3_pump);
          }
          lcd.setCursor(14, 3);
          lcd.print("Sec");
          break;
          }
          case 331:{
              unsigned long j = millis()/390;
              lcd.setCursor(1,0);
              lcd.print(mymanu[12]);
              if((j%2)==0){
              lcd.setCursor(10,3);
              if(Timedelay<1)lcd.print("0");
              lcd.setCursor(10,3);
              lcd.print(Timedelay);
                }
              lcd.setCursor(13, 3);
              lcd.print("Sec");
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
            if(varmanu==31){
                varmanu=varmanu*10+1;
                break;
              }
            if(varmanu==33){
                varmanu=varmanu*10+1;
                break;
             }
            if(varmanu==32){
                varmanu=varmanu*10;
                break;
              }
             if(varmanu==320){
                EEPROM.write(addstate,state);
                lcd.setCursor(5,2);
                lcd.print("SAVE");
                delay(200);
                lcd.clear();
                varmanu++;
                if(varmanu>323)varmanu=321;
                break;
              }
             if(varmanu==320&&state==1){
              varmanu++;
              if(varmanu>321)varmanu=321;
              break;
              }
              if(varmanu==321&&state==1){
                EEPROM.write(addtime1,settime_1_pump);
                lcd.setCursor(5,2);
                lcd.print("SAVE");
                delay(200);
                lcd.clear();
                varmanu=varmanu/10;
                break;
              }
            if(varmanu==321&&state==2){
              varmanu++;
              if(varmanu>322)varmanu=321;
              break;
              }
              if(varmanu==321&&state==3){
              varmanu++;
              if(varmanu>322)varmanu=321;
              break;
              }
             if(varmanu==322&&state==3){
              varmanu++;
              if(varmanu>323)varmanu=321;
              break;
              }
              if(varmanu==322&&state==2){
                EEPROM.write(addtime2,settime_2_pump);
                lcd.setCursor(5,2);
                lcd.print("SAVE");
                delay(200);
                lcd.clear();
                varmanu=varmanu/10;
                break;
              }
              if(varmanu==323&&state==3){
                EEPROM.write(addtime3,settime_3_pump);
                lcd.setCursor(5,2);
                lcd.print("SAVE");
                delay(200);
                lcd.clear();
                varmanu=varmanu/10;
                break;
              }
              if(varmanu==311){
                EEPROM.write(addtimelcd,LCDtime);
                lcd.setCursor(5,2);
                lcd.print("SAVE");
                delay(200);
                lcd.clear();
                varmanu=varmanu/10;
                break;
              }
               if(varmanu==331){
                EEPROM.write(addtimedelay,Timedelay);
                lcd.setCursor(5,2);
                lcd.print("SAVE");
                delay(200);
                lcd.clear();
                varmanu=varmanu/10;
                break;
                }
            if(varmanu==3){
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
              if(varmanu>3)varmanu=1;
              break;
              }
             if(varmanu==2){
              varmanu++;
              if(varmanu>3)varmanu=1;
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
              if(varmanu==31){
              varmanu++;
              if(varmanu>33)varmanu=31;
              break;
              }
              if(varmanu==32){
              varmanu++;
              if(varmanu>33)varmanu=31;
              break;
              }
              if(varmanu==311){
                LCDtime++;
                if(LCDtime>30)LCDtime=1;
                break;
                }
               if(varmanu==331){
                Timedelay++;
                if(Timedelay>30)Timedelay=1;
                break;
                }
              if(varmanu==320||varmanu==321||varmanu==322||varmanu==323){
                if(varmanu==320){
                  state++;
                  if(state>3)state=1;
                  break;
                }
                if(varmanu==321){
                  settime_1_pump++;
                  if(settime_1_pump>60)settime_1_pump=1;
                  break;
                }
                if(varmanu==322){
                  settime_2_pump++;
                  if(settime_2_pump>60)settime_2_pump=1;
                  break;
                }
                if(varmanu==323){
                  settime_3_pump++;
                  if(settime_3_pump>60)settime_3_pump=1;
                  break;
                }
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
            if(varmanu==1){
               varmanu=1;
               break;
              }
             if(varmanu==2){
               varmanu--;
                if(varmanu<1)varmanu=1;
                break;
              }
             if(varmanu==3){
               varmanu--;
                if(varmanu<1)varmanu=1;
                break;
              }
              if(varmanu==33){
                varmanu--;
                if(varmanu<31)varmanu=31;
                break;
                }
               if(varmanu==32){
                varmanu--;
                if(varmanu<31)varmanu=31;
                break;
                }
                if(varmanu==31){
                varmanu=varmanu/10;
                break;
                }
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
                 if(varmanu==320||varmanu==321||varmanu==322||varmanu==323){
                  if(varmanu==321){
                    settime_1_pump--;
                      if(settime_1_pump<1)settime_1_pump=1;
                      break;
                    }
                   if(varmanu==322){
                    settime_2_pump--;
                      if(settime_2_pump<1)settime_2_pump=1;
                      break;
                    }
                     if(varmanu==323){
                      settime_3_pump--;
                      if(settime_3_pump<1)settime_3_pump=1;
                      break;
                    }
                    
                  }
                  if(varmanu==311){
                      LCDtime--;
                      if(LCDtime<1)LCDtime=1;
                      break;
                    }
                    if(varmanu==331){
                      Timedelay--;
                      if(Timedelay<1)Timedelay=1;
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
              if(varmanu==311||varmanu==320||varmanu==321||varmanu==322||varmanu==323||varmanu==331){
                 if(varmanu==311){
                    LCDtime=EEPROM.read(addtimelcd);
                    varmanu =varmanu/10;
                    lcd.clear();
                  }
                  if(varmanu==320){
                    state = EEPROM.read(addstate);
                    varmanu =varmanu/10;
                    lcd.clear();
                  }
                  if(varmanu==321){
                      settime_1_pump=EEPROM.read(addtime1);
                      varmanu =varmanu/10;
                      lcd.clear();
                    }
                   if(varmanu==322){
                      settime_2_pump=EEPROM.read(addtime2);
                      varmanu =varmanu/10;
                      lcd.clear();
                    }
                   if(varmanu==323){
                      settime_3_pump=EEPROM.read(addtime3);
                      varmanu =varmanu/10;
                      lcd.clear();
                    }
                    if(varmanu==331){
                      Timedelay=EEPROM.read(addtimedelay);
                      varmanu =varmanu/10;
                      lcd.clear();
                      }
                      break;
                }
              if(varmanu==21||varmanu==22){
                varmanu=varmanu/10;
                 break;
              }
              if(varmanu==31||varmanu==32){
                varmanu=varmanu/10;
                 break;
              }
              if(varmanu==33){
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
               if(varmanu==3){
                i=0;
                lcd.clear();
                break;
               }
             
          }
          
        break;
    }
    //Serial.println(varmanu);
     
  }
}
