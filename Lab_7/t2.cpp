/**************************************************************************************
 * Filename: t2.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 7
 * ��᫥������� �++ ����ᮢ � IDE Qt Creator
 * ***********************************************************************************/

#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include "lab7.h"

Account::Account(int id, double initial_balance)
  : id(id), balance(initial_balance) {}

bool Account::transfer(Account& from, Account& to, double amount) {
  // ������㥬 ��� ��� �⮬�୮, ������� deadlock
  std::unique_lock<std::mutex> lock1(from.mtx, std::defer_lock);
  std::unique_lock<std::mutex> lock2(to.mtx, std::defer_lock);
  std::lock(lock1, lock2);  // �⮬�ୠ� �����஢�� ���� ���⥪ᮢ

  // �஢��塞 �����筮 �� �।�� �� ��室��� ���
  if (from.balance < amount) {
    return false;
  }

  // ������� ��ࠡ�⪨ ��ॢ���
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  // �믮��塞 ��ॢ��
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


