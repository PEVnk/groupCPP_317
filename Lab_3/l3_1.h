#ifndef T3_H
#define T3_H

#include <string>

//задание 1
//Прототипы функций
double math_prob(double total_ev,double favor_ev);

//задание 2
void printChar(int a='a', char b='b',char c='c', char d='d');

//задание 3
// Объявление глобальной переменной
extern int globalVar;
// Прототип функции с trailing return type
auto initVars() -> void;

//задание 4
// Перечисление Animal
enum class Animals {
  PIG,
  CHICKEN,
  GOAT,
  CAT,
  DOG
};

//Прототипы функций
void getAnimalName(Animals animal);
void printNumberOfLegs(Animals animal);

//задание 5
// Функции для двух параметров типа int
int max(int a, int b);
int min(int a, int b);

// Перегруженные функции для параметров типа unsigned short
unsigned short max(unsigned short a, unsigned short b);
unsigned short min(unsigned short a, unsigned short b);

// Перегруженные функции для трех параметров типа int
int max(int a, int b, int limit);
int min(int a, int b, int limit);

//задание 6
//функции преобразования типов
int impConvers1(int x, float y, double z, unsigned short k);
int stCastConvers1(int x, float y, double z, unsigned short k);
int cStyleCastConvers1(int x, float y, double z, unsigned short k);

unsigned short impConvers2(int x, float y, double z);
unsigned short stCastConvers2(int x, float y, double z);
unsigned short cStyleCastConvers2(int x, float y, double z);

double impConvers3(int x, float y, double z);
double stCastConvers3(int x, float y, double z);
double cStyleCastConvers3(int x, float y, double z);

unsigned int impConvers4(int x, float y, unsigned short k);
unsigned int stCastConvers4(int x, float y, unsigned short k);
unsigned int cStyleCastConvers4(int x, float y, unsigned short k);

short impConvers5(int x, float y);
short stCastConvers5(int x, float y);
short cStyleCastConvers5(int x, float y);

//задание 7
//задание констант для этажей
enum class Level {
  PARKING=0,
  GROCERY_STORE=1,
  GYM=2,
  STORES=3,
  PLAYGROUND=4,
  FOOD_COURT=5,
  CINEMA=6,
  ROOF=7
};
//Прототип функции
std::string getlevellName(Level level);

#endif // T3_H
