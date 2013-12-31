#include <Key.h>
Key on(11), off(10), ok(15);
extern  short freq[];
#include "Speaker.h"
Speaker spk(12);
#include "Bar.h"
Bar bar;

void demo() {
  for (int i=0 ; i<=20 ; ++i) {
    switch (i) {
    case  0: spk.beep(0,30); break; case  3: spk.beep(4,30); break;
    case  6: spk.beep(7,30); break; case 10: spk.beep(12,30); break;
    case 13: spk.beep(7,60); break; case 15: spk.beep(4,60); break;
    case 18: spk.beep(0,60); break; default: break;
    }
    char pin = (i<=10) ? i : (20-i);    
    bar.on(pin); delay(20); bar.off(pin);
  }  
}

void setup() {  
  //spk.playMml("CDEFGABC"); delay(100);
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
}


