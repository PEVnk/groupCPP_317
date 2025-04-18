/**************************************************************************************
 * Filename: t2.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 6
 * ��᫥������� �++ ����ᮢ � IDE Qt Creator
 * ������� 2
 * ************************************************************************************/


#include <iostream>
#include "lab6.h"
#include <algorithm>

PalindromeChecker::PalindromeChecker() {}

void PalindromeChecker::inputData() {
  std::cout << "������ �� " << MAX_SIZE << " ����⮢ (�ᥫ ��� ᫮�). "
         << "��� �����襭�� ����� ������ 'end':" << std::endl;

  std::string input;
  while (elements.size() < MAX_SIZE) {
    std::cout << "������� " << elements.size() + 1 << ": ";
    std::cin >> input;

    if (input == "end") {
      break;
    }

    elements.push_back(input);
  }

  std::cout << "���� �����襭. �ᥣ� ����⮢: " << elements.size() << std::endl;
}

  std::string PalindromeChecker::cleanString(const std::string& s) const {
    std::string cleaned;

    for (char c : s) {
    // �ਢ���� � ������� ॣ����� � �஢��塞, �� ᨬ��� - �㪢� ��� ���
      if (isalnum(c)) {
        cleaned += tolower(c);
      }
    }

  return cleaned;
  }

  bool PalindromeChecker::isPalindrome() const {
    // ��ꥤ��塞 �� ������ � ���� ��ப�
    std::string combined;
    for (const auto& elem : elements) {
      combined += cleanString(elem);
    }

    // �஢��塞 �� ������஬
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
    std::cout << "�������� ������: ";
    for (const auto& elem : elements) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;

    if (isPalindrome()) {
      std::cout << "�� ������஬!" << std::endl;
    } else {
      std::cout << "�� �� ������஬." << std::endl;
    }
  }
