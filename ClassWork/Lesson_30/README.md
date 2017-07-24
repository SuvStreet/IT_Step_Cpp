Исключения
===

Исключительные ситуации
---

**`ситуации, при которых дальнейшее выполнение программы невозможно`**

Причины:
* ошибки в коде
* неверные данные
* непредусмотренные действия пользователя и т. п.

Исключение (exception)
---

* **реакция на исключительную ситуацию, возникшую в программе**
* используются блоки **try – catch**
  * `try` – защищенный блок (вносится код, при выполнении которого может возникнуть исключение)
  * `catch` – блок, перехватывающий исключение

```cpp
try { // операторы защищенного блока }
catch (...) { // обработка исключения }
```

Блок try
---

* включает код, в котором может быть выброшено исключение
* если выброшено исключение, дальнейшие операторы из блока try не выполняются, а управление передается дальше

```cpp
try {
  if (max_vec_size < 0) {
    throw -1; 
  }
  std::vector<int> vec;
  vec.reserve(max_vec_size);
}
```

Блок catch
---

* включает код для обработки исключений
* должен идти сразу за блоком `try`
* бывает нескольких видов:
  * **`catch(тип_исключения) { }`**
  * **`catch(тип_исключения имя) { }`**
  * **`catch(...) { }`**
* блоков `catch` может быть несколько

```cpp
catch (char) { std::cout << "Exception" << std::endl; }
catch (int ex) { std::cout << "Exception №" << ex << std::endl; }
catch (...) { std::cout << "Unknown exception" << std::endl; }
```

throw
---

* когда возникает исключительная ситуация, выбрасывается исключение и передается управление блоку `catch` с таким же типом
* в одном блоке `try` может быть несколько операторов `throw`

```cpp
try {
  if (max_vec_size < 0) 
    throw -1;
  // ...
}
catch(int x) { }  // goto
catch (...) { }
```

Пример 1
---

```cpp
#include <iostream>

void f() {
  int x = 0;
  try {
    if (x == 0) { throw 1; }  // выброс исключения
    std::cout << 2/x;          // дальнейшее не выполнится 
    int y = 15 + x; 
    std::cout << y << std::endl;
  }
  catch (...) { // goto сюда
    std::cout << "Division by zero" << std::endl;
  }
}
```

Пример 2
---

```cpp
#include <iostream>

void f() {
  try {
    std::cout << "BEGIN TRY" << std::endl; 
    throw 1;
    std::cout << "END TRY" << std::endl;
  }
  catch (int x) {
    std::cout << "Exception " << x << std::endl;
  }
  catch (char c) {
    std::cout << "Exception with " << c << std::endl;
  }
}
```

Пример 3
---

```cpp
void f() {
  try {
    std::cout << "BEGIN TRY" << std::endl; 
    std::srand(std::time(NULL));
    int value = std::rand();
    if (value % 2 == 0) {
      throw 1;
    }
    else { throw 'z'; }
    std::cout << "END TRY" << std::endl;
  }
  catch (int x) { std::cout << "Exception " << x << '\n'; }
  catch (char c) { std::cout << "Exception with " << c << '\n'; }
}
```

catch(...)
---
* универсальный `catch` (ловит исключения с типом, который не соответствует типам в других блоках `catch`)
* всегда должен идти последним по счету

```cpp
try {
  if (max_vec_size < 0) 
    throw "Error";
  // ...
}
catch(int x) { }
catch(char c) { }
catch (...) { } //  const char*
```

Исключения и функции
---

* исключение можно генерировать **в функции**

```cpp
void f() {
  std::cout << "BEGIN TRY" << std::endl; 
  std::srand(std::time(NULL));
  int value = std::rand();
  if (value % 2 == 0) { throw 1; }
  else { throw 'z'; }
  std::cout << "END TRY" << std::endl;
}

void main() {
  try { f(); }
  catch (int x) { std::cout << "Exception with " << x << '\n'; }
  catch (char c) { std::cout << "Exception with " << c << '\n'; }
}
```

