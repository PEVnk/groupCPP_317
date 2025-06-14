/**************************************************************************************
 * Filename: t3.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 8
 * Исследование в С++ стандартной библиотеки шаблонов (STL), перегрузка операторов
 * ***********************************************************************************/

#include <iostream>
#include "lab8.h"
#include <cmath>
#include <stdexcept>

// Конструктор
DataSizeConverter::DataSizeConverter(double value, const std::string& unit)
  : inputValue(value), inputUnit(unit) {
  // Проверка на отрицательные значения
  if (value < 0) {
    throw std::invalid_argument("Ошибка: значение не может быть отрицательным");
  }
  // Проверка допустимости единицы измерения
  if (!isValidUnit()) {
    throw std::invalid_argument("Неподдерживаемая единица измерения");
  }
}

// Проверка корректности входной единицы измерения
bool DataSizeConverter::isValidUnit() const {
  const std::vector<std::string> validUnits = {"bit", "byte", "Kbyte", "Mbyte", "Gbyte", "MiB"};
  for (const auto& unit : validUnits) {
    if (unit == inputUnit) return true;
  }
  return false;
}


// Основная функция конвертации
void DataSizeConverter::convert() {
  if (inputUnit == "bit")       convertFromBit();
  else if (inputUnit == "byte") convertFromByte();
  else if (inputUnit == "Kbyte") convertFromKbyte();
  else if (inputUnit == "Mbyte") convertFromMbyte();
  else if (inputUnit == "Gbyte") convertFromGbyte();
  else if (inputUnit == "MiB")   convertFromMiB();
}

// Конвертация из битов
void DataSizeConverter::convertFromBit() {
  results.push_back(inputValue / 8);                  // byte
  results.push_back(inputValue / (8 * 1024));         // Kbyte
  results.push_back(inputValue / (8 * 1024 * 1024));  // Mbyte
  results.push_back(inputValue / (8 * 1024 * 1024 * 1024)); // Gbyte
  results.push_back(inputValue / (8 * 1024 * 1024));  // MiB (равен Mbyte)
}

// Конвертация из байтов
void DataSizeConverter::convertFromByte() {
  results.push_back(inputValue * 8);                  // bit
  results.push_back(inputValue / 1024);               // Kbyte
  results.push_back(inputValue / (1024 * 1024));      // Mbyte
  results.push_back(inputValue / (1024 * 1024 * 1024)); // Gbyte
  results.push_back(inputValue / (1024 * 1024));      // MiB
}

// Конвертация из килобайтов
void DataSizeConverter::convertFromKbyte() {
  results.push_back(inputValue * 1024 * 8);           // bit
  results.push_back(inputValue * 1024);               // byte
  results.push_back(inputValue / 1024);               // Mbyte
  results.push_back(inputValue / (1024 * 1024));      // Gbyte
  results.push_back(inputValue / 1024);               // MiB
}

// Конвертация из мегабайтов
void DataSizeConverter::convertFromMbyte() {
  results.push_back(inputValue * 1024 * 1024 * 8);    // bit
  results.push_back(inputValue * 1024 * 1024);        // byte
  results.push_back(inputValue * 1024);               // Kbyte
  results.push_back(inputValue / 1024);               // Gbyte
  results.push_back(inputValue);                      // MiB (равен Mbyte)
}

// Конвертация из гигабайтов
void DataSizeConverter::convertFromGbyte() {
  results.push_back(inputValue * 1024 * 1024 * 1024 * 8); // bit
  results.push_back(inputValue * 1024 * 1024 * 1024);   // byte
  results.push_back(inputValue * 1024 * 1024);          // Kbyte
  results.push_back(inputValue * 1024);                 // Mbyte
  results.push_back(inputValue * 1024);                 // MiB
}

// Конвертация из мебибайтов
void DataSizeConverter::convertFromMiB() {
  results.push_back(inputValue * 1024 * 1024 * 8);     // bit
  results.push_back(inputValue * 1024 * 1024);        // byte
  results.push_back(inputValue * 1024);               // Kbyte
  results.push_back(inputValue);                      // Mbyte
  results.push_back(inputValue / 1024);               // Gbyte
}

// Вывод результатов
void DataSizeConverter::printResults() const {
  const std::vector<std::string> units = {"bit", "byte", "Kbyte", "Mbyte", "Gbyte", "MiB"};

  std::cout << "\nРезультаты конвертации:" << std::endl;
  std::cout << "Исходное значение: " << inputValue << " " << inputUnit << std::endl;

  size_t i = 0;
  for (const auto& unit : units) {
    if (unit != inputUnit) {
      std::cout << unit << ": " << results[i++] << std::endl;
    }
  }
}
