# Operatory
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Teorii]](#podsumowanie-classic-builder) \
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Praktyki]](#program-11--productfile--guitar) 

**Alternatywna Nawigacja:**  
&nbsp;&nbsp;&nbsp;&nbsp; - [link 1]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [link 2]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [link 3]()




<br/><br/>
-------------
### Operatory Logiczne
&nbsp;&nbsp;&nbsp;&nbsp; - Wykorzystywane przy zapytaniach warunkowych \
&nbsp;&nbsp;&nbsp;&nbsp; - Istnieją trzy operatory logiczne: **!**, **||**, **&&**. \
&nbsp;&nbsp;&nbsp;&nbsp; - Wszystkie trzy posiadają alternatywy nazewnicze w postaci: **not**, **or**, **and**.


<br/><br/>
-------------
### Operatory Logiczne - Negacja
&nbsp;&nbsp;&nbsp;&nbsp; - Jeden z trzech podstawowych operatorów logicznych. \
&nbsp;&nbsp;&nbsp;&nbsp; - Używamy jednym z dwóch możliwych operatorów: \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **(operator !)** lub **(operator not)**. 

&nbsp;&nbsp;&nbsp;&nbsp; - Właściwość logiczna: \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `Zwraca wartość` **`Przeciwną`** `do podanej.`
| a | !a |
|:-------------:|:-------------:|
| 0 | 1 |
| 1 | 0 |
```cpp
    bool a = true;

    if (a){
        // execute when a == true
    }

    if (!a){
        // execute when a == false
    }

    if (not a){
        // execute when a == false
    }

    if (not not a){
        // execute when a == true
    }
```


<br/><br/>
-------------
### Operatory Logiczne - Alternatywa
&nbsp;&nbsp;&nbsp;&nbsp; - Jeden z trzech podstawowych operatorów logicznych. \
&nbsp;&nbsp;&nbsp;&nbsp; - Używamy jednym z dwóch możliwych operatorów: \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **(operator ||)** lub **(operator or)**. 

&nbsp;&nbsp;&nbsp;&nbsp; - Właściwość logiczna: \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `Przynajmniej jeden z warunków musi być spełniony.`
| a | b | a \|\| b |
|:-------------:|:-------------:|:-------------:|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |
```cpp
    bool a = true;
    bool b = false;

    if (a || b){
        // ...
    }

    if (a or b){
        // ...
    }
```

<br/><br/>
-------------
### Operatory Logiczne - Koniunkcja
&nbsp;&nbsp;&nbsp;&nbsp; - Jeden z trzech podstawowych operatorów logicznych. \
&nbsp;&nbsp;&nbsp;&nbsp; - Używamy jednym z dwóch możliwych operatorów: \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **(operator &&)** lub **(operator and)**. 

&nbsp;&nbsp;&nbsp;&nbsp; - Właściwość logiczna: \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `Obydwa warunki muszą być spełnione jednocześnie.`
| a | b | a && b |
|:-------------:|:-------------:|:-------------:|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |
```cpp
    bool a = true;
    bool b = false;

    if (a && b){
        // ...
    }

    if (a and b){
        // ...
    }
```


<br/><br/>
-------------
### Akapit 1


Operator `sizeof` - zwraca wielkość typu w bajtach

napisz tutaj o pliku climits, prata strona 83-84
"producent kompilatora podaje taki plik, który prawidłowo opisuje dany kompilator.
Plik climits jest zbudowany z definicji typów:
#define int max 32767"

napisz przykład wykorzystania sizeof.



<br/><br/>
-------------
### Akapit 2


<br/><br/>
-------------
### Akapit 3


<br/><br/>
-------------
![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
