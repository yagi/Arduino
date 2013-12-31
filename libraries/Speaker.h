class Speaker {
  char mPin;
public:
  Speaker(char iPin) : mPin(iPin) {
    pinMode(mPin, OUTPUT); 
  } 
  void beep(char code, char len = 20) {
    tone(mPin, freq[code], len);
  }

  void playMml(const char* p) {
    for ( ; *p ; ++p ) {
      char code = *p - 'C';
      beep(code, 120);
      delay(120);
    }
  }
};

