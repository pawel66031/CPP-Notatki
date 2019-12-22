# Generyki cpp





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
void SPower(T value) {
    /** Funkcja wypisująca podane [value] do kwadratu. **/
    cout << (value*value);
}
template<typename T>
void SPower(T value, int exponent) {
    /** Funkcja przeciążająca [SPower] dodatkowym argumentem. **/
    T tmp = value;
    for (int i=1; i<exponent; ++i)
        tmp *= value;
    
    cout << tmp;
}
void SPower(char value) {
    /** Funkcja przeciążająca [SPower] dla typu [char]. **/
    cout << "Nie mozna podniesc " << value << " do potegi";
}

```
```cpp
// Funkcja Generyczna:
SPower(2);
SPower(2.25);

// Funkcja Generyczna o Dodatkowym Argumencie:
SPower(2, 6);
SPower(5.654, 3);   // Funkcja o Dodatkowym Argumencie

// Funkcja o Jawnie określonych parametrach:
SPower('K');
SPower('O');
```      
