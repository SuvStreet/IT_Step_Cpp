Указатель this. Ключевое слово explicit
===

Ключевое слово this
---

* константный указатель на объект, для которого вызван метод
* неявно передается во все нестатические методы класса
* инициализируется значением адреса объекта, для которого вызван метод
* нельзя получить адрес
* нельзя присвоить что-нибудь
* в константном методе указывает на константный объект

Ключевое слово this: пример 1
---

myObj.setX(3); => setX(&myObj, 3); => setX(this, 3);

```cpp
void MyClass ::setX(int x)  
{  
  x_ = x;
  this->x_ = x;     // this->имя_поля/имя_метода
  (*this).x_ = x;   // (*this).имя_поля/имя_метода
}
```

Ключевое слово this: пример 2
---

```cpp
class MyClass {
  /* … */
};

void MyClass::setX(int x_)  
{  
  x_ = x_; // Error и плохой стиль…
  this->x_ = x_; // Ok
  (*this).x_ = x_;   // Ok
} 
```

Ключевое слово explicit (C++11)
---
      
**Запрещает неявное преобразование типов в конструкторе:**
* с одним параметром
* с несколькими параметрами, из которых только один не имеет значения по умолчанию

```cpp
class MyClass {
  int x;
public: 
  explicit MyClass(int newX) : x(newX) { };
};
```

Явный (конвертирующий) конструктор: инициализация
---

```cpp
class Box {
  int side_;
public:
  Box(int side) : side_(side) { }
  ~Box(){ }
};

int main(int argc, char* argv[]){
  Box myBox(3);
  Box myBigBox1 = 100; // Box myBigBox1(100)
  Box myBigBox2 = 'a'; // Box myBigBox2(97)
  return 0;
}
```

```cpp
class Box {
  int side1_, side2_;
public:
  Box(int side1, int side2 = 1) : side1_(side1), side2_(side2) { }
  ~Box(){ }
};

int main(int argc, char* argv[]){
  Box myBox(1, 7);
  Box myBigBox = 9.98;  // Box myBigBox(9, 1)
  return 0;
}
```

Явный (конвертирующий) конструктор: аргумент функции
---

```cpp
class Box {
  int side_;
public:
  Box(int side) : side_(side) { }
  int getSide() const { return side_; }
};

void printBaseArea(Box b){
  std::cout << b.getSide() * b.getSide() << std::endl;
}

int main(int argc, char* argv[]){
  printBaseArea(2.99); // 4
  return 0;
}
```

Явный (конвертирующий) конструктор
---

```cpp
class Box {
  int side_;
public:
  explicit Box(int side) : side_(side) { }
  ~Box(){ }
};

int main(int argc, char* argv[]){
  Box myBox(3);
  Box myBigBox = 100;  // Error
  printBaseArea(2.99); // Error
  return 0;
}
```

**25.05.2017**
