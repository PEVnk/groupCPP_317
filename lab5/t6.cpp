/**************************************************************************************
 * Filename: t6.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 5
 * ��᫥������� ��ப, ������� ����� �++ � IDE Qt Creator
 * ������� 6
 * ************************************************************************************/

#include <iostream>
#include <string>
#include "lab5.h"
#include <algorithm>

// �㭪�� ��� ����� ��ப
int inputStrings(std::string strings[], int maxStrings) {
  int count = 0;
  std::string input;

  std::cout << "������ ��ப� (���ᨬ� " << maxStrings << " ��ப). ��� �����襭�� ����� ������ ������ ��ப�:\n";

  while (count < maxStrings) {
    std::getline(std::cin, input);
    if (input.empty()) {
    break; // �����襭�� �����
    }
    if (input.length() > numLength) {
      std::cout << "��ப� ᫨誮� �������. ���ᨬ��쭠� �����: " << numLength << " ᨬ�����.\n";
      continue;
    }
      strings[count] = input;
      count++;
  }

    return count;
}

// �㭪�� ��� ���஢�� ��ப �� �����
void sortLength(std::string strings[], int count) {
  std::sort(strings, strings + count, [](const std::string& a, const std::string& b) {
    return a.length() < b.length();
  });
}

// �㭪�� ��� ���஢�� ��ப �� ��䠢���
void sortAlphabet(std::string strings[], int count) {
  std::sort(strings, strings + count);
}

// �㭪�� ��� �뢮�� ��ப
void printStrings(const std::string strings[], int count) {
  std::cout << "�������:\n";
  for (int i = 0; i < count; ++i) {
    std::cout << strings[i] << "\n";
  }
}
