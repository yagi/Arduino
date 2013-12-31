
extern  short freq[];

#include "Speaker.h"
Speaker spk(12);

#include "Key.h"
Key on(11), off(10), ok(13);

#include "Bar.h"
Bar bar;

void demo() {
  for (int i=0 ; i<=20 ; ++i) {
    switch (i) {
    case  0: spk.beep(0,30); break;
    case  3: spk.beep(4,30); break;
    case  6: spk.beep(7,30); break;
    case 10: spk.beep(12,30); break;
    case 13: spk.beep(7,60); break;
    case 15: spk.beep(4,60); break;
    case 18: spk.beep(0,60);  break;
    }
    char pin = (i<=10) ? i : (20-i);    
    bar.on(pin);
    delay(20);
    bar.off(pin);
  }  
}


static char notes[][2] = {
  {1,2},{3,4},{6,4},{2,1}
};
// 音の高さ CDEF - 音の長さ 

class Game {
  void beep(char code, char len) { }  
  bool handleUp() {  }  
};


void dispNumber(int n) {
}

void setup() {  
  //spk.playMml("CDEFGABC");
  //delay(1000);
  demo();
}

void loop() {
  static int ct = 0;
  ct++;

  if ( on.update() ) {
    spk.beep(7);
    for (int i=0 ; i<10 ; ++i)
      digitalWrite(i, HIGH);
  }

  if ( off.update() ) {
    demo();
  }

  ok.update();
  if ( ok.getState() ) {
    spk.beep(ct%12);
    for (int i=0 ; i<10 ; ++i)
      digitalWrite(i, (random(5)==1 ? HIGH : LOW ));
    delay(33);
  }
  delay(16);
  
/*

  for (int i=0 ; i<10 ; ++i)
    if ( (ct%10) == i )
      digitalWrite(i, HIGH);
    else 
      digitalWrite(i, LOW);
      */

 
/*
  int a = 100;
  if ( yellow && orange )
     a = 12;
  else if ( orange )
     a = 25;
  else if ( yellow )
     a = 50;

    
  // put your main code here, to run repeatedly:
  int orange = (digitalRead(1) == LOW) ? 1 : 0;

  if ( (ct%200) == 0 )
    digitalWrite(7, LOW);
  else if ( (ct%200) == 150  )
    digitalWrite(7, HIGH);
  */
     
  /*
  digitalWrite(3, sw);
  digitalWrite(2, ( sw==HIGH ) ? LOW : HIGH );

  digitalWrite(4, LOW);
  delay(ct%200);
  digitalWrite(4, HIGH);
  delay(ct%100);

  digitalWrite(2, HIGH);
  delay(150);
  digitalWrite(2, LOW);
  delay(150);
  */
}

