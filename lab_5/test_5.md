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

исправленный код:
```cpp
#include<iostream>
int main() {
float a=3.14;
float *pj = &a;
std::cout << *pj << '\n';
}
```  

2) неверный код
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

3) неверный код
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
struct Phone {
int kod;       // Код города
int nom;       // Номер станции
int mom_abon;  // Номер абонента
};
int main() {
setlocale(LC_ALL, "rus");
Phone my_phone = {212, 767, 8900}; 
Phone your_phone;
wcout << L"Введите код города, номер станции и номер абонента: ";
cin >> your_phone.kod >> your_phone.nom >> your_phone.mom_abon;
wcout << L"Мой номер: (" << my_phone.kod << ") " << my_phone.nom << "-" << my_phone.mom_abon << endl;
wcout << L"Ваш номер: (" << your_phone.kod << ") " << your_phone.nom << "-" << your_phone.mom_abon << endl;
return 0;
}
```

4) неверный код
```cpp
#include <iostream>
using namespace std;
int main() {
setlocale (LC_ALL, "rus" );
const int n = 5;
const int m = 10;
int *a;
int *b;
a = new int*[n];
b = new int*[n];
for (int i = 0; i < n; i++) {
a[i] = new int[m];
b[i] = new int[m];
cout << &a[i][0] << endl;
cout << &b[i][0] << endl;
}
}
```
исправленный код:
```cpp
#include <iostream>
#include <locale>
using namespace std;
int main() {
setlocale (LC_ALL, "rus" );
const int n = 5;
const int m = 10;
int **a;
int **b;
a = new int*[n];
b = new int*[n];
for (int i = 0; i < n; i++) {
a[i] = new int[m];
b[i] = new int[m];
cout << &a[i][0] << endl;
cout << &b[i][0] << endl;
}
}
```

5) неверный код
```cpp
#include <iostream>
using namespace std;
int main() {
setlocale (LC_ALL, "rus" );
char s[] = "char s[]: text";
char* ps = "char* ps: text";
std::string str = "std::string str: text";
s = "another text";
str = "std::string str: another text";
char *s_1 = "char *s_1: text";
const char *s_2 = "const char *s_2: text";
wcout << L"Вывод строк : "
}
```
исправленный код:
```cpp
#include <iostream>
#include <string>
#include <locale>
using namespace std;
int main() {
setlocale(LC_ALL, "rus");
string s = "char s[]: text"; 
char* ps = "char* ps: text";
string str = "std::string str: text";
s = "another text"; 
str = "std::string str: another text";
char *s_1 = "char *s_1: text";
const char *s_2 = "const char *s_2: text";
wcout << L"Вывод строк : " << endl;
wcout << s << endl; 
wcout << ps << endl;
wcout << str << endl;
wcout << s_1 << endl; 
wcout << s_2 << endl; 
return 0;
}
```

6) неверный код
```cpp
int main() {
setlocale ();
wstring s = "I'am an developer";
wstring
s1 = s.substr(0, 3),
s2 = s.substr(1, 3),
s3 = s.substr(0, s.length()-1),
s4 = s.substr(1);
wcout << L"Why is you? : " << s1 s2+s3+s4 << '\n';
}
```
исправленный код:
```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
string s = "I'am an developer";
string
s1 = s.substr(0, 3),
s2 = s.substr(3, 4),
s3 = s.substr(7, s.length()-9),
s4 = s.substr(s.length()-2);
cout << "Why is you? : " << s1+s2+s3+s4 << '\n';
}
```

