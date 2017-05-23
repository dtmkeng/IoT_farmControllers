int readkey(){
  keyRead = customKeypad.getKey();
  if(keyRead=='U'){
    delay(200);
    return btnUp;
    }
  if(keyRead=='D'){
    delay(200);
    return btnDown;
    }
   if(keyRead=='E'){
     delay(200); 
     return btnEnter;
    }
    if(keyRead=='C'){
    delay(200);
    return btnEsc;  
    }
    else{
      return btnNon;
      }
 }

