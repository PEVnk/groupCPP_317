#include <iostream>

// Выражение 1: int i=(x+y)*z+k
int impConvers1(int x, float y, double z, unsigned short k){
  return (x+y)*z+k;                           //неявное преобразование
}

int stCastConvers1(int x, float y, double z, unsigned short k) {
  return static_cast<int>((x+y)*z+k);         // Явное преобразование с static_cast
}

int cStyleCastConvers1(int x, float y, double z, unsigned short k) {
  return (int)((x+y)*z+k);                    // Явное преобразование с C-style cast
}

// Выражение 2: k=x-y/z
unsigned short impConvers2(int x, float y, double z) {
  return x-y/z;                               // Неявное преобразование
}

unsigned short stCastConvers2(int x, float y, double z) {
  return static_cast<unsigned short>(x-y/z); // Явное преобразование с static_cast
}

unsigned short cStyleCastConvers2(int x, float y, double z) {
  return (unsigned short)(x-y/z);             // Явное преобразование с C-style cast
}

// Выражение 3: z=x*y+z/x
double impConvers3(int x, float y, double z) {
  return x*y+z/x;                               // Неявное преобразование
}

double stCastConvers3(int x, float y, double z) {
  return static_cast<double>(x*y+z/x);          // Явное преобразование с static_cast
}

double cStyleCastConvers3(int x, float y, double z) {
  return (double)(x*y+z/x);                     // Явное преобразование с C-style cast
}

// Выражение 4: unsigned int ui=x/y+k
unsigned int impConvers4(int x, float y, unsigned short k) {
  return x/y+k;                                 // Неявное преобразование
}

unsigned int stCastConvers4(int x, float y, unsigned short k) {
  return static_cast<unsigned int>(x/y+k); // Явное преобразование с static_cast
}

unsigned int cStyleCastConvers4(int x, float y, unsigned short k) {
  return (unsigned int)(x/y+k);             // Явное преобразование с C-style cast
}

// Выражение 5: short s=x%(x/y)
short impConvers5(int x, float y) {
  return x%static_cast<int>(x/y);                           // Неявное преобразование
}

short stCastConvers5(int x, float y) {
  return static_cast<short>(x%static_cast<int>(x/y));       // Явное преобразование с static_cast
}

short cStyleCastConvers5(int x, float y) {
  return (short)(x%static_cast<int>(x/y));                  // Явное преобразование с C-style cast
}
