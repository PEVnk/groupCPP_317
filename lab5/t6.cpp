/**************************************************************************************
 * Filename: t6.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 5
 * Исследование строк, структур памяти С++ в IDE Qt Creator
 * Задание 6
 * ************************************************************************************/

#include <iostream>
#include <string>
#include "lab5.h"
#include <algorithm>

// Функция для ввода строк
int inputStrings(std::string strings[], int maxStrings) {
  int count = 0;
  std::string input;

  std::cout << "Введите строки (максимум " << maxStrings << " строк). Для завершения ввода введите пустую строку:\n";

  while (count < maxStrings) {
    std::getline(std::cin, input);
    if (input.empty()) {
    break; // Завершение ввода
    }
    if (input.length() > numLength) {
      std::cout << "Строка слишком длинная. Максимальная длина: " << numLength << " символов.\n";
      continue;
    }
      strings[count] = input;
      count++;
  }

    return count;
}

// Функция для сортировки строк по длине
void sortLength(std::string strings[], int count) {
  std::sort(strings, strings + count, [](const std::string& a, const std::string& b) {
    return a.length() < b.length();
  });
}

// Функция для сортировки строк по алфавиту
void sortAlphabet(std::string strings[], int count) {
  std::sort(strings, strings + count);
}

// Функция для вывода строк
void printStrings(const std::string strings[], int count) {
  std::cout << "Результат:\n";
  for (int i = 0; i < count; ++i) {
    std::cout << strings[i] << "\n";
  }
}
