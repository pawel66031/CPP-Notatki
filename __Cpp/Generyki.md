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

std::cout << "\n a: " << a << "\t a^2: " << SPower(a)
          << "\n b: " << b << "\t b^2: " << SPower(b)
          << "\n c: " << c << "\t c^2: " << SPower(c);
```      
