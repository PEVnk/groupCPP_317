#include <iostream>
#include "lab4.h"

// ��������� �㭪樨 ��� ������ ���祭�ﬨ ���� � ������ �祥�
void OddEven(char* arr, int size){
    //���塞 ���⠬� ���祭��
    for (int i=0; i < size-1; i+=2){
    char temp = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = temp;
  }
}
