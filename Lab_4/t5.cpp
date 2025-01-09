#include <iostream>
#include <cstdlib>  // Для rand() и srand()
#include <ctime>    // Для time()
#include <algorithm> // для std::swap
#include "lab4.h"


// Реализация для int
// Реализация функции заполнения массива случайными значениями
void FillRandomArray(int arr[], int UserSize) {
  for (int i = 0; i < UserSize; i++) {
    arr[i] = rand() % 100; // Генерация случайных чисел от 0 до 99
  }
}

// Реализация функции сортировки методом выбора
void SortSelect(int arr[], int UserSize){
  // Перебираем каждый элемент массива (кроме последнего)
  for (int startIndex = 0; startIndex < UserSize - 1; ++startIndex) {
  /* В переменной smallestIndex хранится индекс наименьшего значения,
  * которое мы нашли в этой итерации.
  * Наименьший элемент в этой итерации - это первый элемент (индекс 0)*/
  int smallestIndex = startIndex;
  // Затем ищем элемент поменьше в остальной части массива
  for (int currentIndex = startIndex + 1; currentIndex < UserSize; ++currentIndex) {
  // Если мы нашли элемент, который меньше нашего наименьшего элемента,
    if (arr[currentIndex] < arr[smallestIndex])
    // то запоминаем его
    smallestIndex = currentIndex;
  }
    // smallestIndex теперь наименьший элемент.
    // Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
  std::swap(arr[startIndex], arr[smallestIndex]);
  }
}

// Реализация функции вывода массива
void PrintRandomArray(int arr[], int UserSize) {
    for (int i = 0; i < UserSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Реализация для short
// Реализация функции заполнения массива случайными значениями
void FillRandomArray(short arr[], int UserSize) {
  for (int i = 0; i < UserSize; i++) {
    arr[i] = static_cast<short>(rand()) % 1000; // Генерация случайных short
  }
}

// Реализация функции сортировки методом выбора
void SortSelect(short arr[], int UserSize){
  // Перебираем каждый элемент массива (кроме последнего)
  for (int startIndex = 0; startIndex < UserSize - 1; ++startIndex) {
  /* В переменной smallestIndex хранится индекс наименьшего значения,
  * которое мы нашли в этой итерации.
  * Наименьший элемент в этой итерации - это первый элемент (индекс 0)*/
  int smallestIndex = startIndex;
  // Затем ищем элемент поменьше в остальной части массива
  for (int currentIndex = startIndex + 1; currentIndex < UserSize; ++currentIndex) {
  // Если мы нашли элемент, который меньше нашего наименьшего элемента,
    if (arr[currentIndex] < arr[smallestIndex])
    // то запоминаем его
    smallestIndex = currentIndex;
  }
    // smallestIndex теперь наименьший элемент.
    // Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
  std::swap(arr[startIndex], arr[smallestIndex]);
  }
}

// Реализация функции вывода массива
void PrintRandomArray(short arr[], int UserSize) {
    for (int i = 0; i < UserSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Реализация для float
// Реализация функции заполнения массива случайными значениями
void FillRandomArray(float arr[], int UserSize) {
  for (int i = 0; i < UserSize; i++){
    arr[i] = static_cast<float>(rand()) / RAND_MAX * 100.0f; // Генерация случайных float
  }
}

// Реализация функции сортировки методом выбора
void SortSelect(float arr[], int UserSize){
  // Перебираем каждый элемент массива (кроме последнего)
  for (int startIndex = 0; startIndex < UserSize - 1; ++startIndex) {
  /* В переменной smallestIndex хранится индекс наименьшего значения,
  * которое мы нашли в этой итерации.
  * Наименьший элемент в этой итерации - это первый элемент (индекс 0)*/
  int smallestIndex = startIndex;
  // Затем ищем элемент поменьше в остальной части массива
  for (int currentIndex = startIndex + 1; currentIndex < UserSize; ++currentIndex) {
  // Если мы нашли элемент, который меньше нашего наименьшего элемента,
    if (arr[currentIndex] < arr[smallestIndex])
    // то запоминаем его
    smallestIndex = currentIndex;
  }
    // smallestIndex теперь наименьший элемент.
    // Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
  std::swap(arr[startIndex], arr[smallestIndex]);
  }
}

// Реализация функции вывода массива
void PrintRandomArray(float arr[], int UserSize) {
    for (int i = 0; i < UserSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Реализация для double
// Реализация функции заполнения массива случайными значениями
void FillRandomArray(double arr[], int UserSize) {
  for (int i = 0; i < UserSize; i++) {
    arr[i] = static_cast<double>(rand()) / RAND_MAX * 100.0; // Генерация случайных double
  }
}

// Реализация функции сортировки методом выбора
void SortSelect(double arr[], int UserSize){
  // Перебираем каждый элемент массива (кроме последнего)
  for (int startIndex = 0; startIndex < UserSize - 1; ++startIndex) {
  /* В переменной smallestIndex хранится индекс наименьшего значения,
  * которое мы нашли в этой итерации.
  * Наименьший элемент в этой итерации - это первый элемент (индекс 0)*/
  int smallestIndex = startIndex;
  // Затем ищем элемент поменьше в остальной части массива
  for (int currentIndex = startIndex + 1; currentIndex < UserSize; ++currentIndex) {
  // Если мы нашли элемент, который меньше нашего наименьшего элемента,
    if (arr[currentIndex] < arr[smallestIndex])
    // то запоминаем его
    smallestIndex = currentIndex;
  }
    // smallestIndex теперь наименьший элемент.
    // Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
  std::swap(arr[startIndex], arr[smallestIndex]);
  }
}

// Реализация функции вывода массива
void PrintRandomArray(double arr[], int UserSize) {
    for (int i = 0; i < UserSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Реализация для char
// Реализация функции заполнения массива случайными значениями
void FillRandomArray(char arr[], int UserSize) {
  for (int i = 0; i < UserSize; i++) {
    arr[i] = static_cast<char>(rand()) % 128; // Генерация случайных char
  }
}

// Реализация функции сортировки методом выбора
void SortSelect(char arr[], int UserSize){
  // Перебираем каждый элемент массива (кроме последнего)
  for (int startIndex = 0; startIndex < UserSize - 1; ++startIndex) {
  /* В переменной smallestIndex хранится индекс наименьшего значения,
  * которое мы нашли в этой итерации.
  * Наименьший элемент в этой итерации - это первый элемент (индекс 0)*/
  int smallestIndex = startIndex;
  // Затем ищем элемент поменьше в остальной части массива
  for (int currentIndex = startIndex + 1; currentIndex < UserSize; ++currentIndex) {
  // Если мы нашли элемент, который меньше нашего наименьшего элемента,
    if (arr[currentIndex] < arr[smallestIndex])
    // то запоминаем его
    smallestIndex = currentIndex;
  }
    // smallestIndex теперь наименьший элемент.
    // Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
  std::swap(arr[startIndex], arr[smallestIndex]);
  }
}

// Реализация функции вывода массива
void PrintRandomArray(char arr[], int UserSize) {
    for (int i = 0; i < UserSize; i++) {
        std::cout << static_cast<int>(arr[i]) << " "; // Вывод как чисел
    }
    std::cout << std::endl;
}
