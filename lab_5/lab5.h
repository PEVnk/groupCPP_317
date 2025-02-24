/**************************************************************************************
 * Filename: lab5.h
 * Developer: Perkova Elena
 * Description: ������ୠ� 5
 * ��᫥������� ��ப, ������� ����� �++ � IDE Qt Creator
 * ************************************************************************************/

#ifndef LAB5_H
#define LAB5_H

#include <string>

// ������� 1
// ������� �㭪樨
void printAddresses();

// ������� ��६�����
extern int globalVarBSS;  // ��६����� � ᥪ樨 .bss
extern int globalVarData; // ��६����� � ᥪ樨 .data

// ������� 2
// ������� ��� ���ᠭ�� ����⢠
struct Creature {
  int headNumber;                     // ������⢮ �����
  std::string headType;               // ���� �����
  int legNumber;                      // ������⢮ ���
  std::string bodyCover;              // ���஢ ⥫�
  std::string tailType;               // ��� 墮��
  int eyeNumber;                      // ������⢮ ����
  std::string eyeTypes;               // ���� ����
};

// �㭪�� ��� ᮧ����� ������ ����⢠
Creature createCreature();

// �㭪�� ��� �뢮�� ���ᠭ�� ����⢠
void printCreature(const Creature& creature);

// ������� 3
// ������� ��� �࠭���� ���ଠ樨 � ���⮯��������
struct Location {
    std::string city;     // ��த
    std::string region;   // �������/ॣ���
    std::string capital;  // �⮫��
    std::string country;  // ��࠭�/���㤠��⢮
    std::string continent;// ���ਪ
};

// �㭪�� ��� ���᪠ ���ଠ樨 � ��த�
const Location* searchCity(const Location* locations, size_t size, const std::string& city);


// ������� 4
// �㭪�� ��� �ᯠ����� ��ப�
std::string unpackString(const std::string& packed);

// ������� 5
// �㭪�� ��� ��ࠡ�⪨ ��ப�
void processString(std::string& str);

// ������� 6

// ���ᨬ��쭮� ������⢮ ��ப
const int numStrings = 25;
// ���ᨬ��쭠� ����� ��ப�
const int numLength = 80;

// �㭪�� ��� ����� ��ப
int inputStrings(std::string strings[], int maxStrings);

// �㭪�� ��� ���஢�� ��ப �� �����
void sortLength(std::string strings[], int count);

// �㭪�� ��� ���஢�� ��ப �� ��䠢���
void sortAlphabet(std::string strings[], int count);

// �㭪�� ��� �뢮�� ��ப
void printStrings(const std::string strings[], int count);

// ������� 7

// �㭪�� ��� �८�ࠧ������ �᫠ � ��ப�
std::string intToString(int number);

// �㭪�� ��� �८�ࠧ������ ��ப� � �᫮
int stringToInt(const std::string& str);

// ������� 8
struct Address {
    std::string Country;
    std::string City;
    std::string Street;
    std::string House;
};

// �㭪�� ��� ࠧ��� ��ப� � ���������� �������� Address
void Parse(const std::string& line, Address* const address);

// �㭪�� ��� �ਢ������ ���� � �������᪮�� ����
void Unify(Address* const address);

// �㭪�� ��� �ଠ�஢���� ���� � ��ப�
std::string Format(const Address& address);


#endif // LAB5_H
