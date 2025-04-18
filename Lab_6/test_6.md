1) неверный код
```cpp
#include <iostream>
class Integer {
Integer(int number) {
value=number;
std::cout << "Object created." << std::endl;
}
int getValue() { return value; }
void setValue(int number) { value = number; }
void print() {
std::cout << "Value: " << value << std::endl;
}
private
int value;
}
int main() {
Integer integer;
setValue(3);
std::cout << "Value: " << getValue() << std::endl;
}
```

исправленный код:
```cpp
#include <iostream>
class Integer {
public:
Integer()
Integer(int number) {
value=number;
std::cout << "Object created." << std::endl;
}
int getValue() { return value; }
void setValue(int number) { value = number; }
void print() {
std::cout << "Value: " << value << std::endl;
}
private:
int value;
};
int main() {
Integer integer;
integer.setValue(3);
std::cout << "Value: " << integer.getValue() << std::endl;
}
```  

2) неверный код
```cpp
#include <iostream>
class Students {
public
// Установка имени студента
void set_name(string student_name) {
name = student_name;
}
// Получение имени студента
std::string get_name() {
return name;
}
// Установка фамилии студента
void set_last_name(std::string student_last_name) {
last_name = student_last_name;
}
// Получение фамилии студента
std::string get_last_name() {
return last_name;
}
// Установка промежуточных оценок
void set_scores(int student_scores[]) {
for (int i = 0; i < 5; ++i) {
scores[i] = student_scores[i];
}
}
// Установка среднего балла
void set_average_ball(float ball) {
average_ball = ball;
}
// Получение среднего балла
float get_average_ball() {
return average_ball;
}
Students();
private
// Промежуточные оценки
int scores[5];
// Средний балл
float average_ball;
// Имя
std::string name;
// Фамилия
std::string last_name;
}
main() -> int {
// Создание объекта класса Student
Students ;
std::string name;
string last_name;
// Ввод имени с клавиатуры
cout << "Name: ";
getline(std::cin, name);
// Ввод фамилии
std::cout << "Last name: ";
getline(cin, last_name);
// Сохранение имени и фамилии в объект класса Students
student.set_name(name);
student.set_last_name(last_name);
// Оценки
int scores[5];
// Сумма всех оценок
int sum = 0;
// Ввод промежуточных оценок
for (int i = 0; i < 5; ++i) {
std::cout << "Score " << i+1 << ": ";
std::cin >> scores[i];
// суммирование
sum += scores[i];
}
// Сохраняем промежуточные оценки в объект класса Student
student.set_scores(scores);
// Считаем средний балл
float average_ball = sum / 5.0;
// Сохраняем средний балл в объект класса Students
set_average_ball(average_ball);
// Выводим данные по студенту
std::cout << "Average ball for " << student.get_name() << " "
<< student.get_last_name() << " is "
<< student.get_average_ball() << std::endl;
}
```

исправленный код:
```cpp
#include <string>
#include <iostream>
class Students {
public:
// Установка имени студента
void set_name(std::string student_name) {
name = student_name;
}
// Получение имени студента
std::string get_name() {
return name;
}
// Установка фамилии студента
void set_last_name(std::string student_last_name) {
last_name = student_last_name;
}
// Получение фамилии студента
std::string get_last_name() {
return last_name;
}
// Установка промежуточных оценок
void set_scores(int student_scores[]) {
for (int i = 0; i < 5; ++i) {
scores[i] = student_scores[i];
}
}
// Установка среднего балла
void set_average_ball(float ball) {
average_ball = ball;
}
// Получение среднего балла
float get_average_ball() {
return average_ball;
}
Students(){};
private:
// Промежуточные оценки
int scores[5];
// Средний балл
float average_ball;
// Имя
std::string name;
// Фамилия
std::string last_name;
};
int main() {
// Создание объекта класса Student
Students students;
std::string name;
std::string last_name;
// Ввод имени с клавиатуры
std::cout << "Name: ";
getline(std::cin, name);
// Ввод фамилии
std::cout << "Last name: ";
getline(std::cin, last_name);
// Сохранение имени и фамилии в объект класса Students
students.set_name(name);
students.set_last_name(last_name);
// Оценки
int scores[5];
// Сумма всех оценок
int sum = 0;
// Ввод промежуточных оценок
for (int i = 0; i < 5; ++i) {
std::cout << "Score " << i+1 << ": ";
std::cin >> scores[i];
// суммирование
sum += scores[i];
}
// Сохраняем промежуточные оценки в объект класса Student
students.set_scores(scores);
// Считаем средний балл
float average_ball = sum / 5.0;
// Сохраняем средний балл в объект класса Students
students.set_average_ball(average_ball);
// Выводим данные по студенту
std::cout << "Average ball for " << students.get_name() << " "
<< students.get_last_name() << " is "
<< students.get_average_ball() << std::endl;
}
```

3) неверный код
```cpp
Исправьте ошибки в программе.
#include <iostream>
struct Vec2f {
float x = 0;
float y = 0;
Vec2f (float x, float y) ::x(x)
, y(y) {
this.x = x;
this.y = y;
}
float getLength() const {
const float lengthSquare = x * x + y * y;
return std::sqrt(lengthSquare);
}
}vect2f
int main() {
cout << vect2f.getLength() << '\n';
}
```

исправленный код:
```cpp
#include <iostream>
#include <cmath>
struct Vec2f {
float x = 0;
float y = 0;

Vec2f (float x, float y) : x(x), y(y) {
this->x = x;
this->y = y;
}
float getLength() const {
const float lengthSquare = x * x + y * y;
return std::sqrt(lengthSquare);
}
}vect2f(0, 0);

int main() {

std::cout << vect2f.getLength() << '\n';
return 0;
}
```

4) неверный код
```cpp
class BufferedIO {
public:
enum IOError { None, Access, General, Erro = -1};
class Date {
unsigned short nWeekDay : 3, // 0..7 (3 bits)
unsigned short nMonthDay : 6, // 0..31 (6 bits)
unsigned short nMonth : 5, // 0..12 (5 bits)
unsigned short nYear : 8, // 0..100 (8 bits)
}
// Declare nested class BufferedInput.
class BufferedInput {
BufferedInput();
public:
int read() {}
int Ngood() {
return _inputerror == Erro;
}
private:
int _inputerror;
}
// Declare nested class BufferedOutput.
class BufferedOutput {
BufferedOutput();
public:
int Ngood() {
return _inputerror == Erro;
}
private:
int _inputerror;
}
};
int main() {
BufferedIO _inputerror;
BufferedInput buffIn;
BufferedOutput buffOut;
std::cout << _inputerror.nWeekDay << '\n';
}
```

исправленный код:
```cpp
