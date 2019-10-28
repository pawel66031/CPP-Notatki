# Builder

- Implementacja gotowych schematów do tworzenia różnych reprezentacji danego produktu.
- Odseparowanie procesu konstrukcji złożonego obiektu od jego reprezentacji. 
- Zmniejszenie ilości argumentów w konstruktorze.
- Wzorzec z grupy `Creational Patterns`.

<br/>

1. [Classic Builder](#1-Classic-Builder)
    - [Implementacja](#program-11--productfile--guitar) 
1. [Fluent Builder](#2-Fluent-Builder)

------------
<br/>

## 1. Classic Builder

<br/>

**PRODUCT**  \
&nbsp;&nbsp;&nbsp;&nbsp; Klasa obiektu wynikowego, konstruowanego przez wybranego *buildera*. 

&nbsp;&nbsp;&nbsp;&nbsp; *Builder* nie ma wpływu na funkcjonowanie *Produktu*. \
&nbsp;&nbsp;&nbsp;&nbsp; Możliwość modyfikacji *Produktu* bez ryzyka uszkodzenia *Buildera*.

&nbsp;&nbsp;&nbsp;&nbsp; *Product* nie posiada operacji konstruowania własnych instancji. \
&nbsp;&nbsp;&nbsp;&nbsp; Operacje te posiada *Builder*. *Builder* tworzy instancje klasy *Product*.

<br/>

**I_BUILDER** \


<br/>

**BUILDER** 


<br/>

**DIRECTOR** \


<br/>


**CLIENT**


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








###### [Program 1.1]  `Product.file` &nbsp;&nbsp;&nbsp;&nbsp; [Guitar]
```cpp
#pragma once


/** [class Product] **/
class Guitar{
public:
    Product(string name, string type, string neckMaterial, string soundboardMaterial)
           : name(name), type(type), neckMaterial(neckMaterial), soundboardMaterial(soundboardMaterial){ }

private: // [Product] Fields to initialize:    
    string name;
    string type;
    string neckMaterial;
    string soundboardMaterial;
    
private: // [Product] other Variables:
    // ...

public: // [Product] Operations:
    void MakeSound();
    void CrashSpeaker();
    void TuneTheStrings();
    void CheckSound();
}; 
```

###### [Program 1.2]  `I_Builder.file` &nbsp;&nbsp;&nbsp;&nbsp; [<< interface >>]
```cpp
#pragma once
#include "Product.file"


/** [<<interface>> Builder] **/
class I_Builder{
private: // Fields of [Product] to initialize:    
    string name;
    string type;
    string neckMaterial;
    string soundboardMaterial;

public: // [Builders] operations to construct the [Product]:
    virtual void GiveName() = 0;
    virtual void ClassifyType() = 0;
    virtual void ChooseNeckMaterial() = 0;
    virtual void ChooseSoundboardMaterial() = 0;
    
    virtual Guitar* GetResult() = 0;
}; 
```
###### [Program 1.3]  `Builder_A.file` &nbsp;&nbsp;&nbsp;&nbsp; [BrianMayGuitar_builder]
```cpp
#pragma once
#include "I_Builder.file"


/** [class Builder_A] **/
class BrianMayGuitar_builder : public I_Builder{

public: // [Builder_A] operations of [Product] construction:
    void GiveName(){ name = "Red Special Fireplace"; }
    void ClassifyType(){ type = "Semi-acoustic"; }
    void ChooseNeckMaterial(){ neckMaterial = "Mahogany"; }
    void ChooseSoundboardMaterial(){ soundboardMaterial = "Remains of an Oak table"; }    
    
    Guitar* GetResult(){ return new Guitar(name, type, neckMaterial, soundboardMaterial); }
};  
```
###### [Program 1.4]  `Builder_B.file` &nbsp;&nbsp;&nbsp;&nbsp; [LemmyKilmisterGuitar_builder]
```cpp
#pragma once
#include "I_Builder.file"


/** [class Builder_B] **/
class LemmyKilmisterGuitar_builder : public I_Builder{

public: // [Builder_B] operations of [Product] construction:
    void GiveName(){ name = "Lemmy Signature"; }
    void ClassifyType(){ type = "Bass"; }
    void ChooseNeckMaterial(){ neckMaterial = "Oak"; }
    void ChooseSoundboardMaterial(){ soundboardMaterial = "Oak"; }
    
    Guitar* GetResult(){ return new Guitar(name, type, neckMaterial, soundboardMaterial); }
}; 
```
###### [Program 1.5]  `Director.file`
```cpp
#pragma once
#include "I_Builder.file"


class Director{
public: 
    Director(I_Builder* _builder)
            : _builder(_builder){ }
      
public: // Variable:
    I_Builder* _builder;
    
public: // Methods:
    Guitar* ConstructGuitar(){
        _builder->GiveName();        
        _builder->ClassifyType();
        _builder->ChooseNeckMaterial();
        _builder->ChooseSoundboardMaterial();

        return _builder->GetResult();
    }
};
```
###### [Program 1.6]  `Client.file`
```cpp
#include "Product.file"     // Guitar
#include "Director.file"
#include "Builder_A.file"   // BrianMayGuitar_builder
#include "Builder_B.file"   // LemmyKilmisterGuitar_builder


int main(){

    Director BrianM(new FatASS);
    Director LemmyK(new(VegeASS));

    Guitar* myguitar;

    // Make guitar for Queen band:
    myguitar = BrianM.ConstructZestaw();
    
    // Make guitar for Motorhead band:
    myguitar = LemmyK.ConstructZestaw();

    return 0;
}
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
