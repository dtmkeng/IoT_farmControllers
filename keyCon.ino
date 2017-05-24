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
    if(keyRead=='1'){
    delay(200);
    return 1;  
    }
     if(keyRead=='2'){
    delay(200);
    return 2;  
    }
     if(keyRead=='3'){
    delay(200);
    return 3;  
    }
     if(keyRead=='4'){
    delay(200);
    return 4;  
    }
     if(keyRead=='5'){
    delay(200);
    return 5;  
    }
    if(keyRead=='6'){
    delay(200);
    return 6;  
    }
     if(keyRead=='7'){
    delay(200);
    return 7;  
    }
     if(keyRead=='8'){
    delay(200);
    return 8;  
    }
     if(keyRead=='9'){
    delay(200);
    return 9;  
    }
     if(keyRead=='0'){
    delay(200);
    return 0;  
    }
    if(keyRead=='#'){
    delay(200);
    return btnSave;  
    }
    else{
      return btnNon;
      }
 }

