#include <iostream>
#include "l3_1.h"

//декларация версий целочисленного типа
int min(int a, int b) {
  return (a < b) ? a : b;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// декларация версий типа unsigned short
unsigned short min(unsigned short a, unsigned short b) {
  return (a < b) ? a : b;
}

unsigned short max(unsigned short a, unsigned short b) {
  return (a > b) ? a : b;
}

//перегрузка функции с тремя параметрами
int min(int a, int b, int limit) {
  int result = (a < b) ? a : b;
  return (result > limit) ? limit : result;
}

int max(int a, int b, int limit) {
  int result = (a > b) ? a : b;
  return (result > limit) ? limit : result;
}
