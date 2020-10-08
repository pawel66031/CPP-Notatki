# Static

**Wewnętrzna Nawigacja:**  
&nbsp;&nbsp;&nbsp;&nbsp; - [Static wewnątrz funkcji](#specyfikator-static-wewnątrz-funkcji) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Static wewnątrz klasy](#specyfikator-static-wewnątrz-klasy) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Static przy obiektach globalnych](#specyfikator-static-przy-obiektach-globalnych) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Dobre praktyki](#dobre-praktyki) 


&nbsp;
-------------
**Powiązane Notatki**  
&nbsp;&nbsp;&nbsp;&nbsp; - [Lista Specyfikatorów]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [Teoria O Rodzajach Pamięci](/workspace/Teoria/ModelPamięci.md) 


&nbsp;
-------------
**Powiązane Strony**  
&nbsp;&nbsp;&nbsp;&nbsp; - [cppreference.com/w/cpp/keyword/static](https://en.cppreference.com/w/cpp/keyword/static) 


<br/><br/>

Funkcja *static* pozwala na wydłużenie "życia" zmiennej (pozostaje w pamięci do momentu wyłączania programu), gdzie domyślnie ustawiona zmienna jest usuwana w momencie, kiedy program dojdzie do odczytania końca funkcji, wtedy lokalne zmienne są od razu usuwane.


<br/><br/>
-------------
### Specyfikator static wewnątrz funkcji

Róznica między zmienną ze *static* a bez niej:  
***Static***
```cpp
#include <iostream>

void incrementValue() {
    static int value = 1;
    ++value;
    std::cout << value << '\n';
}

int main() {
    incrementValue();
    incrementValue();
    incrementValue();

    return 0;
}
```
```
    2  
    3  
    4  
```

***Bez statica***
```cpp
#include <iostream>

void incrementValue() {
    int value = 1;
    ++value;
    std::cout << value << '\n';
}

int main() {
    incrementValue();
    incrementValue();
    incrementValue();

    return 0;
}
```
```
    2  
    2  
    2  
```

Jak można dostrzec: program w momencie gdy dochodzi do deklaracji zmiennej z *static* w trakcie działania, gdy dostaje się po raz drugi do konstruktora *wartosc*, wtedy nie dochodzi do jej ponownej deklaracji z tego powodu, że jego wartość ze zmiennej *wartosc* została zapamiętana w pamięci, która zostanie ponownie wykorzystana. Gdyby nie było *static*, wtedy automatycznie po zakończeniu funkcji zmienna *wartosc* zostałaby zapomniana i nie byłoby możliwe wykonanie funkcji sumuj dla liczb w pamięci funkcji.



<br/><br/>
-------------
### Specyfikator static wewnątrz klasy


<br/><br/>
-------------
### Specyfikator static przy obiektach globalnych


<br/><br/>
-------------
### Dobre praktyki
> Przy definiowaniu zmiennej ze *static* najlepiej przed nazwą zmiennej dać przedrostek s_
> dla lepszej czytelności kodu.

Podczas tworzenia dużego projektu należy pamiętać, że zmienne *static* zostają dopiero po zakończeniu programu, więc należy pamiętać o jego ograniczaniu i nie nadużywania tych funkcji.



<br/><br/>
-------------
![]()
