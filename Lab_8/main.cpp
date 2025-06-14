/**************************************************************************************
 * Filename: main.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 8
 * Исследование в С++ стандартной библиотеки шаблонов (STL), перегрузка операторов
 * ***********************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <stdexcept> // для работы с исключениями
#include <limits>
#include "lab8.h"


#define Unit 5

int main()
{
  #if Unit==1
  std::cout << "Задание 1" << std::endl; // Вызов функции задания 1 из отдельного файла

  int N; // Переменная для хранения количества элементов
  std::cout << "Введите количество элементов N (от 1 до 1000): ";
  std::cin >> N; // Пользователь вводит N

  // Проверка, что N в допустимом диапазоне
  if (N < 1 || N > 1000) {
    std::cerr << "Ошибка: N должно быть от 1 до 1000." << std::endl;
    return 1; // Завершаем программу с ошибкой
  }

  // Генерируем контейнер случайных чисел
  std::vector<int> container = generateRandomNumbers(N);

  // Выводим содержимое контейнера
  printContainer(container);

  // Считаем количество уникальных чисел и выводим результат
  int uniqueCount = countUniqueNumbers(container);
  std::cout << "Уникальных чисел: " << uniqueCount << std::endl;




  #elif Unit==2
  std::cout << "Задание 2" << std::endl; // Вызов функции задания 2 из отдельного файла

  // ===== Задача а) =====
  std::vector<int> vec = {1, 2, 3, 4, 5, 6};
  std::list<int> lst = {10, 21, 30, 41, 50};

  std::cout << "Исходный вектор: ";
  printVector(vec);
  std::cout << "Исходный список: ";
  printList(lst);

  std::vector<int> result = replaceEvenWithListOdd(vec, lst);
  std::cout << "Результат замены: ";
  printVector(result);

  //===== Задача b)=====
  std::list<double> numbers = {1.5, 2.5, 3.5, 4.5};
  std::cout << "\nИсходный список (вещественные числа): ";
  for (double num : numbers) std::cout << num << " ";

  addAverageToList(numbers);
  std::cout << "\nПосле добавления среднего: ";
  for (double num : numbers) std::cout << num << " ";
  std::cout << std::endl;


  //===== Задача c)=====
  std::cout << "\nВвод любимых цветов:\n";
  processFavoriteColors();

  #elif Unit==3
  std::cout << "Задание 3" << std::endl; // Вызов функции задания 3 из отдельного файла
  try {
    double value;
    std::string unit;

    std::cout << "Введите значение: ";
    if (!(std::cin >> value)) {
      throw std::runtime_error("Ошибка: введено нечисловое значение");
    }

    std::cout << "Введите единицу измерения (bit, byte, Kbyte, Mbyte, Gbyte, MiB): ";
    if (!(std::cin >> unit)) {
      throw std::runtime_error("Ошибка ввода единицы измерения");
    }

    DataSizeConverter converter(value, unit);
    converter.convert();
    converter.printResults();

    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
      // Очистка буфера ввода в случае ошибки
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return 1;
    }




  #elif Unit==4
  std::cout << "Задание 4" << std::endl; // Вызов функции задания 4 из отдельного файла
  TreeNode root(1);
  auto left_son = root.AddChild(10);
  auto middle_son = root.AddChild(20);
  auto right_son = root.AddChild(30);
  left_son->AddChild(100);
  left_son->AddChild(200);
  root.Print();



  #else
  // Создаем буфер на 5 элементов
  CircularBuffer<int> cb(5);

  // Тестирование
  cb.add(1);
  cb.add(2);
  cb.add(3);

  const CircularBuffer<int>& const_cb = cb;
  // Вызов const-методов
  const_cb.printAll();
  const_cb.printRange(0, 2);

  // Запуск потока записи
  cb.startWriterThread();

  // Ожидание завершения
  std::cout << "Press 'q' to quit..." << std::endl;
  while (cb.isRunning()) {
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
  }



  #endif
  return 0;
  }
