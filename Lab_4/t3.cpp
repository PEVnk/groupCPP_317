#include <iostream>
#include "lab4.h"


// ��������� �㭪樨 �뢮�� �㪢 � ������묨 ������
void PrintCodeAlphabet(){
char ch;
std::cout<<"��䠢��"<<'\t'<<"������� ��� ᨬ���� ������᪮�� �몠" << std::endl;
  for (ch = 'a'; ch <= 'z'; ++ch){
    std::cout<<ch<<'\t'<<static_cast <int>(ch) << std::endl;
  }
}
