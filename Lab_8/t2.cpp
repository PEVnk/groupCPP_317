/**************************************************************************************
 * Filename: t2.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 8
 * Исследование в С++ стандартной библиотеки шаблонов (STL), перегрузка операторов
 * ***********************************************************************************/

#include <iostream>
#include "lab8.h"
#include <algorithm> // Для std::sort
#include <numeric>   // Для std::accumulate

// ===== Задача а) =====

// Функция заменяет чётные элементы вектора на нечётные элементы списка
std::vector<int> replaceEvenWithListOdd(std::vector<int>& vec, std::list<int>& lst) {
  std::vector<int> result = vec; // Копируем исходный вектор
  auto listIt = lst.begin(); // Итератор для списка

  // Проходим по вектору
  for (size_t i = 0; i < result.size(); ++i) {
    if (result[i] % 2 == 0) { // Если элемент чётный
      // Ищем нечётный элемент в списке
      while (listIt != lst.end()) {
        if (*listIt % 2 != 0) { // Нашли нечётный
          result[i] = *listIt; // Заменяем
          ++listIt;            // Переходим к следующему
          break;
        }
      ++listIt;
      }
    }
  }
return result;
}

// Вывод вектора
void printVector(const std::vector<int>& vec) {
  for (int num : vec) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

// Вывод списка
void printList(const std::list<int>& lst) {
  for (int num : lst) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

//===== Задача b)=====

// Добавляет в конец списка среднее арифметическое
void addAverageToList(std::list<double>& lst) {
  if (lst.empty()) return;

  double sum = std::accumulate(lst.begin(), lst.end(), 0.0);
  double average = sum / lst.size();
  lst.push_back(average);
}

//===== Задача c)=====

// Обрабатывает любимые цвета
void processFavoriteColors() {
  std::vector<std::pair<int, std::string>> colors(3); // 3 пары (номер, цвет)

  std::cout << "Введите 3 любимых цвета в формате: рейтинг, название_цвета через пробел\n";
  for (int i = 0; i < 3; ++i) {
    std::cout << "Цвет " << i+1 << ": ";
    std::cin >> colors[i].first >> colors[i].second;
  }

  // Сортируем по номерам (степени любимости)
  std::sort(colors.begin(), colors.end());

  std::cout << "Ваши любимые цвета (по степени любимости):\n";
  printColors(colors);
}

// Вывод цветов
void printColors(const std::vector<std::pair<int, std::string>>& colors) {
  for (const auto& pair : colors) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }
}
