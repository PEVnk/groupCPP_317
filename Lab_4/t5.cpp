#include <iostream>
#include <cstdlib>  // ��� rand() � srand()
#include <ctime>    // ��� time()
#include <algorithm> // ��� std::swap
#include "lab4.h"


// ��������� ��� int
// ��������� �㭪樨 ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
void FillRandomArray(int arr[], int UserSize) {
  for (int i = 0; i < UserSize; i++) {
    arr[i] = rand() % 100; // ������� ��砩��� �ᥫ �� 0 �� 99
  }
}

// ��������� �㭪樨 ���஢�� ��⮤�� �롮�
void SortSelect(int arr[], int UserSize){
  // ��ॡ�ࠥ� ����� ����� ���ᨢ� (�஬� ��᫥�����)
  for (int startIndex = 0; startIndex < UserSize - 1; ++startIndex) {
  /* � ��६����� smallestIndex �࠭���� ������ �������襣� ���祭��,
  * ���஥ �� ��諨 � �⮩ ���樨.
  * �������訩 ����� � �⮩ ���樨 - �� ���� ����� (������ 0)*/
  int smallestIndex = startIndex;
  // ��⥬ �饬 ����� ������� � ��⠫쭮� ��� ���ᨢ�
  for (int currentIndex = startIndex + 1; currentIndex < UserSize; ++currentIndex) {
  // �᫨ �� ��諨 �����, ����� ����� ��襣� �������襣� �����,
    if (arr[currentIndex] < arr[smallestIndex])
    // � ���������� ���
    smallestIndex = currentIndex;
  }
    // smallestIndex ⥯��� �������訩 �����.
    // ���塞 ���⠬� ��� ��砫쭮� �������襥 �᫮ � ⥬, ���஥ �� �����㦨��
  std::swap(arr[startIndex], arr[smallestIndex]);
  }
}

