#include <iostream>
#include "l3_1.h"

// Определение глобальной переменной
int globalVar = 55;

// Реализация функции
auto initVars() -> void {
  // Копирующая инициализация (Copy initialization)
  int iValue1 = 10;
  bool bValue1 = true;
  char cValue1 = 'A';
  long lValue1 = 1000L;

  // Прямая инициализация (Direct initialization)
  int iValue2(15);
  bool bValue2(false);
  char cValue2('B');
  long lValue2(2000L);

  // Унифицированная инициализация (Uniform initialization)
  int iValue3{20};
  bool bValue3{true};
  char cValue3{'C'};
  long lValue3{3000L};

  // Инициализация с использованием auto
  auto iValue4 = 25;
  auto bValue4 = false;
  auto cValue4 = 'D';
  auto lValue4 = 4000L;

  // Вывод значений
  std::cout << "Копирующая инициализация: " << iValue1 << ", " << bValue1 << ", " << cValue1 << ", " << lValue1 << std::endl;
  std::cout << "Прямая инициализация: " << iValue2 << ", " << bValue2 << ", " << cValue2 << ", " << lValue2 << std::endl;
  std::cout << "Унифицированная инициализация: " << iValue3 << ", " << bValue3 << ", " << cValue3 << ", " << lValue3 << std::endl;
  std::cout << "Auto инициализация: " << iValue4 << ", " << bValue4 << ", " << cValue4 << ", " << lValue4 << std::endl;
}
