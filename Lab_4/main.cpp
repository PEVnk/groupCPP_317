#include <iostream>
#include <random>
#include <ctime>
#include "lab4.h"

#define Unit 4
int main()
{
#if Unit==1
std::cout << "������� 1" << std::endl; // �맮� �㭪樨 ������� 1 �� �⤥�쭮�� 䠩��

constexpr int len = 10; // ����� ���ᨢ� �१ ����⠭��� ��६����� ⨯� compiletime

// �������� ���ᨢ� �� 楫�� �ᥫ �������� �����
int array[len];

  // ���������� ���ᨢ� �ᥢ����砩�묨 �᫠��
RandomNumbers(array, len);

  // �뢮� ���ᨢ� �� �࠭
  std::cout << "���ᨢ �ᥢ����砩��� �ᥫ: " << std::endl;
  for (int i = 0; i < len; ++i) {
      std::cout << array[i] << " ";
      // �᫨ �뢥�� 5 �ᥫ, � ��⠢�塞 ᨬ��� ����� ��ப�
      if ((i + 1) % 5 == 0)
        std::cout << "\n";
  }
  std::cout << std::endl;

// ���� �������쭮�� ���祭�� � ���ᨢ�
int MinValue = ArrayMin(array, len);
  std::cout << "�������쭮� ���祭�� ���ᨢ�: " << MinValue << std::endl;

// ���� ���ᨬ��쭮�� ���祭�� � ���ᨢ�
int MaxValue = ArrayMax(array, len);
  std::cout << "���ᨬ��쭮� ���祭�� ���ᨢ�: " << MaxValue << std::endl;


#elif Unit==2
// �������� � �뢮� �����筮� ������
IdentityMatrix();

std::cout << std::endl;

const int rows = 8; // ������⢮ ��ப
const int cols = 8; // ������⢮ �⮫�殢
int matrix[rows][cols]; // �������� ������ 8x8

// ���������� ������ ��砩�묨 �᫠��
fillMatrixRandomNum(matrix, rows, cols);

// �뢮� ������ � ���᮫�
printMatrix(matrix, rows, cols);

// ���᫥��� �㬬� ����⮢ ��� ������� ���������
int sum = AddArrayElements(matrix, rows, cols);

// �뢮� १����
std::cout << "�㬬� ����⮢ ��� ������� ���������: " << sum << std::endl;


#elif Unit==3
std::cout << "������� 3" << std::endl; // �맮� �㭪樨 ������� 3 �� �⤥�쭮�� 䠩��

// �뢮� ��䠢�� � ������묨 ������ � ⠡���� ASCII
PrintCodeAlphabet();

#elif Unit==4
std::cout << "������� 4" << std::endl; // �맮� �㭪樨 ������� 4 �� �⤥�쭮�� 䠩��

//��宦����� 䠪�ਠ��
std::cout << "�. ��宦����� 䠪�ਠ�� �᫠" << std::endl;
std::cout << std::endl;

int Num;

// ����� ����� �᫠ �� ���짮��⥫�
while (true) {
// 横� �த�������� �� �� ���, ���� ���짮��⥫� �� ������ ���४⭮� ���祭��
  std::cout << "������ 楫�� ������⥫쭮� �᫮" << std::endl;
  if (std::cin >> Num){
    // �஢�ઠ ����񭭮�� �᫠
    if (CheckNumber(Num)){
      // ���᫥��� 䠪�ਠ��
      double result = FindFactorialIteration(Num);

      std::cout << "����ਫ � ������� ���権: " << result << std::endl;
      std::cout<<"����ਫ � ������� ४��ᨨ: " <<FindFactorialRecursion(Num)<< std::endl;
      break; // ��室 �� 横��, �᫨ ���� ���४��
    }
    else{
    std::cout << "����ਠ� ��।��� ⮫쪮 ��� ������⥫��� 楫�� �ᥫ" << std::endl;
    }
  }
  else{
    // �᫨ �।��饥 �����祭�� �� �믮������� ��� �ந��諮 ��९�������,
    std::cin.clear(); // � �����頥� cin � '�����' ०�� ࠡ���
    std::cin.ignore(32767,'\n'); // � 㤠�塞 ���祭�� �।��饣� ����� �� �室���� ����
    std::cout << "������� �����४⭮� ���祭��. ������ 楫�� �᫮." << std::endl;
  }
}

//�᫮ ��������
std::cout << "B. ��宦����� �᫠ ��������" << std::endl;
std::cout << std::endl;
int UserNum;
// ����� ����� �᫠ �� ���짮��⥫�
while (true) {
  std::cout << "������ ����� �᫠ ��������: ";
  if (std::cin >> UserNum){
    // �஢�ઠ ����񭭮�� �᫠
    if (CheckFibonacciNumber(UserNum)){
      // ���᫥��� �᫠ ��������
      int NumFib = fib(UserNum);
      std::cout << "\n ��᫮ �������� � ����஬ " << UserNum << " ࠢ��: " << NumFib << std::endl;
      break; // ��室 �� 横��, �᫨ ���� ���४��
    }
    else{
    std::cout << "����� ������ ���� ������⥫��" << std::endl;
    }
  }
  else{
    // �᫨ �।��饥 �����祭�� �� �믮������� ��� �ந��諮 ��९�������,
    std::cin.clear(); // � �����頥� cin � '�����' ०�� ࠡ���
    std::cin.ignore(32767,'\n'); // � 㤠�塞 ���祭�� �।��饣� ����� �� �室���� ����
    std::cout << "������� �����४⭮� ���祭��. ������ 楫�� �᫮." << std::endl;
  }
}

// �뢮� �᫮��� ��ࠬ���

int UserNumber;

  // ���� 楫����� �᫠
  std::cout << "������ 楫���� �᫮: ";
  std::cin >> UserNumber;

  // �맮� �㭪樨 ��� �뢮�� ��ࠬ���
  PrintPiramid(UserNumber);

#elif Unit==5
std::cout << "������� 5" << std::endl; // �맮� �㭪樨 ������� 5 �� �⤥�쭮�� 䠩��

int choice, UserSize;

// ����� ⨯� ������
std::cout << "�롥�� ⨯ ������:\n";
std::cout << "1 - char\n2 - short\n3 - int\n4 - float\n5 - double\n";
std::cin >> choice;

// ����� ������⢠ ����⮢
std::cout << "������ ������⢮ ����⮢: ";
std::cin >> UserSize;

// ���樠������ ������� ��砩��� �ᥫ
std::srand(std::time(0));

// ��ࠡ�⪠ �롮� ⨯� ������
switch (choice) {
  case 1: { //char
    // �������� ���ᨢ�
    char CharArr[UserSize];
    // ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
    FillRandomArray(CharArr, UserSize);
    // �뢮� ��室���� ���ᨢ�
    std::cout << "��室�� ���ᨢ:\n";
    PrintRandomArray(CharArr, UserSize);
    // ����஢�� ���ᨢ� ��⮤�� �롮�
    SortSelect(CharArr, UserSize);
    // �뢮� �����஢������ ���ᨢ�
    std::cout << "�����஢���� ���ᨢ:\n";
    PrintRandomArray(CharArr, UserSize);
    break;
  }

  case 2: { //short
    // �������� ���ᨢ�
    short ShortArr[UserSize];
    // ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
    FillRandomArray(ShortArr, UserSize);
    // �뢮� ��室���� ���ᨢ�
    std::cout << "��室�� ���ᨢ:\n";
    PrintRandomArray(ShortArr, UserSize);
    // ����஢�� ���ᨢ� ��⮤�� �롮�
    SortSelect(ShortArr, UserSize);
    // �뢮� �����஢������ ���ᨢ�
    std::cout << "�����஢���� ���ᨢ:\n";
    PrintRandomArray(ShortArr, UserSize);
    break;
  }
  case 3: { //int
    // �������� ���ᨢ�
    int IntArr[UserSize];
    // ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
    FillRandomArray(IntArr, UserSize);
    // �뢮� ��室���� ���ᨢ�
    std::cout << "��室�� ���ᨢ:\n";
    PrintRandomArray(IntArr, UserSize);
    // ����஢�� ���ᨢ� ��⮤�� �롮�
    SortSelect(IntArr, UserSize);
    // �뢮� �����஢������ ���ᨢ�
    std::cout << "�����஢���� ���ᨢ:\n";
    PrintRandomArray(IntArr, UserSize);
    break;
  }

  case 4: { //float
    // �������� ���ᨢ�
    float FloatArr[UserSize];
    // ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
    FillRandomArray(FloatArr, UserSize);
    // �뢮� ��室���� ���ᨢ�
    std::cout << "��室�� ���ᨢ:\n";
    PrintRandomArray(FloatArr, UserSize);
    // ����஢�� ���ᨢ� ��⮤�� �롮�
    SortSelect(FloatArr, UserSize);
    // �뢮� �����஢������ ���ᨢ�
    std::cout << "�����஢���� ���ᨢ:\n";
    PrintRandomArray(FloatArr, UserSize);
    break;
  }

  case 5: { //double
    // �������� ���ᨢ�
    double DoubleArr[UserSize];
    // ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
    FillRandomArray(DoubleArr, UserSize);
    // �뢮� ��室���� ���ᨢ�
    std::cout << "��室�� ���ᨢ:\n";
    PrintRandomArray(DoubleArr, UserSize);
    // ����஢�� ���ᨢ� ��⮤�� �롮�
    SortSelect(DoubleArr, UserSize);
    // �뢮� �����஢������ ���ᨢ�
    std::cout << "�����஢���� ���ᨢ:\n";
    PrintRandomArray(DoubleArr, UserSize);
    break;
  }
  default:
     std::cout << "������ �롮� ⨯� ������!\n";
     return 1;
  }



  #elif Unit==6
  std::cout << "������� 6" << std::endl; // �맮� �㭪樨 ������� 6 �� �⤥�쭮�� 䠩��

  int m; float x; char t;

  // ����� ���祭��
  std::cout << "������ �᫮ int: ";
  std::cin >> m;
  std::cout << "������ �᫮ float: ";
  std::cin >> x;
  std::cout << "������ ���祭�� ⨯� char: ";
  std::cin >> t;

  // �㭪�� ������ ����
  ReceiveAdress(m, x, t);

  // �㭪�� ����祭�� ���祭�� �� �����
  ReceiveValueAdress(m, x, t);

  // �㭪�� ����祭�� ���� �� ��६����� 㪠��⥫�
  ReceiveAdressVarPointer(m, x, t);

  // �㭪�� ����祭�� ���祭�� �� ������� 㪠��⥫�
  ReceiveAdressOperPointer(m, x, t);

  int n;
  // ����訢��� � ���짮��⥫� ������⢮ ����⮢
  std::cout << "������ ������⢮ ����⮢ (�� ����� " << MAX_SIZE << "): ";
  std::cin >> n;

  // �஢��塞, �⮡� ������⢮ ����⮢ �� �ॢ�蠫� ���ᨬ���� ࠧ���
  if (n > MAX_SIZE) {
  std::cout << "�訡��: ������⢮ ����⮢ �ॢ�蠥� ���ᨬ���� ࠧ��� ���ᨢ�!\n";
  return 1; // �����蠥� �ணࠬ�� � �訡���
  }

  // ������� ���ᨢ
  int arr[MAX_SIZE];

  // �����⥫� �� ��砫� ���ᨢ�
  int* ptr = arr;

  // ������塞 ���ᨢ
  FillArrayB(ptr, n);

  // ���⠥� ���ᨢ
  PrintArrayB(ptr, n);

  #elif Unit==7
  std::cout << "������� 7" << std::endl; // �맮� �㭪樨 ������� 7 �� �⤥�쭮�� 䠩��

  char phases[] = {'U', 'V', 'W', 'N'};
  int n = sizeof(phases) / sizeof(phases[0]); // ������⢮ 䠧
  int count = 0;

  std::cout << "��ਠ��� ��� ����⠭���� 䠧:\n";
  PermutationOptions(phases, 0, n-1, count);

  std::cout << "������⢮ ������祭��: " << count << std::endl;

  #elif Unit==8
  std::cout << "������� 8" << std::endl; // �맮� �㭪樨 ������� 8 �� �⤥�쭮�� 䠩��

  int a, b;
  int choice;

  // ����訢��� � ���짮��⥫� �롮� ����樨
  std::cout << "�롥�� ������:\n";
  std::cout << "1 - �\n";
  std::cout << "2 - ���\n";
  std::cout << "3 - XOR\n";
  std::cin >> choice;

  // ����訢��� ��� �᫠
  std::cout << "������ ��� 楫�� �᫠ (0-255): ";
  std::cin >> a >> b;

  // �롨ࠥ� callback-�㭪�� � ����ᨬ��� �� �롮� ���짮��⥫�
  CallbackType callback = nullptr;

  switch (choice) {
    case 1:
      callback = logicalAND;
      break;
    case 2:
      callback = logicalOR;
      break;
    case 3:
      callback = logicalXOR;
      break;
    default:
      std::cout << "������ �롮� ����樨!\n";
      return 1;
  }

  // ����塞 १���� � ������� callback-�㭪樨
  int result = ResultFunction(a, b, callback);

  // �뢮��� १����
  std::cout << "�������: " << result << std::endl;


  #else
  std::cout << "������� 9" << std::endl; // �맮� �㭪樨 ������� 9 �� �⤥�쭮�� 䠩��

  char arr[12] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};

  std::cout << "��室�� ���ᨢ �� ������: " <<'\n';
  for (int i = 0; i < 12; ++i){
    std::cout << arr[i] <<" ";
  }
  std::cout << std::endl;

  // �맮� �㭪樨
  OddEven(arr, 12);

  std::cout << "���ᨢ ��᫥ ������: " <<'\n';
  for (int i = 0; i < 12; ++i){
    std::cout << arr[i] <<" ";
  }
  std::cout << std::endl;


  #endif
  return 0;
}

