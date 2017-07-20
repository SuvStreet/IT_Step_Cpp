Перегрузка операторов (окончание)
===

Дружественные функции: общие сведения
---

1. Имеют доступ к закрытой части класса.
2. Объявляются в классе с ключевым словом `friend`.
3. Функция не будет методом класса.
4. Реализацию можно писать как в классе (inline), так и вне класса.
5. При реализации не надо писать `::` и `friend`.
6. Объекты надо передавать как аргументы (не получает this).
7. Функция независима от спецификаторов доступа (private, protected, public).
8. Метод другого класса можно объявить как дружественный.
9. Одна функция может быть другом нескольких классов (нужно предварительное объявление класса – class B; ).

Дружественные функции
---

```cpp
class A {
  int x_;
public:
  ...
  friend void set(A& a, const int value);
  friend int get(const A& a);
};

void set(A& a, const int value) { a.x_ = value; }

int get(const A& a) { return a.x_; }
  ...
A obj(15);
std::cout << get(obj) << std::endl;
```

Перегрузка дружественной функцией
---

1. Функция для унарной операции получает один явный аргумент.
2. Функция для бинарной операции получает два явных аргумента. 

```
унарный   - • friend ClassA operator-(const ClassA&);
бинарный  - • friend ClassA operator-(const ClassA&, const ClassA&);
```

Арифметические бинарные операторы: пример
---

```cpp
class Digit{
  int x_;
public:
  ...
  explicit Digit(const int x) : x_(x) { }
  friend Digit operator+(const Digit& a, const Digit& b) {
    Digit tmp;
    tmp.x_ = a.x_+ b.x_;
    return tmp;
  }
};
```

Унарные операторы: пример
---

```cpp
class Digit{
  int x_;
public:
  ...
  explicit Digit(const int x) : x_(x) { }
  friend operator-(const Digit& a) {
    Digit tmp = a;
    tmp.x_ = -a.x_;
    return tmp;
  }
};
```

Дружественные функции vs. методы
---

1. Если оператор создает новый объект, то оператор лучше вынести из класса.
2. Если оператор изменяет исходный объект, то оператор должен быть методом класса.
3. Если первый аргумент – встроенный тип, то оператор не может быть методом.
4. Только методы класса:
```
= [ ] ( ) -> new/new[] delete/delete[]
преобразования типов
```

[**-->     Laboratory_work8     <--**](https://github.com/SuvStreet/IT_Step_Cpp/tree/master/Laboratory_work/Work8)

**7.06.2017**
