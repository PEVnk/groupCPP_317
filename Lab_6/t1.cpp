/**************************************************************************************
 * Filename: t1.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 6
 * ��᫥������� �++ ����ᮢ � IDE Qt Creator
 * ������� 1
 * ************************************************************************************/


#include <iostream>
#include "lab6.h"
#include <algorithm>

// ��������� � ����ன��� ��ࠬ��஢ ��ॡ��
Bruteforce::Bruteforce(bool m_useDigits, bool m_useLower,
                       bool m_useUpper, bool m_useSpecial,
                       int m_maxLength) : m_maxLength(m_maxLength) {
  // ������塞 ����, �᫨ �㦭�
  if (m_useDigits) {
    for (char c = '0'; c <= '9'; ++c) {
      chars.push_back(c);
    }
  }

  // ������塞 ����� �㪢�, �᫨ �㦭�
  if (m_useLower) {
    for (char c = 'a'; c <= 'z'; ++c) {
      chars.push_back(c);
    }
  }

  // ������塞 �������� �㪢�, �᫨ �㦭�
  if (m_useUpper) {
    for (char c = 'A'; c <= 'Z'; ++c) {
      chars.push_back(c);
      }
  }

  // ������塞 ᯥ樠��� ᨬ����, �᫨ �㦭�
  if (m_useSpecial) {
    const std::string specials = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    for (char c : specials) {
      chars.push_back(c);
    }
  }
}

// ��⠭���� ���짮��⥫�᪮�� ����� ᨬ�����
void Bruteforce::setCustomChars(const std::string& customChars) {
  chars.clear();
  for (char c : customChars) {
    chars.push_back(c);
  }
}

// �᭮���� �㭪�� ��� ������ ��஫�
std::string Bruteforce::findPassword(const std::string& target) {
  std::string current;

  // �஢��塞 ��஫� ������ �� 1 �� maxLength
  for (int length = 1; length <= m_maxLength; ++length) {
    if (generateCombinations(target, current, length)) {
      return current;
        }
    }

    return "";  // � ⥮ਨ � ������� �� ������ �� �᫮��� �����,
                //�� ���� �� �������᪨ ��������� ��砥�
}

// �����ᨢ��� �㭪�� ��� �����樨 �������権
bool Bruteforce::generateCombinations(const std::string& target,
                                     std::string& current, int length) {
  // ������ ��砩 ४��ᨨ
  if (current.length() == length) {
    return current == target;
  }

  // �����ᨢ�� ��砩
  for (char c : chars) {
    current.push_back(c);
    if (generateCombinations(target, current, length)) {
      return true;
    }
  current.pop_back();
  }

    return false;
}
