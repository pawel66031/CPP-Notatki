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
&nbsp;&nbsp;&nbsp;&nbsp; - Wypełnianie wszystkich trzech części jest dobrowolne.
```cpp
    // correct syntax:
    for (int i = 0; i < 5; ++i) {
    }
    
    // correct syntax:
    for ( ; ; ) {
    }
    
    // correct syntax:
    for (int i = 0;   ; ++i) {
    }
```

<br/>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **inicjalizacja** \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala na nadawanie wartości utworzonym zmiennym:
```cpp
    int i;
    for (i = 0;   ;   ) {
    }
    
    int e;
    for (i = 0, e = 5;   ;   ) {
    }
```
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala na tworzenie zmiennych o zasięgu bloku pętli. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Tak powstałe zmienne muszą mieć jednakowy typ:
```cpp
    // One variable with INT type:
    for (int i = 0;   ;   ) {
    }
    
    // Two variables with INT type:
    for (int i = 0, e = 5;   ;   ) {
    }
        
    // Two variables with DOUBLE type:
    for (double i = 0, e = 5;   ;   ) {
    }
   
    // Error: 'for' instruction wrong syntax:
    for (double i = 0, int e = 5;   ;   ) {
    }
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **warunek** \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Jeżeli spełniony to wykonuje instrukcje zawarte w bloku instrukcji pętli for. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Gdy nie wypełniony przyjmuje wartość `true`. Pętla nieskończona do pojawienia się instrukcji `break` lub `return`. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala na użycie zmiennej zadeklarowanej wewnątrz części **inicjalizacyjnej** pętli. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala na wykorzystanie nowych zapisów operatorów `not`, `or`, `and`, `xor`.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **instrukcja kroku** \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Wykonywana jest za drugim i każdym następnym razem gdy **warunek** posiada wartość `true`. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Oznacza to że za pierwszym sprawdzeniem **warunku** instrukcje kroku się nie wykonają. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; A za każdym następnym, gdy **warunek** == `true`, zostaną wykonane. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Instrukcją kroku może być wykonanie operacji każdego operatora na zmiennej. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Instrukcją kroku może być wykonanie dowolnej funkcji. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Nazwa **instrukcja kroku** pochodzi od określenia że każde jednorazowe wykonanie bloku pętli jest **jednym krokiem pętli**. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Tak więc **instrukcja kroku** jest instrukcją wykonywaną każdorazowo gdy zakończy się jeden krok pętli. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Możliwe jest wykonanie kilku instrukcji. Każdą następną instrukcję oddzielamy operatorem przecinka `,`. 

<br/>

&nbsp;&nbsp;&nbsp;&nbsp; - Instrukcja For pozwala na używanie składni "ForEach", czyli dla każdego elementu. \
&nbsp;&nbsp;&nbsp;&nbsp; - Ten rodzaj składni for posiada dwie części ```for (zmienna iterująca : dowolny rodzaj indeksowanej tablicy)```. \
&nbsp;&nbsp;&nbsp;&nbsp; - W poniższym przykładzie zmienna `value` nie jest indeksem jak to było w poprzednich pętlach for. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `value` trzyma wartość tablicy `someVector` na której w obecnym kroku ustawił się iterator. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; W następnym kroku pętli zmienna `value` będzie trzymała następny element tablicy `someVector`.
```cpp
    std::vector<int> someVector;

    for (int value : someVector) {
    }   
```
```cpp
    std::vector<char> someVector;

    for (char value : someVector) {
    }   
```
```cpp
    std::vector<std::string> someVector;

    for (std::string value : someVector) {
    }   
    
    for (auto value : someVector) {
    }  
```


<br/><br/>
-------------
### Funkcje


<br/><br/>
-------------
### Akapit 3


<br/><br/>
-------------
![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
