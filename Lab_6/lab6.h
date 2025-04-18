/**************************************************************************************
 * Filename: lab6.h
 * Developer: Perkova Elena
 * Description: Лабораторная 6
 * Исследование С++ классов в IDE Qt Creator
 * ************************************************************************************/


#ifndef LAB6_H
#define LAB6_H

#include <vector>
#include <string>


// Задание 1

class Bruteforce {
public:
  // Конструктор с настройкой параметров перебора
  Bruteforce(bool m_useDigits = true, bool m_useLower = true,
    bool m_useUpper = false, bool m_useSpecial = false,
    int m_maxLength = 3);

  // Основная функция для подбора пароля
  std::string findPassword(const std::string& target);

  // Установка пользовательского набора символов
  void setCustomChars(const std::string& chars);

private:
  std::vector<char> chars;  // Символы для перебора
  int m_maxLength;            // Максимальная длина пароля

  // Рекурсивная функция для генерации комбинаций
  bool generateCombinations(const std::string& target, std::string& current, int length);
};

// Задание 2

class PalindromeChecker {
public:
  // Конструктор
  PalindromeChecker();

  // Метод для ввода данных от пользователя
  void inputData();

  // Метод для проверки на палиндром
  bool isPalindrome() const;

  // Метод для вывода результата
  void printResult() const;

private:
  std::vector<std::string> elements;  // Хранение введенных элементов
  const int MAX_SIZE = 17;           // Максимальное количество элементов

  // Вспомогательный метод для очистки строки (приведение к одному регистру и удаление пробелов)
  std::string cleanString(const std::string& s) const;
};


// Задание 5

class Projection2D; // Предварительное объявление для дружественной функции

class Brick {
private:
  double length;  // Длина кирпича (мм)
  double width;   // Ширина кирпича (мм)
  double height;  // Высота кирпича (мм)

public:
  // Конструктор с параметрами по умолчанию (стандартный кирпич 250x120x65 мм)
  Brick(double l = 250.0, double w = 120.0, double h = 65.0);

  // Геттеры
  double getLength() const;
  double getWidth() const;
  double getHeight() const;

  // Дружественная функция для сравнения с проекцией отверстия
  friend bool canPassThrough(const Brick& brick, const Projection2D& hole);
};


//class Brick; // Предварительное объявление для дружественной функции

class Projection2D {
private:
  double dimension1; // Первый размер отверстия (мм)
  double dimension2; // Второй размер отверстия (мм)

public:
  // Конструктор
  Projection2D(double d1, double d2);

  // Геттеры
  double getDimension1() const;
  double getDimension2() const;

  // Дружественная функция для сравнения с кирпичом
  friend bool canPassThrough(const Brick& brick, const Projection2D& hole);

  // Метод для вывода проекции
  void printProjection() const;
  void draw(double compareWidth = 0, double compareHeight = 0) const;
};




#endif // LAB6_H
