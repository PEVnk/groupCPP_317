/**************************************************************************************
 * Filename: lab7.h
 * Developer: Perkova Elena
 * Description: ������ୠ� 7
 * ��᫥������� � �++ ��������筮��, �訡��, �⫠��� ������ ���� � IDE Qt Creator
 * ************************************************************************************/

#ifndef LAB7_H
#define LAB7_H

#include <vector>
#include <mutex>
#include <condition_variable>
#include <string>

//������� 1

class FibonacciCalculation {
public:
  // ������ n-⮥ �᫮ �������� � �ᯮ�짮������ ��������筮��
  static unsigned long long calculate(int n);

private:
  // �஢���� ���४⭮��� �室���� ��ࠬ��� n ��। ���᫥���� �᫠ ��������
  static void validateInput(int n);
  // �㭪��, �믮��塞�� ����� ��⮪��
  static void compute(int n,
                      std::vector<unsigned long long>& sequence,  // ���ᨢ ��� �࠭���� ��᫥����⥫쭮��
                      std::vector<bool>& ready,                   // ����� ��⮢���� ���祭��
                      std::mutex& mtx,                           // ���⥪� ��� ᨭ�஭���樨
                      std::vector<std::condition_variable>& cv);  // �᫮��� ��६���� ��� ��������
  };


//������� 2
class Account {
public:
  Account(int id, double initial_balance);

  // �᭮���� ��⮤ ��ॢ��� ����� ��⠬�
  static bool transfer(Account& from, Account& to, double amount);

  // ������
  int getId() const;
  double getBalance() const;

private:
  int id;                 // ����� ���
  double balance;         // ����騩 ������
  std::mutex mtx;         // ���⥪� ��� ᨭ�஭���樨

};

//������� 3
class LoggerGuard {
public:
  //��������� �ਭ����� ᮮ�饭�� � ��뫪� �� ��室��� ��⮪, ��࠭�� �� � ����� �����
  LoggerGuard(const std::string& message, std::ostream& out = std::cout)
    : message_(message), out_(out) {}
  //�������� ��뢠���� �� 㭨�⮦���� ��ꥪ� � �뢮��� ᮮ�饭�� � ����������� \n
  ~LoggerGuard() {
    out_ << message_ << "\n";
  }

private:
  std::string message_;
  std::ostream& out_;
};


#endif // LAB7_H
