/**************************************************************************************
 * Filename: lab7.h
 * Developer: Perkova Elena
 * Description: Лабораторная 7
 * Исследование в С++ многопоточности, ошибок, отладки блоков кода в IDE Qt Creator
 * ************************************************************************************/

#ifndef LAB7_H
#define LAB7_H

#include <vector>
#include <mutex>
#include <condition_variable>
#include <string>

//Задание 1

class FibonacciCalculation {
public:
  // Вычисляет n-тое число Фибоначчи с использованием многопоточности
  static unsigned long long calculate(int n);

private:
  // Проверяет корректность входного параметра n перед вычислением числа Фибоначчи
  static void validateInput(int n);
  // Функция, выполняемая каждым потоком
  static void compute(int n,
                      std::vector<unsigned long long>& sequence,  // Массив для хранения последовательности
                      std::vector<bool>& ready,                   // Флаги готовности значений
                      std::mutex& mtx,                           // Мьютекс для синхронизации
                      std::vector<std::condition_variable>& cv);  // Условные переменные для ожидания
  };


//Задание 2
class Account {
public:
  Account(int id, double initial_balance);

  // Основной метод перевода между счетами
  static bool transfer(Account& from, Account& to, double amount);

  // Геттеры
  int getId() const;
  double getBalance() const;

private:
  int id;                 // Номер счета
  double balance;         // Текущий баланс
  std::mutex mtx;         // Мьютекс для синхронизации

};

//Задание 3
class LoggerGuard {
public:
  //конструктор принимает сообщение и ссылку на выходной поток, сохраняя их в полях класса
  LoggerGuard(const std::string& message, std::ostream& out = std::cout)
    : message_(message), out_(out) {}
  //Деструктор вызывается при уничтожении объекта и выводит сообщение с добавлением \n
  ~LoggerGuard() {
    out_ << message_ << "\n";
  }

private:
  std::string message_;
  std::ostream& out_;
};


#endif // LAB7_H
