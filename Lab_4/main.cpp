#include <iostream>
#include <random>
#include <ctime>
#include "lab4.h"

#define Unit 4
int main()
{
#if Unit==1
std::cout << "Задание 1" << std::endl; // Вызов функции задания 1 из отдельного файла

constexpr int len = 10; // Длина массива через константную переменную типа compiletime

// Создание массива из целых чисел заданной длины
int array[len];

  // Заполнение массива псевдослучайными числами
RandomNumbers(array, len);

  // Вывод массива на экран
  std::cout << "Массив псевдослучайных чисел: " << std::endl;
  for (int i = 0; i < len; ++i) {
      std::cout << array[i] << " ";
      // Если вывели 5 чисел, то вставляем символ новой строки
      if ((i + 1) % 5 == 0)
        std::cout << "\n";
  }
  std::cout << std::endl;

// Поиск минимального значения в массиве
int MinValue = ArrayMin(array, len);
  std::cout << "Минимальное значение массива: " << MinValue << std::endl;

// Поиск максимального значения в массиве
int MaxValue = ArrayMax(array, len);
  std::cout << "Максимальное значение массива: " << MaxValue << std::endl;


#elif Unit==2
// Создание и вывод единичной матрицы
IdentityMatrix();

std::cout << std::endl;

const int rows = 8; // Количество строк
const int cols = 8; // Количество столбцов
int matrix[rows][cols]; // Создание матрицы 8x8

// Заполнение матрицы случайными числами
fillMatrixRandomNum(matrix, rows, cols);

// Вывод матрицы в консоль
printMatrix(matrix, rows, cols);

// Вычисление суммы элементов выше главной диагонали
int sum = AddArrayElements(matrix, rows, cols);

// Вывод результата
std::cout << "Сумма элементов выше главной диагонали: " << sum << std::endl;


#elif Unit==3
std::cout << "Задание 3" << std::endl; // Вызов функции задания 3 из отдельного файла

// Вывод алфавита с десятичными кодами с таблицы ASCII
PrintCodeAlphabet();

#elif Unit==4
std::cout << "Задание 4" << std::endl; // Вызов функции задания 4 из отдельного файла

//нахождение факториала
std::cout << "А. Нахождение факториала числа" << std::endl;
std::cout << std::endl;

int Num;

// Запрос ввода числа от пользователя
while (true) {
// цикл продолжается до тех пор, пока пользователь не введет корректное значение
  std::cout << "Введите целое неотрицательное число" << std::endl;
  if (std::cin >> Num){
    // Проверка введённого числа
    if (CheckNumber(Num)){
      // Вычисление факториала
      double result = FindFactorialIteration(Num);

      std::cout << "Факторил с помощью итераций: " << result << std::endl;
      std::cout<<"Факторил с помощью рекурсии: " <<FindFactorialRecursion(Num)<< std::endl;
      break; // выход из цикла, если ввод корректный
    }
    else{
    std::cout << "Факториал определён только для неотрицательных целых чисел" << std::endl;
    }
  }
  else{
    // если предыдущее извлечение не выполнилось или произошло переполнение,
    std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
    std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
    std::cout << "Введено некорректное значение. Введите целое число." << std::endl;
  }
}

//число Фибоначчи
std::cout << "B. Нахождение числа Фибоначчи" << std::endl;
std::cout << std::endl;
int UserNum;
// Запрос ввода числа от пользователя
while (true) {
  std::cout << "Введите номер числа Фибоначчи: ";
  if (std::cin >> UserNum){
    // Проверка введённого числа
    if (CheckFibonacciNumber(UserNum)){
      // Вычисление числа Фибоначчи
      int NumFib = fib(UserNum);
      std::cout << "\n Число Фибоначчи с номером " << UserNum << " равно: " << NumFib << std::endl;
      break; // выход из цикла, если ввод корректный
    }
    else{
    std::cout << "Номер должен быть неотрицательным" << std::endl;
    }
  }
  else{
    // если предыдущее извлечение не выполнилось или произошло переполнение,
    std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
    std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
    std::cout << "Введено некорректное значение. Введите целое число." << std::endl;
  }
}

// Вывод числовой пирамиды

int UserNumber;

  // Ввод целевого числа
  std::cout << "Введите целевое число: ";
  std::cin >> UserNumber;

  // Вызов функции для вывода пирамиды
  PrintPiramid(UserNumber);

#elif Unit==5
std::cout << "Задание 5" << std::endl; // Вызов функции задания 5 из отдельного файла

int choice, UserSize;

// Запрос типа данных
std::cout << "Выберите тип данных:\n";
std::cout << "1 - char\n2 - short\n3 - int\n4 - float\n5 - double\n";
std::cin >> choice;

// Запрос количества элементов
std::cout << "Введите количество элементов: ";
std::cin >> UserSize;

// Инициализация генератора случайных чисел
std::srand(std::time(0));

// Обработка выбора типа данных
switch (choice) {
  case 1: { //char
    // Создание массива
    char CharArr[UserSize];
    // Заполнение массива случайными значениями
    FillRandomArray(CharArr, UserSize);
    // Вывод исходного массива
    std::cout << "Исходный массив:\n";
    PrintRandomArray(CharArr, UserSize);
    // Сортировка массива методом выбора
    SortSelect(CharArr, UserSize);
    // Вывод отсортированного массива
    std::cout << "Отсортированный массив:\n";
    PrintRandomArray(CharArr, UserSize);
    break;
  }

  case 2: { //short
    // Создание массива
    short ShortArr[UserSize];
    // Заполнение массива случайными значениями
    FillRandomArray(ShortArr, UserSize);
    // Вывод исходного массива
    std::cout << "Исходный массив:\n";
    PrintRandomArray(ShortArr, UserSize);
    // Сортировка массива методом выбора
    SortSelect(ShortArr, UserSize);
    // Вывод отсортированного массива
    std::cout << "Отсортированный массив:\n";
    PrintRandomArray(ShortArr, UserSize);
    break;
  }
  case 3: { //int
    // Создание массива
    int IntArr[UserSize];
    // Заполнение массива случайными значениями
    FillRandomArray(IntArr, UserSize);
    // Вывод исходного массива
    std::cout << "Исходный массив:\n";
    PrintRandomArray(IntArr, UserSize);
    // Сортировка массива методом выбора
    SortSelect(IntArr, UserSize);
    // Вывод отсортированного массива
    std::cout << "Отсортированный массив:\n";
    PrintRandomArray(IntArr, UserSize);
    break;
  }

  case 4: { //float
    // Создание массива
    float FloatArr[UserSize];
    // Заполнение массива случайными значениями
    FillRandomArray(FloatArr, UserSize);
    // Вывод исходного массива
    std::cout << "Исходный массив:\n";
    PrintRandomArray(FloatArr, UserSize);
    // Сортировка массива методом выбора
    SortSelect(FloatArr, UserSize);
    // Вывод отсортированного массива
    std::cout << "Отсортированный массив:\n";
    PrintRandomArray(FloatArr, UserSize);
    break;
  }

  case 5: { //double
    // Создание массива
    double DoubleArr[UserSize];
    // Заполнение массива случайными значениями
    FillRandomArray(DoubleArr, UserSize);
    // Вывод исходного массива
    std::cout << "Исходный массив:\n";
    PrintRandomArray(DoubleArr, UserSize);
    // Сортировка массива методом выбора
    SortSelect(DoubleArr, UserSize);
    // Вывод отсортированного массива
    std::cout << "Отсортированный массив:\n";
    PrintRandomArray(DoubleArr, UserSize);
    break;
  }
  default:
     std::cout << "Неверный выбор типа данных!\n";
     return 1;
  }



  #elif Unit==6
  std::cout << "Задание 6" << std::endl; // Вызов функции задания 6 из отдельного файла

  int m; float x; char t;

  // Запрос значений
  std::cout << "Введите число int: ";
  std::cin >> m;
  std::cout << "Введите число float: ";
  std::cin >> x;
  std::cout << "Введите значение типа char: ";
  std::cin >> t;

  // Функция оператора адреса
  ReceiveAdress(m, x, t);

  // Функция получения значения по адресу
  ReceiveValueAdress(m, x, t);

  // Функция получения адреса по переменной указателя
  ReceiveAdressVarPointer(m, x, t);

  // Функция получения значения по оператору указателя
  ReceiveAdressOperPointer(m, x, t);

  int n;
  // Запрашиваем у пользователя количество элементов
  std::cout << "Введите количество элементов (не более " << MAX_SIZE << "): ";
  std::cin >> n;

  // Проверяем, чтобы количество элементов не превышало максимальный размер
  if (n > MAX_SIZE) {
  std::cout << "Ошибка: количество элементов превышает максимальный размер массива!\n";
  return 1; // Завершаем программу с ошибкой
  }

  // Создаем массив
  int arr[MAX_SIZE];

  // Указатель на начало массива
  int* ptr = arr;

  // Заполняем массив
  FillArrayB(ptr, n);

  // Печатаем массив
  PrintArrayB(ptr, n);

  #elif Unit==7
  std::cout << "Задание 7" << std::endl; // Вызов функции задания 7 из отдельного файла

  char phases[] = {'U', 'V', 'W', 'N'};
  int n = sizeof(phases) / sizeof(phases[0]); // Количество фаз
  int count = 0;

  std::cout << "Варианты всех перестановок фаз:\n";
  PermutationOptions(phases, 0, n-1, count);

  std::cout << "Количество подключений: " << count << std::endl;

  #elif Unit==8
  std::cout << "Задание 8" << std::endl; // Вызов функции задания 8 из отдельного файла

  int a, b;
  int choice;

  // Запрашиваем у пользователя выбор операции
  std::cout << "Выберите операцию:\n";
  std::cout << "1 - И\n";
  std::cout << "2 - ИЛИ\n";
  std::cout << "3 - XOR\n";
  std::cin >> choice;

  // Запрашиваем два числа
  std::cout << "Введите два целых числа (0-255): ";
  std::cin >> a >> b;

  // Выбираем callback-функцию в зависимости от выбора пользователя
  CallbackType callback = nullptr;

  switch (choice) {
    case 1:
      callback = logicalAND;
      break;
    case 2:
      callback = logicalOR;
      break;
    case 3:
      callback = logicalXOR;
      break;
    default:
      std::cout << "Неверный выбор операции!\n";
      return 1;
  }

  // Вычисляем результат с помощью callback-функции
  int result = ResultFunction(a, b, callback);

  // Выводим результат
  std::cout << "Результат: " << result << std::endl;


  #else
  std::cout << "Задание 9" << std::endl; // Вызов функции задания 9 из отдельного файла

  char arr[12] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};

  std::cout << "Исходный массив до обмена: " <<'\n';
  for (int i = 0; i < 12; ++i){
    std::cout << arr[i] <<" ";
  }
  std::cout << std::endl;

  // Вызов функции
  OddEven(arr, 12);

  std::cout << "Массив после обмена: " <<'\n';
  for (int i = 0; i < 12; ++i){
    std::cout << arr[i] <<" ";
  }
  std::cout << std::endl;


  #endif
  return 0;
}

