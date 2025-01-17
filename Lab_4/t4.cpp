/**************************************************************************************
 * Filename: t4.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 4
 * ��᫥������� ���ᨢ��, 㪠��⥫��, ��뫮�
 * ������� 4
 * ************************************************************************************/


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
  // ����ਠ� ��।��� ⮫쪮 ��� ������⥫��� �ᥫ
    if (Num < 0) {
      std::cout << "����ਠ� ��।��� ⮫쪮 ��� ������⥫��� �ᥫ." << std::endl;
      return false;
    }
  // ��࠭�祭�� �� ���ᨬ��쭮� ���祭�� ��� 䠪�ਠ��
    if (Num > 47) {
      std::cout << "����ਠ� ��� �ᥫ ����� 47 ᫨誮� ����� � �� ����� ���� ���᫥�." << std::endl;
      return false;
     }
     return true;
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

// ��������� �㭪樨 ��� �஢�ન ����񭭮�� �᫠ ��� �ᥫ ��������
bool CheckFibonacciNumber(int Num) {
  if (Num < 0) {
    std::cout << "��᫠ �������� ��।����� ⮫쪮 ��� ������⥫��� �ᥫ." << std::endl;
    return false;
  }
  // ��࠭�祭�� �� ���ᨬ��쭮� ���祭�� ��� �ᥫ ��������
  if (Num > 47) {
    std::cout << "��᫠ �������� ��� n > 47 ᫨誮� ������ � �� ����� ���� ���᫥��." << std::endl;
    return false;
  }
  return true;
}

// ��������� �㭪樨 �뢮�� ��ࠬ��� �ᥫ
void PrintPiramid(int UserNumber){
  int Sum = 0;
  int row = 1;
  // �த������ �뢮�, ���� ⥪��� �㬬� �� ���⨣��� 楫����� �᫠
  while (true) {
    Sum = 0; // ����뢠�� �㬬� ��� ����� ��ப�

    // ������뢠�� ������⢮ �஡���� ��। �᫠�� ��� ��ࠢ������� �� 業���
    int spaces = UserNumber - row;

    // �뢮��� �஡��� ��� ��ࠢ������� �� 業���
    for (int i = 0; i < spaces; i++) {
      std::cout << " "; // ���� �஡�� ��� ������� �ய�饭���� �᫠
    }

    // �뢮��� �뢠���� ��᫥����⥫쭮��� �ᥫ
    for (int i = row; i >= 1; i--) {
      std::cout << i << " ";
      Sum += i; // ��⠥� �㬬� �ᥫ � ��ப�
    }

    // �뢮��� �㬬� �ᥫ � ��ப�
    std::cout << "   " << Sum << std::endl;

    // �஢��塞, ���⨣�� �� 楫����� �᫠
    if (Sum == UserNumber){
      std::cout << "������� �᫮ ���⨣���" << std::endl;
      break; // �����蠥� 横�
    } else if (Sum > UserNumber){
      std::cout << "������� �᫮ �� ����� ���� ���⨣��� � �⮩ ��᫥����⥫쭮��" << std::endl;

      break; // �����蠥� 横�
    }

   // ���室�� � ᫥���饩 ��ப�
    row++;
  }
}
