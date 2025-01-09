#include <iostream>
#include <random>
#include "lab4.h"

// ��������� �㭪�� ��� ���������� ���ᨢ� ��砩�묨 �᫠��
void RandomNumbers(int array[], int len){
  std::random_device rd;
  // ���樠�����㥬 ����� ���ᥭ�� ��砩�� ���⮢� �᫮�
  std::mt19937 mersenne(rd());
  for (int i = 0; i < len; ++i){
    array[i] = mersenne(); // �������� ���ᨢ� ��ᢠ����� ���祭�� ��砩���� �᫠
  }
}

// ��������� �㭪樨 ���᪠ �������쭮�� ���祭�� ���ᨢ�
int ArrayMin(int array[], int len){
  int MinValue=array[0];
  for (int i = 0; i < len; ++i){
    if (MinValue > array[i])
       MinValue = array[i];
  }
  return MinValue;
}

// ��������� �㭪樨 ���᪠ ���ᨬ��쭮�� ���祭�� ���ᨢ�
int ArrayMax(int array[], int len){
  int MaxValue = array[0];
  for (int i = 0; i < len; ++i){
    if (MaxValue < array[i])
       MaxValue = array[i];
  }
  return MaxValue;
}
