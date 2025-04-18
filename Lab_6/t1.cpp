/**************************************************************************************
 * Filename: t1.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 6
 * Исследование С++ классов в IDE Qt Creator
 * Задание 1
 * ************************************************************************************/


#include <iostream>
#include "lab6.h"
#include <algorithm>

// Конструктор с настройкой параметров перебора
Bruteforce::Bruteforce(bool m_useDigits, bool m_useLower,
                       bool m_useUpper, bool m_useSpecial,
                       int m_maxLength) : m_maxLength(m_maxLength) {
  // Добавляем цифры, если нужно
  if (m_useDigits) {
    for (char c = '0'; c <= '9'; ++c) {
      chars.push_back(c);
    }
  }

  // Добавляем строчные буквы, если нужно
  if (m_useLower) {
    for (char c = 'a'; c <= 'z'; ++c) {
      chars.push_back(c);
    }
  }

  // Добавляем заглавные буквы, если нужно
  if (m_useUpper) {
    for (char c = 'A'; c <= 'Z'; ++c) {
      chars.push_back(c);
      }
  }

  // Добавляем специальные символы, если нужно
  if (m_useSpecial) {
    const std::string specials = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    for (char c : specials) {
      chars.push_back(c);
    }
  }
}

// Установка пользовательского набора символов
void Bruteforce::setCustomChars(const std::string& customChars) {
  chars.clear();
  for (char c : customChars) {
    chars.push_back(c);
  }
}

// Основная функция для подбора пароля
std::string Bruteforce::findPassword(const std::string& target) {
  std::string current;

  // Проверяем пароли длиной от 1 до maxLength
  for (int length = 1; length <= m_maxLength; ++length) {
    if (generateCombinations(target, current, length)) {
      return current;
        }
    }

    return "";  // В теории сюда никогда не дойдем по условию задачи,
                //но защита от гипотетически возможных случаев
}

// Рекурсивная функция для генерации комбинаций
bool Bruteforce::generateCombinations(const std::string& target,
                                     std::string& current, int length) {
  // Базовый случай рекурсии
  if (current.length() == length) {
    return current == target;
  }

  // Рекурсивный случай
  for (char c : chars) {
    current.push_back(c);
    if (generateCombinations(target, current, length)) {
      return true;
    }
  current.pop_back();
  }

    return false;
}
