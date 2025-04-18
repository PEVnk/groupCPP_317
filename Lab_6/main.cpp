/**************************************************************************************
 * Filename: main.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 6
 * ��᫥������� �++ ����ᮢ � IDE Qt Creator
 * ***********************************************************************************/

#include <iostream>
#include <string>
#include "lab6.h"
#include "autobasa.h"
#include "complexnum.h"
#include <limits>

#define Unit 5

int main()
{
  #if Unit==1
  std::cout << "������� 1" << std::endl; // �맮� �㭪樨 ������� 1 �� �⤥�쭮�� 䠩��

  std::cout << "=== Bruteforce Password Finder ===" << std::endl;

  // ����� ��஫� � ���짮��⥫�
  std::string password;
  std::cout << "Enter password to find (max 4 characters): ";
  std::cin >> password;

  // �஢�ઠ ����� ��஫�
  if (password.length() > 4) {
    std::cerr << "Error: Password is too long (max 4 characters allowed)" << std::endl;
    return 1;
  }

  // ����ன�� ��ࠬ��஢ ��ॡ��
  bool m_useDigits, m_useLower, m_useUpper, m_useSpecial;
  char choice;

  std::cout << "\nConfigure character set for brute force:" << std::endl;
  std::cout << "Include digits (0-9)? (y/n): ";
  std::cin >> choice;
  m_useDigits = (choice == 'y' || choice == 'Y');
  std::cout << "Include lowercase letters (a-z)? (y/n): ";
  std::cin >> choice;
  m_useLower = (choice == 'y' || choice == 'Y');

  std::cout << "Include uppercase letters (A-Z)? (y/n): ";
  std::cin >> choice;
  m_useUpper = (choice == 'y' || choice == 'Y');

  std::cout << "Include special characters (!@# etc.)? (y/n): ";
  std::cin >> choice;
  m_useSpecial = (choice == 'y' || choice == 'Y');

  // �������� ��ꥪ� Bruteforce � ����ன����
  Bruteforce bf(m_useDigits, m_useLower, m_useUpper, m_useSpecial, 4);

  std::cout << "\nStarting brute force attack..." << std::endl;

  // ����� ������ ��஫�
  std::string found = bf.findPassword(password);
  if (!found.empty()) {
    std::cout << "Password found: " << found << std::endl;
  } else {
    std::cout << "Password not found (this shouldn't happen!)" << std::endl;
  }


  #elif Unit==2
  std::cout << "������� 2" << std::endl; // �맮� �㭪樨 ������� 2 �� �⤥�쭮�� 䠩��

  std::cout << "=== �஢�ઠ ������஬� ===" << std::endl;
  std::cout << "�ணࠬ�� �஢����, ���� �� ��������� ��᫥����⥫쭮��� ������஬��." << std::endl;
  std::cout << "����� ������� �᫠, ᫮�� �� ���᪮� ��� ������᪮� �몥." << std::endl;
  std::cout << "���ᨬ��쭮� ������⢮ ����⮢: 17." << std::endl << std::endl;

  PalindromeChecker checker;
  checker.inputData();
  checker.printResult();


  #elif Unit==3
  std::cout << "������� 3" << std::endl; // �맮� �㭪樨 ������� 3 �� �⤥�쭮�� 䠩��

  // ������� ��ᯥ���
  Dispatcher dispatcher("���� ���஢");

  // ������塞 ����⥫��
  Driver driver1("���� ���୮�", 1);
  Driver driver2("���� ������", 2);
  dispatcher.addDriver(&driver1);
  dispatcher.addDriver(&driver2);

  // ������塞 ��⮬�����
  Automobile car1("������");
  Automobile car2("Volvo");
  dispatcher.addAutomobile(&car1);
  dispatcher.addAutomobile(&car2);

  // ������� ३��
  Trip* trip1 = dispatcher.createTrip(1, "���", "��⮢�� �孨��");
  Trip* trip2 = dispatcher.createTrip(2, "����ᨡ���", "�த���");

  // �����砥� ३��
  dispatcher.assignTrip(trip1, &driver1, &car1);
  dispatcher.assignTrip(trip2, &driver2, &car2);

  // ��稭��� � �����蠥� ३��
  trip1->startTrip(&driver1, &car1);
  trip1->completeTrip(false); // ��⮬����� �� ���०���

  trip2->startTrip(&driver1, &car1);
  trip2->completeTrip(true); // ��⮬����� ���०���

  // ����⥫� ����訢��� ६���
  driver2.requestRepair();

  // ��ᯥ��� ����࠭�� ����⥫�
  dispatcher.suspendDriver(&driver1);

  // �뢮��� ���ଠ��
  dispatcher.displayAllDrivers();
  dispatcher.displayAllAutomobiles();
  dispatcher.displayAllTrips();


  #elif Unit==4
  std::cout << "������� 4" << std::endl; // �맮� �㭪樨 ������� 4 �� �⤥�쭮�� 䠩��

  // ������� ��������� �᫠ � �����ࠨ�᪮� �ଥ
  ComplexNumber a(3, 4);  // 3 + 4i
  ComplexNumber b(1, -2); // 1 - 2i

  std::cout << "��᫮ a: " << a.toString() << std::endl;
  std::cout << "��᫮ b: " << b.toString() << std::endl;

  // ���塞 ��� �।�⠢�����
  a.setForm(ComplexForm::TRIGONOMETRIC);
  std::cout << "��᫮ a � �ਣ��������᪮� �ଥ: " << a.toString() << std::endl;

  a.setForm(ComplexForm::EXPONENTIAL);
  std::cout << "��᫮ a � �ᯮ���樠�쭮� �ଥ: " << a.toString() << std::endl;

  a.setForm(ComplexForm::ALGEBRAIC);
  std::cout << "��᫮ a � �����ࠨ�᪮� �ଥ: " << a.toString() << std::endl;

  // ����樨 � �᫠��
  ComplexNumber sum = a + b;
  ComplexNumber diff = a - b;
  ComplexNumber product = a * b;
  ComplexNumber quotient = a / b;

  std::cout << "�㬬�: " << sum.toString() << std::endl;
  std::cout << "��������: " << diff.toString() << std::endl;
  std::cout << "�ந��������: " << product.toString() << std::endl;
  std::cout << "���⭮�: " << quotient.toString() << std::endl;

  // ����殮���� �᫮
  ComplexNumber conj = a.conjugate();
  std::cout << "����殮���� � a: " << conj.toString() << std::endl;

  // ���������� � �⥯���
  ComplexNumber power = a.pow(3);
  std::cout << "a^3: " << power.toString() << std::endl;

  // �����祭�� ����
  std::vector<ComplexNumber> roots = a.root(3);
  std::cout << "�㡨�᪨� ��୨ �� a:" << std::endl;
  for (size_t i = 0; i < roots.size(); ++i) {
    std::cout << "  ��७� " << i+1 << ": " << roots[i].toString() << std::endl;
  }

  #else

  Brick standardBrick;

  std::cout << "=== �஢�ઠ ��宦����� ��௨� �१ �⢥��⨥ ===\n";
  std::cout << "�⠭����� ��௨�: "
  << standardBrick.getLength() << " x "
  << standardBrick.getWidth() << " x "
  << standardBrick.getHeight() << " ��\n\n";

  // ���� ࠧ��஢ �⢥����
  double holeHeight, holeWidth;
  std::cout << "������ ����� �⢥���� (��): ";
  std::cin >> holeHeight;
  std::cout << "������ �ਭ� �⢥���� (��): ";
  std::cin >> holeWidth;

  Projection2D hole(holeHeight, holeWidth);

  // �� �������� �஥�樨 ��௨�
  std::vector<std::pair<double, double>> brickProjections = {
  {standardBrick.getLength(), standardBrick.getWidth()},
  {standardBrick.getLength(), standardBrick.getHeight()},
  {standardBrick.getWidth(), standardBrick.getHeight()}
  };

  bool canPass = false;
  int projectionNum = 1;

  // �஢��塞 �� �஥�樨
  for (const auto& proj : brickProjections) {
    std::cout << "\n=== �஢�ઠ �஥�樨 #" << projectionNum++ << " ===\n";
    std::cout << "��௨�: " << proj.first << " x " << proj.second << " ��\n";

    // ���㥬 ��� �஥�樨
    hole.draw(proj.first, proj.second);

    if (proj.first <= hole.getDimension1() && proj.second <= hole.getDimension2()) {
      std::cout << "\n�������: ��௨� ������� � �⮬ ���������!\n";
      canPass = true;
    } else {
      std::cout << "\n�������: ��௨� �� �ன��� � �⮬ ���������.\n";
      }
  }

  // �⮣��� १����
  std::cout << "\n=== �⮣��� १���� ===\n";
  if (canPass) {
    std::cout << "��௨� ����� �ன� �१ �⢥��⨥!\n";
    } else {
      std::cout << "��௨� �� ����� �ன� �१ �⢥��⨥.\n";
  }




#endif
return 0;
}
