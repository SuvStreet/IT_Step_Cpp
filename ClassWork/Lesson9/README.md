Перегрузка операторов (продолжение)
===
 
Преобразования типов (операторы приведения)
--
 
* преобразуют пользовательский тип к стандартному (MyClass => int и т.п.) или другому пользовательскому (Rectangle => Square)
* не имеют аргументов
* не указывается тип возвращаемого значения
* всегда член класса
* наследуется дочерними классами

Преобразование типов: пример
---

```cpp
class Digit{
  int x_;
public:
  Digit( ){ x_ = 10; }
  ~Digit() { }
  operator int( ) const {
    return x_;
  }
};

void f ( ) {
  Digit myDig;
    int a = myDig; // a = 10
}
```

Оператор индекса [ ]
---
      
* принимает один аргумент
* возвращает ссылочный тип
* реализуется как нестатический метод класса

```cpp
double& Point::operator[ ](int index) {
  if (index < 0 || index > 1) {
    std::cout << "Error" << std::endl;
    exit(1);
  }
  if (index == 0) { return x_; }
  else { return y_; }
}
```

Оператор вызова функции ( )
---
      
* может принимать любое число аргументов
* может не возвращать значение
* реализуется как нестатический метод класса

```cpp
void Point::operator( )(double x, double y){
  x_ = x;
  y_ = y;
}
```

Ключевое слово default
---

* указывает, что используется метод, по умолчанию генерируемый компилятором
* добавляется через = в объявление
* используется, если есть вариант по умолчанию

```cpp
class Rectangle {
public:
  Rectangle() = default;
  Rectangle(double x, double y);
  ~Rectangle() = default;
  Rectangle(const Rectangle& r) = default;
  Rectangle& operator=(const Rectangle& r) = default;
};
```

Ключевое слово delete
---
      
* указывает компилятору, что не нужно генерировать объявленный метод
* добавляется через = в объявление
* может быть использовано с любой функцией

```cpp
class Rectangle {
public:
  Rectangle() = delete;
  Rectangle(double x, double y);
  explicit Rectangle(double x) = delete;
  ~Rectangle();
  Rectangle(const Rectangle& r) = delete;
  Rectangle& operator=(const Rectangle& r) = delete;
};
```

[**-->     Laboratory_work6     <--**](https://github.com/SuvStreet/IT_Step_Cpp/tree/master/Laboratory_work/Work6)

**5.06.2017**
