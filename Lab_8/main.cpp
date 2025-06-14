/**************************************************************************************
 * Filename: main.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 8
 * ��᫥������� � �++ �⠭���⭮� ������⥪� 蠡����� (STL), ��ॣ�㧪� �����஢
 * ***********************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <stdexcept> // ��� ࠡ��� � �᪫�祭�ﬨ
#include <limits>
#include "lab8.h"


#define Unit 5

int main()
{
  #if Unit==1
  std::cout << "������� 1" << std::endl; // �맮� �㭪樨 ������� 1 �� �⤥�쭮�� 䠩��

  int N; // ��६����� ��� �࠭���� ������⢠ ����⮢
  std::cout << "������ ������⢮ ����⮢ N (�� 1 �� 1000): ";
  std::cin >> N; // ���짮��⥫� ������ N

  // �஢�ઠ, �� N � �����⨬�� ���������
  if (N < 1 || N > 1000) {
    std::cerr << "�訡��: N ������ ���� �� 1 �� 1000." << std::endl;
    return 1; // �����蠥� �ணࠬ�� � �訡���
  }

  // ������㥬 ���⥩��� ��砩��� �ᥫ
  std::vector<int> container = generateRandomNumbers(N);

  // �뢮��� ᮤ�ন��� ���⥩���
  printContainer(container);

  // ��⠥� ������⢮ 㭨������ �ᥫ � �뢮��� १����
  int uniqueCount = countUniqueNumbers(container);
  std::cout << "��������� �ᥫ: " << uniqueCount << std::endl;




  #elif Unit==2
  std::cout << "������� 2" << std::endl; // �맮� �㭪樨 ������� 2 �� �⤥�쭮�� 䠩��

  // ===== ����� �) =====
  std::vector<int> vec = {1, 2, 3, 4, 5, 6};
  std::list<int> lst = {10, 21, 30, 41, 50};

  std::cout << "��室�� �����: ";
  printVector(vec);
  std::cout << "��室�� ᯨ᮪: ";
  printList(lst);

  std::vector<int> result = replaceEvenWithListOdd(vec, lst);
  std::cout << "������� ������: ";
  printVector(result);

  //===== ����� b)=====
  std::list<double> numbers = {1.5, 2.5, 3.5, 4.5};
  std::cout << "\n��室�� ᯨ᮪ (����⢥��� �᫠): ";
  for (double num : numbers) std::cout << num << " ";

  addAverageToList(numbers);
  std::cout << "\n��᫥ ���������� �।����: ";
  for (double num : numbers) std::cout << num << " ";
  std::cout << std::endl;


  //===== ����� c)=====
  std::cout << "\n���� ���� 梥⮢:\n";
  processFavoriteColors();

  #elif Unit==3
  std::cout << "������� 3" << std::endl; // �맮� �㭪樨 ������� 3 �� �⤥�쭮�� 䠩��
  try {
    double value;
    std::string unit;

    std::cout << "������ ���祭��: ";
    if (!(std::cin >> value)) {
      throw std::runtime_error("�訡��: ������� ���᫮��� ���祭��");
    }

    std::cout << "������ ������� ����७�� (bit, byte, Kbyte, Mbyte, Gbyte, MiB): ";
    if (!(std::cin >> unit)) {
      throw std::runtime_error("�訡�� ����� ������� ����७��");
    }

    DataSizeConverter converter(value, unit);
    converter.convert();
    converter.printResults();

    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
      // ���⪠ ���� ����� � ��砥 �訡��
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return 1;
    }




  #elif Unit==4
  std::cout << "������� 4" << std::endl; // �맮� �㭪樨 ������� 4 �� �⤥�쭮�� 䠩��
  TreeNode root(1);
  auto left_son = root.AddChild(10);
  auto middle_son = root.AddChild(20);
  auto right_son = root.AddChild(30);
  left_son->AddChild(100);
  left_son->AddChild(200);
  root.Print();



  #else
  // ������� ���� �� 5 ����⮢
  CircularBuffer<int> cb(5);

  // ����஢����
  cb.add(1);
  cb.add(2);
  cb.add(3);

  const CircularBuffer<int>& const_cb = cb;
  // �맮� const-��⮤��
  const_cb.printAll();
  const_cb.printRange(0, 2);

  // ����� ��⮪� �����
  cb.startWriterThread();

  // �������� �����襭��
  std::cout << "Press 'q' to quit..." << std::endl;
  while (cb.isRunning()) {
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
  }



  #endif
  return 0;
  }
