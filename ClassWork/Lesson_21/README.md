STL: функторы и предикаты
===

Предопределенные функторы
---

Функтор          |     Операция
-----------------|-------------------------
plus             |     `+`
minus            |     `-(бинарный)`
multiplies       |     `*`
divides          |     `/`
modulus          |     `%`
negate           |     `-(унарный)`
logical_and      |     `&&`
logical_not      |     `!=`
equal_to         |     `==`
not_equal_to     |     `!=`
greater          |     `>`
less             |     `<`
greater_equal    |     `>=`
less_equal       |     `<=`
logical_or       |     `\|\|`

* **нужно включить <functional>**
* **не принимают аргументы**

std::bind (С++11)
---

std::bind(функция, плейсхолдеры, аргументы)

* универсальный «связыватель»
* создает новый объект-функцию с заданным набором аргументов
* использует плейсхолдеры (`_1`, `_2` и т. п.) – показывают, какой по счету переданный  аргумент нужно подставлять в функцию

**std::bind(функция, плейсхолдеры, аргументы)**

std::bind (пример)
---

```cpp
void f() {
  using namespace std::placeholders;
  std::vector<double> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::replace_if(vec.begin(), vec.end(), (std::bind(std::less<double>(), _1, 5)), 0);
  for (auto value : vec) { std::cout << value << " "; }
}
```

```cpp
void f() {
  using namespace std::placeholders;
  std::vector<double> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::replace_if(vec.begin(), vec.end(), (std::bind(std::less<double>(), 5, _1)), 0);
  for (auto value : vec) { std::cout << value << " "; }
}
```

Предопределенные функторы (пример 1)
---

```cpp
#include <string>
#include <list>
#include <functional>
#include <iostream>

void f() {
  std::list<std::string> data = {"ab", "c", "cat", "ac", "b", "cat"};
  data.remove_if(std::bind (std::equal_to<std::string>(), std::placeholders::_1, "cat"));
  for (auto it = data.begin(); it != data.end(); ++it) {
    std::cout << *it << " ";
  }
}
```

Предопределенные функторы (пример 2)
---

```cpp
#include <string>
#include <list>
#include <functional>
#include <iostream>

void f() {
  std::list<std::string> data = {"ab", "c", "cab", "ac", "bb"};
  data.sort();
  data.sort(std::greater<std::string>());
  for (auto it = data.begin(); it != data.end(); ++it) {
    std::cout << *it << " ";
  }
}
```

[**-->     Laboratory_work16     <--**](https://github.com/SuvStreet/IT_Step_Cpp/tree/master/Laboratory_work/Work16)

**26.06.2017**
