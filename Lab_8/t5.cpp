/**************************************************************************************
 * Filename: t5.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 8
 * Исследование в С++ стандартной библиотеки шаблонов (STL), перегрузка операторов
 * ***********************************************************************************/

#include <iostream>
#include "lab8.h"
#include <chrono>

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t size) : capacity(size) {
  // Попытка выделить память с проверкой на успешность
  buffer = new (std::nothrow) T[size];
  if (!buffer) {
    throw std::bad_alloc(); // Генерируем исключение при ошибке
  }
}

template <typename T>
CircularBuffer<T>::~CircularBuffer() {
  stopWriterThread(); // Остановка потока записи
  delete[] buffer; // Освобождение памяти буфера
}

template <typename T>
T CircularBuffer<T>::operator[](size_t index) const {
    std::lock_guard<std::mutex> lock(mtx);
    if (index >= capacity) {
      throw std::out_of_range("Index out of range");
    }
    // Доступ с учетом кольцевой структуры (через tail)
    return buffer[(tail + index) % capacity];
}

template <typename T>
void CircularBuffer<T>::add(const T& value) {
  std::lock_guard<std::mutex> lock(mtx); // Захват мьютекса
  buffer[head] = value;                 // Запись значения
  head = (head + 1) % capacity;     // Обновление головы
  // Если буфер переполнен, двигаем хвост
  if (head == tail) {
    tail = (tail + 1) % capacity;
  }
}

template <typename T>
void CircularBuffer<T>::next() {
  std::lock_guard<std::mutex> lock(mtx);
  tail = (tail + 1) % capacity; // Обновление хвоста
}

template <typename T>
void CircularBuffer<T>::printAll() const {
  std::lock_guard<std::mutex> lock(mtx);
  for (size_t i = 0; i < capacity; ++i) {
    std::cout << buffer[i] << " "; // Вывод каждого элемента
  }
  std::cout << std::endl;
}

//Вывод элементов в заданном диапазоне
template <typename T>
void CircularBuffer<T>::printRange(size_t index1, size_t index2) const {
  std::lock_guard<std::mutex> lock(mtx);
  if (index1 >= capacity || index2 >= capacity) {
    throw std::out_of_range("Index out of range");
  }


  // Вывод с учетом кольцевой структуры
  for (size_t i = index1; i <= index2; ++i) {
    std::cout << buffer[i % capacity] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
bool CircularBuffer<T>::isRunning() const {
  return running.load();
}


template <typename T>
void CircularBuffer<T>::writerThreadFunc() {
  T value = 0;
  while (running) {
    // Проверка нажатия 'q' для выхода
    char input;
    if (std::cin.peek() == 'q') {
      running = false;
      break;
    }

    // Чтение ввода
    std::cin >> input;
    if (input == 'q') {
      running = false;
      break;
    }
    this->add(value++);
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
  }
}

template <typename T>
void CircularBuffer<T>::startWriterThread() {
  running = true; // Установка флага работы
  std::thread(&CircularBuffer<T>::writerThreadFunc, this).detach();
}

// Остановка потока записи
template <typename T>
void CircularBuffer<T>::stopWriterThread() {
    running = false; // Сброс флага работы
}

// Явная инстанциация шаблона для нужных типов
template class CircularBuffer<int>;
