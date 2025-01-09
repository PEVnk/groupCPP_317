#include <iostream>
#include "lab4.h"

// ��������� �㭪樨 ��� ���᫥��� 䠪�ਠ�� � ������� ���権
double FindFactorialIteration(int Num){
  double Factorial{1};

  // ����塞 䠪�ਠ� � ������� 横�� for
  for (int i =1; i<= Num; i++){
    Factorial*= i;
  }
  return Factorial;
}

// ��������� �㭪樨 ��� �஢�ન ����񭭮�� �᫠
bool CheckNumber(int Num){
  // ����ਠ� ��।��� ⮫쪮 ��� ������⥫��� �ᥫ ����� 0
  return Num >= 0;
}

// ��������� �㭪樨 ��� ���᫥��� 䠪�ਠ�� � ������� ४��ᨨ
double FindFactorialRecursion(int Num){
  if (Num == 1)
    return 1; // ������ ��砩 (�᫮��� �����襭��)
  else
    return FindFactorialRecursion(Num-1)*Num; // ४��ᨢ�� �맮� �㭪樨
}

// ��������� �㭪樨 ���᪠ �ᥫ �������� � ������� ���権
int fib(int UserNum) {
  if (UserNum == 0) return 0;
  if (UserNum == 1) return 1;

  int num1 = 0, num2 = 1, num3 = 0;
  for (int i = 2; i < UserNum; i++) {
    num3 = num1 + num2;
    num1 = num2;
    num2 = num3;
  }
    return num2;
}

// ��������� �㭪樨 �뢮�� ��ࠬ��� �ᥫ
void PrintPiramid(int UserNumber){
  int Sum = 0;
  int row = 1;
  // �த������ �뢮�, ���� ⥪��� �㬬� �� ���⨣��� 楫����� �᫠
  while (true) {
    Sum = 0; // ����뢠�� �㬬� ��� ����� ��ப�

    // �뢮��� �뢠���� ��᫥����⥫쭮��� �ᥫ
    for (int i = row; i >= 1; i--) {
      std::cout << i << " ";
      Sum += i; // ��⠥� �㬬� �ᥫ � ��ப�
    }

    // �뢮��� �㬬� �ᥫ � ��ப�
    std::cout << Sum << std::endl;

    // �஢��塞, ���⨣�� �� 楫����� �᫠
    if (Sum == UserNumber){
      std::cout << "������� �᫮ ���⨣���" << std::endl;
      break; // �����蠥� 横�
    } else if (Sum > UserNumber){
      std::cout << "������� �᫮ �� ����� ���� ���⨣��� � \
                    �⮩ ��᫥����⥫쭮��" << std::endl;

      break; // �����蠥� 横�
    }

   // ���室�� � ᫥���饩 ��ப�
    row++;
  }
}