// ��������� �㭪樨 �뢮�� ���ᨢ�
void PrintRandomArray(int arr[], int UserSize) {
    for (int i = 0; i < UserSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// ��������� ��� short
// ��������� �㭪樨 ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
void FillRandomArray(short arr[], int UserSize) {
  for (int i = 0; i < UserSize; i++) {
    arr[i] = static_cast<short>(rand()) % 1000; // ������� ��砩��� short
  }
}

// ��������� �㭪樨 ���஢�� ��⮤�� �롮�
void SortSelect(short arr[], int UserSize){
  // ��ॡ�ࠥ� ����� ����� ���ᨢ� (�஬� ��᫥�����)
  for (int startIndex = 0; startIndex < UserSize - 1; ++startIndex) {
  /* � ��६����� smallestIndex �࠭���� ������ �������襣� ���祭��,
  * ���஥ �� ��諨 � �⮩ ���樨.
  * �������訩 ����� � �⮩ ���樨 - �� ���� ����� (������ 0)*/
  int smallestIndex = startIndex;
  // ��⥬ �饬 ����� ������� � ��⠫쭮� ��� ���ᨢ�
  for (int currentIndex = startIndex + 1; currentIndex < UserSize; ++currentIndex) {
  // �᫨ �� ��諨 �����, ����� ����� ��襣� �������襣� �����,
    if (arr[currentIndex] < arr[smallestIndex])
    // � ���������� ���
    smallestIndex = currentIndex;
  }
    // smallestIndex ⥯��� �������訩 �����.
    // ���塞 ���⠬� ��� ��砫쭮� �������襥 �᫮ � ⥬, ���஥ �� �����㦨��
  std::swap(arr[startIndex], arr[smallestIndex]);
  }
}

// ��������� �㭪樨 �뢮�� ���ᨢ�
void PrintRandomArray(short arr[], int UserSize) {
    for (int i = 0; i < UserSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// ��������� ��� float
// ��������� �㭪樨 ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
void FillRandomArray(float arr[], int UserSize) {
  for (int i = 0; i < UserSize; i++){
    arr[i] = static_cast<float>(rand()) / RAND_MAX * 100.0f; // ������� ��砩��� float
  }
}

// ��������� �㭪樨 ���஢�� ��⮤�� �롮�
void SortSelect(float arr[], int UserSize){
  // ��ॡ�ࠥ� ����� ����� ���ᨢ� (�஬� ��᫥�����)
  for (int startIndex = 0; startIndex < UserSize - 1; ++startIndex) {
  /* � ��६����� smallestIndex �࠭���� ������ �������襣� ���祭��,
  * ���஥ �� ��諨 � �⮩ ���樨.
  * �������訩 ����� � �⮩ ���樨 - �� ���� ����� (������ 0)*/
  int smallestIndex = startIndex;
  // ��⥬ �饬 ����� ������� � ��⠫쭮� ��� ���ᨢ�
  for (int currentIndex = startIndex + 1; currentIndex < UserSize; ++currentIndex) {
  // �᫨ �� ��諨 �����, ����� ����� ��襣� �������襣� �����,
    if (arr[currentIndex] < arr[smallestIndex])
    // � ���������� ���
    smallestIndex = currentIndex;
  }
    // smallestIndex ⥯��� �������訩 �����.
    // ���塞 ���⠬� ��� ��砫쭮� �������襥 �᫮ � ⥬, ���஥ �� �����㦨��
  std::swap(arr[startIndex], arr[smallestIndex]);
  }
}

// ��������� �㭪樨 �뢮�� ���ᨢ�
void PrintRandomArray(float arr[], int UserSize) {
    for (int i = 0; i < UserSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// ��������� ��� double
// ��������� �㭪樨 ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
void FillRandomArray(double arr[], int UserSize) {
  for (int i = 0; i < UserSize; i++) {
    arr[i] = static_cast<double>(rand()) / RAND_MAX * 100.0; // ������� ��砩��� double
  }
}

// ��������� �㭪樨 ���஢�� ��⮤�� �롮�
void SortSelect(double arr[], int UserSize){
  // ��ॡ�ࠥ� ����� ����� ���ᨢ� (�஬� ��᫥�����)
  for (int startIndex = 0; startIndex < UserSize - 1; ++startIndex) {
  /* � ��६����� smallestIndex �࠭���� ������ �������襣� ���祭��,
  * ���஥ �� ��諨 � �⮩ ���樨.
  * �������訩 ����� � �⮩ ���樨 - �� ���� ����� (������ 0)*/
  int smallestIndex = startIndex;
  // ��⥬ �饬 ����� ������� � ��⠫쭮� ��� ���ᨢ�
  for (int currentIndex = startIndex + 1; currentIndex < UserSize; ++currentIndex) {
  // �᫨ �� ��諨 �����, ����� ����� ��襣� �������襣� �����,
    if (arr[currentIndex] < arr[smallestIndex])
    // � ���������� ���
    smallestIndex = currentIndex;
  }
    // smallestIndex ⥯��� �������訩 �����.
    // ���塞 ���⠬� ��� ��砫쭮� �������襥 �᫮ � ⥬, ���஥ �� �����㦨��
  std::swap(arr[startIndex], arr[smallestIndex]);
  }
}

// ��������� �㭪樨 �뢮�� ���ᨢ�
void PrintRandomArray(double arr[], int UserSize) {
    for (int i = 0; i < UserSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// ��������� ��� char
// ��������� �㭪樨 ���������� ���ᨢ� ��砩�묨 ���祭�ﬨ
void FillRandomArray(char arr[], int UserSize) {
  for (int i = 0; i < UserSize; i++) {
    arr[i] = static_cast<char>(rand()) % 128; // ������� ��砩��� char
  }
}

// ��������� �㭪樨 ���஢�� ��⮤�� �롮�
void SortSelect(char arr[], int UserSize){
  // ��ॡ�ࠥ� ����� ����� ���ᨢ� (�஬� ��᫥�����)
  for (int startIndex = 0; startIndex < UserSize - 1; ++startIndex) {
  /* � ��६����� smallestIndex �࠭���� ������ �������襣� ���祭��,
  * ���஥ �� ��諨 � �⮩ ���樨.
  * �������訩 ����� � �⮩ ���樨 - �� ���� ����� (������ 0)*/
  int smallestIndex = startIndex;
  // ��⥬ �饬 ����� ������� � ��⠫쭮� ��� ���ᨢ�
  for (int currentIndex = startIndex + 1; currentIndex < UserSize; ++currentIndex) {
  // �᫨ �� ��諨 �����, ����� ����� ��襣� �������襣� �����,
    if (arr[currentIndex] < arr[smallestIndex])
    // � ���������� ���
    smallestIndex = currentIndex;
  }
    // smallestIndex ⥯��� �������訩 �����.
    // ���塞 ���⠬� ��� ��砫쭮� �������襥 �᫮ � ⥬, ���஥ �� �����㦨��
  std::swap(arr[startIndex], arr[smallestIndex]);
  }
}

// ��������� �㭪樨 �뢮�� ���ᨢ�
void PrintRandomArray(char arr[], int UserSize) {
    for (int i = 0; i < UserSize; i++) {
        std::cout << static_cast<int>(arr[i]) << " "; // �뢮� ��� �ᥫ
    }
    std::cout << std::endl;
}
