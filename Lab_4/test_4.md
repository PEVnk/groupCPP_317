Задание 3.1.  
a) неправильный код
```cpp
#include <iostream>
int return 5(){
return 5;
}
int return8(){
return;
}
int main(){
std::cout << (return5() + return8() ) << std::endl;
return 0
}
```
исправленный код
```cpp
