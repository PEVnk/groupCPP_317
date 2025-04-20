/**************************************************************************************
 * Filename: t1.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 7
 * Исследование С++ классов в IDE Qt Creator
 * ***********************************************************************************/

#include <iostream>
#include <thread>
#include <stdexcept>
#include <vector>
#include "lab7.h"

// Проверка входных данных
void FibonacciCalculation::validateInput(int n) {
  if (n == 9) {
    throw std::invalid_argument("Вычисление 9-го числа Фибоначчи запрещено.");
  }
  if (n < 0) {
    throw std::invalid_argument("Номер числа Фибоначчи должен быть неотрицательным.");
  }
}

// Функция параллельного вычисления, выполняемая в каждом потоке
void FibonacciCalculation::compute(int n,
                                   std::vector<unsigned long long>& sequence, // Массив результатов
                                   std::vector<bool>& ready, // Флаги готовности значений
                                   std::mutex& mtx, // Общий мьютекс
                                   std::vector<std::condition_variable>& cv) {// Условные переменные
  // Каждый поток вычисляет все числа последовательности, но синхронизируется с другими
  for (int i = 1; i <= n; ++i) {
    // Захватываем мьютекс для работы с общими данными
    std::unique_lock<std::mutex> lock(mtx);

    // Для всех элементов кроме первого ждем готовности предыдущего
    if (i > 1) {
      // Ожидаем на условной переменной, пока предыдущее значение не будет готово
      cv[(i-1) % cv.size()].wait(lock, [&ready, i] {
        return ready[i-1];  // Проверяем готовность предыдущего элемента
      });
    }

    // Вычисляем текущее число Фибоначчи
    if (i == 1) {
      sequence[i] = 1;  // Базовый случай F(1) = 1
    } else {
      sequence[i] = sequence[i-1] + sequence[i-2];  // Основная формула
    }

    // Помечаем текущее значение как готовое
    ready[i] = true;
    lock.unlock();

    // Уведомляем следующий поток, что может продолжать
    cv[i % cv.size()].notify_one(); //Разблокирует один из потоков
  }
}

// Основная функция вычисления
unsigned long long FibonacciCalculation::calculate(int n) {
  validateInput(n);  // Сначала проверяем входные данные

  // Базовые случаи
  if (n <= 1) return n;

  // Определяем количество потоков (по числу ядер процессора)
  unsigned num_threads = std::thread::hardware_concurrency();
  if (num_threads == 0) num_threads = 1;  // Если не удалось определить

  // Инициализируем структуры данных:
  std::vector<unsigned long long> sequence(n+1, 0);  // Последовательность Фибоначчи
  std::vector<bool> ready(n+1, false);               // Флаги готовности
  sequence[0] = 0;  // Базовый случай F(0) = 0
  ready[0] = true;  // Нулевой элемент готов сразу

  std::mutex mtx;  // Для синхронизации и защиты доступа к общим данным
  std::vector<std::condition_variable> cv(num_threads);  // // Набор условных переменных для синхронизации потоков

  // Создаем и запускаем потоки
  std::vector<std::thread> threads;
  for (unsigned i = 0; i < num_threads; ++i) {
    // Каждый поток выполняет compute с доступом к общим данным
    threads.emplace_back(compute, n, std::ref(sequence),
                         std::ref(ready), std::ref(mtx), std::ref(cv));
  }

  // Ожидаем завершения всех потоков
  for (auto& t : threads) {
    t.join();
  }

  return sequence[n];  // Возвращаем результат
}
