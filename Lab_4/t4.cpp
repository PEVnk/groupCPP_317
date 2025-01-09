#include <iostream>
#include "lab4.h"

// Реализация функции для вычисления факториала с помощью итераций
double FindFactorialIteration(int Num){
  double Factorial{1};

  // Вычисляем факториал с помощью цикла for
  for (int i =1; i<= Num; i++){
    Factorial*= i;
  }
  return Factorial;
}

// Реализация функции для проверки введённого числа
bool CheckNumber(int Num){
  // Факториал определён только для неотрицательных чисел больше 0
  return Num >= 0;
}

// Реализация функции для вычисления факториала с помощью рекурсии
double FindFactorialRecursion(int Num){
  if (Num == 1)
    return 1; // базовый случай (условие завершения)
  else
    return FindFactorialRecursion(Num-1)*Num; // рекурсивный вызов функции
}

// Реализация функции поиска чисел Фибоначчи с помощью итераций
int fib(int UserNum) {
  if (UserNum == 0) return 0;
  if (UserNum == 1) return 1;

  int num1 = 0, num2 = 1, num3 = 0;
  for (int i = 2; i < UserNum; i++) {
    num3 = num1 + num2;
    num1 = num2;
    num2 = num3;
  }
    return num2;
}

// Реализация функции вывода пирамиды чисел
void PrintPiramid(int UserNumber){
  int Sum = 0;
  int row = 1;
  // Продолжаем вывод, пока текущая сумма не достигнет целевого числа
  while (true) {
    Sum = 0; // Сбрасываем сумму для новой строки

    // Выводим убывающую последовательность чисел
    for (int i = row; i >= 1; i--) {
      std::cout << i << " ";
      Sum += i; // Считаем сумму чисел в строке
    }

    // Выводим сумму чисел в строке
    std::cout << Sum << std::endl;

    // Проверяем, достигли ли целевого числа
    if (Sum == UserNumber){
      std::cout << "Целевое число достигнуто" << std::endl;
      break; // Завершаем цикл
    } else if (Sum > UserNumber){
      std::cout << "Целевое число не может быть достигнуто в \
                    этой последовательности" << std::endl;

      break; // Завершаем цикл
    }

   // Переходим к следующей строке
    row++;
  }
}
