long* microsArray = new long[5];
long intervals[5] = {10000, 1000, 500, 100, 50};
int* lampStates = new int[5];
int lampPins[5] = {3, 5, 6, 9, 10};

void setup() {
  for (int i = 0; i < 5; i++) 
  {
    microsArray[i] = 0;
    lampStates[i] = LOW;
    pinMode(lampPins[i], OUTPUT);
  }
}

void toggleState(int& state) {
  state = (state == LOW) ? HIGH : LOW;
}


void loop() {
  unsigned long currentMicros = micros();

  if (currentMicros - microsArray[0] >= intervals[0]) 
  {
    microsArray[0] = currentMicros;
    toggleState(lampStates[0]);
    digitalWrite(lampPins[0], lampStates[0]);
  }

  if (currentMicros - microsArray[1] >= intervals[1]) 
  {
    microsArray[1] = currentMicros;
    toggleState(lampStates[1]);
    digitalWrite(lampPins[1], lampStates[1]);
  }
  
  if (currentMicros - microsArray[2] >= intervals[2]) 
  {
    microsArray[2] = currentMicros;
    toggleState(lampStates[2]);
    digitalWrite(lampPins[2], lampStates[2]);
  }

  if (currentMicros - microsArray[3] >= intervals[3]) 
  {
    microsArray[3] = currentMicros;
    toggleState(lampStates[3]);
    digitalWrite(lampPins[3], lampStates[3]);
  }

  if (currentMicros - microsArray[4] >= intervals[4]) 
  {
    microsArray[4] = currentMicros;
    toggleState(lampStates[4]);
    digitalWrite(lampPins[4], lampStates[4]);
  }
}
