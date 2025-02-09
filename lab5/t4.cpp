/**************************************************************************************
 * Filename: t4.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 5
 * Исследование строк, структур памяти С++ в IDE Qt Creator
 * Задание 4
 * ************************************************************************************/

#include <iostream>
#include <string>
#include <cctype> // Для isdigit и toupper
#include "lab5.h"

std::string unpackString(const std::string& packed) {
  std::string result; //строка для хранения результата
  int i = 0;
  while (i < packed.length()) {
    // Если текущий символ цифра, извлекаем число
    if (isdigit(packed[i])) {
      int count = 0;
      // Считываем все цифры числа
      while (i < packed.length() && isdigit(packed[i])) {
        count = count * 10 + (packed[i] - '0');  //для обработки многозначных чисел умножаем на 10
          i++;
      }
      // Если после числа идет буква, добавляем её count раз
      if (i < packed.length() && isalpha(packed[i])) {
        char ch = toupper(packed[i]); // Преобразуем в верхний регистр
        result.append(count, ch);
        i++;
      }
    } else if (isalpha(packed[i])) {
      // Если символ ? буква, добавляем её один раз
      char ch = toupper(packed[i]); // Преобразуем в верхний регистр
      result += ch;
      i++;
    } else {
      // Пропускаем недопустимые символы
      i++;
    }
  }
    return result;
}
