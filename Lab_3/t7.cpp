#include <iostream>
#include "l3_1.h"

//�㭪�� ��� ����祭�� �������� �⠦
std::string getlevellName(Level level){
  switch (level) {
  case Level::PARKING: return "��મ���";
  case Level::GROCERY_STORE: return "�த�⮢� �������";
  case Level::GYM: return "����⧠�";
  case Level::STORES: return "��������";
  case Level::PLAYGROUND: return "��஢�� ���頤��";
  case Level::FOOD_COURT: return "�㤪���";
  case Level::CINEMA: return "����⥠��";
  case Level::ROOF: return "����";
  default: return "��������� �⠦";
  }
}

