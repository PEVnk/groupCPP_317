/**************************************************************************************
 * Filename: main.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 5
 * Исследование строк, структур памяти С++ в IDE Qt Creator
 * ***********************************************************************************/

#include <iostream>
#include <string>
#include "lab5.h"

int globalVarBSS;  // Переменная в секции .bss (неинициализированная)

#define Unit 1
int main()
{
  #if Unit==1
  std::cout << "Задание 1" << std::endl; // Вызов функции задания 1 из отдельного файла

  // Адрес функции main
  std::cout << "Адрес функции main: " << (void*)&main << std::endl;

  // Адрес функции printAddresses
  printAddresses();

  // Адрес переменной в стеке
  int stakVar = 20;
  std::cout << "Адрес переменной в стеке: " << &stakVar << std::endl;

  // Адреса и значения элементов массива в стеке
  int stakArray[3] = {5, 6, 7};
  for (int i = 0; i < 3; ++i){
    std::cout << "Адрес stakArray[" << i << "]: " << &stakArray[i] << ", значение: " << stakArray[i] << std::endl;
  }

  // Адрес переменной в статической памяти в секции .bss
  std::cout << "Адрес globalVarBSS: " << &globalVarBSS << std::endl;

  // Адрес переменной в статической памяти в секции .data
  std::cout << "Адрес globalVarData: " << &globalVarData << std::endl;

  // Адреса и значения элементов массива в статической памяти
  static int staticArray[3] = {8, 9, 10};
  for (int i = 0; i < 3; ++i){
    std::cout << "Адрес staticArray[" << i << "]: " << &staticArray[i] << ", значение: " << staticArray[i] << std::endl;
  }

  // Адрес переменной в куче
  int* heapVar = new (std::nothrow)int(25);
  std::cout << "Адрес переменной в куче: " << heapVar << std::endl;

  // Адреса и значения элементов массива в куче
  int* heapArray = new (std::nothrow)int[3]{7, 8, 9};
  for (int i = 0; i < 3; ++i){
    std::cout << "Адрес heapArray[" << i << "]: " << &heapArray[i] << ", значение: " << heapArray[i] << std::endl;
  }

  // Освобождение памяти
  delete heapVar;
  delete[] heapArray;


  #elif Unit==2
  std::cout << "Задание 2" << std::endl; // Вызов функции задания 2 из отдельного файла

  std::cout << "Добро пожаловать в программу 'Новый вид'!\n";
  std::cout << "Вы можете создать новое существо, для этого введите его характеристики.\n";

  // Создание нового существа
  Creature newCreature = createCreature();

  std::cout << "\nВы создали новый вид!\n";

  // Вывод описания существа
  printCreature(newCreature);

  #elif Unit==3
  std::cout << "Задание 3" << std::endl; // Вызов функции задания 3 из отдельного файла

  // Создаем массив объектов структуры в статической памяти
  constexpr size_t staticSize = 10;
  Location staticLocations[staticSize] = {
    {"Москва", "Московская область", "Москва", "Россия", "Евразия"},
    {"Санкт-Петербург", "Ленинградская область", "Москва", "Россия", "Евразия"},
    {"Новосибирск", "Новосибирская область", "Новосибирск", "Россия", "Евразия"},
    {"Лос-Анджелес", "Калифорния", "Вашингтон", "США", "Северная Америка"},
    {"Найроби", "Найроби", "Найроби", "Кения", "Африка"},
    {"Новокузнецк", "Кемеровская область", "Кемерово", "Россия", "Евразия"},
    {"Абакан", "Хакасия", "Абакан", "Россия", "Евразия"},
    {"Пекин", "Хэбэй", "Пекин", "Китай", "Евразия"},
    {"Прокопьевск", "Кемеровская область", "Кемерово", "Россия", "Евразия"},
    {"Сеул", "Судоквон", "Сеул", "Республика Корея", "Евразия"}
  };

  // Создаем массив указателей на объекты в динамической памяти
  const size_t dynamicSize = 2;
  Location* dynamicLocations[dynamicSize];
  dynamicLocations[0] = new (std::nothrow)Location{"Лондон", "Англия", "Лондон", "Великобритания", "Евразия"};
  dynamicLocations[1] = new (std::nothrow)Location{"Рим", "Лацио", "Рим", "Италия", "Евразия"};

  // Основной цикл программы
  while (true){
    std::string city;
    std::cout << "Введите название города (или 'q' для выхода): ";
    std::getline(std::cin, city);
    if (city == "q") {
      break; // Выход из программы
    }

    // Поиск информации о городе в статическом массиве
    const Location* result = searchCity(staticLocations, staticSize, city);

    // Если город не найден в статическом массиве, ищем в динамическом
    if (!result){
      result = searchCity(*dynamicLocations, dynamicSize, city);
    }

    if (result){
      // Вывод информации о городе
      std::cout << "Город: " << result->city << "\n";
      std::cout << "Регион: " << result->region << "\n";
      std::cout << "Столица: " << result->capital << "\n";
      std::cout << "Страна: " << result->country << "\n";
      std::cout << "Материк: " << result->continent << "\n";
    } else {
      std::cout << "Данная информация отсутствует.\n";
    }
  }

  // Освобождаем динамическую память
  for (size_t i = 0; i < dynamicSize; ++i){
    delete dynamicLocations[i];
  }


  #elif Unit==4
  std::cout << "Задание 4" << std::endl; // Вызов функции задания 4 из отдельного файла
  std::string packed;
  std::cout << "Введите упакованную строку: ";
  std::cin >> packed;

  // Распаковываем строку
  std::string unpacked = unpackString(packed);

  // Выводим результат
  std::cout << "Распакованная строка: " << unpacked << std::endl;

  #elif Unit==5
  std::cout << "Задание 5" << std::endl; // Вызов функции задания 5 из отдельного файла
  std::string input;
  std::cout << "Введите строку (максимум 100 символов): ";
  std::getline(std::cin, input); // Считываем всю строку, включая пробелы

  // Обрабатываем строку
  processString(input);

  // Выводим результат
  std::cout << "Обработанная строка: " << input << std::endl;

  #elif Unit==6
  std::cout << "Задание 6" << std::endl; // Вызов функции задания 6 из отдельного файла

  std::string strings[numStrings];
  int count = inputStrings(strings, numStrings);

  if (count == 0){
    std::cout << "Не введено ни одной строки.\n";
    return 0;
  }

  // Выбор способа сортировки
  std::cout << "Выберите способ сортировки:\n";
  std::cout << "1. По длине строки\n";
  std::cout << "2. По алфавиту\n";
  int choice;
  std::cin >> choice;
  std::cin.ignore(); // Игнорируем оставшийся символ новой строки

  switch (choice){
    case 1:
      sortLength(strings, count);
      break;
    case 2:
      sortAlphabet(strings, count);
      break;
    default:
      std::cout << "Неверный выбор. Сортировка не выполнена.\n";
      return 1;
  }

  // Вывод отсортированных строк
  printStrings(strings, count);


  #elif Unit==7
  std::cout << "Задание 7" << std::endl; // Вызов функции задания 7 из отдельного файла

  // Пример преобразования числа в строку
  int number;
  std::cout << "Введите число для преобразования в строку: ";
  std::cin >> number;

  std::string str = intToString(number);
  std::cout << "Результат преобразования числа в строку: " << str << "\n";


  // Пример преобразования строки в число
  std::string input;
  std::cout << "Введите строку для преобразования в число: ";
  std::cin >> input;

  try{
    int num = stringToInt(input);
    std::cout << "Результат преобразования строки в число: " << num << "\n";
  }
  catch (std::invalid_argument const &e){
    std::cout << "Bad input: std::invalid_argument thrown" << std::endl;
  }
  catch (std::out_of_range const &e){
    std::cout << "Integer overflow: std::out_of_range thrown" << std::endl;
  }


  #else
  std::string line;
    while (getline(std::cin, line)){
      Address address; // Создаем объект Address на стеке
    try{
      Parse(line, &address); // Передаем указатель на объект
      Unify(&address);
      std::cout << Format(address) << "\n";
    }
    catch (const std::exception& e){
      std::cout << "exception\n"; // Выводим "exception" в случае ошибки
    }
    }



  #endif
  return 0;
}
