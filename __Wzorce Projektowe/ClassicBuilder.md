# Classic Builder 
&nbsp;&nbsp;&nbsp;&nbsp; - *Creational Patterns* \
&nbsp;&nbsp;&nbsp;&nbsp; - Odseparowanie kodu *konstruującego produkt* od deklaracji klasy *Produktu*. \
&nbsp;&nbsp;&nbsp;&nbsp; - Podzielenie kodu *konstruującego produkt* na *Etapy*. \
&nbsp;&nbsp;&nbsp;&nbsp; - [[Do Implementacji]](#program-11--productfile--guitar) 

<br/><br/><br/>

**Zalety**:
* Odseparowanie *Procesu konstruowania produktów* od *Produktów*:
    * Możliwość tworzenia nowych konfiguracji danego produktu.
    * Wielokrotne wykorzystanie kodu konstruowania *Produktów*.
    * Zmniejszenie monstrualnej ilości argumentów w konstruktorze *Produktu*.
    <br/>
* Dzielenie *procesu konstruowania Produktów* na *Etapy*: 
    * Schludne konstruowanie złożonych *produktów* krok po kroku.
    * Bezpieczne modyfikowanie kodu wybranych *etapów*. 
    * Możliwość zmiany kolejności wywoływania etapów, w tym pomijanie i dodawanie etapów. 
    * Możliwość wywoływania wybranych etapów rekurencyjnie.
    <br/>
* Hermetyczność:
    * Odseparowanie *Procesu* konstruowania *Produktu*.
    * Odseparowanie konstruowanego *Produktu*, do momentu aż będzie gotowy i wykończony.
    
**Wady**:
* Rozrastanie się struktury projektu o nowe pliki.

<br/><br/><br/>

**Powiązane Patterny:**  
   - [ ] [Fluent Builder](#2-Fluent-Builder) 
   - [ ] [Singleton](#2-Fluent-Builder) 
   - [ ] [Bridge](#2-Fluent-Builder)

------------
<br/>

**PRODUCT**  \
&nbsp;&nbsp;&nbsp;&nbsp; Klasa obiektu wynikowego, konstruowanego przez wybranego *buildera*. 

&nbsp;&nbsp;&nbsp;&nbsp; *Builder* nie ma wpływu na funkcjonowanie *Produktu*. \
&nbsp;&nbsp;&nbsp;&nbsp; Możliwość modyfikacji *Produktu* bez ryzyka uszkodzenia *Buildera*.

&nbsp;&nbsp;&nbsp;&nbsp; *Product* nie posiada operacji konstruowania własnych instancji. \
&nbsp;&nbsp;&nbsp;&nbsp; Operacje te posiada *Builder*. Operacje *Buildera* tworzą instancje klasy *Product*.

&nbsp;&nbsp;&nbsp;&nbsp; *Produkty* tworzone przez różne *Buildery* nie muszą przynależeć do tej samej klasy.

<br/>

**I_BUILDER** \
&nbsp;&nbsp;&nbsp;&nbsp; Interfejs wszystkich builderów konstruujących *Produkt*. \
&nbsp;&nbsp;&nbsp;&nbsp; Posiada wirtualne operacje tworzenia *Produktu*. \
&nbsp;&nbsp;&nbsp;&nbsp; Najważniejszą z nich jest `virtual Product GetResult() = 0;`.

<br/>

**BUILDER** \
&nbsp;&nbsp;&nbsp;&nbsp; Każdy *Builder* posiada implementacje własnych etapów konstruowania *Produktu*. \
&nbsp;&nbsp;&nbsp;&nbsp; Mogą tworzyć różne *Produkty* tymi samymi etapami konstrukcji.

&nbsp;&nbsp;&nbsp;&nbsp; Implementacje tych etapów nie muszą pokrywać się z operacjami interfejsu `I_Builder`. \
&nbsp;&nbsp;&nbsp;&nbsp; *Buildery* nie wywołują własnych operacji. Zajmuje się tym *Director* lub *Client*.

<br/>

**DIRECTOR** \
&nbsp;&nbsp;&nbsp;&nbsp; Zarządza obecnie przypisanym mu *Builderem*. \
&nbsp;&nbsp;&nbsp;&nbsp; Wie jak wywoływać operacje *Buildera*, aby powstał *Produkt*.

&nbsp;&nbsp;&nbsp;&nbsp; Pozwala na dodatkowe konfiguracje konstruowania *Produktu*. \
&nbsp;&nbsp;&nbsp;&nbsp; Może posiadać więcej niż jedną operację wytworzenia *Produktu*. \

&nbsp;&nbsp;&nbsp;&nbsp; Ukrywa szczegóły konstruowania *Produktu*. \
&nbsp;&nbsp;&nbsp;&nbsp; Nie jest wymagany.

<br/>

**CLIENT** \
&nbsp;&nbsp;&nbsp;&nbsp; Przypisuje *Buildera* do *Directora*. \
&nbsp;&nbsp;&nbsp;&nbsp; Wywołuje jedną z operacji konstruowania produktu *Directora*. \
&nbsp;&nbsp;&nbsp;&nbsp; Odbiera *Produkt Wynikowy* od *Buildera*.

------------
<br/>

###### [Program 1.1]  `Product.file` &nbsp;&nbsp;&nbsp;&nbsp; [Guitar]
```cpp
#pragma once


/** [class Product] **/
class Guitar{
public:
    Guitar(string name, string type, string neckMaterial, string soundboardMaterial)
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
public:
    virtual ~I_Builder(){ }
    
protected: // Fields of [Product] to initialize:    
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
public: // Constructor / Destructor
    Director(){ }

    Director(I_Builder* _builder): _builder(_builder){ }

    ~Director(){ delete (this->_builder); }

public: // Operator () override
    void operator() (I_Builder* _builder){
        if (_builder){
            delete (this->_builder);
            this->_builder = _builder;
        }
    }

public: // Variable:
    I_Builder* _builder = 0;

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

    Director director;
    Guitar* myguitar;

    // Make guitar for Queen band:
    director(new BrianMayGuitar_builder);
    Guitar* rockmanGuitar = director.ConstructGuitar();

    // Make guitar for Motorhead band:
    director(new LemmyKilmisterGuitar_builder);
    Guitar* metalheadGuitar = director.ConstructGuitar();
    
    // And one for me:
    myguitar = director.ConstructGuitar();
    
    return 0;
}

```  
------------

<br/>

**Powiązane Patterny:**  
   - [ ] [Fluent Builder](#2-Fluent-Builder) 
   - [ ] [Singleton](#2-Fluent-Builder) 
   - [ ] [Bridge](#2-Fluent-Builder)

<br/>

![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
