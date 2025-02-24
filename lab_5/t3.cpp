/**************************************************************************************
 * Filename: t3.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 5
 * ��᫥������� ��ப, ������� ����� �++ � IDE Qt Creator
 * ������� 3
 * ************************************************************************************/

#include <iostream>
#include <string>
#include "lab5.h"

// �㭪�� ��� ���᪠ ���ଠ樨 � ��த�
const Location* searchCity(const Location* locations, size_t size, const std::string& city) {
    for (size_t i = 0; i < size; ++i) {
        if (locations[i].city == city) {
            return &locations[i]; // �����頥� 㪠��⥫� �� �������� ��ꥪ�
        }
    }
    return nullptr; // �᫨ ��த �� ������
}
