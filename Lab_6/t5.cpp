/**************************************************************************************
 * Filename: t5.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 6
 * Исследование С++ классов в IDE Qt Creator
 * Задание 5
 * ************************************************************************************/

#include <iostream>
#include <algorithm> // для std::min и std::max
#include <cmath>
#include "lab6.h"

// Конструктор
Brick::Brick(double l, double w, double h) : length(l), width(w), height(h) {}

// Геттеры
double Brick::getLength() const { return length; }
double Brick::getWidth() const { return width; }
double Brick::getHeight() const { return height; }


// Конструктор
Projection2D::Projection2D(double d1, double d2) : dimension1(d1), dimension2(d2) {}

// Геттеры
double Projection2D::getDimension1() const { return dimension1; }
double Projection2D::getDimension2() const { return dimension2; }

// Вывод проекции
void Projection2D::printProjection() const {
    std::cout << "Проекция отверстия: " << dimension1 << " мм x " << dimension2 << " мм" << std::endl;
}


// Дружественная функция для проверки прохождения кирпича
bool canPassThrough(const Brick& brick, const Projection2D& hole) {
  // Получаем все возможные комбинации сторон кирпича
  double brickCombinations[3][2] = {
    {brick.getLength(), brick.getWidth()},
    {brick.getLength(), brick.getHeight()},
    {brick.getWidth(), brick.getHeight()}
  };

  // Размеры отверстия
  double holeD1 = hole.getDimension1();
  double holeD2 = hole.getDimension2();

  // Проверяем все возможные ориентации кирпича
  for (int i = 0; i < 3; ++i) {
    // Находим минимальную и максимальную сторону для текущей ориентации кирпича
    double brickMin = std::min(brickCombinations[i][0], brickCombinations[i][1]);
    double brickMax = std::max(brickCombinations[i][0], brickCombinations[i][1]);

    // Находим минимальную и максимальную сторону отверстия
    double holeMin = std::min(holeD1, holeD2);
    double holeMax = std::max(holeD1, holeD2);

    // Если кирпич проходит по обоим измерениям
    if (brickMin <= holeMin && brickMax <= holeMax) {
      return true;
    }
  }
  return false;
}

void Projection2D::draw(double compareWidth, double compareHeight) const {
  const int displayWidth = 50;  // Ширина области отображения
  const int displayHeight = 20; // Высота области отображения

  // Находим максимальные размеры для масштабирования
  double maxWidth = std::max(dimension1, compareWidth);
  double maxHeight = std::max(dimension2, compareHeight);

  // Вычисляем коэффициенты масштабирования
  double widthScale = displayWidth / maxWidth;
  double heightScale = displayHeight / maxHeight;

  // Используем одинаковый масштаб по обеим осям
  double uniformScale = std::min(widthScale, heightScale);

  // Масштабируем размеры
  int holeW = static_cast<int>(dimension1 * uniformScale);
  int holeH = static_cast<int>(dimension2 * uniformScale);
  int brickW = static_cast<int>(compareWidth * uniformScale);
  int brickH = static_cast<int>(compareHeight * uniformScale);

  // Рисуем отверстие
  std::cout << "\nОтверстие(" << dimension1 << " x " << dimension2 << " мм):\n";
  for (int y = 0; y <= holeH; ++y) {
    for (int x = 0; x <= holeW; ++x) {
      if (y == 0 || y == holeH || x == 0 || x == holeW) {
        std::cout << "*"; // Граница
        } else {
          std::cout << " "; // Отверстие
        }
      }
      std::cout << std::endl;
    }
  // Рисуем сравниваемую проекцию кирпича (если задана)
  if (compareWidth > 0 && compareHeight > 0) {
    std::cout << "\nПроекция кирпича(" << compareWidth << " x " << compareHeight << " мм):\n";
    for (int y = 0; y <= brickH; ++y) {
      for (int x = 0; x <= brickW; ++x) {
        if (y == 0 || y == brickH || x == 0 || x == brickW) {
          std::cout << "*"; // Граница
        } else {
          std::cout << " "; // Кирпич
        }
      }
    std::cout << std::endl;
    }
  }
  // Добавляем разделитель
  std::cout << "\n" << std::string(std::max(holeW, brickW) + 1, '-') << "\n";
}


