class Key {
  char mPin;
  bool mState, mLastState;
public:
  Key(char iPin) : mPin(iPin), mState(false), mLastState(false) {
    pinMode(mPin, INPUT);
  }
  
  bool update() {
    mLastState = mState;
    mState = (digitalRead(mPin) == LOW);
    return !mLastState && mState;
  }
  bool getState() {
    return mState;
  }
};
