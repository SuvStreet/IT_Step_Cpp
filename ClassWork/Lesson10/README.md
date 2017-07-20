Перегрузка операторов (продолжение)
==

Перегрузка глобальной функцией
---

1. Функция для унарной операции получает один явный аргумент.
2. Функция для бинарной операции получает два явных аргумента. 

```
унарный   - • ClassA operator-(const ClassA&);
бинарный  - • ClassA operator-(const ClassA&, const ClassA&);
```

3. Объявляется и реализуется вне класса.
4. Перед словом operator не надо писать имя класса ( MyClass::operator+).
5. Обращение к полям класса осуществляется через аксессоры.

```cpp
return-type operator op( arg );
```

Арифметические бинарные операторы: пример
---

```cpp
class Digit {
  int x_;
public:
  explicit Digit(const int x) : x_(x) { }
  int getDigit( ) const { return x_; }
  void setDigit(const int x) { x_ = x; }
};

Digit operator+(const Digit& a, const Digit& b) {
  Digit tmp;
  tmp.setDigit(a.getDigit() + b.getDigit());
  return tmp;
}
```

Бинарные операторы: пример
---

```cpp
void f ( ) {
  Digit a(5);
  Digit b(7);
  Digit c(0);
  
  c = a + b;
  
  Digit d = operator+(a, b);
}
```

Унарные операторы: пример
---

```cpp
class Digit {
  int x_;
public:
  explicit Digit(const int x) : x_(x) { }
  int getDigit( ) const { return x_; }
  void setDigit( const int x ) { x_ = x; }
};

Digit operator-(const Digit& a) {
  Digit tmp = a;
  tmp.setDigit( -a.getDigit() );
  return tmp;
}

int main() {
  Digit a(10);
  Digit b = -a;
  b = operator-(a);
}
```

Операторы >> и <<
---

```cpp
std::ostream& operator<<( std::ostream&, const Digit&);
std::istream& operator>>( std::istream&, Digit&);
```

* **cin** – объект класса istream (оператор >>) **cout** – объект класса ostream (оператор <<)
* всегда не член класса
* возвращают ссылку на поток
* принимают два аргумента (ссылка на поток и пользовательский объект)

Операторы << и >>: пример
---

```cpp
class Digit{ /* … */ };

std::ostream& operator<<(std::ostream& os, const Digit& a) {
  os << a.getDigit( );
  return os;
}

std::istream& operator>>(std::istream& is, Digit& a) {
  int tmp;
  is >> tmp;
  a.setDigit(tmp);
  return is;
}

int main() {
  std::cout << a << b;
  std::cin >> a >> b;
  ((std::cout << a) << b);
  ((std::cin >> a) >> b);
}
```

[**-->     Laboratory_work7     <--**](https://github.com/SuvStreet/IT_Step_Cpp/tree/master/Laboratory_work/Work7)

**6.06.2017**
