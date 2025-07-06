2) Разместите адреса (заполните адресное пространство)(заполните следующую таблицу), для примера представленного ниже:
```cpp
#include <iostream>
#include <vector>
#include <array>
const int CONSTT{3};
int g_val{4};
int g_val1;
int main () {
int v = 3;
std::vector<int> vk;
vk.push_back(1);
vk.push_back(2);
vk.push_back(3);
std::array<int,3> ak;
std::cout << "\n1 ???? is at " << &vk;
std::cout << "\n2 ???? is at " << &vk.front();
std::cout << "\n3 ???? is at " << &vk;
std::cout << "\n4 ???? is at " << &ak.front();
std::cout << "\n5 ???? is at " << &v;
std::cout << "\n6 ???? is at " << malloc(8);
std::cout << "\n7 ???? is at " << &g_val;
std::cout << "\n8 ???? is at " << &g_val1;
std::cout << "\n9 ???? is at " << &CONSTT;
std::cout << "\n10 Text is at " << reinterpret_cast<void*>(main) << "\n";
}
```
 ```cpp
1 ???? is at 0x...  // стек
2 ???? is at 0x...  // куча
3 ???? is at 0x...  // стек
4 ???? is at 0x...  // стек
5 ???? is at 0x...  //стек
6 ???? is at 0x...  // куча
7 ???? is at 0x...  // data 
8 ???? is at 0x...  // bss
9 ???? is at 0x...  // text
10 Text is at 0x... // text
```
3) неверный код
```cpp
class Dollars {
private:
int m_dollars;
public:
Dollars(int dollars) { m_dollars = dollars; }
// выполняем Dollars + Dollars через дружественную функцию
friend Dollars operator+(const Dollars &d1, const Dollars &d2);
// выполняем Dollars - Dollars через дружественную функцию
Dollars operator-(const Dollars &d1, const Dollars &d2);
Dollars operator*(const Dollars &d1, const Dollars &d2);
Dollars operator/(const Dollars &d1, const Dollars &d2);
int getDollars() const { return m_dollars; }
}
// Примечание: Эта функция не является методом класса!
Dollars +(const Dollars &d1, const Dollars &d2) {
// используем конструктор Dollars и operator+(int, int)
// мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
return Dollars(d1.m_dollars + d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator-(const Dollars &d1, const Dollars &d2) {
// используем конструктор Dollars и operator-(int, int)
// мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
return Dollars(d1.m_dollars - d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator*(const Dollars &d1, const Dollars &d2) {
// используем конструктор Dollars и operator*(int, int)
// мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
return Dollars(d1.m_dollars * d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars /(const Dollars &d1, const Dollars &d2) {
// используем конструктор Dollars и operator/(int, int)
// мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
return Dollars(d1.m_dollars / d2.m_dollars);
}
int main() {
Dollars dollars1();
Dollars dollars2();
std::cout << "+: " << (dollars1 + dollars2).getDollars() << " dollars." << std::endl;
std::cout << "-: " << (dollars1 - dollars2).getDollars() << " dollars." << std::endl;
std::cout << "*: " << (dollars1 * dollars2).getDollars() << " dollars." << std::endl
std::cout << "/: " << (dollars1 / dollars2).getDollars() << " dollars." << std::endl;
std::cout << "/: " << (dollars1 + 3).getDollars() << " dollars." << std::endl;
}
```

