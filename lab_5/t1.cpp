/**************************************************************************************
 * Filename: t1.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 5
 * ��᫥������� ��ப, ������� ����� �++ � IDE Qt Creator
 * ������� 1
 * ************************************************************************************/

#include <iostream>
#include "lab5.h"

// ��।������ �㭪樨
void printAddresses() {
    std::cout << "���� �㭪樨 printAddresses: " << (void*)&printAddresses << std::endl;
}

// ��।������ ��६�����
int globalVarBSS;  // ��६����� � ᥪ樨 .bss (�����樠����஢�����)
int globalVarData = 15; // ��६����� � ᥪ樨 .data (���樠����஢�����)
