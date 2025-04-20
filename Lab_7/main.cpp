/**************************************************************************************
 * Filename: main.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 7
 * ��᫥������� �++ ����ᮢ � IDE Qt Creator
 * ***********************************************************************************/

#include <iostream>
#include <stdexcept>
#include <thread>
#include <random>
#include <vector>
#include <chrono>
#include "lab7.h"
#include "MyMessage.h"

#define Unit 4

int main()
{
  #if Unit==1
  std::cout << "������� 1" << std::endl; // �맮� �㭪樨 ������� 1 �� �⤥�쭮�� 䠩��

  int n;
  std::cout << "������ ����� �᫠ ��������: ";
  std::cin >> n;

  try {
    unsigned long long result = FibonacciCalculation::calculate(n);
    std::cout << n << "-� �᫮ ��������: " << result << std::endl;
    }
  // ��ࠡ��뢠�� �᪫�祭�� invalid_argument (����뢠���� �� n=9 ��� ����⥫쭮� n)
  catch (const std::invalid_argument& e) {
    std::cerr << "�訡��: " << e.what() << std::endl; // �뢮��� ᮮ�饭�� �� �訡�� � �⠭����� ��⮪ �訡��
    return 1;
  }
  // ��ࠡ��뢠�� ��� ��㣨� �᪫�祭��
  catch (...) {
    std::cerr << "�������⭠� �訡�� �� ���᫥��� �᫠ ��������" << std::endl;
    return 2;
  }


  #elif Unit==2
  std::cout << "������� 2" << std::endl; // �맮� �㭪樨 ������� 2 �� �⤥�쭮�� 䠩��

  // ������� ��� ��� � ��砫�� �����ᮬ 1000 �㡫��
  Account acc1(1, 1000.0);
  Account acc2(2, 1000.0);

  // �뢮��� ��砫�� �������
  std::cout << "��砫�� �������:\n";
  std::cout << "��� " << acc1.getId() << ": " << acc1.getBalance() << "��.\n";
  std::cout << "��� " << acc2.getId() << ": " << acc2.getBalance() << "��.\n\n";

  // ����᪠�� ��ॢ��� � ࠧ��� ��⮪��
  std::thread t1([&acc1, &acc2]() {
  bool success = Account::transfer(acc1, acc2, 500.0);
  std::cout << "��ॢ�� 500 ��. � ��� 1 �� ��� 2: "
                           << (success ? "�ᯥ譮" : "�������筮 �।��") << "\n";
  });

  std::thread t2([&acc2, &acc1]() {
  bool success = Account::transfer(acc2, acc1, 1200.0);
  std::cout << "��ॢ�� 1200 ��. � ��� 2 �� ��� 1: "
                           << (success ? "�ᯥ譮" : "�������筮 �।��") << "\n";
  });

  // ���� �����襭�� ��⮪��
  t1.join();
  t2.join();

  // �뢮��� �⮣��� �������
  std::cout << "\n�⮣��� �������:\n";
  std::cout << "��� " << acc1.getId() << ": " << acc1.getBalance() << "��.\n";
  std::cout << "��� " << acc2.getId() << ": " << acc2.getBalance() << "��.\n\n";



  #else
  using namespace Config;  // �ᯮ��㥬 ����⠭�� �� namespace

  MyMessage logger;
  std::vector<int> array(ARRAY_SIZE);  // �ᯮ��㥬 ARRAY_SIZE �� namespace

  // ����� ��⮪� ������
  std::thread loggerThread([&logger]() {
    logger.processQueue();
  });

  // ����� ࠡ��� ��⮪��
  std::thread filler(Workers::fillRandomNumbers, std::ref(array), std::ref(logger));
  std::thread filter(Workers::filterArray, std::ref(array), std::ref(logger));
  std::thread printer(Workers::printArray, std::ref(array), std::ref(logger));

  // �������� �����襭��
  filler.join();
  filter.join();
  printer.join();

  logger.stopProcessing();
  loggerThread.join();


  #endif
  return 0;
}
