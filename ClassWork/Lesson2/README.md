С++: Классы. Знакомство со строками
---

Встроенные (inline) методы
---

1. в точку вызова подставляется всё тело метода => не генерируется код вызова
=> растёт скорость исполнения программы
2. все методы, тело которых находится в определении класса, являются встроенными,

**НО:**

3. подходит, если тело функции не очень большое
4. чтобы сделать встроенным метод, тело которого находится вне определения класса,
нужно использовать спецификатор inline
          
```cpp
inline void MyClass::foo() { /*…*/ }
```                       

5. определение inline метода должно находиться в заголовочном файле!
6. спецификатор inline является рекомендацией компилятору

Встроенные (inline) методы: синтаксис
---

```cpp
---------------------------------------------------------------------------
class A {                     |            class A {
  int value;                  |               int value;
public:                       |            public:
  int getValue() const        |              int getValue() const;
  {                           |               void setValue(int x);
    return value;             |            };     
  }                           |
  void setValue(int x)        |            inline int A::getValue() const
  {                           |               { return value; }
  value = x;                  |
  }                           |            inline void A::setValue(int x)
};                            |               { value = x; }
```

Класс std::string
---

* безопасный класс для работы с символами
* строка – это массив символов произвольной длины

```cpp
#include <string>
void f() {
  std::string myString = "Hello, world!";
}
```

Инициализация строк
---

```cpp
#include <string>
void f() {
  std::string str0;
  std::string str1 = "";
  std::string str2 = "Hello, world!";
  const char* cStr = "Hello, world!";
  std::string str3 = cStr;                // инициализация строкой char*
  std::string str4 = str2;
  str1 = str4;
  std::string str5 = '!';                 // Error
  str0 = '!';                             // OK
}
```

Длина строки
---

* методы size() и length() (нулевой байт не учитывается)
* проверка на пустоту – метод empty() (пустая – true, непустая – false)

```cpp
#include <string>
void f() {
  std::string str = "Hello, world!";
  int len1 = str.length();                      // len1 = 13;
  int len2 = str.size();                        // len2 = 13;
  if ( str.empty() ) { str = "new value"; }
}
```

Доступ к символам
---

* перегружен оператор [ ]
* метод at() – генерирует исключение out_of_range при выходе за границы диапазона

```cpp
#include <string>
void f() {
  std::string str = "abc";
  char symb1 = str[0];
  char symb2 = str.at(0);
  char symb3 = str[10];       // Error
  char symb4 = str.at(10);    // Исключение
}
```

Итерирование по строке
---

```cpp
#include <string>
#include <iostream>
std::string str = "Hello, world!";
for (int i = 0; i < str.length(); ++i) {
  std::cout << str[i];
}
```

```cpp
#include <string>
#include <iostream>
std::string str = "Hello, world!";
for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
  std::cout << *it;
}
```

Итерирование по строке (С++11)
---

```cpp
#include <string>
#include <iostream>
std::string str = "Hello, world!";
for (auto symbol : str) {
  std::cout << symbol;
}
std::cout << std::endl;
```

Сравнение и конкатенация строк
---

* перегружены операторы == и !=
* перегружены операторы > и <
* перегружены операторы + и +=

```cpp
#include <string>
#include <iostream>
void f() {
  std::string str1 = "abc";
  std::string str2 = "abcd";
  if (str1 != str2) { str1 += str2; }
}
```

**2 пара "С++: Классы. Знакомство со строками" 23.05.2017**
