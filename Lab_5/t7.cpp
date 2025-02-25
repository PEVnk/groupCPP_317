/**************************************************************************************
 * Filename: t7.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 5
 * ��᫥������� ��ப, ������� ����� �++ � IDE Qt Creator
 * ������� 7
 * ************************************************************************************/

#include <iostream>
#include <string>
#include "lab5.h"


// �㭪�� ��� �८�ࠧ������ �᫠ � ��ப�
std::string intToString(int number){
  if (number == 0){
    return "0"; // �᫨ �᫮ ࠢ�� 0
  }

  // ��ࠡ��뢠�� ����⥫�� �᫠
  bool isNegative = false;
  if (number < 0){
    isNegative = true;
    number = -number;
  }

  std::string result;

  // ��������� ���� � ������塞 �� � ��ப�
  do {
    char digit = '0' + (number % 10); // �뤥�塞 ��᫥���� ����
    result += digit; // ������塞 ���� � ��ப�
    number /= 10; // 㤠�塞 ��᫥���� ����
  } while (number > 0);

  // �᫨ �᫮ ����⥫쭮�, ������塞 �����
  if (isNegative){
  result += '-';
  }

  // ��ॢ��稢��� ��ப� ������, ⠪ ��� ���� ������﫨�� � ���⭮� ���浪�
  std::string finalResult;
  for (int i = result.length() - 1; i >= 0; --i){
    finalResult += result[i];
  }
  return finalResult;
}

// �㭪�� ��� �८�ࠧ������ ��ப� � �᫮
int stringToInt(const std::string& str){
  int result = 0;
  int sign = 1; // ���� �᫠
  size_t i = 0;

  // ��ࠡ�⪠ �����
  if (str[0] == '-') {
    sign = -1;
    i = 1; // �ய�᪠�� ���� �����
  }

  // �८�ࠧ������ ��ப� � �᫮

  for (; i < str.length(); ++i){
    result = result * 10 + (str[i] - '0'); // �८�ࠧ㥬 ᨬ��� � ����
  }
  return result;
}

