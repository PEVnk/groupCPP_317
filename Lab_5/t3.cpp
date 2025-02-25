/**************************************************************************************
 * Filename: t3.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 5
 * Исследование строк, структур памяти С++ в IDE Qt Creator
 * Задание 3
 * ************************************************************************************/

#include <iostream>
#include <string>
#include "lab5.h"

// Функция для поиска информации о городе
const Location* searchCity(const Location* locations, size_t size, const std::string& city) {
    for (size_t i = 0; i < size; ++i) {
        if (locations[i].city == city) {
            return &locations[i]; // Возвращаем указатель на найденный объект
        }
    }
    return nullptr; // Если город не найден
}
