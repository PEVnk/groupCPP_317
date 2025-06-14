/**************************************************************************************
 * Filename: t5.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 8
 * ��᫥������� � �++ �⠭���⭮� ������⥪� 蠡����� (STL), ��ॣ�㧪� �����஢
 * ***********************************************************************************/

#include <iostream>
#include "lab8.h"
#include <chrono>

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t size) : capacity(size) {
  // ����⪠ �뤥���� ������ � �஢�મ� �� �ᯥ譮���
  buffer = new (std::nothrow) T[size];
  if (!buffer) {
    throw std::bad_alloc(); // ������㥬 �᪫�祭�� �� �訡��
  }
}

template <typename T>
CircularBuffer<T>::~CircularBuffer() {
  stopWriterThread(); // ��⠭���� ��⮪� �����
  delete[] buffer; // �᢮�������� ����� ����
}

template <typename T>
T CircularBuffer<T>::operator[](size_t index) const {
    std::lock_guard<std::mutex> lock(mtx);
    if (index >= capacity) {
      throw std::out_of_range("Index out of range");
    }
    // ����� � ��⮬ ����楢�� �������� (�१ tail)
    return buffer[(tail + index) % capacity];
}

template <typename T>
void CircularBuffer<T>::add(const T& value) {
  std::lock_guard<std::mutex> lock(mtx); // ��墠� ���⥪�
  buffer[head] = value;                 // ������ ���祭��
  head = (head + 1) % capacity;     // ���������� ������
  // �᫨ ���� ��९�����, ������� 墮��
  if (head == tail) {
    tail = (tail + 1) % capacity;
  }
}

template <typename T>
void CircularBuffer<T>::next() {
  std::lock_guard<std::mutex> lock(mtx);
  tail = (tail + 1) % capacity; // ���������� 墮��
}

template <typename T>
void CircularBuffer<T>::printAll() const {
  std::lock_guard<std::mutex> lock(mtx);
  for (size_t i = 0; i < capacity; ++i) {
    std::cout << buffer[i] << " "; // �뢮� ������� �����
  }
  std::cout << std::endl;
}

//�뢮� ����⮢ � �������� ���������
template <typename T>
void CircularBuffer<T>::printRange(size_t index1, size_t index2) const {
  std::lock_guard<std::mutex> lock(mtx);
  if (index1 >= capacity || index2 >= capacity) {
    throw std::out_of_range("Index out of range");
  }


  // �뢮� � ��⮬ ����楢�� ��������
  for (size_t i = index1; i <= index2; ++i) {
    std::cout << buffer[i % capacity] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
bool CircularBuffer<T>::isRunning() const {
  return running.load();
}


template <typename T>
void CircularBuffer<T>::writerThreadFunc() {
  T value = 0;
  while (running) {
    // �஢�ઠ ������ 'q' ��� ��室�
    char input;
    if (std::cin.peek() == 'q') {
      running = false;
      break;
    }

    // �⥭�� �����
    std::cin >> input;
    if (input == 'q') {
      running = false;
      break;
    }
    this->add(value++);
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
  }
}

template <typename T>
void CircularBuffer<T>::startWriterThread() {
  running = true; // ��⠭���� 䫠�� ࠡ���
  std::thread(&CircularBuffer<T>::writerThreadFunc, this).detach();
}

// ��⠭���� ��⮪� �����
template <typename T>
void CircularBuffer<T>::stopWriterThread() {
    running = false; // ���� 䫠�� ࠡ���
}

// ����� ���⠭樠�� 蠡���� ��� �㦭�� ⨯��
template class CircularBuffer<int>;
