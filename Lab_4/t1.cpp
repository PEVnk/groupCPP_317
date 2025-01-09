#include <iostream>
#include <random>
#include "lab4.h"

// Реализация функция для заполнения массива случайными числами
void RandomNumbers(int array[], int len){
  std::random_device rd;
  // Инициализируем Вихрь Мерсенна случайным стартовым числом
  std::mt19937 mersenne(rd());
  for (int i = 0; i < len; ++i){
    array[i] = mersenne(); // Элементу массива присваиваем значение случайного числа
  }
}

// Реализация функции поиска минимального значения массива
int ArrayMin(int array[], int len){
  int MinValue=array[0];
  for (int i = 0; i < len; ++i){
    if (MinValue > array[i])
       MinValue = array[i];
  }
  return MinValue;
}

// Реализация функции поиска максимального значения массива
int ArrayMax(int array[], int len){
  int MaxValue = array[0];
  for (int i = 0; i < len; ++i){
    if (MaxValue < array[i])
       MaxValue = array[i];
  }
  return MaxValue;
}
