/**************************************************************************************
 * Filename: t87.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 5
 * Исследование строк, структур памяти С++ в IDE Qt Creator
 * Задание 8
 * ************************************************************************************/

#include <iostream>
#include <string>
#include "lab5.h"
#include <stdexcept>
#include <algorithm>

// Функция для разбора строки
void Parse(const std::string& line, Address* const address){
  if (!address) {
    throw std::invalid_argument("Address pointer is null");
  }

  size_t start = 0;
  size_t end = line.find(',');
  if (end == std::string::npos){
    throw std::invalid_argument("Invalid address format");
  }
  address->Country = std::string(&line[start], &line[end]); // Копируем символы от start до end
  start = end + 1;

  end = line.find(',', start);
  if (end == std::string::npos){
    throw std::invalid_argument("Invalid address format");
  }
  address->City = std::string(&line[start], &line[end]); // Копируем символы от start до end
  start = end + 1;

  end = line.find(',', start);
  if (end == std::string::npos){
    throw std::invalid_argument("Invalid address format");
  }
  address->Street = std::string(&line[start], &line[end]); // Копируем символы от start до end
  start = end + 1;

  address->House = std::string(&line[start], &line[line.size()]); // Копируем символы от start до конца строки
}

// Функция для приведения адреса к каноническому виду
void Unify(Address* const address){
  if (!address){
    throw std::invalid_argument("Address pointer is null");
  }

  // Пример приведения к каноническому виду
  if (address->Street.find("пр-д") != std::string::npos){
    address->Street.replace(address->Street.find("пр-д"), 4, "проезд");
  }

  // Удаляем лишние пробелы
  address->Country.erase(0, address->Country.find_first_not_of(' '));
  address->Country.erase(address->Country.find_last_not_of(' ') + 1);
  address->City.erase(0, address->City.find_first_not_of(' '));
  address->City.erase(address->City.find_last_not_of(' ') + 1);
  address->Street.erase(0, address->Street.find_first_not_of(' '));
  address->Street.erase(address->Street.find_last_not_of(' ') + 1);
  address->House.erase(0, address->House.find_first_not_of(' '));
  address->House.erase(address->House.find_last_not_of(' ') + 1);
}

// Функция для форматирования адреса в строку
std::string Format(const Address& address){
  return address.Country + ", " + address.City + ", " + address.Street + ", " + address.House;
}
