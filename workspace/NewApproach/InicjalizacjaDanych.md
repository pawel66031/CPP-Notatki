# Inicjalizacja Danych
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Teorii]]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Praktyki]]() 

**Alternatywna Nawigacja:**  
&nbsp;&nbsp;&nbsp;&nbsp; - [link 1]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [link 2]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [link 3]()



<br/><br/>
-------------
### Sposobów inicjalizacji zmiennych
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **a] &nbsp; Brak inicjalizacji, przypisanie wartości później:** \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **`int a;`** \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **`a = 5;`**
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **b] &nbsp; Inicjalizacja operatorem przypisania: &nbsp; `int b = 5;`**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **c] &nbsp; Inicjalizacja z klasycznego języka C: &nbsp;  `int c (5);`** 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **d] &nbsp; Użycie inicjalizatora klamrowego:  &nbsp;  `int d {5};`** \
&nbsp;&nbsp;&nbsp;&nbsp; - względem poprzednich sposobów nowoczesne. \
&nbsp;&nbsp;&nbsp;&nbsp; - możliwe od wersji Cpp11. \
&nbsp;&nbsp;&nbsp;&nbsp; - pozwala lepiej się zabezpieczyć przed błędami konwersji typów.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **e] &nbsp; `int e = {0};`**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **f] &nbsp; `int f { };`** \
&nbsp;&nbsp;&nbsp;&nbsp; - nadaje zmiennej f wartość zero.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **g] &nbsp; `int g = { };`** \
&nbsp;&nbsp;&nbsp;&nbsp; - nadaje zmiennej g wartość zero.








<br/><br/>
-------------
### Porównanie czasów inicjalizacji:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Dane otrzymano z strony `quick-bench.com` dla kompilatora Clang-9.0, std=c++17

| Sposób Inicjalizacji  | Czas Bez Optymalizacji | Z Optymalizacją <sup>[1]</sup>O3 |
| ------------- |:-------------:|:-------------:|
| brak inicjalizacji    | [4] 6198.43   | [3] 0.12490   |
| int b = 5;            | [3] 6192.25   | [4] 0.12496   |
| int c(5);             | [2] 6192.14   | [1] 0.12482   |
| int d{5};             | [1] 6185.66   | [2] 0.12492   |

<br/> \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Dane otrzymano z strony `quick-bench.com` dla kompilatora GCC-9.2, std=c++17

| Sposób Inicjalizacji  | Czas Bez Optymalizacji | Z Optymalizacją <sup>[2]</sup>O3 |
| ------------- |:-------------:|:-------------:|
| brak inicjalizacji    | [1] 11578.49   | [2] 0.50077e-5   |
| int b = 5;            | [4] 11598.41   | [3] 0.51166e-5   |
| int c(5);             | [3] 11589.55   | [4] 0.41272e-4   |
| int d{5};             | [2] 11586.76   | [1] 0.47772e-5   |

<br/> \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **Wnioski z czasów wykonania programów skompilowanych z optymalizacją O3:** \
&nbsp;&nbsp;&nbsp;&nbsp; - najsprawniejszym sposobem inicjalizacji jest inicjalizacja klamrowa. \
&nbsp;&nbsp;&nbsp;&nbsp; - najwolniejszym sposobem inicjalizacji jest wykorzystanie operatora przypisania. \
&nbsp;&nbsp;&nbsp;&nbsp; - inicjalizacja klamrowa potrafi być 8.6 razy szybsza od inicjalizacji nawiasowej z klasycznego C. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Nie będzie to jednak prawdą w wszystkich sytuacjach.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **UWAGA:** W zależności od wybranego kompilatora oraz jego konfiguracji można uzyskać \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; bardzo odmienne rezultaty. Wybierając konkretny sposób inicjalizacji należy \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; mieć na uwadze inne aspekty takie jak czytelność i jednolitość kodu wewnątrz \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; projektu oraz ogólne tendencje rozwoju języka i kompilatorów.

<br/>
<br/>

> **<sup>[1]</sup> Poziom Optymalizacji O3 dla kompilatora Clang:** \
> "Moderate level of optimization which enables optimizations that take longer to \
> perform or that may generate larger code (in an attempt to make the program run faster)." \
> <ins>`www.clang.llvm.org/docs/CommandGuide/clang.html`</ins>

<br/>

> **<sup>[2]</sup> Poziom Optymalizacji O3 dla kompilatora GCC:** \
> "optimization more for code size and execution time". \
> Wydłuża czas kompilacji (compile time), zmniejsza czas wykonania (execution time). \
> <ins>`www.rapidtables.com/code/linux/gcc/gcc-o.html`</ins>


<br/><br/>
-------------
### Akapit 3


<br/><br/>
-------------
![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
