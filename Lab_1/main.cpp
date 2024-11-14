#include <iostream>    // Подключаем библиотеку для ввода/вывода
#include <iomanip>     // Подключаем библиотеку для форматирования ввода/вывода
using namespace std;   // Подключаем пространство имен

// main - главная функция с которой начинается исполнение программы
/*--------------------------------------------------------------------------*/
int main()
{ /* Открытая скобка - начало блока стейтмена, кода относящийся к функции main */
// Тело функции

//Задание 1.1.

#if 0
Вывод в консоль
#endif
  std::cout << "Номер группы 317, факультет дополнительного образования" << std::endl;
  std::cout << "Разработчики программы 1. Перкова Елена Владимировна" << std::endl;
  std::cout << "                       2. ______________" << std::endl;
  std::cout << "Номер Лабораторной работы 1" << std::endl;
  std::cout << endl;

/*объем *.exe файла в режиме отладки 65 КБ,
 * в режиме выпуска 17 КБ*/


//Задание 1.2.

#if 0
  Вывод в консоль
#endif

// установка флага вывода
  cout.setf(ios::fixed);
  cout << setw(10)<< "*****" << setw(35) << "ТУСУР" << setw(35)<< "*****" << setw(10) << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout.setf( ios::left);
  cout << "                                               Факультет: Доп. Образование"
     << endl;
  cout << "                                               Группа: 317" << endl;
  cout << "                                               Студент: Перкова Елена"
     <<endl;
  cout.unsetf( ios::left);  // снятие флага
  cout << endl;
  cout << setw(50) << "Томск 2024" << endl;
  cout << endl;

 //Задание 1.3


  //решение первой задачи на вычисление скорости
  double DistanceS,TimeT, SpeedV;
  cout << "Введите расстояние DistanceS(км): ";
  cin >> DistanceS;
  cout << "Введите время TimeT(ч): ";
  cin >> TimeT;
  SpeedV=DistanceS/TimeT;
  cout << "Скорость прямолинейного движения: " << SpeedV << " км/ч" << endl;

  //решение второй задачи на вычисление ускорения
  double InitialSpeed,FinalSpeed,Time,AccelerationA;
  cout << "Введите начальную скорость InitialSpeed (м/с): ";
  cin >> InitialSpeed;
  cout << "Введите конечную скорость FinalSpeed (м/с): ";
  cin >> FinalSpeed;
  cout << "Введите время Time(с): ";
  cin >> Time;
  AccelerationA=(FinalSpeed-InitialSpeed)/Time;
  cout << "Ускорение: " << AccelerationA << " м/с2" << endl;

  //решение третьей задачи на вычисление радиуса круга
  double Pi,RadiusR,LengthCircle;
  Pi=3.14;
  cout << "Введите длину окружности (см): ";
  cin >> LengthCircle;
  RadiusR=LengthCircle/(2*Pi);
  cout << "Радиус окружности: " << RadiusR << " см" << endl;

} /* Закрытая скобка - окончание блока стейтмена, кода относящийся к функции main */
/*--------------------------------------------------------------------------*/
// end main_cpp
/*--------------------------------------------------------------------------*/
