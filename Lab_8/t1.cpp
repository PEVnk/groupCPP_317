/**************************************************************************************
 * Filename: t1.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 8
 * Исследование в С++ стандартной библиотеки шаблонов (STL), перегрузка операторов
 * ***********************************************************************************/

#include <iostream>
#include "lab8.h"
#include <ctime>
#include <random>   // Для генерации случайных чисел
#include <unordered_set> // Для std::unordered_set (подсчёт уникальных чисел)

// Генерация N случайных чисел в диапазоне [-100, 100]
std::vector<int> generateRandomNumbers(int N) {
  std::vector<int> numbers; // Вектор для хранения чисел

  // Инициализация генератора случайных чисел
  std::default_random_engine gen(time(0));
  std::uniform_int_distribution<int> dist(-100, 100);

  // Заполняем вектор N случайными числами
  for (int i = 0; i < N; ++i) {
    numbers.push_back(dist(gen)); // Добавляем случайное число
  }

  return numbers; // Возвращаем заполненный вектор
}

// Выводит контейнер в прямом и обратном порядке по 10 чисел в строке
void printContainer(const std::vector<int>& container) {
  std::cout << "Содержимое контейнера (прямой порядок):" << std::endl;
  for (size_t i = 0; i < container.size(); ++i) {
    std::cout << container[i] << " ";
    // Каждые 10 элементов переходим на новую строку
    if ((i + 1) % 10 == 0) {
      std::cout << std::endl;
    }
  }
    // Если последняя строка не полная, добавляем перевод строки
    if (container.size() % 10 != 0) {
        std::cout << std::endl;
    }

  // Выводим в обратном порядке
  printContainerReverse(container);
}

// Выводит контейнер в обратном порядке (с использованием обратного итератора)
void printContainerReverse(const std::vector<int>& container) {
  std::cout << "Содержимое контейнера (обратный порядок):" << std::endl;
  size_t count = 0;

  // Используем обратный итератор (rbegin, rend)
  for (auto it = container.rbegin(); it != container.rend(); ++it) {
    std::cout << *it << " ";
    // Каждые 10 элементов переходим на новую строку
    if (++count % 10 == 0) {
      std::cout << std::endl;
        }
    }
    // Если последняя строка не полная, добавляем перевод строки
    if (count % 10 != 0) {
      std::cout << std::endl;
    }
}

// Подсчёт уникальных чисел с помощью std::unordered_set
int countUniqueNumbers(const std::vector<int>& container) {
  // unordered_set автоматически удаляет дубликаты
  std::unordered_set<int> uniqueNumbers(container.begin(), container.end());

  // Размер множества = количество уникальных чисел
  return uniqueNumbers.size();
}


