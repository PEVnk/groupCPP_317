/**************************************************************************************
 * Filename: t5.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 5
 * Исследование строк, структур памяти С++ в IDE Qt Creator
 * Задание 5
 * ************************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include "lab5.h"

void processString(std::string& str) {
  // Заменяем все табуляции на пробелы
  std::replace(str.begin(), str.end(), '\t', ' ');

  // Удаляем двойные пробелы через поиск и замену подстроки
  size_t pos;
  while ((pos = str.find("  ")) != std::string::npos) {
    str.replace(pos, 2, " "); // Заменяем два пробела на один
  }
}
