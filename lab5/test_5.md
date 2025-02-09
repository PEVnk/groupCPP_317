1) неверный код
```cpp
#include<iostream>
int main() {
float a=3.14;
char *pj;
pj = (char*)&a;
std::cout << *pj << '\n';
}
```
происходит потеря данных из-за попытки вывести значение переменной типа float как char. Это приводит к некорректному отображению в памяти.
исправленный код:
```cpp
#include<iostream>
int main() {
float a=3.14;
float *pj;
pj = (float*)&a;
std::cout << *pj << '\n';
}
```
2)неверный код
```cpp
int main(){
int a=10, *pj;
void *pk;
pj = pk = &a;
pj++;
k++;
std::cout << pk << '\n';
std::cout << pj << '\n'
}
```
исправленный код:
```cpp
#include<iostream>
int main(){
int a=10, *pj;
int *pk;
pj = pk = &a;
std::cout << pk << '\n';
std::cout << *pj << '\n';
}
```
3)неверный код
```cpp
#include <iostream>
using namespace std;
struct phone{
int kod ;
int nom ;
int mom_abon ;
};
struct new_phone{
int kod1;
int nom1;
int mom_abon1;
};
int main() {
setlocale (LC_ALL, "rus" );
phone object;
new_phone new_object;
wcout << L"Введите код города, номер станции и номер абонента: ";
int mas_all[11];
cin >> mas_all[11];
int mas_a[2];
mas_a[0] = mas_all[0];
mas_a[1] = mas_all[1];
mas_a[2] = mas_all[2];
new_object.kod1 = mas_a[2];
int mas_b[2];
mas_b[0] = mas_all[4];
mas_b[1] = mas_all[5];
mas_b[2] = mas_all[6];
new_object.nom1 = mas_b[2];
int mas_c[3];
mas_c[0] = mas_all[8];
mas_c[1] = mas_all[9];
mas_c[2] = mas_all[10];
mas_c[3] = mas_all[11];
new_object.mom_abon1= mas_b[2];
object.kod = 123;
object.nom = 456;
object.mom_abon = 7890;
wcout << L"Мой номер телефона : " << object.kod << " " << object.nom << " " << object.mom_abon << endl;
wcout << L"Ваш номер : " << new_object.kod1 << " " << new_object.nom1 << " " << new_object.mom_abon1 << endl;
return 0;
}
```
исправленный код:
```cpp
#include <iostream>
using namespace std;

// Структура для хранения телефонного номера
struct Phone {
    int kod;       // Код города
    int nom;       // Номер станции
    int mom_abon;  // Номер абонента
};

int main() {
    setlocale(LC_ALL, "rus");

    // Инициализация первой структуры
    Phone my_phone = {212, 767, 8900}; // Мой номер: (212) 767-8900

    // Вторая структура для ввода данных
    Phone your_phone;

    // Запрос данных от пользователя
    wcout << L"Введите код города, номер станции и номер абонента: ";
    cin >> your_phone.kod >> your_phone.nom >> your_phone.mom_abon;

    // Вывод данных
    wcout << L"Мой номер: (" << my_phone.kod << ") " << my_phone.nom << "-" << my_phone.mom_abon << endl;
    wcout << L"Ваш номер: (" << your_phone.kod << ") " << your_phone.nom << "-" << your_phone.mom_abon << endl;

    return 0;
}
```
5)неверный код
```cpp
