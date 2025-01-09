#include <iostream>
#include "lab4.h"

// Функция для обмена двух символов
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

// Функция перестановок
void PermutationOptions(char arr[], int start, int end, int& count){
  if (start == end){
    // Если достигнут конец массива, выводим текущую перестановку
    for (int i = 0; i <= end; ++i) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    count++;
  } else {
    // Рекурсия для перестановок
    for (int i = start; i <= end; ++i) {
      swap(arr[start], arr[i]); // Меняем местами текущий элемент с начальным
      PermutationOptions(arr, start+1, end, count); // Для следующего элемента
      swap(arr[start], arr[i]); // Возвращаем массив в исходное состояние
    }
  }
}
