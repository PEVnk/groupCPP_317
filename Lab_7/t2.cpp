/**************************************************************************************
 * Filename: t2.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 7
 * Исследование С++ классов в IDE Qt Creator
 * ***********************************************************************************/

#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include "lab7.h"

Account::Account(int id, double initial_balance)
  : id(id), balance(initial_balance) {}

bool Account::transfer(Account& from, Account& to, double amount) {
  // Блокируем оба счета атомарно, избегая deadlock
  std::unique_lock<std::mutex> lock1(from.mtx, std::defer_lock);
  std::unique_lock<std::mutex> lock2(to.mtx, std::defer_lock);
  std::lock(lock1, lock2);  // Атомарная блокировка двух мьютексов

  // Проверяем достаточно ли средств на исходном счете
  if (from.balance < amount) {
    return false;
  }

  // Симуляция обработки перевода
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  // Выполняем перевод
  from.balance -= amount;
  to.balance += amount;

  return true;
}

int Account::getId() const {
  return id;
}

double Account::getBalance() const {
  return balance;
}


