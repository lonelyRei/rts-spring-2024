#include <TaskManagerIO.h>

long times[5] = {10000, 1000, 500, 100, 50};
int* lamps = new int[5];
int pins[5] = {3, 5, 6, 9, 10};

void toggleLamp(int index) {
  if (lamps[index] == LOW) {
    lamps[index] = HIGH;
  } else {
    lamps[index] = LOW;
  }
  digitalWrite(pins[index], lamps[index]);
}

void setup() {
  for (int i = 0; i < 5; i++) {
    lamps[i] = LOW;
    pinMode(pins[i], OUTPUT);
  }

  for (int i = 0; i < 5; i++) {
    taskid_t taskId = taskManager.scheduleFixedRate(times[i], [i] {
      toggleLamp(i);
    }, TIME_MICROS);
  }
}

void loop() {
  taskManager.runLoop();
}