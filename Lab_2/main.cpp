/*
* Лабораторная работа №2
* Исследование ввода-вывода типов данных стандартной библиотеки С++
* Типы данных
* Developer: Перкова Е.В.
*/
/*
* INCLUDE LIBS
*/
#include <iostream> /* Подключаем библиотеку для ввода/вывода */
#include <iomanip> //для setprecision()
#include <cmath>  // Подключаем библиотеку для математических функций
#include <bitset> //для двоичного представления
using namespace std; /* Пространство имен std */

//main - главная функция с которой начинается исполнение программы
int main() { // Начало блока стейтмена, тело функции main

//задание 1
  cout << "Введите свой возраст (количество полных лет) и нажмите Enter" << endl; // вывод сообщения
  int agePerson;
  cin >> agePerson;    //получаем пользовательское число и сохраняем его в переменную
  cout << "Введите свой вес в кг и нажмите Enter" << endl; // вывод сообщения
  int weightPerson;
  cin >> weightPerson; //получаем пользовательское число и сохраняем его в переменную
  cout << "Введите свой рост в см и нажмите Enter" << endl; // вывод сообщения
  int heightPerson;
  cin >> heightPerson; //получаем пользовательское число и сохраняем его в переменную
  cout << "Если мужчина введите 1, женщина - 0 и нажмите Enter" << endl; // вывод сообщения
  int genderPerson;
  cin >> genderPerson; //получаем пользовательское число и сохраняем его в переменную

  //расчет идеального веса по формуле Брока
  double idealWeight;
  //для мужчин
  if (genderPerson==1){
      idealWeight=(heightPerson-100)*0.9;
      cout << fixed << setprecision(3);
      cout << "a - по формуле Брока: " << idealWeight<< endl;
  //для женщин
  } else if (genderPerson==0){
      idealWeight=(heightPerson-100)*0.85;
      cout << fixed << setprecision(3);
      cout << "a - по формуле Брока: " << idealWeight<< endl;
  }

  //расчет индекса массы тела
  double bodyMassIndex;
  bodyMassIndex = weightPerson/((heightPerson/100.0)*(heightPerson/100.0));
  cout << "ИМТ=" << bodyMassIndex << endl;
  if (bodyMassIndex<=16){
      cout << "b - по индексу массы тела: Выраженный дефицит массы" << endl;
  } else if (bodyMassIndex>16 && bodyMassIndex<=18.5){
      cout << "b - по индексу массы тела: Недостаточная (дефицит) масса тела" << endl;
  } else if (bodyMassIndex>18.5 && bodyMassIndex<=25){
      cout << "b - по индексу массы тела: Норма" << endl;
  } else if (bodyMassIndex>25 && bodyMassIndex<=30){
      cout << "b - по индексу массы тела: Избыточная масса тела (предожирение)" << endl;
  } else if (bodyMassIndex>30 && bodyMassIndex<=35){
      cout << "b - по индексу массы тела: Ожирение первой степени" << endl;
  } else if (bodyMassIndex>35 && bodyMassIndex<=40){
      cout << "b - по индексу массы тела: Ожирение второй степени" << endl;
  } else if (bodyMassIndex>40){
      cout << "b - по индексу массы тела: Ожирение третьей степени (морбидное)" << endl;
  }

  //индекс массы тела по возрасту
  if (genderPerson==1){
    if (agePerson>=19 && agePerson<=24){
        if (bodyMassIndex<21.4){
            cout << "с - по индексу массы тела с учетом возраста: дефицит массы тела" << endl;
        } else if (bodyMassIndex>=21.4 && bodyMassIndex<26.4){
            cout << "с - по индексу массы тела с учетом возраста: нормальный вес" << endl;
        } else {
            cout << "с - по индексу массы тела с учетом возраста: проблемы с лишним весом" << endl;
        }
    }
    if (agePerson>=25 && agePerson<=34){
        if (bodyMassIndex<21.6){
            cout << "с - по индексу массы тела с учетом возраста: дефицит массы тела" << endl;
        } else if (bodyMassIndex>=21.6 && bodyMassIndex<26.6) {
            cout << "с - по индексу массы тела с учетом возраста: нормальный вес" << endl;
        } else {
            cout << "с - по индексу массы тела с учетом возраста: проблемы с лишним весом" << endl;
        }
    }
    if (agePerson>=35 && agePerson<=44){
        if (bodyMassIndex<22.9){
            cout << "с - по индексу массы тела с учетом возраста: дефицит массы тела" << endl;
        } else if (bodyMassIndex>= 22.9 && bodyMassIndex<27.9) {
            cout << "с - по индексу массы тела с учетом возраста: нормальный вес" << endl;
        } else {
            cout << "с - по индексу массы тела с учетом возраста: проблемы с лишним весом" << endl;
        }
    }
    if (agePerson>=45 && agePerson<=54){
        if (bodyMassIndex<25.8){
            cout << "с - по индексу массы тела с учетом возраста: дефицит массы тела" << endl;
        } else if (bodyMassIndex>=25.8 && bodyMassIndex<30.8) {
            cout << "с - по индексу массы тела с учетом возраста: нормальный веc" << endl;
        } else {
            cout << "с - по индексу массы тела с учетом возраста: проблемы с лишним весом" << endl;
        }
    }
    if (agePerson>=55){
        if (bodyMassIndex<26.6){
            cout << "с - по индексу массы тела с учетом возраста: дефицит массы тела" << endl;
        } else if (bodyMassIndex>=26.6 && bodyMassIndex<31.6) {
            cout << "с - по индексу массы тела с учетом возраста: нормальный вес" << endl;
        } else {
            cout << "с - по индексу массы тела с учетом возраста: проблемы с лишним весом" << endl;
        }
    }
  } else if (genderPerson==0){
      if (agePerson>=19 && agePerson<=24){
          if (bodyMassIndex<19.5){
              cout << "с - по индексу массы тела с учетом возраста: дефицит массы тела" << endl;
          } else if (bodyMassIndex>=19.5 && bodyMassIndex<24.5) {
              cout << "с - по индексу массы тела с учетом возраста: нормальный вес" << endl;
          } else {
              cout << "с - по индексу массы тела с учетом возраста: проблемы с лишним весом" << endl;
          }
      }
      if (agePerson>=25 && agePerson<=34){
          if (bodyMassIndex<23.2){
              cout << "с - по индексу массы тела с учетом возраста: дефицит массы тела" << endl;
          } else if (bodyMassIndex>=23.2 && bodyMassIndex<28.2) {
              cout << "с - по индексу массы тела с учетом возраста: нормальный вес" << endl;
          } else {
              cout << "с - по индексу массы тела с учетом возраста: проблемы с лишним весом" << endl;
          }
      }
      if (agePerson>=35 && agePerson<=44){
          if (bodyMassIndex<23.4){
              cout << "с - по индексу массы тела с учетом возраста: дефицит массы тела" << endl;
          } else if (bodyMassIndex>=23.4 && bodyMassIndex<28.4) {
              cout << "с - по индексу массы тела с учетом возраста: нормальный вес" << endl;
          } else {
              cout << "с - по индексу массы тела с учетом возраста: проблемы с лишним весом" << endl;
          }
      }
      if (agePerson>=45 && agePerson<=54){
          if (bodyMassIndex<25.2){
              cout << "с - по индексу массы тела с учетом возраста: дефицит массы тела" << endl;
          } else if (bodyMassIndex>=25.2 && bodyMassIndex<30.2) {
              cout << "с - по индексу массы тела с учетом возраста: нормальный вес" << endl;
          } else {
              cout << "с - по индексу массы тела с учетом возраста: проблемы с лишним весом" << endl;
          }
      }
      if (agePerson>=55){
          if (bodyMassIndex<27.3){
              cout << "с - по индексу массы тела с учетом возраста: дефицит массы тела" << endl;
          } else if (bodyMassIndex>=27.3 && bodyMassIndex<32.3) {
              cout << "с - по индексу массы тела с учетом возраста: нормальный вес" << endl;
          } else {
              cout << "с - по индексу массы тела с учетом возраста: проблемы с лишним весом" << endl;
          }
      }
  }



//задание 2

  //вывод размера в байтах осноных типов данных
  cout << "int:\t\t" << sizeof(int) << " bytes;" << endl;
  cout << "bool:\t\t" << sizeof(bool) << " bytes;" << endl;
  cout << "char:\t\t" << sizeof(char) << " bytes;" << endl;
  cout << "float:\t\t" << sizeof(float) << " bytes;" << endl;
  cout << "double:\t\t" << sizeof(double) << " bytes;" << endl;

  cout << "long:\t\t" << sizeof(long) << " bytes;" << endl;
  cout << "long long:\t" << sizeof(long long) << " bytes;" << endl;
  cout << "short:\t" << sizeof(short) << " bytes;" << endl;
  cout << "unsigned int:\t" << sizeof(unsigned int) << " bytes;" << endl;
  cout << "signed int:\t" << sizeof(signed int) << " bytes;" << endl;
  cout << "long double:\t" << sizeof(long double) << " bytes;" << endl;
  cout << "signed short:\t" << sizeof(signed short) << " bytes;" << endl;
  cout << "unsigned short:\t" << sizeof(unsigned short) << " bytes;" << endl;

  //расчет числового диапазона для типов данных
  cout << "Числовой диапазон int:\tот " << long(-(pow(2,((sizeof(int)*8)-1)))) << " до " << long((pow(2,((sizeof(int)*8)-1)))-1) << endl;
  cout << "Числовой диапазон bool:\tот " << long(-(pow(2,((sizeof(bool)*8)-1)))) << " до " << long((pow(2,((sizeof(bool)*8)-1)))-1) << endl;
  cout << "Числовой диапазон long:\tот " << long(-(pow(2,((sizeof(long)*8)-1)))) << " до " << long((pow(2,((sizeof(long)*8)-1)))-1) << endl;
  cout << "Числовой диапазон signed short в oct:\tот " << oct << long(-(pow(2,((sizeof(signed short)*8)-1)))) << " до " << long((pow(2,((sizeof(signed short)*8)-1)))-1) << endl;
  cout << "Числовой диапазон char в hex:\tот " << hex<< long(-(pow(2,((sizeof(char)*8)-1)))) << " до " << long((pow(2,((sizeof(char)*8)-1)))-1) << endl;


//задание 3

  double a1,b1,c,d,f,g,h,k1,l,m;
  cout << "Введите десять чисел с плавающей точкой\n"; //вывод сообщения
  cin >> a1 >> b1 >> c >> d >> f >> g >> h >> k1 >> l >> m; //получаем пользовательские числа и сохраняем их в переменные
  double arithmeticMean=(a1+b1+c+d+f+g+h+k1+l+m)/10; //расчет среднего арифметического чисел
  cout << "Среднее арифметическое чисел равно " << arithmeticMean << endl;

//задание 4

  double p_1=34.5;
  double p_2=0.004000;
  double p_3=123.005;
  double p_4=146000;
  //перевод в экспоненциальную запись
  cout << "p_1="<<scientific<<p_1<<endl;
  cout << "p_2="<<scientific<<p_2<<endl;
  cout << "p_3="<<scientific<<p_3<<endl;
  cout << "p_4="<<scientific<<p_4<<endl;

//задание 5
//1)
  cout << ((true && true) || false) << endl;            //true
  cout << ((false && true) || true) << endl;            //true
  cout << ((false && true) || false || true) << endl;   //true
  cout << ((5 > 6 || 4 > 3) && (7 > 8)) << endl;        //false
  cout << (!(7 > 6 || 3 > 4)) << endl;                  //false

//2)
  //задание логических констант с помощью const
  const bool CONST_TRUE=true;
  const bool CONST_FALSE=false;

  //задание логических констант с помощью constexpr
  constexpr bool CONSTEXPR_TRUE=true;
  constexpr bool CONSTEXPR_FALSE=false;

  //задание логических констант с помощью макросов
  #define MACRO_TRUE true
  #define MACRO_FALSE false

  //задание целочисленных констан с помощью enum
  enum IntegerConst {
      ONE=1,
      TWO=2,
      THREE=3,
      FOUR=4
  };
  //вывод результатов выражений
  cout << "((CONST_TRUE && CONST_FALSE) || (!CONST_FALSE) && (CONST_TRUE||CONST_FALSE))= "
       << ((CONST_TRUE && CONST_FALSE) || (!CONST_FALSE) && (CONST_TRUE || CONST_FALSE)) << endl;
  cout << "((CONSTEXPR_TRUE && CONSTEXPR_FALSE) || (CONSTEXPR_TRUE && CONSTEXPR_FALSE) || (!CONSTEXPR_TRUE))= "
       <<((CONSTEXPR_TRUE && CONSTEXPR_FALSE) || (CONSTEXPR_TRUE && CONSTEXPR_FALSE) || (!CONSTEXPR_TRUE)) << endl;
  cout << "((MACRO_TRUE || MACRO_FALSE) && (MACRO_TRUE || MACRO_FALSE) && (MACRO_TRUE ||MACRO_FALSE))= "
       << ((MACRO_TRUE || MACRO_FALSE) && (MACRO_TRUE || MACRO_FALSE) && (MACRO_TRUE ||MACRO_FALSE)) << endl;
  cout << "((ONE>TWO) && (THREE<FOUR) && (TWO!=THREE))= " << ((ONE>TWO) && (THREE<FOUR) && (TWO!=THREE)) << endl;


//3)

  const bool variableA=true;
  const bool variableB=false;
  if ((!(variableA && variableB))==((!variableA) || (!variableB)))  //проверка правильности первого закона Моргана
      cout << "Первый закон Моргана доказан: не (a и b) = (не a) или (не b)" << endl;
  else
      cout << "Первый закон Моргана не доказан" << endl;
  if ((!(variableA || variableB))==((!variableA) && (!variableB)))  //проверка правильности второго закона Моргана
      cout << "Второй закон Моргана доказан: не (a или b) = (не a) и (не b)" << endl;
  else
      cout << "Второй закон Моргана не доказан" << endl;

//4)
  cout << "введите целочисленные переменных x, y, z, v" << endl;
  int x,y,z,v;
  bool logicValue;
  cin >> x >> y >> z >> v; //получаем пользовательские числа и сохраняем их в переменные
  x=3+4+5; //присваиваем х значение 12
  cout << "x = " << x << "\ty = " << y << "\tz = " << z << "\tv = " << v << endl;   //вывод полученных значений
  x=y=z; //присваиваем х и y значение равное z
  cout << "x = " << x << "\ty = " << y << "\tz = " << z << "\tv = " << v << endl;   //вывод полученных значений
  z*=++y+5; //инкремент переменной y, y присваивается это значение, z умножается на y
  cout << "x = " << x << "\ty = " << y << "\tz = " << z << "\tv = " << v << endl;   //вывод полученных значений
  logicValue=x || y && z || v; //выражение будет false, если z и v изначально равны 0
  cout << "logicValue = " << logicValue << endl;

//5)
  unsigned int varNumber,shiftNumber;
  cout << "введите целое число от 0 до 16" << endl;
  cin >> varNumber;
  cout << "введите целое число сдвига влево" << endl;
  cin >> shiftNumber;
  cout << "В десятичном формате " << varNumber << "<<" << shiftNumber << ": " << (varNumber << shiftNumber) << endl;
  cout << "В шестнадцатиричном формате " << varNumber << "<<" << shiftNumber << ": " << hex << (varNumber << shiftNumber) << endl;
  cout << "В восьмиричном формате " << varNumber << "<<" << shiftNumber << ": " << oct << (varNumber << shiftNumber) << endl;
  cout << "В двоичном формате " << varNumber << "<<" << shiftNumber << ": "
       << bitset<8*sizeof(varNumber << shiftNumber)>(varNumber << shiftNumber) << endl;

//6)

  int a=20, b=10, k=30;
  // приоритет операторов: умножение, деление, сложение, вычитание
  int res_1=a+b*1-128/5;
  // приоритет операторов: сдвиг вправо, побитовое ИЛИ
  int res_2=a | b >> 1;
  // приоритет операторов: деление, умножение; умножение и деление имеют левую ассоциативность и выполняются слева направо
  int res_3=a/b*k;
  cout << "res_1 = a+b*1-128/5 = " << res_1 << endl;
  cout << "res_2 = a | b >> 1 = " << res_2 << endl;
  cout << "res_3 = a/b*k = " << res_3 << endl;



  cin.clear();
  cin.ignore(32767, '\n');
  cin.get();
  return 0;
}// Закрытая скобка - окончание блока стейтмена кода, относящегося к функции main
