#include <iostream>
#include "l3_1.h"

//�㭪�� ��� �뢮�� �������� ����⭮��
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
    std::cout << "Unknown"; // �᫨ ��祣� �� ᮢ����
    break;
    }
}

//�㭪�� ��� �뢮�� ������⢠ ��� ����⭮��
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
    std::cout << "Unknown"; // �᫨ ��祣� �� ᮢ����
    break;
    }
}
