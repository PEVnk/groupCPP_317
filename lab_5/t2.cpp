/**************************************************************************************
 * Filename: t2.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 5
 * ��᫥������� ��ப, ������� ����� �++ � IDE Qt Creator
 * ������� 2
 * ************************************************************************************/

#include <iostream>
#include "lab5.h"
#include <string>

// �㭪�� ��� ᮧ����� ������ ����⢠
Creature createCreature() {
  Creature creature;

  // ����� ������⢠ � ⨯� �����
  std::cout << "������ ������⢮ �����: ";
  std::cin >> creature.headNumber;
  std::cin.ignore(); // ������㥬 ��⠢訩�� ᨬ��� ����� ��ப�

  std::cout << "������ ⨯ ������: ";
  std::getline(std::cin, creature.headType);

  // ����� ������⢠ ���
  std::cout << "������ ������⢮ ���: ";
  std::cin >> creature.legNumber;
  std::cin.ignore();

  // ����� ���஢� ⥫�
  std::cout << "������ ���஢ ⥫� (���ਬ��, ��᭠� �����, �ୠ� ����): ";
  std::getline(std::cin, creature.bodyCover);

  // ����� ⨯� 墮��
  std::cout << "������ ⨯ 墮��: ";
  std::getline(std::cin, creature.tailType);

  // ����� ������⢠ ����
  std::cout << "������ ������⢮ ����: ";
  std::cin >> creature.eyeNumber;
  std::cin.ignore();

  // ����� ⨯�� ����
  std::cout << "������ ⨯ ����: ";
  std::getline(std::cin, creature.eyeTypes);

  return creature;
  }

  // �㭪�� ��� �뢮�� ���ᠭ�� ����⢠
  void printCreature(const Creature& creature) {
    std::cout << "\n=== ���� ��� ����⢠ ===\n";

    // �뢮� ���ଠ樨 � �������
    std::cout << "������⢮ �����: " << creature.headNumber << "\n";
    std::cout << "��� �����: " << creature.headType << "\n";

    // �뢮� ���ଠ樨 � �����
    std::cout << "������⢮ ���: " << creature.legNumber << "\n";

    // �뢮� ���ଠ樨 � ���஢� ⥫�
    std::cout << "���஢ ⥫�: " << creature.bodyCover << "\n";

    // �뢮� ���ଠ樨 � 墮��
    std::cout << "��� 墮��: " << creature.tailType << "\n";

    // �뢮� ���ଠ樨 � ������
    std::cout << "������⢮ ����: "<< creature.eyeNumber << "\n";
    std::cout << "��� ����: " << creature.eyeTypes << "\n";
  }
