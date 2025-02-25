/**************************************************************************************
 * Filename: t4.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 5
 * ��᫥������� ��ப, ������� ����� �++ � IDE Qt Creator
 * ������� 4
 * ************************************************************************************/

#include <iostream>
#include <string>
#include <cctype> // ��� isdigit � toupper
#include "lab5.h"

std::string unpackString(const std::string& packed) {
  std::string result; //��ப� ��� �࠭���� १����
  int i = 0;
  while (i < packed.length()) {
    // �᫨ ⥪�騩 ᨬ��� ���, ��������� �᫮
    if (isdigit(packed[i])) {
      int count = 0;
      // ���뢠�� �� ���� �᫠
      while (i < packed.length() && isdigit(packed[i])) {
        count = count * 10 + (packed[i] - '0');  //��� ��ࠡ�⪨ ����������� �ᥫ 㬭����� �� 10
          i++;
      }
      // �᫨ ��᫥ �᫠ ���� �㪢�, ������塞 �� count ࠧ
      if (i < packed.length() && isalpha(packed[i])) {
        char ch = toupper(packed[i]); // �८�ࠧ㥬 � ���孨� ॣ����
        result.append(count, ch);
        i++;
      }
    } else if (isalpha(packed[i])) {
      // �᫨ ᨬ��� ? �㪢�, ������塞 �� ���� ࠧ
      char ch = toupper(packed[i]); // �८�ࠧ㥬 � ���孨� ॣ����
      result += ch;
      i++;
    } else {
      // �ய�᪠�� �������⨬� ᨬ����
      i++;
    }
  }
    return result;
}
