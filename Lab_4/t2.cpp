#include <iostream>
#include <cstdlib>
#include <ctime> // для функции time()
#include "lab4.h"

// Задание а
// Реализация функции для создания и вывода единичной матрицы
void IdentityMatrix(){
  constexpr int size = 5; // Задание размера матрицы
  int Matrix[size][size] = {0};// Обнуление элементов массива


  // Заполнение единичной матрицы
  for (int i = 0; i < size; ++i) {
     Matrix[i][i] = 1; // Диагональные элементы равны 1
  }

  // Вывод матрицы в консоль
  std::cout << "Единичная матрица 5x5:" << std::endl;
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        std::cout << Matrix[i][j] << " ";
      }
    std::cout << std::endl; // Переход на новую строку после каждой строки матрицы
    }
}

// Задание b

// Реализация функции для заполнения матрицы псевдослучайными числами
void fillMatrixRandomNum(int matrix[][8], int rows, int cols) {
  // Инициализация генератора случайных чисел
  std::srand(static_cast<unsigned int>(std::time(0)));
  // Заполнение матрицы случайными числами от -15 до 15
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j){
      matrix[i][j] = std::rand() % 31 - 15; // Генерация числа в диапазоне [-15, 15]
    }
  }
}

// Реализация функции для вывода матрицы в консоль
void printMatrix(const int matrix[][8], int rows, int cols) {
  std::cout << "Матрица 8x8:" << std::endl;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cout << matrix[i][j] << "\t"; // Вывод элемента с табуляцией
    }
      std::cout << std::endl; // Переход на новую строку после каждой строки матрицы
  }
}

// Реализация функции для вычисления суммы элементов выше главной диагонали
int AddArrayElements(const int matrix[][8], int rows, int cols){
  int sum = 0;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        // Если элемент находится выше главной диагонали (j > i), добавляем его к сумме
        if (j > i){
          sum += matrix[i][j];
        }
      }
    }
return sum;
}
