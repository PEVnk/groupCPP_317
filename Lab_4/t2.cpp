#include <iostream>
#include <cstdlib>
#include <ctime> // ��� �㭪樨 time()
#include "lab4.h"

// ������� �
// ��������� �㭪樨 ��� ᮧ����� � �뢮�� �����筮� ������
void IdentityMatrix(){
  constexpr int size = 5; // ������� ࠧ��� ������
  int Matrix[size][size] = {0};// ���㫥��� ����⮢ ���ᨢ�


  // ���������� �����筮� ������
  for (int i = 0; i < size; ++i) {
     Matrix[i][i] = 1; // ���������� ������ ࠢ�� 1
  }

  // �뢮� ������ � ���᮫�
  std::cout << "�����筠� ����� 5x5:" << std::endl;
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        std::cout << Matrix[i][j] << " ";
      }
    std::cout << std::endl; // ���室 �� ����� ��ப� ��᫥ ������ ��ப� ������
    }
}

// ������� b

// ��������� �㭪樨 ��� ���������� ������ �ᥢ����砩�묨 �᫠��
void fillMatrixRandomNum(int matrix[][8], int rows, int cols) {
  // ���樠������ ������� ��砩��� �ᥫ
  std::srand(static_cast<unsigned int>(std::time(0)));
  // ���������� ������ ��砩�묨 �᫠�� �� -15 �� 15
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j){
      matrix[i][j] = std::rand() % 31 - 15; // ������� �᫠ � ��������� [-15, 15]
    }
  }
}

// ��������� �㭪樨 ��� �뢮�� ������ � ���᮫�
void printMatrix(const int matrix[][8], int rows, int cols) {
  std::cout << "����� 8x8:" << std::endl;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cout << matrix[i][j] << "\t"; // �뢮� ����� � ⠡��樥�
    }
      std::cout << std::endl; // ���室 �� ����� ��ப� ��᫥ ������ ��ப� ������
  }
}

// ��������� �㭪樨 ��� ���᫥��� �㬬� ����⮢ ��� ������� ���������
int AddArrayElements(const int matrix[][8], int rows, int cols){
  int sum = 0;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        // �᫨ ����� ��室���� ��� ������� ��������� (j > i), ������塞 ��� � �㬬�
        if (j > i){
          sum += matrix[i][j];
        }
      }
    }
return sum;
}
