/**************************************************************************************
 * Filename: lab6.h
 * Developer: Perkova Elena
 * Description: ������ୠ� 6
 * ��᫥������� �++ ����ᮢ � IDE Qt Creator
 * ************************************************************************************/


#ifndef LAB6_H
#define LAB6_H

#include <vector>
#include <string>


// ������� 1

class Bruteforce {
public:
  // ��������� � ����ன��� ��ࠬ��஢ ��ॡ��
  Bruteforce(bool m_useDigits = true, bool m_useLower = true,
    bool m_useUpper = false, bool m_useSpecial = false,
    int m_maxLength = 3);

  // �᭮���� �㭪�� ��� ������ ��஫�
  std::string findPassword(const std::string& target);

  // ��⠭���� ���짮��⥫�᪮�� ����� ᨬ�����
  void setCustomChars(const std::string& chars);

private:
  std::vector<char> chars;  // ������� ��� ��ॡ��
  int m_maxLength;            // ���ᨬ��쭠� ����� ��஫�

  // �����ᨢ��� �㭪�� ��� �����樨 �������権
  bool generateCombinations(const std::string& target, std::string& current, int length);
};

// ������� 2

class PalindromeChecker {
public:
  // ���������
  PalindromeChecker();

  // ��⮤ ��� ����� ������ �� ���짮��⥫�
  void inputData();

  // ��⮤ ��� �஢�ન �� ������஬
  bool isPalindrome() const;

  // ��⮤ ��� �뢮�� १����
  void printResult() const;

private:
  std::vector<std::string> elements;  // �࠭���� ��������� ����⮢
  const int MAX_SIZE = 17;           // ���ᨬ��쭮� ������⢮ ����⮢

  // �ᯮ����⥫�� ��⮤ ��� ���⪨ ��ப� (�ਢ������ � ������ ॣ����� � 㤠����� �஡����)
  std::string cleanString(const std::string& s) const;
};


// ������� 5

class Projection2D; // �।���⥫쭮� ������� ��� ��㦥�⢥���� �㭪樨

class Brick {
private:
  double length;  // ����� ��௨� (��)
  double width;   // ��ਭ� ��௨� (��)
  double height;  // ���� ��௨� (��)

public:
  // ��������� � ��ࠬ��ࠬ� �� 㬮�砭�� (�⠭����� ��௨� 250x120x65 ��)
  Brick(double l = 250.0, double w = 120.0, double h = 65.0);

  // ������
  double getLength() const;
  double getWidth() const;
  double getHeight() const;

  // ��㦥�⢥���� �㭪�� ��� �ࠢ����� � �஥�樥� �⢥����
  friend bool canPassThrough(const Brick& brick, const Projection2D& hole);
};


//class Brick; // �।���⥫쭮� ������� ��� ��㦥�⢥���� �㭪樨

class Projection2D {
private:
  double dimension1; // ���� ࠧ��� �⢥���� (��)
  double dimension2; // ��ன ࠧ��� �⢥���� (��)

public:
  // ���������
  Projection2D(double d1, double d2);

  // ������
  double getDimension1() const;
  double getDimension2() const;

  // ��㦥�⢥���� �㭪�� ��� �ࠢ����� � ��௨箬
  friend bool canPassThrough(const Brick& brick, const Projection2D& hole);

  // ��⮤ ��� �뢮�� �஥�樨
  void printProjection() const;
  void draw(double compareWidth = 0, double compareHeight = 0) const;
};




#endif // LAB6_H
