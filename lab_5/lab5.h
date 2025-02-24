/**************************************************************************************
 * Filename: lab5.h
 * Developer: Perkova Elena
 * Description: Лабораторная 5
 * Исследование строк, структур памяти С++ в IDE Qt Creator
 * ************************************************************************************/

#ifndef LAB5_H
#define LAB5_H

#include <string>

// Задание 1
// Объявление функции
void printAddresses();

// Объявление переменных
extern int globalVarBSS;  // Переменная в секции .bss
extern int globalVarData; // Переменная в секции .data

// Задание 2
// Структура для описания существа
struct Creature {
  int headNumber;                     // Количество голов
  std::string headType;               // Типы голов
  int legNumber;                      // Количество лап
  std::string bodyCover;              // Покров тела
  std::string tailType;               // Тип хвоста
  int eyeNumber;                      // Количество глаз
  std::string eyeTypes;               // Типы глаз
};

// Функция для создания нового существа
Creature createCreature();

// Функция для вывода описания существа
void printCreature(const Creature& creature);

// Задание 3
// Структура для хранения информации о местоположении
struct Location {
    std::string city;     // Город
    std::string region;   // Область/регион
    std::string capital;  // Столица
    std::string country;  // Страна/государство
    std::string continent;// Материк
};

// Функция для поиска информации о городе
const Location* searchCity(const Location* locations, size_t size, const std::string& city);


// Задание 4
// Функция для распаковки строки
std::string unpackString(const std::string& packed);

// Задание 5
// Функция для обработки строки
void processString(std::string& str);

// Задание 6

// Максимальное количество строк
const int numStrings = 25;
// Максимальная длина строки
const int numLength = 80;

// Функция для ввода строк
int inputStrings(std::string strings[], int maxStrings);

// Функция для сортировки строк по длине
void sortLength(std::string strings[], int count);

// Функция для сортировки строк по алфавиту
void sortAlphabet(std::string strings[], int count);

// Функция для вывода строк
void printStrings(const std::string strings[], int count);

// Задание 7

// Функция для преобразования числа в строку
std::string intToString(int number);

// Функция для преобразования строки в число
int stringToInt(const std::string& str);

// Задание 8
struct Address {
    std::string Country;
    std::string City;
    std::string Street;
    std::string House;
};

// Функция для разбора строки и заполнения структуры Address
void Parse(const std::string& line, Address* const address);

// Функция для приведения адреса к каноническому виду
void Unify(Address* const address);

// Функция для форматирования адреса в строку
std::string Format(const Address& address);


#endif // LAB5_H
