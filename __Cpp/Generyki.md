# Generyki

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
### 1. Szablony Funkcji (Template Functions)
###### [Program 1.1]
```cpp
// Deklaracja Funkcji => Nagłówek Funkcji:
template<typename T> T SPower(T);

// Definicja Funkcji => Nagłówek + BlokInstrukcji:
template<typename T>
T SPower(T value) {
    /** Funkcja zwracająca podane [value] do kwadratu. **/
    return (value*value);
}
```
```cpp
int a = 5015;
float b = 6.25;
double c = 7.333;

cout << "\n a: " << a << "\t a^2: " << SPower(a)
     << "\n b: " << b << "\t b^2: " << SPower(b)
     << "\n c: " << c << "\t c^2: " << SPower(c);
``` 

<br/>

###### [Program 1.2] `Przeciążanie Funkcji`
```cpp
template<typename T>
void Power(T value) {
    /** Funkcja wypisująca podane [value] do kwadratu. **/
    cout << (value*value);
}
template<typename T>
void Power(T value, int exponent) {
    /** Funkcja przeciążająca [Power] dodatkowym argumentem. 
        Podnosi [value] do potęgi [exponent]. **/
    T tmp = value;
    for (int i=1; i<exponent; ++i)
        tmp *= value;
    
    cout << tmp;
}
void Power(char value) {
    /** Funkcja przeciążająca [Power] dla typu [char]. **/
    cout << "Nie mozna podniesc " << value << " do potegi";
}
```
```cpp
// Funkcja Generyczna:
Power(2);
Power(2.25);

// Funkcja Generyczna o Dodatkowym Argumencie:
Power(2, 6);
Power(5.654, 3);

// Funkcja o Jawnie określonych parametrach:
Power('K');
Power('O');
```

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
### 2. Szablony Klas
###### [Program 2.1] 
```cpp
template <typename T1, typename T2>
class ExemplaryClass {
    T1 var1;
    T2 var2;

public:
    ExemplaryClass(T1 var1, T2 var2): var1(var1),var2(var2) { }

    void Show() {
        cout "\n " << << var1 << "  " << var2;
    }
};
```
```cpp
ExemplaryClass<int,int>    a(2, 3);
ExemplaryClass<float,char> b(6.55, 'K');

a.Show();
b.Show();
```

<br/>

###### [Program 2.2] `Typy Domyślne`
```cpp
template <typename T1=bool, typename T2=bool>
class ExemplaryClass {
    T1 var1;
    T2 var2;

public:
    ExemplaryClass(T1 var1, T2 var2): var1(var1),var2(var2) { }

    void Show() {
        cout << "\n " << var1 << "  " << var2;
    }
};
```
```cpp
ExemplaryClass<>        a(true, true);
ExemplaryClass<float>   b(2.24, true);
ExemplaryClass<int,int> c(1014, 2548);

a.Show();
b.Show();
c.Show();
```

<br/>

###### [Program 2.3] `Specjalizacja Klas`
```cpp
// -----------------------------------------------------------
template <typename T>
class ExemplaryClass {
    T var;
public:
    ExemplaryClass(T var): var(var) { }
    void Show() { cout << "\n " << var; }
};

// -----------------------------------------------------------
template<> 
class ExemplaryClass<char> {
    char var;
public:
    ExemplaryClass(char var): var(var) { }
    void Show() { cout << "\n The letter is: " << var; }
};
```
```cpp
ExemplaryClass<int>     a(32);
ExemplaryClass<bool>    b(false);
ExemplaryClass<char>    c('V');

a.Show();   // Oryginalna klasa generyczna <int>
b.Show();   // Oryginalna klasa generyczna <bool>
c.Show();   // Specjalizacja klasy, dla typu <char>
```

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
### 3. Szablony Wariadyczne (Variadic Templates)
###### [Program 3.1]
```cpp
/** Pozwalają na wprowadzenie wielu argumentów **/
template<typename ... Args>
void Function() {
...
}
```




------------
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
