/**************************************************************************************
 * Filename: t7.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 5
 * Исследование строк, структур памяти С++ в IDE Qt Creator
 * Задание 7
 * ************************************************************************************/

#include <iostream>
#include <string>
#include "lab5.h"


// Функция для преобразования числа в строку
std::string intToString(int number){
  if (number == 0){
    return "0"; // Если число равно 0
  }

  // Обрабатываем отрицательные числа
  bool isNegative = false;
  if (number < 0){
    isNegative = true;
    number = -number;
  }

  std::string result;

  // Извлекаем цифры и добавляем их в строку
  do {
    char digit = '0' + (number % 10); // выделяем последнюю цифру
    result += digit; // добавляем цифру в строку
    number /= 10; // удаляем последнюю цифру
  } while (number > 0);

  // Если число отрицательное, добавляем минус
  if (isNegative){
  result += '-';
  }

  // Переворачиваем строку вручную, так как цифры добавлялись в обратном порядке
  std::string finalResult;
  for (int i = result.length() - 1; i >= 0; --i){
    finalResult += result[i];
  }
  return finalResult;
}

// Функция для преобразования строки в число
int stringToInt(const std::string& str){
  int result = 0;
  int sign = 1; // Знак числа
  size_t i = 0;

  // Обработка знака
  if (str[0] == '-') {
    sign = -1;
    i = 1; // Пропускаем знак минус
  }

  // Преобразование строки в число

  for (; i < str.length(); ++i){
    result = result * 10 + (str[i] - '0'); // Преобразуем символ в цифру
  }
  return result;
}

