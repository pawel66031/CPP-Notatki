# Rodzaje Pamięci - Kategoryzacja Obiektów

&nbsp;&nbsp;&nbsp;&nbsp; - Rozróżniamy cztery sposoby trzymania danych przez program: \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Pamięć automatyczna](#1-pamięć-automatyczna) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Pamięć statyczna](#2-pamięć-statyczna) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Pamięć wątku](#3-pamięć-wątku) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Pamięć dynamiczna](#4-pamięć-dynamiczna) 

&nbsp;&nbsp;&nbsp;&nbsp; - Od sposobu trzymania danych zależy: \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - czas życia danych [ang. lifetime] \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - sposób współużytkowania [ang. linkage] \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - zasięg nazwy [ang. scope]

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
### Tworzenie i Niszczenie Obiektów w Modelu Pamięci 
Tworząc nowy obiekt program rezerwuje dla niego przedział pamięci o określonym rozmiarze. \
W danym przedziale trzymana jest obecna wartość danego obiektu. 

Zniszczenie obiektu polega na zwolnieniu przez program zarezerwowanej dla obiektu pamięci. 

Wartości trzymane w danym miejscu nie są modyfikowane podczas zwalaniania. \
Oznacza to że w danym przedziale, albo w jego fragmencie, program może tworzyć nowe obiekty. 

Nie zainicjalizowanie wartości nowych obiektów skutkuje \
trzymaniem starych wartości już nie istniejących obiektów. \
Przy czym program dobiera przedziały na nowe obiekty bez naszej wiedzy. \
Dlatego zakładamy że obiekty bez zainicjalizowanej wartości trzymają \
w sobie nieprzewidywalne dane z których nie ma sensu korzystać.

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
### 1. Pamięć automatyczna
Pamięć automatyczna dotyczy obiektów powstających wewnątrz **bloku instrukcji**, \
czyli fragmentu kodu zamkniętego klamrami [ang. brackets]. Funkcje, pętle, samodzielny blok, etc. \
Dotyczy to również argumentów funkcji. Wszystkie argumenty zawsze są obiektami automatycznymi.

<br/>

***czas życia [lifetime]*** \
Pamięć automatyczna działa za pomocą stosu. [LIFO - ang. LastInFirstOut] \
Oznacza to że obiekty powstające w danym bloku instrukcji \
są niszczone w momencie gdy program go opuszcza. [czas życia bloku instrukcji] \
`Zwolnienie zarezerwowanej pamięci nie oznacza jej wyczyszczenia.` [|Up|](#tworzenie-i-niszczenie-obiektow-w-modelu-pamieci) 

<br/>

***sposób współużytkowania [linkage]*** \
Obiekty automatyczne nie posiadają łączenia. \
Oznacza to że mogą być używane tylko i wyłącznie lokalnie.

<br/>

***zasięg nazwy [scope]*** \
Lokalny - widoczny jedynie w bloku zawierającym \
definicję danego obiektu, od miejsca deklaracji obiektu.

Pojęcie: *`przesłonięcia nazw`* / *`ukrycia nazw`* : \
&nbsp;&nbsp;&nbsp;&nbsp; __Zasięg lokalny posiada pierwszeństwo przed innymi zasięgami__. \
&nbsp;&nbsp;&nbsp;&nbsp; W sytuacji gdy występują dwa obiekty o takiej samej nazwie \
&nbsp;&nbsp;&nbsp;&nbsp; kompilator albo ostrzeże o niejednoznaczności nazw, albo skorzysta z lokalnego obiektu.

<br/>

***zmienne rejestrowe*** \
Zmienne rejestrowe to drugi rodzaj zmiennych automatycznych. \
Obecnie - w wyniku rozwoju oraz optymalizacji języka - przestarzały. \
Specyfikator __register__  określał jawne zdefiniowanie obiektu w pamięci automatycznej. 

Dzisiaj - o ile nie nakażemy inaczej - wszystkie obiekty zdefiniowane wewnątrz \
bloku instrukcji zostaną utworzone w pamięci automatycznej. \
Sam specyfikator niemalże przestał mieć wpływ na działanie kompilatora. \
&nbsp;&nbsp;&nbsp;&nbsp; Kiedyś opisane wyżej działanie posiadał specyfikator __auto__. \
&nbsp;&nbsp;&nbsp;&nbsp; Nowe, zupełnie inne zastosowanie specyfikatora: [*auto*]().

Obecnie, zastosowanie specyfikatora __register__ ograniczyło się do podkreślenia przez programistę informacji: \
&nbsp;&nbsp;&nbsp;&nbsp; - istnieje inny obiekt zewnętrzny(nie lokalny) o takiej samej nazwie. \
&nbsp;&nbsp;&nbsp;&nbsp; - ten obiekt jest, pod względem optymalności, punktem krytycznym danego bloku instrukcji.

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
### 2. Pamięć statyczna
Obiekty statyczne istnieją w specjalnie przygotowanym bloku pamięci o stałym rozmiarze. \
Liczba obiektów statycznych nie zmienia się w trakcie działania programu. 

Pojęcie: *inicjalizacji zerami* [*zero-initialized*] \
&nbsp;&nbsp;&nbsp;&nbsp; - Przy braku jawnej inicjalizacji obiektów statycznych kompilator inicjalizuje je wartością _Zero_. \
&nbsp;&nbsp;&nbsp;&nbsp; - Dotyczy to również typów złożonych np tablica, struktura. Wszystkie bity obiektu są ustawiane na _Zero_.

<br/>

***czas życia [lifetime]*** \
Czas życia równy czasowi wykonywania programu: \
&nbsp;&nbsp;&nbsp;&nbsp; - obiekty statyczne powstają na etapie uruchamiania programu. \
&nbsp;&nbsp;&nbsp;&nbsp; - zostają niszczone w momencie jego zamknięcia. 

<br/>

***sposób współużytkowania [linkage]*** \
Rozróżniamy trzy odmiany łączenia obiektów statycznych. \
Obiekty z każdej z odmian posiadają inny ***zasięg nazwy [scope]***.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  ***łączenie zewnętrzne*** - zmienne zewnętrzne \
&nbsp;&nbsp;&nbsp;&nbsp; - Obiekt zadeklarowany poza blokiem kodu instrukcji. \
&nbsp;&nbsp;&nbsp;&nbsp; - Nazwa obiektu posiada __zasięg pliku__ od miejsca deklaracji. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Jest dostępna w każdym bloku kodu poniżej deklaracji obiektu. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Gdy dany blok posiada zmienną lokalną o takiej samej nazwie, \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; która _przesłania_ nam nazwę naszego globalnego obiektu, \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; wtedy możemy wskazać jawnie na obiekt globalny. &nbsp;&nbsp;&nbsp;&nbsp; [*operator zasięgu : :*]()
``` cpp
    int val = -1;
    // ... more code

    void Fun(int val){    
        val *= 2;       // Local object modification
        ::val += 10;    // Global object modification
    }
```

dostęp między plikami \
&nbsp;&nbsp;&nbsp;&nbsp; Obiekt zadeklarowany 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  ***łączenie wewnętrzne*** - dostęp z funkcji \
&nbsp;&nbsp;&nbsp;&nbsp; Obiekt zadeklarowany poza blokiem kodu z specyfikatorem _static_. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  ***brak łączenia*** \
&nbsp;&nbsp;&nbsp;&nbsp; - Obiekt zadeklarowany wewnątrz bloku instrukcji z specyfikatorem _static_. \
&nbsp;&nbsp;&nbsp;&nbsp; - Nazwa obiektu posiada __zasięg lokalny__ bloku instrukcji od miejsca deklaracji. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; W przeciwieństwie do zmiennych automatycznych, wartość tego obiektu nie ulegnie \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; zniszczeniu po przekroczeniu danego bloku. Przykładowo, zmienna statyczna int _counter_, \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; inkrementująca swoją wartość ilekroć wywołamy funkcję w której się znajduje, \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; będzie zwiększać o jeden wartość zachowaną z poprzedniego wywołania funkcji. \
``` cpp
    void Fun(){
        static int counter = 0;     // Initialization with zero value occurs only 
                                    // once while starting the program. 
        // ... more code

        // COUNTER stores the number of times that 
        // this Fun() function has been completed to the end: 
        ++counter;
        return;
    }
```
<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
### 3. Pamięć wątku

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
### 4. Pamięć dynamiczna

<br/>

------------
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)

