/**************************************************************************************
 * Filename: main.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 5
 * ��᫥������� ��ப, ������� ����� �++ � IDE Qt Creator
 * ***********************************************************************************/

#include <iostream>
#include <string>
#include "lab5.h"

int globalVarBSS;  // ��६����� � ᥪ樨 .bss (�����樠����஢�����)

#define Unit 1
int main()
{
  #if Unit==1
  std::cout << "������� 1" << std::endl; // �맮� �㭪樨 ������� 1 �� �⤥�쭮�� 䠩��

  // ���� �㭪樨 main
  std::cout << "���� �㭪樨 main: " << (void*)&main << std::endl;

  // ���� �㭪樨 printAddresses
  printAddresses();

  // ���� ��६����� � �⥪�
  int stakVar = 20;
  std::cout << "���� ��६����� � �⥪�: " << &stakVar << std::endl;

  // ���� � ���祭�� ����⮢ ���ᨢ� � �⥪�
  int stakArray[3] = {5, 6, 7};
  for (int i = 0; i < 3; ++i){
    std::cout << "���� stakArray[" << i << "]: " << &stakArray[i] << ", ���祭��: " << stakArray[i] << std::endl;
  }

  // ���� ��६����� � ����᪮� ����� � ᥪ樨 .bss
  std::cout << "���� globalVarBSS: " << &globalVarBSS << std::endl;

  // ���� ��६����� � ����᪮� ����� � ᥪ樨 .data
  std::cout << "���� globalVarData: " << &globalVarData << std::endl;

  // ���� � ���祭�� ����⮢ ���ᨢ� � ����᪮� �����
  static int staticArray[3] = {8, 9, 10};
  for (int i = 0; i < 3; ++i){
    std::cout << "���� staticArray[" << i << "]: " << &staticArray[i] << ", ���祭��: " << staticArray[i] << std::endl;
  }

  // ���� ��६����� � ���
  int* heapVar = new (std::nothrow)int(25);
  std::cout << "���� ��६����� � ���: " << heapVar << std::endl;

  // ���� � ���祭�� ����⮢ ���ᨢ� � ���
  int* heapArray = new (std::nothrow)int[3]{7, 8, 9};
  for (int i = 0; i < 3; ++i){
    std::cout << "���� heapArray[" << i << "]: " << &heapArray[i] << ", ���祭��: " << heapArray[i] << std::endl;
  }

  // �᢮�������� �����
  delete heapVar;
  delete[] heapArray;


  #elif Unit==2
  std::cout << "������� 2" << std::endl; // �맮� �㭪樨 ������� 2 �� �⤥�쭮�� 䠩��

  std::cout << "���� ���������� � �ணࠬ�� '���� ���'!\n";
  std::cout << "�� ����� ᮧ���� ����� ����⢮, ��� �⮣� ������ ��� �ࠪ���⨪�.\n";

  // �������� ������ ����⢠
  Creature newCreature = createCreature();

  std::cout << "\n�� ᮧ���� ���� ���!\n";

  // �뢮� ���ᠭ�� ����⢠
  printCreature(newCreature);

  #elif Unit==3
  std::cout << "������� 3" << std::endl; // �맮� �㭪樨 ������� 3 �� �⤥�쭮�� 䠩��

  // ������� ���ᨢ ��ꥪ⮢ �������� � ����᪮� �����
  constexpr size_t staticSize = 10;
  Location staticLocations[staticSize] = {
    {"��᪢�", "��᪮�᪠� �������", "��᪢�", "�����", "��ࠧ��"},
    {"�����-������", "������ࠤ᪠� �������", "��᪢�", "�����", "��ࠧ��"},
    {"����ᨡ���", "����ᨡ��᪠� �������", "����ᨡ���", "�����", "��ࠧ��"},
    {"���-��������", "�����୨�", "��設�⮭", "���", "����ୠ� ���ਪ�"},
    {"���஡�", "���஡�", "���஡�", "�����", "��ਪ�"},
    {"�����㧭��", "����஢᪠� �������", "����஢�", "�����", "��ࠧ��"},
    {"������", "������", "������", "�����", "��ࠧ��"},
    {"�����", "���", "�����", "��⠩", "��ࠧ��"},
    {"�ப��쥢�", "����஢᪠� �������", "����஢�", "�����", "��ࠧ��"},
    {"���", "�㤮����", "���", "���㡫��� ����", "��ࠧ��"}
  };

  // ������� ���ᨢ 㪠��⥫�� �� ��ꥪ�� � �������᪮� �����
  const size_t dynamicSize = 2;
  Location* dynamicLocations[dynamicSize];
  dynamicLocations[0] = new (std::nothrow)Location{"������", "������", "������", "��������⠭��", "��ࠧ��"};
  dynamicLocations[1] = new (std::nothrow)Location{"���", "��樮", "���", "�⠫��", "��ࠧ��"};

  // �᭮���� 横� �ணࠬ��
  while (true){
    std::string city;
    std::cout << "������ �������� ��த� (��� 'q' ��� ��室�): ";
    std::getline(std::cin, city);
    if (city == "q") {
      break; // ��室 �� �ணࠬ��
    }

    // ���� ���ଠ樨 � ��த� � ����᪮� ���ᨢ�
    const Location* result = searchCity(staticLocations, staticSize, city);

    // �᫨ ��த �� ������ � ����᪮� ���ᨢ�, �饬 � �������᪮�
    if (!result){
      result = searchCity(*dynamicLocations, dynamicSize, city);
    }

    if (result){
      // �뢮� ���ଠ樨 � ��த�
      std::cout << "��த: " << result->city << "\n";
      std::cout << "������: " << result->region << "\n";
      std::cout << "�⮫��: " << result->capital << "\n";
      std::cout << "��࠭�: " << result->country << "\n";
      std::cout << "���ਪ: " << result->continent << "\n";
    } else {
      std::cout << "������ ���ଠ�� ���������.\n";
    }
  }

  // �᢮������� ���������� ������
  for (size_t i = 0; i < dynamicSize; ++i){
    delete dynamicLocations[i];
  }


  #elif Unit==4
  std::cout << "������� 4" << std::endl; // �맮� �㭪樨 ������� 4 �� �⤥�쭮�� 䠩��
  std::string packed;
  std::cout << "������ 㯠�������� ��ப�: ";
  std::cin >> packed;

  // ��ᯠ���뢠�� ��ப�
  std::string unpacked = unpackString(packed);

  // �뢮��� १����
  std::cout << "��ᯠ�������� ��ப�: " << unpacked << std::endl;

  #elif Unit==5
  std::cout << "������� 5" << std::endl; // �맮� �㭪樨 ������� 5 �� �⤥�쭮�� 䠩��
  std::string input;
  std::cout << "������ ��ப� (���ᨬ� 100 ᨬ�����): ";
  std::getline(std::cin, input); // ���뢠�� ��� ��ப�, ������ �஡���

  // ��ࠡ��뢠�� ��ப�
  processString(input);

  // �뢮��� १����
  std::cout << "��ࠡ�⠭��� ��ப�: " << input << std::endl;

  #elif Unit==6
  std::cout << "������� 6" << std::endl; // �맮� �㭪樨 ������� 6 �� �⤥�쭮�� 䠩��

  std::string strings[numStrings];
  int count = inputStrings(strings, numStrings);

  if (count == 0){
    std::cout << "�� ������� �� ����� ��ப�.\n";
    return 0;
  }

  // �롮� ᯮᮡ� ���஢��
  std::cout << "�롥�� ᯮᮡ ���஢��:\n";
  std::cout << "1. �� ����� ��ப�\n";
  std::cout << "2. �� ��䠢���\n";
  int choice;
  std::cin >> choice;
  std::cin.ignore(); // ������㥬 ��⠢訩�� ᨬ��� ����� ��ப�

  switch (choice){
    case 1:
      sortLength(strings, count);
      break;
    case 2:
      sortAlphabet(strings, count);
      break;
    default:
      std::cout << "������ �롮�. ����஢�� �� �믮�����.\n";
      return 1;
  }

  // �뢮� �����஢����� ��ப
  printStrings(strings, count);


  #elif Unit==7
  std::cout << "������� 7" << std::endl; // �맮� �㭪樨 ������� 7 �� �⤥�쭮�� 䠩��

  // �ਬ�� �८�ࠧ������ �᫠ � ��ப�
  int number;
  std::cout << "������ �᫮ ��� �८�ࠧ������ � ��ப�: ";
  std::cin >> number;

  std::string str = intToString(number);
  std::cout << "������� �८�ࠧ������ �᫠ � ��ப�: " << str << "\n";


  // �ਬ�� �८�ࠧ������ ��ப� � �᫮
  std::string input;
  std::cout << "������ ��ப� ��� �८�ࠧ������ � �᫮: ";
  std::cin >> input;

  try{
    int num = stringToInt(input);
    std::cout << "������� �८�ࠧ������ ��ப� � �᫮: " << num << "\n";
  }
  catch (std::invalid_argument const &e){
    std::cout << "Bad input: std::invalid_argument thrown" << std::endl;
  }
  catch (std::out_of_range const &e){
    std::cout << "Integer overflow: std::out_of_range thrown" << std::endl;
  }


  #else
  std::string line;
    while (getline(std::cin, line)){
      Address address; // ������� ��ꥪ� Address �� �⥪�
    try{
      Parse(line, &address); // ��।��� 㪠��⥫� �� ��ꥪ�
      Unify(&address);
      std::cout << Format(address) << "\n";
    }
    catch (const std::exception& e){
      std::cout << "exception\n"; // �뢮��� "exception" � ��砥 �訡��
    }
    }



  #endif
  return 0;
}
