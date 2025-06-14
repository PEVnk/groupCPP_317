/**************************************************************************************
 * Filename: t1.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 8
 * ��᫥������� � �++ �⠭���⭮� ������⥪� 蠡����� (STL), ��ॣ�㧪� �����஢
 * ***********************************************************************************/

#include <iostream>
#include "lab8.h"
#include <ctime>
#include <random>   // ��� �����樨 ��砩��� �ᥫ
#include <unordered_set> // ��� std::unordered_set (������� 㭨������ �ᥫ)

// ������� N ��砩��� �ᥫ � ��������� [-100, 100]
std::vector<int> generateRandomNumbers(int N) {
  std::vector<int> numbers; // ����� ��� �࠭���� �ᥫ

  // ���樠������ ������� ��砩��� �ᥫ
  std::default_random_engine gen(time(0));
  std::uniform_int_distribution<int> dist(-100, 100);

  // ������塞 ����� N ��砩�묨 �᫠��
  for (int i = 0; i < N; ++i) {
    numbers.push_back(dist(gen)); // ������塞 ��砩��� �᫮
  }

  return numbers; // �����頥� ���������� �����
}

// �뢮��� ���⥩��� � ��אַ� � ���⭮� ���浪� �� 10 �ᥫ � ��ப�
void printContainer(const std::vector<int>& container) {
  std::cout << "����ন��� ���⥩��� (��אַ� ���冷�):" << std::endl;
  for (size_t i = 0; i < container.size(); ++i) {
    std::cout << container[i] << " ";
    // ����� 10 ����⮢ ���室�� �� ����� ��ப�
    if ((i + 1) % 10 == 0) {
      std::cout << std::endl;
    }
  }
    // �᫨ ��᫥���� ��ப� �� ������, ������塞 ��ॢ�� ��ப�
    if (container.size() % 10 != 0) {
        std::cout << std::endl;
    }

  // �뢮��� � ���⭮� ���浪�
  printContainerReverse(container);
}

// �뢮��� ���⥩��� � ���⭮� ���浪� (� �ᯮ�짮������ ���⭮�� �����)
void printContainerReverse(const std::vector<int>& container) {
  std::cout << "����ন��� ���⥩��� (����� ���冷�):" << std::endl;
  size_t count = 0;

  // �ᯮ��㥬 ����� ����� (rbegin, rend)
  for (auto it = container.rbegin(); it != container.rend(); ++it) {
    std::cout << *it << " ";
    // ����� 10 ����⮢ ���室�� �� ����� ��ப�
    if (++count % 10 == 0) {
      std::cout << std::endl;
        }
    }
    // �᫨ ��᫥���� ��ப� �� ������, ������塞 ��ॢ�� ��ப�
    if (count % 10 != 0) {
      std::cout << std::endl;
    }
}

// ������� 㭨������ �ᥫ � ������� std::unordered_set
int countUniqueNumbers(const std::vector<int>& container) {
  // unordered_set ��⮬���᪨ 㤠��� �㡫�����
  std::unordered_set<int> uniqueNumbers(container.begin(), container.end());

  // ������ ������⢠ = ������⢮ 㭨������ �ᥫ
  return uniqueNumbers.size();
}


