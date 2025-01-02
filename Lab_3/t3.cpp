#include <iostream>
#include "l3_1.h"

// ��।������ ������쭮� ��६�����
int globalVar = 55;

// ��������� �㭪樨
auto initVars() -> void {
  // ��������� ���樠������ (Copy initialization)
  int iValue1 = 10;
  bool bValue1 = true;
  char cValue1 = 'A';
  long lValue1 = 1000L;

  // ��ﬠ� ���樠������ (Direct initialization)
  int iValue2(15);
  bool bValue2(false);
  char cValue2('B');
  long lValue2(2000L);

  // �����஢����� ���樠������ (Uniform initialization)
  int iValue3{20};
  bool bValue3{true};
  char cValue3{'C'};
  long lValue3{3000L};

  // ���樠������ � �ᯮ�짮������ auto
  auto iValue4 = 25;
  auto bValue4 = false;
  auto cValue4 = 'D';
  auto lValue4 = 4000L;

  // �뢮� ���祭��
  std::cout << "��������� ���樠������: " << iValue1 << ", " << bValue1 << ", " << cValue1 << ", " << lValue1 << std::endl;
  std::cout << "��ﬠ� ���樠������: " << iValue2 << ", " << bValue2 << ", " << cValue2 << ", " << lValue2 << std::endl;
  std::cout << "�����஢����� ���樠������: " << iValue3 << ", " << bValue3 << ", " << cValue3 << ", " << lValue3 << std::endl;
  std::cout << "Auto ���樠������: " << iValue4 << ", " << bValue4 << ", " << cValue4 << ", " << lValue4 << std::endl;
}
