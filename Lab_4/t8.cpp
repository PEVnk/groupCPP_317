#include <iostream>
#include <functional>
#include "lab4.h"

// Реализация логических операций
int logicalAND(int a, int b) {
  return a & b;

}

int logicalOR(int a, int b) {
  return a | b;
}

int logicalXOR(int a, int b) {
  return a ^ b;
}

// Реализация функции compute
int ResultFunction(int a, int b, CallbackType callback) {
  return callback(a, b);
}
