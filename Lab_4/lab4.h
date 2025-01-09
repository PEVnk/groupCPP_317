#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <random>
#include <functional> // Для std::function
#include <cstdint> // Для uint8_t

// Задание 1
// Функция для заполнения массива случайными числами
void RandomNumbers(int array[], int len);

// Функция поиска минимального значения
int ArrayMin(int array[], int len);

// Функция поиска максимального значения
int ArrayMax(int array[], int len);

// Задание 2
// Функция создания единичной матрицы
void IdentityMatrix();

// Функция для заполнения матрицы псевдослучайными числами
void fillMatrixRandomNum(int matrix[][8], int rows, int cols);

// Функция для вывода матрицы в консоль
void printMatrix(const int matrix[][8], int rows, int cols);

// Функция вычисления суммы элементов массива выше главной диагонали
int AddArrayElements(const int matrix[][8], int rows, int cols);

// Задание 3
// Функция вывода букв с десятичными кодами
void PrintCodeAlphabet();

// Задание 4

// Функция проверки введенного числа
bool CheckNumber(int Num);

// Функция нахождения факториала с помощью итераций
double FindFactorialIteration(int Num);

// Функция нахождения факториала с помощью рекурсии
double FindFactorialRecursion(int Num);

// Функция поиска чисел Фибоначчи с помощью итераций
int fib(int UserNum);

// Функция вывода пирамиды чисел
void PrintPiramid(int UserNumber);

// Задание 5

// Функции для типа int
// Функция заполнения массива случайными числами
void FillRandomArray(int arr[], int UserSize);
// Функция сортировки массива
void SortSelect(int arr[], int UserSize);
// Функция для вывода массива
void PrintRandomArray(int arr[], int UserSize);

// Функции для типа char
// Функция заполнения массива случайными значениями
void FillRandomArray(char arr[], int UserSize);
// Функция сортировки массива
void SortSelect(char arr[], int UserSize);
// Функция для вывода массива
void PrintRandomArray(char arr[], int UserSize);

// Функции для типа short
// Функция заполнения массива случайными значениями
void FillRandomArray(short arr[], int UserSize);
// Функция сортировки массива
void SortSelect(short arr[], int UserSize);
// Функция для вывода массива
void PrintRandomArray(short arr[], int UserSize);

// Функции для типа float
// Функция заполнения массива случайными значениями
void FillRandomArray(float arr[], int UserSize);
// Функция сортировки массива
void SortSelect(float arr[], int UserSize);
// Функция для вывода массива
void PrintRandomArray(float arr[], int UserSize);

// Функции для типа double
// Функция заполнения массива случайными значениями
void FillRandomArray(double arr[], int UserSize);
// Функция сортировки массива
void SortSelect(double arr[], int UserSize);
// Функция для вывода массива
void PrintRandomArray(double arr[], int UserSize);

// Задание 6
// Функция оператора адреса
void ReceiveAdress(int m, float x, char t);

// Функция получения значения по адресу
void ReceiveValueAdress(int m, float x, char t);

// Функция получения адреса по переменной указателя
void ReceiveAdressVarPointer(int m, float x, char t);

// Функция получения значения по оператору указателя
void ReceiveAdressOperPointer(int m, float x, char t);

// Ограничим максимальный размер массива
const int MAX_SIZE = 100;

// Функция для заполнения массива
void FillArrayB(int* ptr, int n);

// Функция для печати массива
void PrintArrayB(const int* ptr, int n);

// Задание 7
// Функция перестановок
void PermutationOptions(char arr[], int start, int end, int& count);

// Задание 8
// Объявления логических операций
int logicalAND(int a, int b);
int logicalOR(int a, int b);
int logicalXOR(int a, int b);

// Тип для callback-функции
using CallbackType = int(*)(int, int);

// Функция для вычисления результата
int ResultFunction(int a, int b, CallbackType callback);

// Задание 9
// Функция обмена значений четных и нечетных ячеек
void OddEven(char* arr, int size);




#endif // LAB4_H
