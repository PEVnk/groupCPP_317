/**************************************************************************************
 * Filename: t3.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 8
 * ��᫥������� � �++ �⠭���⭮� ������⥪� 蠡����� (STL), ��ॣ�㧪� �����஢
 * ***********************************************************************************/

#include <iostream>
#include "lab8.h"
#include <cmath>
#include <stdexcept>

// ���������
DataSizeConverter::DataSizeConverter(double value, const std::string& unit)
  : inputValue(value), inputUnit(unit) {
  // �஢�ઠ �� ����⥫�� ���祭��
  if (value < 0) {
    throw std::invalid_argument("�訡��: ���祭�� �� ����� ���� ����⥫��");
  }
  // �஢�ઠ �����⨬��� ������� ����७��
  if (!isValidUnit()) {
    throw std::invalid_argument("�������ন������ ������ ����७��");
  }
}

// �஢�ઠ ���४⭮�� �室��� ������� ����७��
bool DataSizeConverter::isValidUnit() const {
  const std::vector<std::string> validUnits = {"bit", "byte", "Kbyte", "Mbyte", "Gbyte", "MiB"};
  for (const auto& unit : validUnits) {
    if (unit == inputUnit) return true;
  }
  return false;
}


// �᭮���� �㭪�� �������樨
void DataSizeConverter::convert() {
  if (inputUnit == "bit")       convertFromBit();
  else if (inputUnit == "byte") convertFromByte();
  else if (inputUnit == "Kbyte") convertFromKbyte();
  else if (inputUnit == "Mbyte") convertFromMbyte();
  else if (inputUnit == "Gbyte") convertFromGbyte();
  else if (inputUnit == "MiB")   convertFromMiB();
}

// ��������� �� ��⮢
void DataSizeConverter::convertFromBit() {
  results.push_back(inputValue / 8);                  // byte
  results.push_back(inputValue / (8 * 1024));         // Kbyte
  results.push_back(inputValue / (8 * 1024 * 1024));  // Mbyte
  results.push_back(inputValue / (8 * 1024 * 1024 * 1024)); // Gbyte
  results.push_back(inputValue / (8 * 1024 * 1024));  // MiB (ࠢ�� Mbyte)
}

// ��������� �� ���⮢
void DataSizeConverter::convertFromByte() {
  results.push_back(inputValue * 8);                  // bit
  results.push_back(inputValue / 1024);               // Kbyte
  results.push_back(inputValue / (1024 * 1024));      // Mbyte
  results.push_back(inputValue / (1024 * 1024 * 1024)); // Gbyte
  results.push_back(inputValue / (1024 * 1024));      // MiB
}

// ��������� �� �������⮢
void DataSizeConverter::convertFromKbyte() {
  results.push_back(inputValue * 1024 * 8);           // bit
  results.push_back(inputValue * 1024);               // byte
  results.push_back(inputValue / 1024);               // Mbyte
  results.push_back(inputValue / (1024 * 1024));      // Gbyte
  results.push_back(inputValue / 1024);               // MiB
}

// ��������� �� �������⮢
void DataSizeConverter::convertFromMbyte() {
  results.push_back(inputValue * 1024 * 1024 * 8);    // bit
  results.push_back(inputValue * 1024 * 1024);        // byte
  results.push_back(inputValue * 1024);               // Kbyte
  results.push_back(inputValue / 1024);               // Gbyte
  results.push_back(inputValue);                      // MiB (ࠢ�� Mbyte)
}

// ��������� �� �������⮢
void DataSizeConverter::convertFromGbyte() {
  results.push_back(inputValue * 1024 * 1024 * 1024 * 8); // bit
  results.push_back(inputValue * 1024 * 1024 * 1024);   // byte
  results.push_back(inputValue * 1024 * 1024);          // Kbyte
  results.push_back(inputValue * 1024);                 // Mbyte
  results.push_back(inputValue * 1024);                 // MiB
}

// ��������� �� �������⮢
void DataSizeConverter::convertFromMiB() {
  results.push_back(inputValue * 1024 * 1024 * 8);     // bit
  results.push_back(inputValue * 1024 * 1024);        // byte
  results.push_back(inputValue * 1024);               // Kbyte
  results.push_back(inputValue);                      // Mbyte
  results.push_back(inputValue / 1024);               // Gbyte
}

// �뢮� १���⮢
void DataSizeConverter::printResults() const {
  const std::vector<std::string> units = {"bit", "byte", "Kbyte", "Mbyte", "Gbyte", "MiB"};

  std::cout << "\n�������� �������樨:" << std::endl;
  std::cout << "��室��� ���祭��: " << inputValue << " " << inputUnit << std::endl;

  size_t i = 0;
  for (const auto& unit : units) {
    if (unit != inputUnit) {
      std::cout << unit << ": " << results[i++] << std::endl;
    }
  }
}
