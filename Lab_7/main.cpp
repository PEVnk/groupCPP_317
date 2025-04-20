/**************************************************************************************
 * Filename: main.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 7
 * Исследование С++ классов в IDE Qt Creator
 * ***********************************************************************************/

#include <iostream>
#include <stdexcept>
#include <thread>
#include <random>
#include <vector>
#include <chrono>
#include "lab7.h"
#include "MyMessage.h"

#define Unit 4

int main()
{
  #if Unit==1
  std::cout << "Задание 1" << std::endl; // Вызов функции задания 1 из отдельного файла

  int n;
  std::cout << "Введите номер числа Фибоначчи: ";
  std::cin >> n;

  try {
    unsigned long long result = FibonacciCalculation::calculate(n);
    std::cout << n << "-е число Фибоначчи: " << result << std::endl;
    }
  // Обрабатываем исключение invalid_argument (выбрасывается при n=9 или отрицательном n)
  catch (const std::invalid_argument& e) {
    std::cerr << "Ошибка: " << e.what() << std::endl; // Выводим сообщение об ошибке в стандартный поток ошибок
    return 1;
  }
  // Обрабатываем любые другие исключения
  catch (...) {
    std::cerr << "Неизвестная ошибка при вычислении числа Фибоначчи" << std::endl;
    return 2;
  }


  #elif Unit==2
  std::cout << "Задание 2" << std::endl; // Вызов функции задания 2 из отдельного файла

  // Создаем два счета с начальным балансом 1000 рублей
  Account acc1(1, 1000.0);
  Account acc2(2, 1000.0);

  // Выводим начальные балансы
  std::cout << "Начальные балансы:\n";
  std::cout << "Счет " << acc1.getId() << ": " << acc1.getBalance() << "руб.\n";
  std::cout << "Счет " << acc2.getId() << ": " << acc2.getBalance() << "руб.\n\n";

  // Запускаем переводы в разных потоках
  std::thread t1([&acc1, &acc2]() {
  bool success = Account::transfer(acc1, acc2, 500.0);
  std::cout << "Перевод 500 руб. со счета 1 на счет 2: "
                           << (success ? "успешно" : "недостаточно средств") << "\n";
  });

  std::thread t2([&acc2, &acc1]() {
  bool success = Account::transfer(acc2, acc1, 1200.0);
  std::cout << "Перевод 1200 руб. со счета 2 на счет 1: "
                           << (success ? "успешно" : "недостаточно средств") << "\n";
  });

  // Ждем завершения потоков
  t1.join();
  t2.join();

  // Выводим итоговые балансы
  std::cout << "\nИтоговые балансы:\n";
  std::cout << "Счет " << acc1.getId() << ": " << acc1.getBalance() << "руб.\n";
  std::cout << "Счет " << acc2.getId() << ": " << acc2.getBalance() << "руб.\n\n";



  #else
  using namespace Config;  // Используем константы из namespace

  MyMessage logger;
  std::vector<int> array(ARRAY_SIZE);  // Используем ARRAY_SIZE из namespace

  // Запуск потока логгера
  std::thread loggerThread([&logger]() {
    logger.processQueue();
  });

  // Запуск рабочих потоков
  std::thread filler(Workers::fillRandomNumbers, std::ref(array), std::ref(logger));
  std::thread filter(Workers::filterArray, std::ref(array), std::ref(logger));
  std::thread printer(Workers::printArray, std::ref(array), std::ref(logger));

  // Ожидание завершения
  filler.join();
  filter.join();
  printer.join();

  logger.stopProcessing();
  loggerThread.join();


  #endif
  return 0;
}
