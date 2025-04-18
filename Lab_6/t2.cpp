/**************************************************************************************
 * Filename: t2.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 6
 * Исследование С++ классов в IDE Qt Creator
 * Задание 2
 * ************************************************************************************/


#include <iostream>
#include "lab6.h"
#include <algorithm>

PalindromeChecker::PalindromeChecker() {}

void PalindromeChecker::inputData() {
  std::cout << "Введите до " << MAX_SIZE << " элементов (чисел или слов). "
         << "Для завершения ввода введите 'end':" << std::endl;

  std::string input;
  while (elements.size() < MAX_SIZE) {
    std::cout << "Элемент " << elements.size() + 1 << ": ";
    std::cin >> input;

    if (input == "end") {
      break;
    }

    elements.push_back(input);
  }

  std::cout << "Ввод завершен. Всего элементов: " << elements.size() << std::endl;
}

  std::string PalindromeChecker::cleanString(const std::string& s) const {
    std::string cleaned;

    for (char c : s) {
    // Приводим к нижнему регистру и проверяем, что символ - буква или цифра
      if (isalnum(c)) {
        cleaned += tolower(c);
      }
    }

  return cleaned;
  }

  bool PalindromeChecker::isPalindrome() const {
    // Объединяем все элементы в одну строку
    std::string combined;
    for (const auto& elem : elements) {
      combined += cleanString(elem);
    }

    // Проверяем на палиндром
    int left = 0;
    int right = combined.length() - 1;

    while (left < right) {
      if (combined[left] != combined[right]) {
        return false;
      }
      left++;
      right--;
    }

    return true;
  }
  void PalindromeChecker::printResult() const {
    std::cout << "Введенные элементы: ";
    for (const auto& elem : elements) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;

    if (isPalindrome()) {
      std::cout << "Это палиндром!" << std::endl;
    } else {
      std::cout << "Это НЕ палиндром." << std::endl;
    }
  }
