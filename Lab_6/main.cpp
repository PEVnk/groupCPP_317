/**************************************************************************************
 * Filename: main.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 6
 * Исследование С++ классов в IDE Qt Creator
 * ***********************************************************************************/

#include <iostream>
#include <string>
#include "lab6.h"
#include "autobasa.h"
#include "complexnum.h"
#include <limits>

#define Unit 5

int main()
{
  #if Unit==1
  std::cout << "Задание 1" << std::endl; // Вызов функции задания 1 из отдельного файла

  std::cout << "=== Bruteforce Password Finder ===" << std::endl;

  // Запрос пароля у пользователя
  std::string password;
  std::cout << "Enter password to find (max 4 characters): ";
  std::cin >> password;

  // Проверка длины пароля
  if (password.length() > 4) {
    std::cerr << "Error: Password is too long (max 4 characters allowed)" << std::endl;
    return 1;
  }

  // Настройка параметров перебора
  bool m_useDigits, m_useLower, m_useUpper, m_useSpecial;
  char choice;

  std::cout << "\nConfigure character set for brute force:" << std::endl;
  std::cout << "Include digits (0-9)? (y/n): ";
  std::cin >> choice;
  m_useDigits = (choice == 'y' || choice == 'Y');
  std::cout << "Include lowercase letters (a-z)? (y/n): ";
  std::cin >> choice;
  m_useLower = (choice == 'y' || choice == 'Y');

  std::cout << "Include uppercase letters (A-Z)? (y/n): ";
  std::cin >> choice;
  m_useUpper = (choice == 'y' || choice == 'Y');

  std::cout << "Include special characters (!@# etc.)? (y/n): ";
  std::cin >> choice;
  m_useSpecial = (choice == 'y' || choice == 'Y');

  // Создание объекта Bruteforce с настройками
  Bruteforce bf(m_useDigits, m_useLower, m_useUpper, m_useSpecial, 4);

  std::cout << "\nStarting brute force attack..." << std::endl;

  // Запуск подбора пароля
  std::string found = bf.findPassword(password);
  if (!found.empty()) {
    std::cout << "Password found: " << found << std::endl;
  } else {
    std::cout << "Password not found (this shouldn't happen!)" << std::endl;
  }


  #elif Unit==2
  std::cout << "Задание 2" << std::endl; // Вызов функции задания 2 из отдельного файла

  std::cout << "=== Проверка палиндрома ===" << std::endl;
  std::cout << "Программа проверяет, является ли введенная последовательность палиндромом." << std::endl;
  std::cout << "Можно вводить числа, слова на русском или английском языке." << std::endl;
  std::cout << "Максимальное количество элементов: 17." << std::endl << std::endl;

  PalindromeChecker checker;
  checker.inputData();
  checker.printResult();


  #elif Unit==3
  std::cout << "Задание 3" << std::endl; // Вызов функции задания 3 из отдельного файла

  // Создаем диспетчера
  Dispatcher dispatcher("Петр Петров");

  // Добавляем водителей
  Driver driver1("Иван Смирнов", 1);
  Driver driver2("Илья Иванов", 2);
  dispatcher.addDriver(&driver1);
  dispatcher.addDriver(&driver2);

  // Добавляем автомобили
  Automobile car1("ГАЗель");
  Automobile car2("Volvo");
  dispatcher.addAutomobile(&car1);
  dispatcher.addAutomobile(&car2);

  // Создаем рейсы
  Trip* trip1 = dispatcher.createTrip(1, "Омск", "Бытовая техника");
  Trip* trip2 = dispatcher.createTrip(2, "Новосибирск", "Продукты");

  // Назначаем рейсы
  dispatcher.assignTrip(trip1, &driver1, &car1);
  dispatcher.assignTrip(trip2, &driver2, &car2);

  // Начинаем и завершаем рейсы
  trip1->startTrip(&driver1, &car1);
  trip1->completeTrip(false); // Автомобиль не поврежден

  trip2->startTrip(&driver1, &car1);
  trip2->completeTrip(true); // Автомобиль поврежден

  // Водитель запрашивает ремонт
  driver2.requestRepair();

  // Диспетчер отстраняет водителя
  dispatcher.suspendDriver(&driver1);

  // Выводим информацию
  dispatcher.displayAllDrivers();
  dispatcher.displayAllAutomobiles();
  dispatcher.displayAllTrips();


  #elif Unit==4
  std::cout << "Задание 4" << std::endl; // Вызов функции задания 4 из отдельного файла

  // Создаем комплексные числа в алгебраической форме
  ComplexNumber a(3, 4);  // 3 + 4i
  ComplexNumber b(1, -2); // 1 - 2i

  std::cout << "Число a: " << a.toString() << std::endl;
  std::cout << "Число b: " << b.toString() << std::endl;

  // Меняем форму представления
  a.setForm(ComplexForm::TRIGONOMETRIC);
  std::cout << "Число a в тригонометрической форме: " << a.toString() << std::endl;

  a.setForm(ComplexForm::EXPONENTIAL);
  std::cout << "Число a в экспоненциальной форме: " << a.toString() << std::endl;

  a.setForm(ComplexForm::ALGEBRAIC);
  std::cout << "Число a в алгебраической форме: " << a.toString() << std::endl;

  // Операции с числами
  ComplexNumber sum = a + b;
  ComplexNumber diff = a - b;
  ComplexNumber product = a * b;
  ComplexNumber quotient = a / b;

  std::cout << "Сумма: " << sum.toString() << std::endl;
  std::cout << "Разность: " << diff.toString() << std::endl;
  std::cout << "Произведение: " << product.toString() << std::endl;
  std::cout << "Частное: " << quotient.toString() << std::endl;

  // Сопряженное число
  ComplexNumber conj = a.conjugate();
  std::cout << "Сопряженное к a: " << conj.toString() << std::endl;

  // Возведение в степень
  ComplexNumber power = a.pow(3);
  std::cout << "a^3: " << power.toString() << std::endl;

  // Извлечение корня
  std::vector<ComplexNumber> roots = a.root(3);
  std::cout << "Кубические корни из a:" << std::endl;
  for (size_t i = 0; i < roots.size(); ++i) {
    std::cout << "  Корень " << i+1 << ": " << roots[i].toString() << std::endl;
  }

  #else

  Brick standardBrick;

  std::cout << "=== Проверка прохождения кирпича через отверстие ===\n";
  std::cout << "Стандартный кирпич: "
  << standardBrick.getLength() << " x "
  << standardBrick.getWidth() << " x "
  << standardBrick.getHeight() << " мм\n\n";

  // Ввод размеров отверстия
  double holeHeight, holeWidth;
  std::cout << "Введите высоту отверстия (мм): ";
  std::cin >> holeHeight;
  std::cout << "Введите ширину отверстия (мм): ";
  std::cin >> holeWidth;

  Projection2D hole(holeHeight, holeWidth);

  // Все возможные проекции кирпича
  std::vector<std::pair<double, double>> brickProjections = {
  {standardBrick.getLength(), standardBrick.getWidth()},
  {standardBrick.getLength(), standardBrick.getHeight()},
  {standardBrick.getWidth(), standardBrick.getHeight()}
  };

  bool canPass = false;
  int projectionNum = 1;

  // Проверяем все проекции
  for (const auto& proj : brickProjections) {
    std::cout << "\n=== Проверка проекции #" << projectionNum++ << " ===\n";
    std::cout << "Кирпич: " << proj.first << " x " << proj.second << " мм\n";

    // Рисуем обе проекции
    hole.draw(proj.first, proj.second);

    if (proj.first <= hole.getDimension1() && proj.second <= hole.getDimension2()) {
      std::cout << "\nРезультат: Кирпич ПРОЙДЕТ в этом положении!\n";
      canPass = true;
    } else {
      std::cout << "\nРезультат: Кирпич НЕ пройдет в этом положении.\n";
      }
  }

  // Итоговый результат
  std::cout << "\n=== Итоговый результат ===\n";
  if (canPass) {
    std::cout << "Кирпич МОЖЕТ пройти через отверстие!\n";
    } else {
      std::cout << "Кирпич НЕ МОЖЕТ пройти через отверстие.\n";
  }




#endif
return 0;
}
