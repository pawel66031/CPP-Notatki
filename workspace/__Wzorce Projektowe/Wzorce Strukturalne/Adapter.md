# Adapter
&nbsp;&nbsp;&nbsp;&nbsp; - *Structural Patterns* \
&nbsp;&nbsp;&nbsp;&nbsp; - Tworzenie interfejsu między dwoma nie kolaboratywnymi obiektami. \
&nbsp;&nbsp;&nbsp;&nbsp; - [[Do Implementacji] - Adapter](#1-Adapter-Wrapper) \
&nbsp;&nbsp;&nbsp;&nbsp; - [[Do Implementacji] - Object Adapter](#2-Object-Adapter) \
&nbsp;&nbsp;&nbsp;&nbsp; - [[Do Implementacji] - Class Adapter](#3-Class-Adapter) 

<br/>

------------

<br/>

**Zalety**:
* Pozwala uniknąć zmian w implementacji już działających obiektów, modyfikujemy jedynie interfejs:
    * Zmniejszenie ilości pracy. 
    * Odrzucenie ryzyka uszkodzenia działającego kodu.
    * Odrzucenie ryzyka naderwania innych modułów już korzystających z działającego obiektu.
    * Pozwala nam pracować w momencie gdy nie mamy dostępu do *już działających obiektów*.
    <br/>
* ...

    
**Wady**:
* Rozrastanie się struktury projektu o nowe klasy, obiekty, pliki.
* Nadmiar pracy. Czasem bardziej opłaca się zmodyfikować obiekt niż pisać *adapter*.

------------
<br/>


### 1. Adapter "Wrapper"

![](https://github.com/Ptysiek/resources/blob/master/WzorceProjektowe/Adapter_Wrapper.png)


------------
<br/>

###### [Program 1.1]  `Class_A.file`
```cpp
#pragma once
#include "i_ClassA.file"


class A : public i_ClassA{
public: // CONSTRUCTOR:
    A(int x){
        this->x = x;
    }


public: // [Class_A] OPERATIONS:
    int GetX() { return this->x; }
    int GetSomeoneX(i_ClassA* someone) { return someone->GetX(); }


private: // PUBLIC/PRIVATE STATES AND OPERATIONS - of [Class_A]:
    // ...
    

};

```

###### [Program 1.2]  `Class_B.file`
```cpp
#pragma once


class B{
public: // CONSTRUCTOR:
    B(int x1, int x2, int x3)
     :x1(x1), x2(x2), x3(x3){}


public: // [Class_B] OPERATIONS
        // that [Class_A] want to use:
    int  Operation() { return x1 + x2 + x3; }


public: // PUBLIC/PRIVATE STATES - of [Class_B]:
    int x1;
    int x2;
    int x3;
    // ...


// PUBLIC/PRIVATE OPERATIONS - of [Class_B]:
    // ...


};

```
###### [Program 1.3]  `i_ClassA.file` &nbsp;&nbsp;&nbsp;&nbsp; [Interface of Class_A]
```cpp
#pragma once


class i_ClassA{
public: // STATES
    int x;

public: // OPERATIONS
    virtual int GetX(){};

};

```
###### [Program 1.4]  `a_ClassB.file` &nbsp;&nbsp;&nbsp;&nbsp; [Adapter of Class_B]
```cpp
#pragma once
#include "i_ClassA.file"
#include "Class_B.file"


class ClassB_Adapter : public i_ClassA{
public: // ADAPTER CONSTRUCTOR
    ClassB_Adapter(B* b): b_class(b){ }


private: // AGGREGATION:
    B* b_class;


public: // [Class_A] virtual method
        // for [Class_B] operation usage:
     int GetX(){
        return b_class->Operation();   // <- [Class_B] Operation
    }
};

```
###### [Program 1.6]  `Client.file`
```cpp
#include <iostream>
using std::cout;

#include "Class_A.file"  
#include "a_ClassB.file" // Adapter for [Class_B]


int main(){
    // _________________________________________________________
    // Using [Class_A] Operations on [Class_A] Instance:
    A a(5);                                     // Class_A
    cout << a.GetSomeoneX(&a) << "\n\n";

    // _________________________________________________________
    // Using [Class_A] Operations on wrapped [Class_B] Instance:
    B b(10, 12, -1);                            // Class_B

    // _________________________________________________________
    // Because we cannot do that:   a.GetSomeoneX(&b)
    // We need to wrapp [Class_B] Instance with the adapter:
    ClassB_Adapter* wrapped_b = new ClassB_Adapter(&b);
    cout << a.GetSomeoneX(wrapped_b) << "\n\n";
}

```  

------------
<br/>



### 2. Object Adapter



------------
<br/>


### 3. Class Adapter

![](https://github.com/Ptysiek/resources/blob/master/WzorceProjektowe/ClassAdapter.png)



------------
<br/>

###### [Program 3.1]  `Class_A.file`
```cpp
#pragma once
#include<iostream>
using std::cout;


class A{
// _________________________________________________
// PUBLIC/PRIVATE STATES - of [Class_A]:
    // ...

// _________________________________________________
public: // Virtual methods for [Class_B] operations
        // that we want to use from this [Class_A]:
    virtual void v_Operation_1(){ cout << "[Class_A] operation1"; };
    virtual void v_Operation_2(){ cout << "[Class_A] operation2"; };

// _________________________________________________
// PUBLIC/PRIVATE OPERATIONS - of [Class_A]:
    // ...

};
```

###### [Program 3.2]  `Class_B.file`
```cpp
#pragma once
#include<iostream>
using std::cout;


class B{
public: // CONSTRUCTOR:
    B(int x1, int x2, int x3)
     :x1(x1), x2(x2), x3(x3){ cout << "\n[Class_B] Constructor"; }


public: // [Class_B] OPERATIONS
        // that [Class_A] want to use:
    void Operation1() { cout << "\n" << x1 << "  " << x2 << "  " << x3; }
    void Operation2() { ++x1; ++x2; ++x3; }


private: // PUBLIC/PRIVATE STATES - of [Class_B]:
    int x1;
    int x2;
    int x3;
    // ...


// PUBLIC/PRIVATE OPERATIONS - of [Class_B]:
    // ...

};
```
###### [Program 3.3]  `ClassA__Adapter.file`
```cpp
#pragma once
#include<iostream>
using std::cout;

#include "Class_A"
#include "Class_B"


class ClassA__Adapter : public A, private B{

public: // ADAPTER CONSTRUCTOR:
    ClassA__Adapter(int x1, int x2, int x3): B(x1, x2, x3){
         cout << "\n[ClassA__Adapter] Constructor";
    }


public: // [Class_A] virtual methods
        // for [Class_B] operations:
    virtual void v_Operation_1(){
        Operation1();   // <- [Class_B] Operation
    }
    virtual void v_Operation_2(){
        Operation2();   // <- [Class_B] Operation
    }
};
```
###### [Program 3.4]  `Client.file` &nbsp;&nbsp;&nbsp;&nbsp; [main.cpp]
```cpp
#include <iostream>
using std::cout;

#include "Class_A"
#include "ClassA__Adapter"


int main(){
    // _________________________________________________________
    // Using [Class_A] Instance with only [Class_A] Operations:
    A a;
    a.v_Operation_1();
    cout << "\n\n";

    // _________________________________________________________
    // Using [Class_A] Instance with extra [Class_B] Operations:
    A* a_with_b = new ClassA__Adapter(5, 2, -1);
    cout << "\n\n";

    a_with_b->v_Operation_1();  // Show [Class_B] States
    a_with_b->v_Operation_2();  // Increment [Class_B] States
    a_with_b->v_Operation_2();  // Increment [Class_B] States
    a_with_b->v_Operation_1();  // Show [Class_B] States
    cout << "\n\n";

}
```
------------

<br/>

**Powiązane Patterny:**  
   - [X] [Fluent Builder](https://github.com/Ptysiek/CPP-Notatki/blob/master/__Wzorce%20Projektowe/FluentBuilder.md) 
   - [ ] [Singleton](#2-Fluent-Builder) 
   - [ ] [Bridge](#2-Fluent-Builder)

<br/>

![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
