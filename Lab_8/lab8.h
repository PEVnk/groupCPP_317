/**************************************************************************************
 * Filename: lab8.h
 * Developer: Perkova Elena
 * Description: Лабораторная 8
 * Исследование в С++ стандартной библиотеки шаблонов (STL), перегрузка операторов
 * ************************************************************************************/

#ifndef LAB_8_H
#define LAB_8_H


#include <vector>  // Для использования std::vector
#include <list>  // Для использования std::list
#include <string>
#include <mutex>
#include <thread>
#include <stdexcept>
#include <atomic>

//Задание 1

//Генерирует N случайных чисел и возвращает их в векторе
std::vector<int> generateRandomNumbers(int N);

// Выводит содержимое контейнера по 10 элементов в строке
void printContainer(const std::vector<int>& container);

//Выводит содержимое контейнера в обратном порядке
void printContainerReverse(const std::vector<int>& container);

// Подсчитывает количество уникальных чисел в контейнере
int countUniqueNumbers(const std::vector<int>& container);


//Задание 2
//===== Задача a)=====
std::vector<int> replaceEvenWithListOdd(std::vector<int>& vec, std::list<int>& lst);
void printVector(const std::vector<int>& vec);
void printList(const std::list<int>& lst);

//===== Задача b)=====
void addAverageToList(std::list<double>& lst);

//===== Задача c)=====
void processFavoriteColors();
void printColors(const std::vector<std::pair<int, std::string>>& colors);

//Задание 3

class DataSizeConverter {
public:
  // Конструктор
  DataSizeConverter(double value, const std::string& unit);


  // Основная функция конвертации
  void convert();

  // Вывод результатов
  void printResults() const;

private:
  double inputValue;           // Входное значение
  std::string inputUnit;       // Входная единица измерения
  std::vector<double> results; // Результаты конвертации

  // Вспомогательные методы
  void convertFromBit();
  void convertFromByte();
  void convertFromKbyte();
  void convertFromMbyte();
  void convertFromGbyte();
  void convertFromMiB();

  // Проверка входных данных
  bool isValidUnit() const;
};

//Задание 4
class TreeNode {
private:
  int value;
  TreeNode* parent = nullptr;
  std::vector<TreeNode*> children;

public:
  explicit TreeNode(int val); //конструктор explicit для предотвращения неявных преобразований
  ~TreeNode(); //Добавляем деструктор ~TreeNode(), который рекурсивно удаляет все дочерние узлы

  // Запрещаем копирование и присваивание
  TreeNode(const TreeNode&) = delete;
  TreeNode& operator=(const TreeNode&) = delete;

  TreeNode* AddChild(int child_value);
  void Print(int depth = 0) const;
};

//Задание 5

template <typename T>
class CircularBuffer {
public:
  //Явный конструктор с выделением памяти
  explicit CircularBuffer(size_t size);
  //Деструктор
  ~CircularBuffer();

  // Запрещаем копирование
  CircularBuffer(const CircularBuffer&) = delete;
  CircularBuffer& operator=(const CircularBuffer&) = delete;

  //Чтение элемента по индексу
  T operator[](size_t index) const;

  // Основные операции
  void add(const T& value);
  void next();

  // Методы вывода
  void printAll() const;
  void printRange(size_t index1, size_t index2) const;

  // Потоковая запись
  void startWriterThread();
  void stopWriterThread();
  bool isRunning() const;

private:
  T* buffer;                  // Указатель на буфер
  size_t capacity;            // Емкость буфера
  size_t head = 0;            // Индекс головы (запись)
  size_t tail = 0;            // Индекс хвоста (чтение)
  mutable std::mutex mtx;     // Мьютекс для потокобезопасности
  std::atomic<bool> running;  // Флаг работы потока

  //Потоковая функция записи
  void writerThreadFunc();

};

#endif // LAB_8_H
