/**************************************************************************************
 * Filename: t5.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 5
 * ��᫥������� ��ப, ������� ����� �++ � IDE Qt Creator
 * ������� 5
 * ************************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include "lab5.h"

void processString(std::string& str) {
  // �����塞 �� ⠡��樨 �� �஡���
  std::replace(str.begin(), str.end(), '\t', ' ');

  // ����塞 ������ �஡��� �१ ���� � ������ �����ப�
  size_t pos;
  while ((pos = str.find("  ")) != std::string::npos) {
    str.replace(pos, 2, " "); // �����塞 ��� �஡��� �� ����
  }
}
