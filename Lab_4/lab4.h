#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <random>
#include <functional> // ��� std::function
#include <cstdint> // ��� uint8_t

// ������� 1
// �㭪�� ��� ���������� ���ᨢ� ��砩�묨 �᫠��
void RandomNumbers(int array[], int len);

// �㭪�� ���᪠ �������쭮�� ���祭��
int ArrayMin(int array[], int len);

// �㭪�� ���᪠ ���ᨬ��쭮�� ���祭��
int ArrayMax(int array[], int len);

// ������� 2
// �㭪�� ᮧ����� �����筮� ������
void IdentityMatrix();

// �㭪�� ��� ���������� ������ �ᥢ����砩�묨 �᫠��
void fillMatrixRandomNum(int matrix[][8], int rows, int cols);

// �㭪�� ��� �뢮�� ������ � ���᮫�
void printMatrix(const int matrix[][8], int rows, int cols);

// �㭪�� ���᫥��� �㬬� ����⮢ ���ᨢ� ��� ������� ���������
int AddArrayElements(const int matrix[][8], int rows, int cols);

// ������� 3
// �㭪�� �뢮�� �㪢 � ������묨 ������
void PrintCodeAlphabet();

// ������� 4

// �㭪�� �஢�ન ���������� �᫠
bool CheckNumber(int Num);

// �㭪�� ��宦����� 䠪�ਠ�� � ������� ���権
double FindFactorialIteration(int Num);

// �㭪�� ��宦����� 䠪�ਠ�� � ������� ४��ᨨ
double FindFactorialRecursion(int Num);

// �㭪�� ���᪠ �ᥫ �������� � ������� ���権
int fib(int UserNum);

// �㭪�� �뢮�� ��ࠬ��� �ᥫ
void PrintPiramid(int UserNumber);

// ������� 5

// �㭪樨 ��� ⨯� int
// �㭪�� ���������� ���ᨢ� ��砩�묨 �᫠��
void FillRandomArray(int arr[], int UserSize);
// �㭪�� ���஢�� ���ᨢ�
void SortSelect(int arr[], int UserSize);
// �㭪�� ��� �뢮�� ���ᨢ�
void PrintRandomArray(int arr[], int UserSize);

// �㭪樨 ��� ⨯� char
// �㭪�� ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
void FillRandomArray(char arr[], int UserSize);
// �㭪�� ���஢�� ���ᨢ�
void SortSelect(char arr[], int UserSize);
// �㭪�� ��� �뢮�� ���ᨢ�
void PrintRandomArray(char arr[], int UserSize);

// �㭪樨 ��� ⨯� short
// �㭪�� ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
void FillRandomArray(short arr[], int UserSize);
// �㭪�� ���஢�� ���ᨢ�
void SortSelect(short arr[], int UserSize);
// �㭪�� ��� �뢮�� ���ᨢ�
void PrintRandomArray(short arr[], int UserSize);

// �㭪樨 ��� ⨯� float
// �㭪�� ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
void FillRandomArray(float arr[], int UserSize);
// �㭪�� ���஢�� ���ᨢ�
void SortSelect(float arr[], int UserSize);
// �㭪�� ��� �뢮�� ���ᨢ�
void PrintRandomArray(float arr[], int UserSize);

// �㭪樨 ��� ⨯� double
// �㭪�� ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
void FillRandomArray(double arr[], int UserSize);
// �㭪�� ���஢�� ���ᨢ�
void SortSelect(double arr[], int UserSize);
// �㭪�� ��� �뢮�� ���ᨢ�
void PrintRandomArray(double arr[], int UserSize);

// ������� 6
// �㭪�� ������ ����
void ReceiveAdress(int m, float x, char t);

// �㭪�� ����祭�� ���祭�� �� �����
void ReceiveValueAdress(int m, float x, char t);

// �㭪�� ����祭�� ���� �� ��६����� 㪠��⥫�
void ReceiveAdressVarPointer(int m, float x, char t);

// �㭪�� ����祭�� ���祭�� �� ������� 㪠��⥫�
void ReceiveAdressOperPointer(int m, float x, char t);

// ��࠭�稬 ���ᨬ���� ࠧ��� ���ᨢ�
const int MAX_SIZE = 100;

// �㭪�� ��� ���������� ���ᨢ�
void FillArrayB(int* ptr, int n);

// �㭪�� ��� ���� ���ᨢ�
void PrintArrayB(const int* ptr, int n);

// ������� 7
// �㭪�� ����⠭����
void PermutationOptions(char arr[], int start, int end, int& count);

// ������� 8
// ������� �����᪨� ����権
int logicalAND(int a, int b);
int logicalOR(int a, int b);
int logicalXOR(int a, int b);

// ��� ��� callback-�㭪樨
using CallbackType = int(*)(int, int);

// �㭪�� ��� ���᫥��� १����
int ResultFunction(int a, int b, CallbackType callback);

// ������� 9
// �㭪�� ������ ���祭�� ���� � ������ �祥�
void OddEven(char* arr, int size);




#endif // LAB4_H
