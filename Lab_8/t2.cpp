/**************************************************************************************
 * Filename: t2.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 8
 * ��᫥������� � �++ �⠭���⭮� ������⥪� 蠡����� (STL), ��ॣ�㧪� �����஢
 * ***********************************************************************************/

#include <iostream>
#include "lab8.h"
#include <algorithm> // ��� std::sort
#include <numeric>   // ��� std::accumulate

// ===== ����� �) =====

// �㭪�� ������� ���� ������ ����� �� ������ ������ ᯨ᪠
std::vector<int> replaceEvenWithListOdd(std::vector<int>& vec, std::list<int>& lst) {
  std::vector<int> result = vec; // �����㥬 ��室�� �����
  auto listIt = lst.begin(); // ����� ��� ᯨ᪠

  // ��室�� �� ������
  for (size_t i = 0; i < result.size(); ++i) {
    if (result[i] % 2 == 0) { // �᫨ ����� ����
      // �饬 ������ ����� � ᯨ᪥
      while (listIt != lst.end()) {
        if (*listIt % 2 != 0) { // ��諨 ������
          result[i] = *listIt; // �����塞
          ++listIt;            // ���室�� � ᫥���饬�
          break;
        }
      ++listIt;
      }
    }
  }
return result;
}

// �뢮� �����
void printVector(const std::vector<int>& vec) {
  for (int num : vec) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

// �뢮� ᯨ᪠
void printList(const std::list<int>& lst) {
  for (int num : lst) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

//===== ����� b)=====

// �������� � ����� ᯨ᪠ �।��� ��䬥��᪮�
void addAverageToList(std::list<double>& lst) {
  if (lst.empty()) return;

  double sum = std::accumulate(lst.begin(), lst.end(), 0.0);
  double average = sum / lst.size();
  lst.push_back(average);
}

//===== ����� c)=====

// ��ࠡ��뢠�� ��� 梥�
void processFavoriteColors() {
  std::vector<std::pair<int, std::string>> colors(3); // 3 ���� (�����, 梥�)

  std::cout << "������ 3 ���� 梥� � �ଠ�: ३⨭�, ��������_梥� �१ �஡��\n";
  for (int i = 0; i < 3; ++i) {
    std::cout << "���� " << i+1 << ": ";
    std::cin >> colors[i].first >> colors[i].second;
  }

  // �����㥬 �� ����ࠬ (�⥯��� �����)
  std::sort(colors.begin(), colors.end());

  std::cout << "��� ��� 梥� (�� �⥯��� �����):\n";
  printColors(colors);
}

// �뢮� 梥⮢
void printColors(const std::vector<std::pair<int, std::string>>& colors) {
  for (const auto& pair : colors) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }
}
