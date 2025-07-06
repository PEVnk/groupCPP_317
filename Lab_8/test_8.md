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

