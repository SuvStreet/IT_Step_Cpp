Виды конструкторов
***

1. Конструктор по умолчанию
2. Конструктор с параметрами:
    * явный (неконвертирующий) 
    * конвертирующий
3. Делегирующий конструктор (С++11)
4. Копирующий конструктор
5. Конструктор перемещения (С++11)

Конструктор по умолчанию
---

```cpp
class MyClass {
public:
  MyClass() { }; // или так MyClass() = default; 
  };
```

Конструктор с параметрами `явный (неконвертирующий)`
---

```cpp
class MyClass {
  int a, b;
public:
  explicit MyClass(int x, int y = 1) { 
    a = x; 
    b = y;
  } 
};
```

Конструктор с параметрами `конвертирующий`
---

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

Делегирующий конструктор C++11
---

```cpp
class MyClass {
  public:
    MyClass(double x) { ... }
    MyClass(int x) : MyClass(double(x))
    {
        // сделай что-нибудь
    }
};
```

Копирующий конструктор
---

```cpp
class MyClass {
public:
  MyClass(const MyClass& myObj);
  {
      // сделай что-нибудь
  }
};
```

Конструктор перемещения (С++11)
---

```cpp
class MyClass {
public:
  MyClass(MyClass&& myObj);
  {
      // сделай что-нибудь
  }
};

// Вызов конструктора перемещения:
// * компилятор сам решает, какой из конструкторов (копирования или перемещения) вызвать
// * чтобы явно указать компилятору, что нужно вызвать именно конструктор перемещения, имя вызываемого объекта передается в функцию std::move

MyClass m1;
MyClass m2 = std::move(m1);
```
