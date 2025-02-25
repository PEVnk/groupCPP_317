/**************************************************************************************
 * Filename: t2.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 5
 * Исследование строк, структур памяти С++ в IDE Qt Creator
 * Задание 2
 * ************************************************************************************/

#include <iostream>
#include "lab5.h"
#include <string>

// Функция для создания нового существа
Creature createCreature() {
  Creature creature;

  // Запрос количества и типа голов
  std::cout << "Введите количество голов: ";
  std::cin >> creature.headNumber;
  std::cin.ignore(); // Игнорируем оставшийся символ новой строки

  std::cout << "Введите тип головы: ";
  std::getline(std::cin, creature.headType);

  // Запрос количества лап
  std::cout << "Введите количество лап: ";
  std::cin >> creature.legNumber;
  std::cin.ignore();

  // Запрос покрова тела
  std::cout << "Введите покров тела (например, красная шерсть, черная чешуя): ";
  std::getline(std::cin, creature.bodyCover);

  // Запрос типа хвоста
  std::cout << "Введите тип хвоста: ";
  std::getline(std::cin, creature.tailType);

  // Запрос количества глаз
  std::cout << "Введите количество глаз: ";
  std::cin >> creature.eyeNumber;
  std::cin.ignore();

  // Запрос типов глаз
  std::cout << "Введите тип глаз: ";
  std::getline(std::cin, creature.eyeTypes);

  return creature;
  }

  // Функция для вывода описания существа
  void printCreature(const Creature& creature) {
    std::cout << "\n=== Новый вид существа ===\n";

    // Вывод информации о головах
    std::cout << "Количество голов: " << creature.headNumber << "\n";
    std::cout << "Тип голов: " << creature.headType << "\n";

    // Вывод информации о лапах
    std::cout << "Количество лап: " << creature.legNumber << "\n";

    // Вывод информации о покрове тела
    std::cout << "Покров тела: " << creature.bodyCover << "\n";

    // Вывод информации о хвосте
    std::cout << "Тип хвоста: " << creature.tailType << "\n";

    // Вывод информации о глазах
    std::cout << "Количество глаз: "<< creature.eyeNumber << "\n";
    std::cout << "Тип глаз: " << creature.eyeTypes << "\n";
  }
