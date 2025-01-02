#include <iostream>
#include "l3_1.h"

//функция для получения названия этаж
std::string getlevellName(Level level){
  switch (level) {
  case Level::PARKING: return "Парковка";
  case Level::GROCERY_STORE: return "Продуктовый магазин";
  case Level::GYM: return "Спортзал";
  case Level::STORES: return "Магазины";
  case Level::PLAYGROUND: return "Игровая площадка";
  case Level::FOOD_COURT: return "Фудкорт";
  case Level::CINEMA: return "Кинотеатр";
  case Level::ROOF: return "Крыша";
  default: return "Неизвестный этаж";
  }
}

