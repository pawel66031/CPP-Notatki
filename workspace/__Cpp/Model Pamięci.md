# Model Pamięci

&nbsp;&nbsp;&nbsp;&nbsp; - Pamięć programu trzymającą dane dzielimy na cztery rodzaje: \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Pamięć automatyczna](#1-pamięć-automatyczna) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Pamięć statyczna](#2-pamięć-statyczna) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Pamięć wątku](#3-pamięć-wątku) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Pamięć dynamiczna](#4-pamięć-dynamiczna) 

&nbsp;&nbsp;&nbsp;&nbsp; - Od sposobu trzymania danych zależy ich: \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - czas życia \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - zasięg nazwy [scope] \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - sposób współużytkowania [linkage]

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
### 1. Pamięć automatyczna
Pamięć automatyczna dotyczy obiektów powstających wewnątrz **bloku instrukcji**, \
czyli fragmentu kodu zamkniętego klamrami [brackets]. Funkcje, pętle, samodzielny blok, etc. \
Dotyczy to również argumentów funkcji. Wszystkie argumenty zawsze są obiektami automatycznymi.

<br/>

***czas życia*** \
Pamięć automatyczna działa za pomocą stosu. [LIFO] \
Oznacza to że obiekty powstające w danym bloku instrukcji \
są niszczone w momencie gdy program go opuszcza. [czas życia bloku instrukcji] \
`Zwolnienie zarezerwowanej pamięci nie oznacza jej wyczyszczenia.`

<br/>

***zasięg nazwy [scope]*** \
Lokalny, widoczny jedynie w bloku zawierającym \
definicję danego obiektu, od miejsca deklaracji obiektu.

Pojęcie: *ukrycia nazwy* / *przesłonięcia nazwy* \
&nbsp;&nbsp;&nbsp;&nbsp; Zasięg lokalny posiada pierwszeństwo przed innymi zasięgami.\
&nbsp;&nbsp;&nbsp;&nbsp; Oznacza to że w sytuacji gdy występują dwa obiekty o takiej samej nazwie, \
&nbsp;&nbsp;&nbsp;&nbsp; to kompilator albo cię ostrzeże o niejednoznaczności nazw, albo skorzysta z lokalnego obiektu.

<br/>

***sposób współużytkowania [linkage]*** \
Obiekty automatyczne nie posiadają łączenia. \
Oznacza to że mogą być używane tylko i wyłącznie lokalnie.

<br/>

***zmienne rejestrowe*** \
Zmienne rejestrowe to drugi rodzaj zmiennych automatycznych. \
Obecnie - w wyniku rozwoju oraz optymalizacji języka - przestarzały. \
Specyfikator __register__  określał jawne zdefiniowanie obiektu w pamięci automatycznej. \
`Dzisiaj - o ile nie nakażemy inaczej - wszystkie obiekty zdefiniowane wewnątrz` \
`bloku instrukcji zostaną utworzone w pamięci automatycznej.` \
`Sam specyfikator niemalże przestał mieć wpływ na działanie kompilatora.`

Obecnie, zastosowanie specyfikatora __register__ ograniczyło się do podkreślenia przez programistę informacji: \
&nbsp;&nbsp;&nbsp;&nbsp; - istnieje inny obiekt zewnętrzny o takiej samej nazwie. \
&nbsp;&nbsp;&nbsp;&nbsp; - ten obiekt jest, pod względem optymalności, punktem krytycznym danego bloku instrukcji.

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
### 2. Pamięć statyczna

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

