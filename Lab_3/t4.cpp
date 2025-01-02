#include <iostream>
#include "l3_1.h"

//функция для вывода названия животного
void getAnimalName(Animals animal){
  switch (animal) {
  case Animals::PIG:
    std::cout << "Pig";
  break;
  case Animals::CHICKEN:
    std::cout << "Chicken";
    break;
  case Animals::GOAT:
    std::cout << "Goat";
    break;
  case Animals::CAT:
    std::cout << "Cat";
    break;
  case Animals::DOG:
    std::cout << "Dog";
    break;
  default:
    std::cout << "Unknown"; // Если ничего не совпало
    break;
    }
}

//функция для вывода количества лап животного
void printNumberOfLegs(Animals animal){
  switch (animal) {
  case Animals::PIG:
  case Animals::GOAT:
  case Animals::CAT:
  case Animals::DOG:
    std::cout << "4 legs";
    break;
  case Animals::CHICKEN:
    std::cout << "2 legs";
    break;
  default:
    std::cout << "Unknown"; // Если ничего не совпало
    break;
    }
}
