#include <iostream>
#include "lab4.h"

// Реализация функции для обмена значениями четных и нечетных ячеек
void OddEven(char* arr, int size){
    //меняем местами значения
    for (int i=0; i < size-1; i+=2){
    char temp = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = temp;
  }
}
