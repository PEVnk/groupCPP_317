#include <iostream>
#include "lab4.h"


// ��������� �㭪樨 ������ ����
void ReceiveAdress(int m, float x, char t){
  std::cout << "���� m = " << &m << std:: endl;
  std::cout << "���� fx = " << &x << std:: endl;
  int p = static_cast<int>(t);
  std::cout << "���� cht = " << &p << std:: endl;
}

// ��������� �㭪樨 ����祭�� ���祭�� �� �����
void ReceiveValueAdress(int m, float x, char t){
  std::cout << "���祭�� �� ����� m = " << *&m << std::endl;
  std::cout << "���祭�� �� ����� fx = " << *&x << std::endl;
  std::cout << "���祭�� �� ����� cht = " << *&t << std::endl;
}

// ��������� �㭪樨 ����祭�� ���� �� ��६����� 㪠��⥫�
void ReceiveAdressVarPointer(int m, float x, char t){
  int *pi_m = &m;
  std::cout << "���� m = " << pi_m << std::endl;
  float *pf_x = &x;
  std::cout << "���� fx = " << pf_x << std::endl;
  //char* ptr = &t;
  int p = static_cast<int>(t);
  int *pi_p = &p;
  std::cout << "���� cht = " << pi_p << std::endl;
}

// ��������� �㭪樨 ����祭�� ���祭�� �� ������� 㪠��⥫�
void ReceiveAdressOperPointer(int m, float x, char t){
  int *pi_m = &m;
  std::cout << "���祭�� �� ����� m = " << *pi_m << std::endl;
  float *pf_x = &x;
  std::cout << "���祭�� �� ����� fx = " << *pf_x << std::endl;
  char *pch_t = &t;
  std::cout << "���祭�� �� ����� cht = " << *pch_t << std::endl;
}


// ��������� �㭪樨 ��� ���������� ���ᨢ� �१ 㪠��⥫�
void FillArrayB(int* ptr, int n){
  std::cout << "������ " << n << " ����⮢:\n";
    for (int i = 0; i < n; ++i) {
      std::cin >> *(ptr + i); // �ᯮ��㥬 㪠��⥫� ��� ����㯠 � ����⠬ ���ᨢ�
    }
}

// ��������� �㭪樨 ��� ���� ���ᨢ� �१ 㪠��⥫�
void PrintArrayB(const int* ptr, int n){
  std::cout << "�������� ���ᨢ�:\n";
    for (int i = 0; i < n; ++i) {
      std::cout << *(ptr + i) << " "; // ���⠥� ������ ���ᨢ� �१ 㪠��⥫�
    }
  std::cout << std::endl;
}
