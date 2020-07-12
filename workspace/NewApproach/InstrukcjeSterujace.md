# Instrukcje Sterujące
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Teorii]](#podsumowanie-classic-builder) \
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Praktyki]](#program-11--productfile--guitar) 

**Alternatywna Nawigacja:**  
&nbsp;&nbsp;&nbsp;&nbsp; - [link 1]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [link 2]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [link 3]()


<br/><br/>
-------------
### Blok Instrukcji
&nbsp;&nbsp;&nbsp;&nbsp; - Określany za pomocą dwóch klamer **{ ... }**. \
&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala wskazać linijki kodu należące do funkcji, klasy, przestrzeni nazw, innych instrukcji sterujących. \
&nbsp;&nbsp;&nbsp;&nbsp; - Narzuca własne zasady na zasięg nazw obiektów.

<br/><br/>
-------------
### Instrukcje Warunkowe - If
&nbsp;&nbsp;&nbsp;&nbsp; - Sprawdzają warunki od lewej strony. \
&nbsp;&nbsp;&nbsp;&nbsp; - Pozwalają na wykorzystanie nowych zapisów operatorów `not`, `or`, `and`, `xor`.

<br/><br/>
-------------
### Pętle - For
&nbsp;&nbsp;&nbsp;&nbsp; - Pętla wykonywana przez znaną ilość kroków. \
&nbsp;&nbsp;&nbsp;&nbsp; - Posiada w swojej budowie trzy części:   ```for (inicjalizacja; warunek; instrukcja kroku)```. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **inicjalizacja** \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala na nadawanie wartości utworzonym zmiennym:
```cpp
    int i;
    for (i = 0; i < 5; ++i) {
    }
    
    int e;
    for (i = 0, e = 5; i < e; ++i) {
    }
```
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala na tworzenie zmiennych o zasięgu bloku pętli. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Tak powstałe zmienne muszą mieć jednakowy typ:
```cpp
    // One variable with INT type:
    for (int i = 0; i < 5; ++i) {
    }
    
    // Two variables with INT type:
    for (int i = 0, e = 5; i < e; ++i) {
    }
        
    // Two variables with DOUBLE type:
    for (double i = 0, e = 5; i < e; ++i) {
    }
   
    // Error: wrong 'for' syntax
    for (double i = 0, int e = 5; i < e; ++i) {
    }
```

<br/>

&nbsp;&nbsp;&nbsp;&nbsp; - Instrukcja For pozwala na używanie składni "ForEach".



<br/><br/>
-------------
### Funkcje


<br/><br/>
-------------
### Akapit 3


<br/><br/>
-------------
![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
