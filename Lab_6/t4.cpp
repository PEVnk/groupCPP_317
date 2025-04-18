/**************************************************************************************
 * Filename: t4.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 6
 * Исследование С++ классов в IDE Qt Creator
 * Задание 4
 * ************************************************************************************/

#include <iostream>
#include "complexnum.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <complex>


// Конструктор для алгебраической формы
ComplexNumber::ComplexNumber(double re, double im)
  : real(re), imaginary(im), currentForm(ComplexForm::ALGEBRAIC) {
  updatePolar();
}

// Конструктор для полярных форм
ComplexNumber::ComplexNumber(double mag, double ang, ComplexForm form)
  : magnitude(mag), angle(ang), currentForm(form) {
  if (form != ComplexForm::ALGEBRAIC) {
    updateAlgebraic();
  } else {
    // Если передана алгебраическая форма, но вызван этот конструктор
    real = magnitude;
    imaginary = angle;
    updatePolar();
  }
}

// Обновление полярных координат по алгебраическим
void ComplexNumber::updatePolar() {
  magnitude = sqrt(real * real + imaginary * imaginary);
  angle = atan2(imaginary, real);
}

// Обновление алгебраических координат по полярным
void ComplexNumber::updateAlgebraic() {
  real = magnitude * cos(angle);
  imaginary = magnitude * sin(angle);
}

// Геттеры
double ComplexNumber::getReal() const { return real; }
double ComplexNumber::getImaginary() const { return imaginary; }
double ComplexNumber::getMagnitude() const { return magnitude; }
double ComplexNumber::getAngle() const { return angle; }

// Установка формы представления
void ComplexNumber::setForm(ComplexForm form) {
  currentForm = form;
}

ComplexForm ComplexNumber::getForm() const {
  return currentForm;
}

// Сопряженное число
ComplexNumber ComplexNumber::conjugate() const {
  return ComplexNumber(real, -imaginary);
}

// Операция сложения
ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
  return ComplexNumber(real + other.real, imaginary + other.imaginary);
}

// Операция вычитания
ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
  return ComplexNumber(real - other.real, imaginary - other.imaginary);
}

// Операция умножения
ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
  double re = real * other.real - imaginary * other.imaginary;
  double im = real * other.imaginary + imaginary * other.real;
  return ComplexNumber(re, im);
}

// Операция деления
ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
  double denominator = other.real * other.real + other.imaginary * other.imaginary;
  if (denominator == 0) {
    throw std::runtime_error("Division by zero");
  }
  double re = (real * other.real + imaginary * other.imaginary) / denominator;
  double im = (imaginary * other.real - real * other.imaginary) / denominator;
  return ComplexNumber(re, im);
}

// Возведение в целую степень (формула Муавра)
ComplexNumber ComplexNumber::pow(int n) const {
  if (n == 0) {
    return ComplexNumber(1, 0);
  }

  double newMag = std::pow(magnitude, n);
  double newAng = angle * n;

  return ComplexNumber(newMag * cos(newAng), newMag * sin(newAng));
}

// Извлечение корня n-й степени
std::vector<ComplexNumber> ComplexNumber::root(int n) const {
  if (n <= 0) {
    throw std::invalid_argument("Root degree must be positive");
  }

  std::vector<ComplexNumber> roots;
  double rootMag = std::pow(magnitude, 1.0 / n);

  for (int k = 0; k < n; ++k) {
    double rootAng = (angle + 2 * M_PI * k) / n;
    roots.emplace_back(rootMag * cos(rootAng), rootMag * sin(rootAng));
    }

  return roots;
}

// Преобразование в строку согласно текущей форме представления
std::string ComplexNumber::toString() const {
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(3);

  switch (currentForm) {
    case ComplexForm::ALGEBRAIC:
      oss << real;
      if (imaginary >= 0) {
        oss << " + " << imaginary << "i";
      } else {
        oss << " - " << -imaginary << "i";
      }
      break;

      case ComplexForm::TRIGONOMETRIC:
        oss << magnitude << "(cos(" << angle << ") + i*sin(" << angle << "))";
        break;

      case ComplexForm::EXPONENTIAL:
        oss << magnitude << "e^(i*" << angle << ")";
      break;
  }

  return oss.str();
}
