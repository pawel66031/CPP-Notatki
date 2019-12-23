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
### 1. Szablony Klas
###### [Program 2.1] 
```cpp
template <typename T1, typename T2>
class ExemplaryClass {
    T1 variable1;
    T2 variable2;

public:
    ExemplaryClass(T1 var1, T2 var2)
        : variable1(var1), variable2(var2) { }

    void Show() {
        cout << variable1 << "  " << variable2;
    }
};
```
```cpp
ExemplaryClass<int,int>    a(2, 3);
ExemplaryClass<float,char> b(6.55, 'K');

a.Show();
b.Show();
```
