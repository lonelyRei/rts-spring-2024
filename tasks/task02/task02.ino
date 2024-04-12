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

  taskid_t taskId0 = taskManager.scheduleFixedRate(times[0], [] {
    toggleLamp(0);
  }, TIME_MICROS);

  taskid_t taskId1 = taskManager.scheduleFixedRate(times[1], [] {
    toggleLamp(1);
  }, TIME_MICROS);

  taskid_t taskId2 = taskManager.scheduleFixedRate(times[2], [] {
    toggleLamp(2);
  }, TIME_MICROS);

  taskid_t taskId3 = taskManager.scheduleFixedRate(times[3], [] {
    toggleLamp(3);
  }, TIME_MICROS);

  taskid_t taskId4 = taskManager.scheduleFixedRate(times[4], [] {
    toggleLamp(4);
  }, TIME_MICROS);
}

void loop() {
  taskManager.runLoop();
}
