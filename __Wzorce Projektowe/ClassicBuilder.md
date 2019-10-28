# Builder

- Implementacja gotowych schematów do tworzenia różnych reprezentacji danego produktu.
- Odseparowanie procesu konstrukcji złożonego obiektu od jego reprezentacji. 
- Zmniejszenie ilości argumentów w konstruktorze.
- Wzorzec z grupy `Creational Patterns`.

<br/>

1. [Classic Builder](#1-Classic-Builder)
    - [Implementacja](#program-11--productfile) 
1. [Fluent Builder](#2-Fluent-Builder)

------------
<br/>

### 1. Classic Builder

<br/>

---
**Product** \
*pola:* \
    - q \
    - a \
*operacje:* \
    - q \
    - a

 
<br/>

- **SUBJECT**
    - **Przedmiot** będący wynikiem działania wzorca `Classic Builder` 
    - Niezależny od reszty wzorca. Można rozpruć builder bez uszkodzenia klasy.
- **BUILDER**
    - **Interfejs** obiektów `Subjects{}`.
    - Posiada wszystkie inicjowane pola zbioru `Subject`, \
    oraz wirtualne metody do ich ustawiania. 
    - **Nie** posiadaja operacji klasy `Subject`**!**
- **SUBJECTS { }**
    - Grupa **Robotników** { \
    `SUBJECT_verA`, \
    `SUBJECT_verB`, \
    `SUBJECT_verC`, `...` }.
    - Każdy **Robotnik** wytwarza własną, niepowtarzalną wersję *przedmiotu* `Subject`. 
    - **Robotnicy** dostają polecenia od kierownika `Director` do którego są przypisani.
    - Utworzony *przedmiot* jest zwracany przez metodę `GetResult() : Subject`.
    - Robotnicy **Nie** posiadają operacji klasy `Subject`**!**
- **DIRECTOR**  
    - Zarządza obecnie przypisanym mu *robotnikiem*.
    - Wydaje polecenia, w celu utworzenia przedmiotu `Subject`.
    - Może posiadać więcej niż jedną operację wytworzenia przedmiotu.
- **CLIENT**
    - Tworzy jednego *robotnika* z grupy `Subjects{}`.
    - Tworzy egzemplarz `Director`, któremu \
    przypisuje wcześniej wybrany egzemplarz *robotnika*.
    - Korzystając z `Director`, tworzy obiekt wynikowy, `Subject`.


###### [Program 1.1]  `Product.file`
```cpp
#pragma once

#include<string>
using std::string;


class Product{
public:
    Product(int width, int height, int depth, string material, string name)
           : width(width), height(height), depth(depth), material(material), name(name){ }

private: // [Product] Fields to initialize:
    int width;
    int height;
    int depth;
    string material;
    string name;

public: // [Product] Operations:
    string Show();

    void Walk();
    void Fly();
    void Cook();
    void Draw();
};
```
###### [Program 1.2]  `Builder.file` [*InterfejsRobotników*]
```cpp
 
```
###### [Program 1.3]  `Subject_verA.file` [*Robotnik*]
```cpp
 
```
###### [Program 1.4]  `Director.file` [*InstruujeRobotników*]
```cpp
 
```
###### [Program 1.5]  `Client.file` [UżywaWzorcaProjektowego*]
```cpp
 
```
<br/>

### 2. Fluent Builder

<br/>

###### [Program 2.1]
```cpp
 
```

------------
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
