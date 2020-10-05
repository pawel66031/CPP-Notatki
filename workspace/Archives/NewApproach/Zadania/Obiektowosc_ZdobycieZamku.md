# Zdobycie Zamku <br/> Zadanie z kategorii: Obiektowe
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Teorii]]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Praktyki]]() 

**Alternatywna Nawigacja:**  
&nbsp;&nbsp;&nbsp;&nbsp; - [link 1]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [link 2]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [link 3]()




<br/><br/>
-------------
### Wstęp
&nbsp; Zadanie ma na celu przećwiczenie projektowania klas oraz zagadnień paradygmatu obiektowego. \
&nbsp; Pod każdym poleceniem znajduje się propozycja implementacji od Autora. \
&nbsp; Zapoznanie się z propozycjami nie jest obowiązkowe. Są one jedynie dodatkiem.

&nbsp; Dla zwiększenia czytelności, każda wzmianka o dowolnej klasie zamyka jej nazwę wewnątrz `takiego` bloczku. \
&nbsp; Przykład: `Skarb` trzymany jest wewnątrz `Zamku`. Może oznaczać taką implementacje:
```cpp
class Gold { 
private: // Fields:
    int m_value;
};

class Castle {
private: // Fields:
    Gold m_treasure;
};
```

<br/><br/>
-------------
### [1] Napisz Klasę Zamek 
&nbsp;&nbsp;&nbsp;&nbsp; - Funkcją `Zamku` jest obrona trzymanego wewnątrz skarbu. \
&nbsp;&nbsp;&nbsp;&nbsp; - Musi on posiadać w sobie `Skarb` oraz jakieś `Fortyfikacje`.

<br/>

###### Skarb:
```cpp
class Gold { 
private: // Fields:
    int m_value;
};
```

<br/>

###### Mur:
```cpp
class Wall { 
    std::array<int> blocks;
};
```

<br/>

###### Zamek:
```cpp
class Castle { 
public: // Operations:
    int TryAcquireTreasure();

private: // Fields:
    Gold m_treasure;
    Wall m_wall;
};
```

<br/><br/>
-------------
### [2] Napisz Klasę Która Pomoże Nam Zdobyć Skarb 
&nbsp;&nbsp;&nbsp;&nbsp; - . \
&nbsp;&nbsp;&nbsp;&nbsp; - .


###### Katapulta: (Niszczy Mur)
```cpp
class Catapult {     
};
```



<br/><br/>
-------------
![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
