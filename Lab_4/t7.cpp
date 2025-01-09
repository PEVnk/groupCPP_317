#include <iostream>
#include "lab4.h"

// �㭪�� ��� ������ ���� ᨬ�����
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

// �㭪�� ����⠭����
void PermutationOptions(char arr[], int start, int end, int& count){
  if (start == end){
    // �᫨ ���⨣��� ����� ���ᨢ�, �뢮��� ⥪���� ����⠭����
    for (int i = 0; i <= end; ++i) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    count++;
  } else {
    // ������� ��� ����⠭����
    for (int i = start; i <= end; ++i) {
      swap(arr[start], arr[i]); // ���塞 ���⠬� ⥪�騩 ����� � ��砫��
      PermutationOptions(arr, start+1, end, count); // ��� ᫥���饣� �����
      swap(arr[start], arr[i]); // �����頥� ���ᨢ � ��室��� ���ﭨ�
    }
  }
}
