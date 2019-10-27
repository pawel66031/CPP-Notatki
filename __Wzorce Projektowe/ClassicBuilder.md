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

![](https://github.com/Ptysiek/resources/blob/master/WzorceProjektowe/ClassicBuilderHD.png)

<br/>

**CLIENT**
- Wybiera i tworzy egzemplarz z grupy `Subjects{}`.
- Tworzy egzemplarz `Director`, \
któremu przypisuje utworzony wcześniej egzemplarz z grupy `Subjects{}`.
- Korzystając z `Director`, tworzy obiekt `Subject`.

**SUBJECTS{ }** 
- `SUBJECT_verA`, `SUBJECT_verB`, `...`
- Grupa
- Każdy wytwarza inną wersję tego samego Przedmiotu.

**BUILDER**
- Interfejs obiektów `Subjects{}`

**DIRECTOR**  - Wywołuje wybranego robotnika. Zwraca Przedmiot 

**SUBJECT**









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

