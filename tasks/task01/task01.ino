const int NUM_LAMPS = 5;
long* micrs = new long[NUM_LAMPS];
int* lamps = new int[NUM_LAMPS];
int pins[NUM_LAMPS] = {3, 5, 6, 9, 10};
unsigned long times[NUM_LAMPS] = {10000, 1000, 500, 100, 50};

void setup() {
  for (int i = 0; i < NUM_LAMPS; i++) {
    micrs[i] = 0;
    lamps[i] = LOW;
    pinMode(pins[i], OUTPUT);
  }
}

void toggleLamp(int index) {
  if (lamps[index] == LOW) {
    lamps[index] = HIGH;
  } else {
    lamps[index] = LOW;
  }
  digitalWrite(pins[index], lamps[index]);
}

void loop() {
  unsigned long micr_cur = micros();

  for (int i = 0; i < NUM_LAMPS; i++) {
    if (micr_cur - micrs[i] >= times[i]) {
      micrs[i] = micr_cur;
      toggleLamp(i);
    }
  }
}