#include <iostream>
#include "l3_1.h"


#define Unit 1
int main()
{
#if Unit==1
std::cout << "������� 1" << std::endl; // �맮� �㭪樨 ������� 1 �� �⤥�쭮�� 䠩��
  std::cout << "����⭮��� ������ �㧠: " << math_prob(52,4) << std::endl;
  std::cout << "����⭮��� ⮣�, �� �㬬�\
  �믠��� �窮� �㤥� ࠢ�� 7: " << math_prob(36,6) << std::endl;
  std::cout << "����⭮��� ����祭�� ᫮�� '����': " << math_prob(6,1) << std::endl;

#elif Unit==2
std::cout << "������� 2" << std::endl; // �맮� �㭪樨 ������� 2 �� �⤥�쭮�� 䠩��
  std::cout << "�맮� ��� ��㬥�⮢" << std::endl;
  printChar();
  std::cout << "�맮� � ����� ��㬥�⮬" << std::endl;
  printChar(65);                                             //a = 65 (���ਬ��, ASCII ��� ��� 'A'), b = 'b', c = 'c', d = 'd'
  std::cout << "�맮� � ���� ��㬥�⠬�" << std::endl;
  printChar(65, 'x');                                       // a = 65, b = 'x', c = 'c', d = 'd'
  std::cout << "�맮� � �६� ��㬥�⠬�" << std::endl;
  printChar(65, 'x', 'y');                                 // a = 65, b = 'x', c = 'y', d = 'd'
  std::cout << "�맮� � ������ ��㬥�⠬�" << std::endl;
  printChar(65, 'x', 'y', 'z');                            // a = 65, b = 'x', c = 'y', d = 'z'


#elif Unit==3
std::cout << "������� 3" << std::endl; // �맮� �㭪樨 ������� 3 �� �⤥�쭮�� 䠩��
  // �����쭠� ��६����� � ⥬ �� ������, �� � ������쭠�
  int globalVar = 200;

  // �맮� �㭪樨 ���樠����樨
  initVars();

  // �뢮� ������쭮� � �����쭮� ��६�����
  std::cout << "������쭠� ��६�����: " << ::globalVar << std::endl;
  std::cout << "�����쭠� ��६�����: " << globalVar << std::endl;

  return 0;


#elif Unit==4
std::cout << "������� 4" << std::endl;  // �맮� �㭪樨 ������� 4 �� �⤥�쭮�� 䠩��
  // �ਬ��� �ᯮ�짮����� �㭪権
  Animals animal1 = Animals::PIG;
  Animals animal2 = Animals::CHICKEN;

  std::cout << "Animal 1: ";
  getAnimalName(animal1);
  std::cout << ", ";
  printNumberOfLegs(animal1);
  std::cout << std::endl;

  std::cout << "Animal 2: ";
  getAnimalName(animal2);
  std::cout << ", ";
  printNumberOfLegs(animal2);
  std::cout << std::endl;
  return 0;

#elif Unit==5
std::cout << "������� 5" << std::endl;  // �맮� �㭪樨 ������� 5 �� �⤥�쭮�� 䠩��
  int a, b, c;
  unsigned short usA, usB;

  // ���� ������ �� ���짮��⥫�
  std::cout << "������ ��� 楫�� �᫠ (int): ";
  std::cin >> a >> b;
  std::cout << "���ᨬ�: " << max(a, b) << ", ������: " << min(a, b) << std::endl;

  std::cout << "������ ��� �᫠ ⨯� unsigned short: ";
  std::cin >> usA >> usB;
  std::cout << "���ᨬ�: " << max(usA, usB) << ", ������: " << min(usA, usB) << std::endl;

  std::cout << "������ �� 楫�� �᫠ (int): ";
  std::cin >> a >> b >> c;
  std::cout << "���ᨬ� � ��࠭�祭���: " << max(a, b, c) << ", ������ � ��࠭�祭���: " << min(a, b, c) << std::endl;

  return 0;


#elif Unit==6
std::cout << "������� 6" << std::endl;  // �맮� �㭪樨 ������� 6 �� �⤥�쭮�� 䠩��
  //���������� ࠡ��� �㭪樨
  int x = 10;
  float y = 5.5f;
  double z = 2.5;
  unsigned short k = 7;

  // ��ࠦ���� 1
  std::cout << "��ࠦ���� 1 (int i=(x+y)*z+k):" << std::endl;
  std::cout << "���� �८�ࠧ������: " << impConvers1(x, y, z, k) << std::endl;
  std::cout << "static_cast: " << stCastConvers1(x, y, z, k) << std::endl;
  std::cout << "C-style cast: " << cStyleCastConvers1(x, y, z, k) << std::endl;

  // ��ࠦ���� 2
  std::cout << "\n��ࠦ���� 2 (k=x-y/z):" << std::endl;
  std::cout << "���� �८�ࠧ������: " << impConvers2(x, y, z) << std::endl;
  std::cout << "static_cast: " << stCastConvers2(x, y, z) << std::endl;
  std::cout << "C-style cast: " << cStyleCastConvers2(x, y, z) << std::endl;

  // ��ࠦ���� 3
  std::cout << "\n��ࠦ���� 3 (z=x*y+z/x):" << std::endl;
  std::cout << "���� �८�ࠧ������: " << impConvers3(x, y, z) << std::endl;
  std::cout << "static_cast: " << stCastConvers3(x, y, z) << std::endl;
  std::cout << "C-style cast: " << cStyleCastConvers3(x, y, z) << std::endl;

  // ��ࠦ���� 4
  std::cout << "\n��ࠦ���� 4 (unsigned int ui=x/y+k):" << std::endl;
  std::cout << "���� �८�ࠧ������: " << impConvers4(x, y, k) << std::endl;
  std::cout << "static_cast: " << stCastConvers4(x, y, k) << std::endl;
  std::cout << "C-style cast: " << cStyleCastConvers4(x, y, k) << std::endl;

  // ��ࠦ���� 5
  std::cout << "\n��ࠦ���� 5 (short s=x%(x/y)):" << std::endl;
  std::cout << "���� �८�ࠧ������: " << impConvers5(x, y) << std::endl;
  std::cout << "static_cast: " << stCastConvers5(x, y) << std::endl;
  std::cout << "C-style cast: " << cStyleCastConvers5(x, y) << std::endl;

  return 0;


#else
std::cout << "������� 7" << std::endl;  // �맮� �㭪樨 ������� 7 �� �⤥�쭮�� 䠩��
  int num_input;
  std::cout << "���� ���������� � ����㠫�� �࣮��-ࠧ�����⥫�� 業��!\n";
  std::cout << "�롥�� �⠦ (0-7):\n";
  std::cout << "0. ��મ���\n";
  std::cout << "1. �த�⮢� �������\n";
  std::cout << "2. ����⧠�\n";
  std::cout << "3. ��������\n";
  std::cout << "4. ��஢�� ���頤��\n";
  std::cout << "5. �㤪���\n";
  std::cout << "6. ����⥠��\n";
  std::cout << "7. ����\n";
  std::cin >> num_input;            //����祭�� ����� �⠦� �� ���짮��⥫�

  // �८�ࠧ������ ���������� ���짮��⥫�� �᫠ � enum
  Level selectedLevel = static_cast<Level>(num_input);

  // �஢�ઠ ���४⭮�� �����
  if (num_input<0 || num_input>7) {
    std::cout << "�訡��: ������ ����� �⠦�!\n";
    return 1;
  }
  // �뢮� �������� ��࠭���� �⠦�
  std::cout << "�� ���ࠢ����� �� �⠦: " << getlevellName(selectedLevel) << "\n";

  return 0;

#endif
return 0;
}