исправленный код:
```cpp
#include <iostream>

class Dollars {
private:
int m_dollars;
public:
Dollars(int dollars=0) { m_dollars = dollars; }
// выполняем Dollars + Dollars через дружественную функцию
friend Dollars operator+(const Dollars &d1, const Dollars &d2);
// выполняем Dollars - Dollars через дружественную функцию
friend Dollars operator-(const Dollars &d1, const Dollars &d2);
friend Dollars operator*(const Dollars &d1, const Dollars &d2);
friend Dollars operator/(const Dollars &d1, const Dollars &d2);
int getDollars() const { return m_dollars; }
};
// Примечание: Эта функция не является методом класса!
Dollars operator+(const Dollars &d1, const Dollars &d2) {
// используем конструктор Dollars и operator+(int, int)
// мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
return Dollars(d1.m_dollars + d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator-(const Dollars &d1, const Dollars &d2) {
// используем конструктор Dollars и operator-(int, int)
// мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
return Dollars(d1.m_dollars - d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator*(const Dollars &d1, const Dollars &d2) {
// используем конструктор Dollars и operator*(int, int)
// мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
return Dollars(d1.m_dollars * d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator/(const Dollars &d1, const Dollars &d2) {
// используем конструктор Dollars и operator/(int, int)
// мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
return Dollars(d1.m_dollars / d2.m_dollars);
}
int main() {
Dollars dollars1(7);
Dollars dollars2(3);
std::cout << "+: " << (dollars1 + dollars2).getDollars() << " dollars." << std::endl;
std::cout << "-: " << (dollars1 - dollars2).getDollars() << " dollars." << std::endl;
std::cout << "*: " << (dollars1 * dollars2).getDollars() << " dollars." << std::endl;
std::cout << "/: " << (dollars1 / dollars2).getDollars() << " dollars." << std::endl;
std::cout << "/: " << (dollars1 + 3).getDollars() << " dollars." << std::endl;
}
```

4) неверный код
```cpp
Сделайте код программы рабочим, причем элементы массива выводим с использованием цикла foreach.
#include <iostream>
int sumArray(int array) {
int result = 0;
for (const auto &number : array)
result += number;
return result;
}
int main() {
int array[7] = { 10, 8, 6, 5, 4, 3, 1 };
std::cout << sumArray(array);
return 0;
}
```

исправленный код:
```cpp
#include <iostream>

int sumArray(int* array, size_t size) {
int result = 0;
for (size_t i = 0; i < size; ++i) {
        result += array[i];
    }
    return result;
}
int main() {
int array[7] = { 10, 8, 6, 5, 4, 3, 1 };
std::cout << "Sum: " << sumArray(array, 7) << std::endl;
return 0;
}
```

4) неверный код
```cpp
Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
void (*pfunc)();
void print(int i) {
std::cout << i << " ";
}
int main() {
int data[]{1,2,3,4,5};
int len = sizeof(data)/sizeof(data[0]);
std::for_each(data, data+len, pfunc);
return 0;
}
```

исправленный код:
```cpp
#include <iostream>
#include <algorithm>

void print(int i) {
std::cout << i << " ";
}
void (*pfunc)(int)= print;

int main() {
int data[]{1,2,3,4,5};
int len = sizeof(data)/sizeof(data[0]);
std::for_each(data, data+len, pfunc);
return 0;
}
```
5) неверный код
```cpp
Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
class Number {
private:
int m_number;
Number(int number=0): m_number(number) {}
Number& operator++();
Number& operator--();
Number operator++(int);
Number operator--(int);
friend std::ostream& operator<< (std::ostream &out, const Number &n);
}
Number ::operator++() {
++m_number;
return *this;
}
Number operator--(){
--m_number;
return *this;
}
Number Number::operator++(int){
Number temp(m_number);
++(*this);
return temp;
}
Number Number::operator--(int){
Number temp(m_number);
--(*this);
return temp;
}
std::ostream& operator<< (std::ostream &out, const Number &d){
out << d.m_number << "\n";
return out;
}
int main(){
Number number(6);
std::cout << ++number;
std::cout << number++;
std::cout << number;
std::cout << --number;
std::cout << number--;
std::cout << number;
}
```

исправленный код:
```cpp
#include <iostream>

class Number {
private:
int m_number;
public: 
Number(int number=0): m_number(number) {}
Number& operator++();
Number& operator--();
Number operator++(int);
Number operator--(int);
friend std::ostream& operator<< (std::ostream &out, const Number &n);
};
Number& Number ::operator++() {
++m_number;
return *this;
}
Number& Number::operator--(){
--m_number;
return *this;
}
Number Number::operator++(int){
Number temp(m_number);
++(*this);
return temp;
}
Number Number::operator--(int){
Number temp(m_number);
--(*this);
return temp;
}
std::ostream& operator<< (std::ostream &out, const Number &d){
out << d.m_number << "\n";
return out;
}
int main(){
Number number(6);
std::cout << ++number;
std::cout << number++;
std::cout << number;
std::cout << --number;
std::cout << number--;
std::cout << number;
}
```
