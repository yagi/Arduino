
 
class Bar {
public:
  Bar() {
    for (int i=0 ; i<10 ; ++i)
      pinMode(i, OUTPUT);
  }
  void on(char iPin) {
    digitalWrite(iPin, HIGH); 
  }
  void off(char iPin) {
    digitalWrite(iPin, LOW); 
  }
};
