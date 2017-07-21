Наследование
===

![Пример](https://pp.userapi.com/c637816/v637816933/59916/DigBSAi9HWQ.jpg)

Производные классы получают «по наследству» данные и методы своих базовых классов и расширяют их функциональность за счет своих полей и методов.

```cpp
Class Shape                 Class Circle

  int size;                       int size;
  char* color;                    char* color;
  void show();                    void show();

                              double center;
                              double radius; 
```

Наследование: синтаксис
---

```cpp
class A
{
public:
  A();
  virtual ~A();
};

class B : public A
{
public:
  B();
  ~B();
};
```

Конструкторы и деструкторы
---

1. Конструктор базового класса всегда вызывается и выполняется **до** конструктора производного класса.
2. Деструктор базового класса выполняется **после** деструктора производного класса.

* **Конструкторы:**   Class A -> Class B
* **Деструкторы:**    Class B -> Class A

Конструктор c параметрами в родительском классе
---

```cpp
class A
{
public:
  A(int x);
};

class B: public A
{
public:
  B(int x, int y);
};
```

```
B::B(int x, int y) :
  A(x)
{
  ...
}

/*
В листе инициализации
вызывается конструктор
базового класса с параметрами
*/
```

Типы наследования по спецификаторам доступа
---

* открытое (public)
* защищенное (protected)
* закрытое (private)

Типы наследования
---

![Таблица](https://pp.userapi.com/c637816/v637816658/6aa7a/GP5KOD2MA_g.jpg)

Наследование (доступ)
---

```cpp
class Derived : (public | protected | private) Base { };
```

* по умолчанию **в классах** используется **закрытое** (`private`) наследование
* по умолчанию **в структурах** используется **открытое** (`public`) наследование
* хотя все унаследованные `private`-поля недоступны непосредственно в объектах производного класса, но содержатся в них

Наследование (пример)
---

```cpp
class Base{
public:
  void a() { std::cout << "Base" << std::endl; }
};
class Derived : public Base {
public:
  void b() { std::cout << "Derived" << std::endl; }
};

void f() {
  Derived dr;
  dr.a(); // ОК
  dr.b(); // ОК
}
```

```cpp
class Base{
public:
  void a() { std::cout << "Base" << std::endl; }
};
class Derived : protected Base {
public:
  void b() { std::cout << "Derived" << std::endl; }
};

void f() {
  Derived dr;
  dr.a(); // Error
  dr.b(); // ОК
}
```

Указатель на базовый класс
---

* указатель **на объект базового класса** может указывать **на объект производного класса** (наоборот – нельзя)
* позволяет создавать массивы, в которых есть элементы и базового, и производного классов

```cpp
class Base { ... };
class Derived : Base { ... };

Derived derObject;
Base* pBaseObject = &derObject; // OK
Base* pBaseObj = new Derived; // OK
```

Указатели на базовый класс (пример)
---

```cpp
class Cat {
public:
  void say() { std::cout << "Meow!" << std::endl; }
};
class Kitten : public Cat {
public:
  void say() { std::cout << "Mimimi!" << std::endl; }
};

void f() {
  Cat* myPets[3];
  myPets[0] = new Cat;
  myPets[1] = new Kitten;
  myPets[2] = new Kitten;
  ...
};
```

```cpp
void g() {
  for (int i = 0; i < 3; ++i) {
    myPets[i]->say();
  }
}
// Все говорят “Meow!”
```

Виртуальный метод
---

* метод, который можно **переопределить в наследуемых классах** так, что **конкретная реализация выбирается при выполнении кода**
* задается в базовом классе через ключевое слово `virtual`, в производном – можно `override`
* `virtual` действует до конца цепочки наследования

```cpp
class Cat {
  ...
  virtual void say();
};

class Kitten : public Cat {
  ...
  void say() override;
};
```

Виртуальный метод (пример)
---

```cpp
class Cat {
public:
  virtual void say() { std::cout << "Meow!" << std::endl; }
};

class Kitten : public Cat {
public:
  void say() override { std::cout << "Mimimi!" << std::endl; }
};

void f() {
  Cat* myPets[3];
  myPets[0] = new Cat;
  myPets[1] = new Kitten;
  myPets[2] = new Kitten;
  ...
};
```

Ключевое слово override
---

* указывает, что метод **переопределен**

```cpp
class Cat {
public:
  virtual void say() { std::cout << "Meow!" << std::endl; }
};

class Kitten : public Cat {
public:
  void say(const std::string& str) override { // Error
    std::cout << str << std::endl;
  }
  void say() override {
    std::cout << "Mimimi!" << std::endl; // OK
  }
};
```

Ключевое слово final
---

* указывает, что метод **нельзя дальше переопределить** или что от класса **нельзя наследовать**

```cpp
class Cat {
public:
  virtual void say() final { std::cout << "Meow!" << std::endl; }
};

class Kitten : public Cat {
public:
  void say() override { // Error
    std::cout << "Mimimi!" << std::endl;
  }
};
```

Таблица виртуальных методов
---

* создается **для каждого класса**, если в нем есть **хотя бы один виртуальный метод**
* каждый объект класса **содержит указатель на таблицу** виртуальных методов для своего класса
* в таблице содержится **массив указателей на виртуальные методы** (функции)
* вызов виртуального метода происходит **через указатель** на таблицу и на метод в ней

Таблица виртуальных методов
---

![Пример](https://pp.userapi.com/c637816/v637816820/58161/PQlaLXVkfgw.jpg)

Виртуальные методы: уточнение
---

* при вызове виртуальных методов **в конструкторах и деструкторах виртуальность не работает**, потому что таблица виртуальных функций либо еще не создана, либо уже разрушена
* при наследовании **деструкторы должны быть виртуальными**

Наследование: деструкторы
---

**Не забывайте добавлять перед деструктором базового класса ключевое слово `virtual`**

Связывание
---

**Объединение объекта и вызова метода**

* Раннее
  * происходит на этапе компиляции
  * учитывается точный тип объекта
  * более быстрое, требует меньше памяти

* Позднее
  * происходит при выполнении программы
  * достигается через виртуальные методы и наследование
  * более медленное, но более гибкое

Раннее связывание (пример)
---

```cpp
class Cat {
public:
  void say() { std::cout << "Meow!" << std::endl; }
};

class Dog {
public:
  void say() { std::cout << "Arrrgh!" << std::endl; }
};

void f() {
  Dog angryDog;
  angryDog.say(); // раннее связывание
};
```

Позднее связывание (пример)
---

```cpp
class Cat {
public:
  virtual void say() { std::cout << "Meow!" << std::endl; }
};

class Kitten : public Cat {
public:
  void say() { std::cout << "Mimimi!" << std::endl; }
};

void f() {
  Cat* myPet = new Kitten; // позднее связывание
  myPet->say();
  ...
};
```

Абстрактный класс
---

* класс, в котором хотя бы один метод определен как **чисто виртуальный**, т. е. не имеет тела (`= 0`)
* **нельзя создать объект абстрактного класса**
* если в дочернем классе чисто виртуальный метод из родительского класса не имеет реализации, то дочерний класс тоже будет абстрактным

```cpp
class Shape {
  virtual float getArea() = 0;
};
```

Чисто виртуальный деструктор
---

* нужен тогда, когда мы хотим сделать класс абстрактным, но в нем нет подходящих методов
* объявляется с ключевым словом `virtual`
* должен иметь пустую реализацию

```cpp
class AbstractClass {
  AbstractClass() { }
  virtual ~AbstractClass() = 0;
};
AbstractClass():: ~AbstractClass() { }
```

[**-->     Laboratory_work18     <--**](https://github.com/SuvStreet/IT_Step_Cpp/tree/master/Laboratory_work/Work18)

**28.06.2017**
