STL: функторы и предикаты
===

Некоторые базовые алгоритмы
---

* `find()`    **находит первое вхождение значения в последовательность**
* `count()`   **подсчитывает количество вхождений указанного значения в последовательность**
* `replace()` **заменяет элементы с указанным значением на новое**
* `remove()`  **удаляет элементы с указанным значением**

Особенности алгоритмов
---

```cpp
#include <algorithm>
```

* обрабатывают данные **в контейнерах**
* используют **итераторы**, по которым получают диапазон элементов
* алгоритмы, возвращающие итератор, обычно возвращают **end()**

Пример
---

```cpp
#include <list>
#include <algorithm>
#include <iostream>

void f(){
  std::list<int> data = {1, 8, -9, 4, 7, -18, 11, 0, 4, -7, 4};
  int res1 = std::count(data.begin(), data.end(), 4);
  auto it1 = std::find(data.begin(), data.end(), 11);
  *(++it1) = 12;
  std::replace(data.begin(), data.end(), -18, 6);
  auto it2 = std::remove(data.begin(), data.end(), -9);
  data.erase(it2, data.end());
}
```

Предикаты
---
      
* функциональные объекты (функции), которые **возвращают значение типа bool**
* бывают **унарные** (принимают один аргумент) и **бинарные** (принимают два аргумента)
* используются в качестве параметра в стандартных алгоритмах, например:
    * задают критерий поиска (унарные)
    * задают критерий сортировки (бинарные)
    * модифицируют элементы
* передаются **без ()**

Предикаты (пример)
---

```cpp
#include <list>
#include <algorithm>

bool deleteA(const std::string& s1) 
{
  return s1[0] == 'a'; // нельзя передать символ в функцию
}

void f() {
  std::list<std::string> data = {"ab", "c", "cab", "ac", "bb"};
  data.remove_if(deleteA);
}
```

Функторы
---

* вид **классов**, которые включают в себя **перегруженный оператор вызова функции – operator()**
* позволяют **использовать объект как функцию**
* могут применяться там, где нужна функция
* при первом вызове функтора происходит инициализация объекта (нужный **параметр передается через конструктор** объекта)

Функторы (пример 1)
---

```cpp
#include <string>
#include <iostream>

struct Comp {
  bool operator()(std::string& s1, std::string& s2) const { return s1.length() < s2.length(); }
};

void f(){
  Comp c;
  std::string str1 = "abcdef";
  std::string str2 = "abacaba";
  std::cout << c(str1, str2) << std::endl;
}
```

Функторы (пример 2)
---

```cpp
#include <string>
#include <list>

struct DeleteA {
  bool operator()(const std::string& s1) const { return s1[0] == 'a'; }
};

void f(){
  std::list<std::string> data = {"ab", "c", "cab", "ac", "bb"};
  DeleteA obj;
  data.remove_if(obj); // или data.remove_if(DeleteA());
}
```

Функторы (пример 3)
---

```cpp
#include <string>
#include <list>

class DeleteSymb {
  char symbol;
public:
  DeleteSymb(char s) : symbol(s) { };  // передаем аргумент
  bool operator()(const std::string& s1) const { return s1[0] == symbol; }
};

void f(){
  std::list<std::string> data = {"ab", "c", "cab", "ac", "bb"};
  data.remove_if(DeleteSymb('a'));
}
```

Алгоритмы с проверкой условия
---

* `find_if()`         **находит первое вхождение значения, соответствующее условию**
* `count_if()`        **подсчитывает количество выполнений условия**
* `remove_if()`       **удаляет элементы, если выполняется предикат (после применяем erase())**
* `replace_if()`      **заменяет элементы, если выполняется предикат**

Пример
---

```cpp
class Pred {
  int value;
public:
  Pred(const int v) : value(v) { }
  bool operator()(const int elem) { return elem > value; }
};

void f(){
  std::list<int> data = {1, 8, -90, 4, 7, -18, 11, 0, 4, -7, 4};
  int res = std::count_if(data.begin(), data.end(), Pred(1));
  std::list<int>::iterator it = std::find_if(data.begin(), data.end(), Pred(2)); 
  std::replace_if(data.begin(), data.end(), Pred(3), 0);
}
```

[**-->     Laboratory_work15     <--**](https://github.com/SuvStreet/IT_Step_Cpp/tree/master/Laboratory_work/Work15)

**22.06.2017**
