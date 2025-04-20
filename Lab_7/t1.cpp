/**************************************************************************************
 * Filename: t1.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 7
 * ��᫥������� �++ ����ᮢ � IDE Qt Creator
 * ***********************************************************************************/

#include <iostream>
#include <thread>
#include <stdexcept>
#include <vector>
#include "lab7.h"

// �஢�ઠ �室��� ������
void FibonacciCalculation::validateInput(int n) {
  if (n == 9) {
    throw std::invalid_argument("���᫥��� 9-�� �᫠ �������� ����饭�.");
  }
  if (n < 0) {
    throw std::invalid_argument("����� �᫠ �������� ������ ���� ������⥫��.");
  }
}

// �㭪�� ��ࠫ���쭮�� ���᫥���, �믮��塞�� � ������ ��⮪�
void FibonacciCalculation::compute(int n,
                                   std::vector<unsigned long long>& sequence, // ���ᨢ १���⮢
                                   std::vector<bool>& ready, // ����� ��⮢���� ���祭��
                                   std::mutex& mtx, // ��騩 ���⥪�
                                   std::vector<std::condition_variable>& cv) {// �᫮��� ��६����
  // ����� ��⮪ ������ �� �᫠ ��᫥����⥫쭮��, �� ᨭ�஭�������� � ��㣨��
  for (int i = 1; i <= n; ++i) {
    // ��墠�뢠�� ���⥪� ��� ࠡ��� � ��騬� ����묨
    std::unique_lock<std::mutex> lock(mtx);

    // ��� ��� ����⮢ �஬� ��ࢮ�� ���� ��⮢���� �।��饣�
    if (i > 1) {
      // ������� �� �᫮���� ��६�����, ���� �।��饥 ���祭�� �� �㤥� ��⮢�
      cv[(i-1) % cv.size()].wait(lock, [&ready, i] {
        return ready[i-1];  // �஢��塞 ��⮢����� �।��饣� �����
      });
    }

    // ����塞 ⥪�饥 �᫮ ��������
    if (i == 1) {
      sequence[i] = 1;  // ������ ��砩 F(1) = 1
    } else {
      sequence[i] = sequence[i-1] + sequence[i-2];  // �᭮���� ��㫠
    }

    // ����砥� ⥪�饥 ���祭�� ��� ��⮢��
    ready[i] = true;
    lock.unlock();

    // �������塞 ᫥���騩 ��⮪, �� ����� �த������
    cv[i % cv.size()].notify_one(); //����������� ���� �� ��⮪��
  }
}

// �᭮���� �㭪�� ���᫥���
unsigned long long FibonacciCalculation::calculate(int n) {
  validateInput(n);  // ���砫� �஢��塞 �室�� �����

  // ������ ��砨
  if (n <= 1) return n;

  // ��।��塞 ������⢮ ��⮪�� (�� ��� 拉� ������)
  unsigned num_threads = std::thread::hardware_concurrency();
  if (num_threads == 0) num_threads = 1;  // �᫨ �� 㤠���� ��।�����

  // ���樠�����㥬 �������� ������:
  std::vector<unsigned long long> sequence(n+1, 0);  // ��᫥����⥫쭮��� ��������
  std::vector<bool> ready(n+1, false);               // ����� ��⮢����
  sequence[0] = 0;  // ������ ��砩 F(0) = 0
  ready[0] = true;  // �㫥��� ����� ��⮢ �ࠧ�

  std::mutex mtx;  // ��� ᨭ�஭���樨 � ����� ����㯠 � ��騬 �����
  std::vector<std::condition_variable> cv(num_threads);  // // ����� �᫮���� ��६����� ��� ᨭ�஭���樨 ��⮪��

  // ������� � ����᪠�� ��⮪�
  std::vector<std::thread> threads;
  for (unsigned i = 0; i < num_threads; ++i) {
    // ����� ��⮪ �믮���� compute � ����㯮� � ��騬 �����
    threads.emplace_back(compute, n, std::ref(sequence),
                         std::ref(ready), std::ref(mtx), std::ref(cv));
  }

  // ������� �����襭�� ��� ��⮪��
  for (auto& t : threads) {
    t.join();
  }

  return sequence[n];  // �����頥� १����
}
