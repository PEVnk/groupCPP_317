#include <iostream>
#include "l3_1.h"


#define Unit 1
int main()
{
#if Unit==1
std::cout << "Задание 1" << std::endl; // Вызов функции задания 1 из отдельного файла
  std::cout << "вероятность появления туза: " << math_prob(52,4) << std::endl;
  std::cout << "вероятность того, что сумма\
  выпавших очков будет равна 7: " << math_prob(36,6) << std::endl;
  std::cout << "вероятность получения слово 'МАМА': " << math_prob(6,1) << std::endl;

#elif Unit==2
std::cout << "Задание 2" << std::endl; // Вызов функции задания 2 из отдельного файла
  std::cout << "вызов без аргументов" << std::endl;
  printChar();
  std::cout << "вызов с одним аргументом" << std::endl;
  printChar(65);                                             //a = 65 (например, ASCII код для 'A'), b = 'b', c = 'c', d = 'd'
  std::cout << "вызов с двумя аргументами" << std::endl;
  printChar(65, 'x');                                       // a = 65, b = 'x', c = 'c', d = 'd'
  std::cout << "вызов с тремя аргументами" << std::endl;
  printChar(65, 'x', 'y');                                 // a = 65, b = 'x', c = 'y', d = 'd'
  std::cout << "вызов с четырьмя аргументами" << std::endl;
  printChar(65, 'x', 'y', 'z');                            // a = 65, b = 'x', c = 'y', d = 'z'


#elif Unit==3
std::cout << "Задание 3" << std::endl; // Вызов функции задания 3 из отдельного файла
  // Локальная переменная с тем же именем, что и глобальная
  int globalVar = 200;

  // Вызов функции инициализации
  initVars();

  // Вывод глобальной и локальной переменной
  std::cout << "Глобальная переменная: " << ::globalVar << std::endl;
  std::cout << "Локальная переменная: " << globalVar << std::endl;

  return 0;


#elif Unit==4
std::cout << "Задание 4" << std::endl;  // Вызов функции задания 4 из отдельного файла
  // Примеры использования функций
  Animals animal1 = Animals::PIG;
  Animals animal2 = Animals::CHICKEN;

  std::cout << "Animal 1: ";
  getAnimalName(animal1);
  std::cout << ", ";
  printNumberOfLegs(animal1);
  std::cout << std::endl;

  std::cout << "Animal 2: ";
  getAnimalName(animal2);
  std::cout << ", ";
  printNumberOfLegs(animal2);
  std::cout << std::endl;
  return 0;

#elif Unit==5
std::cout << "Задание 5" << std::endl;  // Вызов функции задания 5 из отдельного файла
  int a, b, c;
  unsigned short usA, usB;

  // Ввод данных от пользователя
  std::cout << "Введите два целых числа (int): ";
  std::cin >> a >> b;
  std::cout << "Максимум: " << max(a, b) << ", Минимум: " << min(a, b) << std::endl;

  std::cout << "Введите два числа типа unsigned short: ";
  std::cin >> usA >> usB;
  std::cout << "Максимум: " << max(usA, usB) << ", Минимум: " << min(usA, usB) << std::endl;

  std::cout << "Введите три целых числа (int): ";
  std::cin >> a >> b >> c;
  std::cout << "Максимум с ограничением: " << max(a, b, c) << ", Минимум с ограничением: " << min(a, b, c) << std::endl;

  return 0;


#elif Unit==6
std::cout << "Задание 6" << std::endl;  // Вызов функции задания 6 из отдельного файла
  //демонстрация работы функции
  int x = 10;
  float y = 5.5f;
  double z = 2.5;
  unsigned short k = 7;

  // Выражение 1
  std::cout << "Выражение 1 (int i=(x+y)*z+k):" << std::endl;
  std::cout << "Неявное преобразование: " << impConvers1(x, y, z, k) << std::endl;
  std::cout << "static_cast: " << stCastConvers1(x, y, z, k) << std::endl;
  std::cout << "C-style cast: " << cStyleCastConvers1(x, y, z, k) << std::endl;

  // Выражение 2
  std::cout << "\nВыражение 2 (k=x-y/z):" << std::endl;
  std::cout << "Неявное преобразование: " << impConvers2(x, y, z) << std::endl;
  std::cout << "static_cast: " << stCastConvers2(x, y, z) << std::endl;
  std::cout << "C-style cast: " << cStyleCastConvers2(x, y, z) << std::endl;

  // Выражение 3
  std::cout << "\nВыражение 3 (z=x*y+z/x):" << std::endl;
  std::cout << "Неявное преобразование: " << impConvers3(x, y, z) << std::endl;
  std::cout << "static_cast: " << stCastConvers3(x, y, z) << std::endl;
  std::cout << "C-style cast: " << cStyleCastConvers3(x, y, z) << std::endl;

  // Выражение 4
  std::cout << "\nВыражение 4 (unsigned int ui=x/y+k):" << std::endl;
  std::cout << "Неявное преобразование: " << impConvers4(x, y, k) << std::endl;
  std::cout << "static_cast: " << stCastConvers4(x, y, k) << std::endl;
  std::cout << "C-style cast: " << cStyleCastConvers4(x, y, k) << std::endl;

  // Выражение 5
  std::cout << "\nВыражение 5 (short s=x%(x/y)):" << std::endl;
  std::cout << "Неявное преобразование: " << impConvers5(x, y) << std::endl;
  std::cout << "static_cast: " << stCastConvers5(x, y) << std::endl;
  std::cout << "C-style cast: " << cStyleCastConvers5(x, y) << std::endl;

  return 0;


#else
std::cout << "Задание 7" << std::endl;  // Вызов функции задания 7 из отдельного файла
  int num_input;
  std::cout << "Добро пожаловать в виртуальный торгово-развлекательный центр!\n";
  std::cout << "Выберите этаж (0-7):\n";
  std::cout << "0. Парковка\n";
  std::cout << "1. Продуктовый магазин\n";
  std::cout << "2. Спортзал\n";
  std::cout << "3. Магазины\n";
  std::cout << "4. Игровая площадка\n";
  std::cout << "5. Фудкорт\n";
  std::cout << "6. Кинотеатр\n";
  std::cout << "7. Крыша\n";
  std::cin >> num_input;            //получение номера этажа от пользователя

  // Преобразование введенного пользователем числа в enum
  Level selectedLevel = static_cast<Level>(num_input);

  // Проверка корректности ввода
  if (num_input<0 || num_input>7) {
    std::cout << "Ошибка: неверный номер этажа!\n";
    return 1;
  }
  // Вывод названия выбранного этажа
  std::cout << "Вы направляетесь на этаж: " << getlevellName(selectedLevel) << "\n";

  return 0;

#endif
return 0;
}
