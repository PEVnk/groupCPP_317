/**************************************************************************************
 * Filename: t1.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 5
 * Исследование строк, структур памяти С++ в IDE Qt Creator
 * Задание 1
 * ************************************************************************************/

#include <iostream>
#include "lab5.h"

// Определение функции
void printAddresses() {
    std::cout << "Адрес функции printAddresses: " << (void*)&printAddresses << std::endl;
}

// Определение переменных
int globalVarBSS;  // Переменная в секции .bss (неинициализированная)
int globalVarData = 15; // Переменная в секции .data (инициализированная)
