#include <iostream>
#include "lab4.h"


// Реализация функции оператора адреса
void ReceiveAdress(int m, float x, char t){
  std::cout << "адрес m = " << &m << std:: endl;
  std::cout << "адрес fx = " << &x << std:: endl;
  int p = static_cast<int>(t);
  std::cout << "адрес cht = " << &p << std:: endl;
}

// Реализация функции получения значения по адресу
void ReceiveValueAdress(int m, float x, char t){
  std::cout << "значение по адресу m = " << *&m << std::endl;
  std::cout << "значение по адресу fx = " << *&x << std::endl;
  std::cout << "значение по адресу cht = " << *&t << std::endl;
}

// Реализация функции получения адреса по переменной указателя
void ReceiveAdressVarPointer(int m, float x, char t){
  int *pi_m = &m;
  std::cout << "адрес m = " << pi_m << std::endl;
  float *pf_x = &x;
  std::cout << "адрес fx = " << pf_x << std::endl;
  //char* ptr = &t;
  int p = static_cast<int>(t);
  int *pi_p = &p;
  std::cout << "адрес cht = " << pi_p << std::endl;
}

// Реализация функции получения значения по оператору указателя
void ReceiveAdressOperPointer(int m, float x, char t){
  int *pi_m = &m;
  std::cout << "значение по адресу m = " << *pi_m << std::endl;
  float *pf_x = &x;
  std::cout << "значение по адресу fx = " << *pf_x << std::endl;
  char *pch_t = &t;
  std::cout << "значение по адресу cht = " << *pch_t << std::endl;
}


// Реализация функции для заполнения массива через указатель
void FillArrayB(int* ptr, int n){
  std::cout << "Введите " << n << " элементов:\n";
    for (int i = 0; i < n; ++i) {
      std::cin >> *(ptr + i); // Используем указатель для доступа к элементам массива
    }
}

// Реализация функции для печати массива через указатель
void PrintArrayB(const int* ptr, int n){
  std::cout << "Элементы массива:\n";
    for (int i = 0; i < n; ++i) {
      std::cout << *(ptr + i) << " "; // Печатаем элементы массива через указатель
    }
  std::cout << std::endl;
}
