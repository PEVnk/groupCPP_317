/**************************************************************************************
 * Filename: t5.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 6
 * ��᫥������� �++ ����ᮢ � IDE Qt Creator
 * ������� 5
 * ************************************************************************************/

#include <iostream>
#include <algorithm> // ��� std::min � std::max
#include <cmath>
#include "lab6.h"

// ���������
Brick::Brick(double l, double w, double h) : length(l), width(w), height(h) {}

// ������
double Brick::getLength() const { return length; }
double Brick::getWidth() const { return width; }
double Brick::getHeight() const { return height; }


// ���������
Projection2D::Projection2D(double d1, double d2) : dimension1(d1), dimension2(d2) {}

// ������
double Projection2D::getDimension1() const { return dimension1; }
double Projection2D::getDimension2() const { return dimension2; }

// �뢮� �஥�樨
void Projection2D::printProjection() const {
    std::cout << "�஥��� �⢥����: " << dimension1 << " �� x " << dimension2 << " ��" << std::endl;
}


// ��㦥�⢥���� �㭪�� ��� �஢�ન ��宦����� ��௨�
bool canPassThrough(const Brick& brick, const Projection2D& hole) {
  // ����砥� �� �������� �������樨 ��஭ ��௨�
  double brickCombinations[3][2] = {
    {brick.getLength(), brick.getWidth()},
    {brick.getLength(), brick.getHeight()},
    {brick.getWidth(), brick.getHeight()}
  };

  // ������� �⢥����
  double holeD1 = hole.getDimension1();
  double holeD2 = hole.getDimension2();

  // �஢��塞 �� �������� �ਥ��樨 ��௨�
  for (int i = 0; i < 3; ++i) {
    // ��室�� ���������� � ���ᨬ����� ��஭� ��� ⥪�饩 �ਥ��樨 ��௨�
    double brickMin = std::min(brickCombinations[i][0], brickCombinations[i][1]);
    double brickMax = std::max(brickCombinations[i][0], brickCombinations[i][1]);

    // ��室�� ���������� � ���ᨬ����� ��஭� �⢥����
    double holeMin = std::min(holeD1, holeD2);
    double holeMax = std::max(holeD1, holeD2);

    // �᫨ ��௨� ��室�� �� ����� ����७��
    if (brickMin <= holeMin && brickMax <= holeMax) {
      return true;
    }
  }
  return false;
}

void Projection2D::draw(double compareWidth, double compareHeight) const {
  const int displayWidth = 50;  // ��ਭ� ������ �⮡ࠦ����
  const int displayHeight = 20; // ���� ������ �⮡ࠦ����

  // ��室�� ���ᨬ���� ࠧ���� ��� ����⠡�஢����
  double maxWidth = std::max(dimension1, compareWidth);
  double maxHeight = std::max(dimension2, compareHeight);

  // ����塞 �����樥��� ����⠡�஢����
  double widthScale = displayWidth / maxWidth;
  double heightScale = displayHeight / maxHeight;

  // �ᯮ��㥬 ��������� ����⠡ �� ����� ���
  double uniformScale = std::min(widthScale, heightScale);

  // ����⠡��㥬 ࠧ����
  int holeW = static_cast<int>(dimension1 * uniformScale);
  int holeH = static_cast<int>(dimension2 * uniformScale);
  int brickW = static_cast<int>(compareWidth * uniformScale);
  int brickH = static_cast<int>(compareHeight * uniformScale);

  // ���㥬 �⢥��⨥
  std::cout << "\n�⢥��⨥(" << dimension1 << " x " << dimension2 << " ��):\n";
  for (int y = 0; y <= holeH; ++y) {
    for (int x = 0; x <= holeW; ++x) {
      if (y == 0 || y == holeH || x == 0 || x == holeW) {
        std::cout << "*"; // �࠭��
        } else {
          std::cout << " "; // �⢥��⨥
        }
      }
      std::cout << std::endl;
    }
  // ���㥬 �ࠢ�������� �஥��� ��௨� (�᫨ ������)
  if (compareWidth > 0 && compareHeight > 0) {
    std::cout << "\n�஥��� ��௨�(" << compareWidth << " x " << compareHeight << " ��):\n";
    for (int y = 0; y <= brickH; ++y) {
      for (int x = 0; x <= brickW; ++x) {
        if (y == 0 || y == brickH || x == 0 || x == brickW) {
          std::cout << "*"; // �࠭��
        } else {
          std::cout << " "; // ��௨�
        }
      }
    std::cout << std::endl;
    }
  }
  // ������塞 ࠧ����⥫�
  std::cout << "\n" << std::string(std::max(holeW, brickW) + 1, '-') << "\n";
}


