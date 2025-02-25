/**************************************************************************************
 * Filename: t87.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 5
 * ��᫥������� ��ப, ������� ����� �++ � IDE Qt Creator
 * ������� 8
 * ************************************************************************************/

#include <iostream>
#include <string>
#include "lab5.h"
#include <stdexcept>
#include <algorithm>

// �㭪�� ��� ࠧ��� ��ப�
void Parse(const std::string& line, Address* const address){
  if (!address) {
    throw std::invalid_argument("Address pointer is null");
  }

  size_t start = 0;
  size_t end = line.find(',');
  if (end == std::string::npos){
    throw std::invalid_argument("Invalid address format");
  }
  address->Country = std::string(&line[start], &line[end]); // �����㥬 ᨬ���� �� start �� end
  start = end + 1;

  end = line.find(',', start);
  if (end == std::string::npos){
    throw std::invalid_argument("Invalid address format");
  }
  address->City = std::string(&line[start], &line[end]); // �����㥬 ᨬ���� �� start �� end
  start = end + 1;

  end = line.find(',', start);
  if (end == std::string::npos){
    throw std::invalid_argument("Invalid address format");
  }
  address->Street = std::string(&line[start], &line[end]); // �����㥬 ᨬ���� �� start �� end
  start = end + 1;

  address->House = std::string(&line[start], &line[line.size()]); // �����㥬 ᨬ���� �� start �� ���� ��ப�
}

// �㭪�� ��� �ਢ������ ���� � �������᪮�� ����
void Unify(Address* const address){
  if (!address){
    throw std::invalid_argument("Address pointer is null");
  }

  // �ਬ�� �ਢ������ � �������᪮�� ����
  if (address->Street.find("��-�") != std::string::npos){
    address->Street.replace(address->Street.find("��-�"), 4, "�஥��");
  }

  // ����塞 ��譨� �஡���
  address->Country.erase(0, address->Country.find_first_not_of(' '));
  address->Country.erase(address->Country.find_last_not_of(' ') + 1);
  address->City.erase(0, address->City.find_first_not_of(' '));
  address->City.erase(address->City.find_last_not_of(' ') + 1);
  address->Street.erase(0, address->Street.find_first_not_of(' '));
  address->Street.erase(address->Street.find_last_not_of(' ') + 1);
  address->House.erase(0, address->House.find_first_not_of(' '));
  address->House.erase(address->House.find_last_not_of(' ') + 1);
}

// �㭪�� ��� �ଠ�஢���� ���� � ��ப�
std::string Format(const Address& address){
  return address.Country + ", " + address.City + ", " + address.Street + ", " + address.House;
}
