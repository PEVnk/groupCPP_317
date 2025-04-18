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
#include <iostream>
class BufferedIO {
public:
enum IOError { None, Access, General, Erro = -1};
class Date {
public:   
unsigned short nWeekDay : 3; // 0..7 (3 bits)
unsigned short nMonthDay : 6; // 0..31 (6 bits)
unsigned short nMonth : 5; // 0..12 (5 bits)
unsigned short nYear : 8; // 0..100 (8 bits)
};
// Declare nested class BufferedInput.
class BufferedInput {
public:
BufferedInput() : _inputerror(None) {}
public:
int read() {return 0;}
int Ngood() {
return _inputerror == Erro;
}
private:
IOError _inputerror;
};
// Declare nested class BufferedOutput.
class BufferedOutput {
public:
BufferedOutput() : _inputerror(None) {}
int Ngood() {
return _inputerror == Erro;
}
private:
IOError _inputerror;
};
};

int main() {
BufferedIO:: Date _inputerror;
BufferedIO:: BufferedInput buffIn;
BufferedIO:: BufferedOutput buffOut;

std::cout << _inputerror.nWeekDay << '\n';
return 0;
}
```

5) неверный код
```cpp
class BufferedOutput {
short BytesWritten() {
return bytecount;
}
static void ResetCount() {
bytecount = 0;
}
static long bytecount;
};
int main() {
BufferedOutput bufOut = new BufferedOutput;
std::cout << bufOut.bytecount << '\n';
}

```

исправленный код:
```cpp
#include <iostream>
class BufferedOutput {
public:
    short BytesWritten() {
    return bytecount;
    }
    static void ResetCount() {
    bytecount = 0;
    }
    static long bytecount;
};
long BufferedOutput :: bytecount=0;
int main() {
    BufferedOutput bufOut;
    std::cout << bufOut.bytecount << '\n';
    return 0;
    }
```

6) неверный код
```cpp
class X {
X(int flag) : m_flag(flag) {}
bool getFlag() const {
m_accessCount++;
return m_flag + m_accessCount;
}
private:
int m_flag;
int m_accessCount{0};
};
int main() {
X x(new X);
std::cout << x.getFlag << '\n';
}
```

исправленный код:
```cpp
#include <iostream>
class X {
public:
X(int flag) : m_flag(flag) {}
int getFlag() const {
//m_accessCount++;
return m_flag + (++m_accessCount);
}
private:
int m_flag;
mutable int m_accessCount{0};
};

int main() {
X x(3);
std::cout << x.getFlag() << '\n';
return 0;
}
```

7) неверный код
```cpp
#include <iostream>
using namespace std;
namespace box {
class Box {
double length; // Length of a box
double breadth; // Breadth of a box
double height; // Height of a box
} };
int main() {
Box Box1; // Declare Box1 of type Box
Box Box2; // Declare Box2 of type Box
box::Box Box3(new Box); // Declare Box2 of type Box
double volume = 0.0; // Store the volume of a box here
// box 1 specification
box::Box1.height = 5.0;
box::Box1.length = 6.0;
box::Box1.breadth = 7.0;
// box 2 specification
box::Box2.height = 10.0;
box::Box2.length = 12.0;
box::Box2.breadth = 13.0;
// volume of box 1
volume = box::Box1.height * box::Box1.length * box::Box1.breadth;
cout << "Volume of Box1 : " << volume <<endl;
// volume of box 2
volume = box::Box2.height * box::Box2.length * box::Box2.breadth;
cout << "Volume of Box2 : " << volume <<endl;
delete box::Box3[];
}
```

исправленный код:
```cpp
#include <iostream>
using namespace std;
namespace box {
class Box {
  public:
    double length; // Length of a box
    double breadth; // Breadth of a box
    double height; // Height of a box
    // Конструктор по умолчанию
    Box() : length(0), breadth(0), height(0) {}
        
    // Конструктор с параметрами
    Box(double l, double b, double h) : length(l), breadth(b), height(h) {}
  }; 
}
int main() {
    box::Box Box1; // Declare Box1 of type Box
    box::Box Box2; // Declare Box2 of type Box

    // box 1 specification
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;
    
    // box 2 specification
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;
    
    // volume of box 1
    double volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Volume of Box1 : " << volume <<endl;
    // volume of box 2
    volume = Box2.height * Box2.length * Box2.breadth;
    cout << "Volume of Box2 : " << volume <<endl;
    
    return 0;
}
```

8) неверный код
```cpp
class Window {
public:
Window(); // Default constructor.
Window( int x1, int y1, int x2, int y2 ) {} // Constructor specifying Window size.
bool SetCaption( const char *szTitle ) { return 0; } // Set window caption.
const char *GetCaption() {} // Get window caption.
char *szWinCaption; // Window caption.
};
// Declare a pointer
char Window::*pwCaption = &Window::szWinCaption;
const char * (Window::* pfnwGC)() = Window::GetCaption;
bool (Window:: pfnwSC)( const char * ) = &Window::SetCaption;
Window wMainWindow;
Window pwChildWindow = new Window;
char *szUntitled = "Untitled - ";
int cUntitledLen = strlen(szUntitled);
int main() {
}
```

исправленный код:
```cpp
#include <iostream>
class Window {
public:
Window(); // Default constructor.
Window( int x1, int y1, int x2, int y2 ) {} // Constructor specifying Window size.
bool SetCaption( const char *szTitle ) { return 0; } // Set window caption.
const char *GetCaption() {return szWinCaption; } // Get window caption.
char *szWinCaption; // Window caption.
};

// Declare a pointer
char* Window::*pwCaption = &Window::szWinCaption;

const char * (Window::* pfnwGC)() = &Window::GetCaption;

bool (Window:: *pfnwSC)( const char * ) = &Window::SetCaption;

Window wMainWindow;
Window* pwChildWindow = new Window;
const char *szUntitled = "Untitled - ";
int cUntitledLen = strlen(szUntitled);

int main() {
}
```
