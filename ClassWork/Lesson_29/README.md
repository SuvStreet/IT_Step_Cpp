Лямбда-функции (C++11)
===

```cpp
[список_захвата](параметры) -> возвр._тип { тело_функции };
```

* анонимные (безымянные) функции
* используются вместо функторов
* могут делать код более компактным

```cpp
[ ](int x) { return x % 2 == 0; };

[ ](const std::string& str) { return str[0] == 'a'; };

[ ](const std::string& str) -> bool
  { if (str[0] == 'a' && str.size() < 4 ) { return true; }
  else { return false; }
};
```

Возвращаемый тип
---

* если в функции один `return`, то возвращаемый тип **выводится компилятором**
* если в функции не один `return`, то возвращаемый тип следует указать **за списком параметров после ->** (до С++14)
* если `return`'а нет, то выводится тип `void`

```cpp
[ ](int x) { return x % 2 == 0; };

[ ](const std::string& str) -> bool
  {  if (str[0] == 'a' && str.size() < 4 ) { return true; }
  else { return false; }
};
```

Сохранение под именем
---

* лямбда-функции можно **присваивать имя**
* лямбду можно вызывать по имени так же, **как и обычную функцию**
* подходит тогда, когда одну и ту же лямбду нужно использовать несколько раз

```cpp
auto f1 = [ ](const int x) { return x % 2 == 0; };
bool res = f1(10);

size_t res1 = std::count_if(vec1.begin(), vec1.end(), f1);
size_t res2 = std::count_if(vec2.begin(), vec2.end(), f1);
```

Захват переменных
---

* захват переменных – **передача переменных из области видимости** в лямбду, так чток этим переменным можно обращаться по их именам
* имена захватываемых переменных указываются **в []**

```cpp
const int div = 2;
auto f1 = [ div ](const int x) { return x % div == 0; };
bool res = f1(10);
```

Способы захвата
---

* **`[]`** - ничего не захватывается
* **`[имя]`** - переменная захватывается по значению
* **`[&имя]`** - переменная захватывается по ссылке
* **`[&]`** - все переменные из области видимости захватываются по ссылке
* **`[=]`** - все переменные из области видимости захватываются по значению
* **`[&имя1, имя2]`** - переменная 1 захватывается по ссылке, а переменная 2 – по значению

**Переменные, захваченные по значению, – const**

Захват переменных (пример 1)
---

```cpp
#include <vector>
#include <algorithm>

void f(){
  const int max = 50;
  int min = 10;
  int count_value = 0;
  std::vector<int> vec = {1, 2, 4, 15, 6, 7, 28, 9, 10, 15, 89, 20, 9};
  std::replace_if(vec.begin(), vec.end(), [max, min, &count_value](const int x) -> bool {
    if (min < x && x < max) { count_value++; return true; }
    else { --min; return false; } // Error
  }, 0);
}
```

Захват переменных (пример 2)
---

```cpp
#include <vector>
#include <algorithm>

void f() {
  const int max = 50;
  int min = 10;
  int count_value = 0;
  std::vector<int> vec = {1, 2, 4, 15, 6, 7, 28, 9, 10, 15, 89, 20, 9};
  std::replace_if(vec.begin(), vec.end(), [max, min, &count_value](const int x) mutable -> bool {
    if (min < x && x < max) { count_value++; return true; }
    else { --min; return false; } // OK
  }, 0);
}
```

Лямбда вместо предиката (пример)
---

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

void f() {
  std::vector<int> vec = {1, 2, 4, 5, 6, 7, 8, 9, 10, 15, 89, 20, 9};
  std::replace_if(vec.begin(), vec.end(), [ ](const int x) { return x % 5 == 0; }, -1);
  for (auto value : vec) { std::cout << value << " "; }
}
```

[**-->     Laboratory_work22     <--**](https://github.com/SuvStreet/IT_Step_Cpp/tree/master/Laboratory_work/Work22)

**11.07.2017**
