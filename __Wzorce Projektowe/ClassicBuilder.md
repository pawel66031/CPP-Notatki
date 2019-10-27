# Builder

- Tworzenie tym samym  

- Tworzenie różnych reprezentacji danego produktu .
- Odseparowanie konstrukcji złożonego obiektu od jego reprezentacji. 
- Zmniejszenie ilości argumentów w konstruktorze
- `Wzorzec Kreacyjny` 

<br/>

1. [Classic Builder](#1-Classic-Builder) 
        
1. [Fluent Builder](#2-Fluent-Builder)

------------
<br/>


SUBJECT


**CLIENT**
- Wybiera i tworzy egzemplarz z grupy zbiorów `Subjects`.
- Tworzy egzemplarz zbioru `Director`, \
któremu przypisuje utworzony wcześniej egzemplarz z grupy `Subjects`.
- Korzystając z `Director`, tworzy obiekt `Subject`.

BUILDER 
- Interfejs przedmiotu `Subject`

SUBJECTS: 
- `SUBJECT_verA`, `SUBJECT_verB`, `...`

SUBJECT_A  - każdy wykonuje inną wersję tego samego Przedmiotu.
SUBJECT_B
SUBJECT_C
SUBJECT_D 

DIRECTOR  - Wywołuje wybranego robotnika. Zwraca Przedmiot 



![](https://github.com/Ptysiek/resources/blob/master/WzorceProjektowe/ClassicBuilderHD.png)






#### 1. Classic Builder
###### [Program 1.1] `operator[ ]` `.size( )` `.capacity( )`
```cpp
 
```

<br/>

#### 2. Fluent Builder
```cpp
 
```

------------
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)

