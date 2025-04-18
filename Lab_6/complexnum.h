/**************************************************************************************
 * Filename: complexnum.h
 * Developer: Perkova Elena
 * Description: Лабораторная 6 задание 4
 * Исследование С++ классов в IDE Qt Creator
 * ************************************************************************************/


#ifndef COMPLEXNUM_H
#define COMPLEXNUM_H


#include <cmath>
#include <vector>
#include <string>

// Формы представления комплексного числа
enum class ComplexForm {
  ALGEBRAIC,      // Алгебраическая форма: a + bi
  TRIGONOMETRIC,   // Тригонометрическая форма: r(cos? + isin?)
  EXPONENTIAL      // Экспоненциальная форма: re^(i?)
};

class ComplexNumber {
private:
  double real;        // Действительная часть (a)
  double imaginary;   // Мнимая часть (b)
  double magnitude;    // Модуль (r)
  double angle;       // Аргумент (?) в радианах

  ComplexForm currentForm; // Текущая форма представления

  // Обновление тригонометрических параметров
  void updatePolar();
  // Обновление алгебраических параметров
  void updateAlgebraic();

public:
  // Конструкторы
  ComplexNumber(double re = 0.0, double im = 0.0); // Алгебраическая форма
  ComplexNumber(double mag, double ang, ComplexForm form); // Полярная форма

  // Методы доступа
  double getReal() const;
  double getImaginary() const;
  double getMagnitude() const;
  double getAngle() const;

  // Установка формы представления
  void setForm(ComplexForm form);
  ComplexForm getForm() const;

  // Основные операции
  ComplexNumber conjugate() const; // Сопряжение
  ComplexNumber operator+(const ComplexNumber& other) const; // Сложение
  ComplexNumber operator-(const ComplexNumber& other) const; // Вычитание
  ComplexNumber operator*(const ComplexNumber& other) const; // Умножение
  ComplexNumber operator/(const ComplexNumber& other) const; // Деление

  // Возведение в степень и извлечение корня
  ComplexNumber pow(int n) const; // Целая степень
  std::vector<ComplexNumber> root(int n) const; // Корень n-й степени

  // Вывод числа в строку
  std::string toString() const;
};


#endif // COMPLEXNUM_H
