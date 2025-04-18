/**************************************************************************************
 * Filename: complexnum.h
 * Developer: Perkova Elena
 * Description: ������ୠ� 6 ������� 4
 * ��᫥������� �++ ����ᮢ � IDE Qt Creator
 * ************************************************************************************/


#ifndef COMPLEXNUM_H
#define COMPLEXNUM_H


#include <cmath>
#include <vector>
#include <string>

// ���� �।�⠢����� �������᭮�� �᫠
enum class ComplexForm {
  ALGEBRAIC,      // �����ࠨ�᪠� �ଠ: a + bi
  TRIGONOMETRIC,   // �ਣ��������᪠� �ଠ: r(cos? + isin?)
  EXPONENTIAL      // ��ᯮ���樠�쭠� �ଠ: re^(i?)
};

class ComplexNumber {
private:
  double real;        // ����⢨⥫쭠� ���� (a)
  double imaginary;   // ������ ���� (b)
  double magnitude;    // ����� (r)
  double angle;       // ��㬥�� (?) � ࠤ�����

  ComplexForm currentForm; // ������ �ଠ �।�⠢�����

  // ���������� �ਣ��������᪨� ��ࠬ��஢
  void updatePolar();
  // ���������� �����ࠨ�᪨� ��ࠬ��஢
  void updateAlgebraic();

public:
  // ����������
  ComplexNumber(double re = 0.0, double im = 0.0); // �����ࠨ�᪠� �ଠ
  ComplexNumber(double mag, double ang, ComplexForm form); // ����ୠ� �ଠ

  // ��⮤� ����㯠
  double getReal() const;
  double getImaginary() const;
  double getMagnitude() const;
  double getAngle() const;

  // ��⠭���� ��� �।�⠢�����
  void setForm(ComplexForm form);
  ComplexForm getForm() const;

  // �᭮��� ����樨
  ComplexNumber conjugate() const; // ����殮���
  ComplexNumber operator+(const ComplexNumber& other) const; // ��������
  ComplexNumber operator-(const ComplexNumber& other) const; // ���⠭��
  ComplexNumber operator*(const ComplexNumber& other) const; // ���������
  ComplexNumber operator/(const ComplexNumber& other) const; // �������

  // ���������� � �⥯��� � �����祭�� ����
  ComplexNumber pow(int n) const; // ����� �⥯���
  std::vector<ComplexNumber> root(int n) const; // ��७� n-� �⥯���

  // �뢮� �᫠ � ��ப�
  std::string toString() const;
};


#endif // COMPLEXNUM_H
