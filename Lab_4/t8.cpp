#include <iostream>
#include <functional>
#include "lab4.h"

// ��������� �����᪨� ����権
int logicalAND(int a, int b) {
  return a & b;

}

int logicalOR(int a, int b) {
  return a | b;
}

int logicalXOR(int a, int b) {
  return a ^ b;
}

// ��������� �㭪樨 compute
int ResultFunction(int a, int b, CallbackType callback) {
  return callback(a, b);
}