Ключевое слово noexcept (C++11)
---

* показывает, что функция **не генерирует исключений**
* пишется **после объявления** функции

```cpp
void message() noexcept {
  std::cout << "invalid value "  << cur_value <<  std::endl;
}
```

Что происходит внутри...
---

![пример](https://pp.userapi.com/c637818/v637818227/5949b/Us943n5BnOU.jpg)

Раскрутка стека
---

![пример](https://pp.userapi.com/c637818/v637818227/594a3/W1qokwjmmeE.jpg)

Исключения и объекты
---

* создается **специальный класс** для типа исключений
* при генерации исключения вызывается **конструктор**

```cpp
class bad_range {
  int cur_value;
public:
  bad_range(int value) : cur_value(value) { }
  void message() {
    std::cout << "invalid value "  << cur_value <<  std::endl;
  }
};
```

Пример
---

```cpp
class bad_range {
  int cur_value;
public:
  bad_range(int value) : cur_value(value) { }
  void message() {
    std::cout << "invalid value "  << cur_value <<  std::endl;
  }
};

void createArray() {
  int x;
  std::cin >> x;
  if (x > 100) { throw bad_range(x); }
  // ...
}
```

```cpp
try {
createArray();
}
catch(bad_range &x) {
x.message();
// …
}
```

Особенности исключений
---

* оператор `throw` передает выполнение в тувнешнюю функцию, в которой есть подходящий по типу исключения блок `try` – `catch`
* при генерации исключения всегда создается **копия** (даже если ловится будто бы ссылка)

```cpp
class  MyException { ... };

void f () { if (1 == 1) throw MyException(); }
void g() {
  try {   f();   }
  catch(MyException& exc) { ... } // копия объекта
```

Иерархия исключений
---

* классы исключений можно наследовать друг от друга
* действуют стандартные правила наследования

![пример](https://pp.userapi.com/c637818/v637818227/594ab/qrrh2U5pFlU.jpg)

Иерархия исключений (1)
---

```cpp
class  MyMathExc{ 
public: 
  virtual void print_info() { std::cout << "Math error\n"; }
};

class  ZeroDivide : public MyMathExc {     
public:
  void print_info() { std::cout << "Divide by zero\n"; }
};

class  InvalidArg : public MyMathExc {     
  int x;
public:
  InvalidArg(int tmp) : x(tmp) { }
  void print_info() { std::cout << "Invalid value " << x << "\n"; }
};
```

Иерархия исключений (2)
---

```cpp
double div() {
  int x, y;
  std::cin >> x >> y;
  if (y == 0) throw ZeroDivide();
  if (y < 0) throw InvalidArg(y);
  if ( x > 10000000 ) throw MyMathExc();
  return static_cast<double>(x) / y;
}

void test() {
  try { std::cout << div() << std::endl; }
  catch(MyMathExc mm) { mm.print_info(); }   // Всегда здесь!
  catch(ZeroDivide zd) { zd.print_info(); } 
  catch(InvalidArg ia) { ia.print_info(); }
}
```

Иерархия исключений (3)
---

```cpp
double div() {
  int x, y;
  std::cin >> x >> y;
  if (y == 0) throw ZeroDivide();
  if (y < 0) throw InvalidArg(y);
  if ( x > 10000000 ) throw MyMathExc();
  return static_cast<double>(x) / y;
}

void test() {
  try { std::cout << div() << std::endl; }
  catch(ZeroDivide zd) { zd.print_info(); }
  catch(InvalidArg ia) { ia.print_info(); }
  catch(MyMathExc mm) { mm.print_info(); } // OK
}
```

Иерархия исключений (4)
---

```cpp
double div() {
  int x, y;
  std::cin >> x >> y;
  if (y == 0) throw ZeroDivide();
  if (y < 0) throw InvalidArg(y);
  if ( x > 10000000 ) throw MyMathExc();
  return static_cast<double>(x) / y;
}

void test() {
  try { std::cout << div() << std::endl; }
  catch(MyMathExc& mm) { mm.print_info(); } // OK
  catch(…) { std::cout << "Unknown exception\n"; }
}
```

Выводы
---

* нужно располагать блоки `catch` в правильном порядке: **от самого последнего в иерархии до базового**
* при перехвате исключения удобно пользоваться **указателем или ссылкой на базовый класс**, а в самих классах иметь виртуальные методы
* если перехватывать объекты-исключения по значению, а ловить объект базового класса, то будет вызываться **метод базового класса**

Класс exception
---

* нужно подключить заголовочный файл **<exception>**
* класс `exception` – базовый класс для остальных классов исключений
* виртуальный метод `what()` выводит строку с сообщением про тип исключения
* от классов стандартных исключений можно **наследовать свой класс**

Класс exception (пример)
---

```cpp
double div() {
    double x, y;
    std::cin >> x >> y;
    if (x / y < 0) throw std::exception();
    std::cout << x / y << std::endl;
}

void test() {
  try { std::cout << div() << std::endl; }
  catch(std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
```

Стандартные исключения
---

![пример](https://pp.userapi.com/c637818/v637818227/594b3/CvrX_RM9mdk.jpg)

Семейство logic_error
---

* класс `logic_error` – описание логических ошибок
* во всех производных классах реализован **конструктор с параметром** (текстовая строка для описания исключения)

```cpp
class logic_error : public exception {
public:
  explicit logic_error(const std::string& what_arg);
};

class domain_error : public logic_error {
public:
  explicit domain_error(const std::string& what_arg);
};
```

Семейство runtime_error
---

* класс `runtime_error` – описание ошибок, которые могут возникнуть при исполнении программы
* реализован **конструктор с параметром** (текстовая строка для описания исключения)
* класс `range_error` – результат вычислений лежит вне допустимого диапазона
* класс `underflow_error` – потеря точности
* класс `overfow_error` – переполнение (результат превышает допустимый максимум)

Основные стандартные исключения
---

* **dynamic_cast** ***bad_cast*** - не может выполнить приведение типов
* **new** ***bad_alloc*** - не может выделить память
* **string** ***out_of_range*** / ***length_error*** - выход за границы диапазона; недостаточно памяти для `append()` – результат длиннее максимума
* **vector** ***out_of_range*** - выход за границы диапазона
* **typeid** ***bad_typeid*** - не может вернуть объект типа
* **type_info** ***regex regex_error*** - проблемы с регулярными выражениями

**`Лучше перехватывать исключение родительского класса (exception)`**

Исключения и выделение памяти
---

* оператор `new` может генерировать исключение `bad_alloc`, если у него **нет запрашиваемого количества свободной памяти**

```cpp
void f {
  MyClass* obj;
  try { obj = new MyClass[100]; }
  catch (std::bad_alloc& ba){
    std::cout << "Exception: " << ba.what() << std::endl;
    exit(1);
  }
delete [] obj;
}
```

Неперехваченные исключения
---

```
-> нет подходящего блока catch
-> вызывается функция terminate()
-> вызывается функция abort()
-> программа завершает выполнение
```

Изменение поведения
---

* замена вызова функции `abort()` на свою функцию
* своя функция должна быть типа void без аргументов
* замена делается через `set_terminate()`

```cpp
#include <exception>

void myExit() {
  exit(1);
}

set_terminame(myExit);
```

Советы
---

> «Мы настоятельно рекомендуем не генерировать исключения встроенных типов, например числа типа int или C-строки. Вместо этого следует генерировать объекты типов, специально разработанных для использования в качестве исключений. Для этого можно использовать класс, производный от стандартного класса exception». *Бьерн Страуструп*

> «Функцию what() можно использовать для получения строки, предназначенной для указания информации об ошибке, вызвавшей исключение». *Бьерн Страуструп*

**12.07.2017**
