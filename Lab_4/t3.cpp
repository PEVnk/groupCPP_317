#include <iostream>
#include "lab4.h"


// Реализация функции вывода букв с десятичными кодами
void PrintCodeAlphabet(){
char ch;
std::cout<<"Алфавит"<<'\t'<<"Десятичный код символа английского языка" << std::endl;
  for (ch = 'a'; ch <= 'z'; ++ch){
    std::cout<<ch<<'\t'<<static_cast <int>(ch) << std::endl;
  }
}
