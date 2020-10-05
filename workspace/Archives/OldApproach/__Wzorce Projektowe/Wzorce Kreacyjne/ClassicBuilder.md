![](https://github.com/Ptysiek/resources/blob/master/WzorceProjektowe/ClassicBuilder/ClassicBuilder.png)

<br/>
<br/>
<br/>

# Classic Builder 
&nbsp;&nbsp;&nbsp;&nbsp; - [[Do Podsumowania]](#podsumowanie-classic-builder) \
&nbsp;&nbsp;&nbsp;&nbsp; - [[Do Implementacji]](#program-11--productfile--guitar) 

**Powiązane Patterny:**  
&nbsp;&nbsp;&nbsp;&nbsp; - [Fluent Builder](https://github.com/Ptysiek/CPP-Notatki/blob/master/__Wzorce%20Projektowe/FluentBuilder.md) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Singleton](#2-Fluent-Builder) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Bridge](#2-Fluent-Builder)

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
Builder jest wzorcem do tworzenia obiektów o złożonej budowie oraz różnorodnych konfiguracjach powstawania. \
Polega on na odseparowaniu _Procesu Konstruowania Obiektów_ od ich implementacji. \
`Dodatkowo dzięki temu unikamy sytuacji w których obiekty tworzą same siebie.`

_Konstruowanie Obiektów_ polega na wykonywaniu ustalonej sekwecji _Etapów_. \
Podział _Procesu Konstrukcji_ na _Etapy_ pozwala na: \
&nbsp;&nbsp;&nbsp;&nbsp; - Napisanie nowych etapów bez wpływu na istniejące. \
&nbsp;&nbsp;&nbsp;&nbsp; - Modyfikację etapów bez wpływu na inne etapy. \
&nbsp;&nbsp;&nbsp;&nbsp; - Zmianę ilości wykonywanych etapów. \
&nbsp;&nbsp;&nbsp;&nbsp; - Zmianę kolejności wykonywania etapów. \
`Wszystkie te cechy pozwalają na łatwą zmianę konfiguracji powstających obiektów.`

**Dodatkowe zastosowania**: \
&nbsp;&nbsp;&nbsp;&nbsp; - Możliwość zmniejszenia ilości argumentów w konstruktorze. \
&nbsp;&nbsp;&nbsp;&nbsp; - Możliwość wykonywania wybranych _Etapów_ rekurencyjnie.

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
**PRODUCT**  \
&nbsp;&nbsp;&nbsp;&nbsp; Klasa obiektu wynikowego, konstruowanego przez wybranego *buildera*. 

&nbsp;&nbsp;&nbsp;&nbsp; *Builder* nie ma wpływu na funkcjonowanie *Produktu*. \
&nbsp;&nbsp;&nbsp;&nbsp; Możliwość modyfikacji *Produktu* bez ryzyka uszkodzenia *Buildera*.

&nbsp;&nbsp;&nbsp;&nbsp; *Product* nie posiada operacji konstruowania własnych instancji. \
&nbsp;&nbsp;&nbsp;&nbsp; Operacje te posiada *Builder*. Operacje *Buildera* tworzą instancje klasy *Product*.

&nbsp;&nbsp;&nbsp;&nbsp; *Produkty* tworzone przez różne *Buildery* nie muszą przynależeć do tej samej klasy. 

<br/>
<br/>

**I_BUILDER** \
&nbsp;&nbsp;&nbsp;&nbsp; Interfejs wszystkich builderów konstruujących *Produkt*. \
&nbsp;&nbsp;&nbsp;&nbsp; Posiada wirtualne operacje tworzenia *Produktu*. \
&nbsp;&nbsp;&nbsp;&nbsp; Najważniejszą z nich jest `virtual Product GetResult() = 0;`. \
![](https://github.com/Ptysiek/resources/blob/master/WzorceProjektowe/ClassicBuilder/I_Builder.png)

<br/>
<br/>

**BUILDER** \
&nbsp;&nbsp;&nbsp;&nbsp; Każdy *Builder* posiada implementacje własnych etapów konstruowania *Produktu*. \
&nbsp;&nbsp;&nbsp;&nbsp; Mogą tworzyć różne *Produkty* tymi samymi etapami konstrukcji.

&nbsp;&nbsp;&nbsp;&nbsp; Implementacje tych etapów nie muszą pokrywać się z operacjami interfejsu `I_Builder`. \
&nbsp;&nbsp;&nbsp;&nbsp; *Buildery* nie wywołują własnych operacji. Zajmuje się tym *Director* lub *Client*. \
![](https://github.com/Ptysiek/resources/blob/master/WzorceProjektowe/ClassicBuilder/Builders.png) 

<br/>
<br/>

**DIRECTOR** \
&nbsp;&nbsp;&nbsp;&nbsp; Zna sekwencje tworzenia **Produktu**. \
&nbsp;&nbsp;&nbsp;&nbsp; Wie jakie, i w jakiej kolejności wywoływać **Etapy** tworzenia **Produktu**.

&nbsp;&nbsp;&nbsp;&nbsp; Nie Wie na czym polegają etapy. \
&nbsp;&nbsp;&nbsp;&nbsp; Nie musi wiedzieć ponieważ przypisujemy mu **Buildera** o własnej wiedzy jak wykonywać dany etap. 

&nbsp;&nbsp;&nbsp;&nbsp; Pozwala na dodatkowe konfiguracje konstruowania *Produktu*. \
&nbsp;&nbsp;&nbsp;&nbsp; Może posiadać więcej niż jedną operację wytworzenia *Produktu*. 

&nbsp;&nbsp;&nbsp;&nbsp; Ukrywa szczegóły konstruowania *Produktu*. \
&nbsp;&nbsp;&nbsp;&nbsp; Nie jest wymagany. 

<br/>
<br/>

**CLIENT** \
&nbsp;&nbsp;&nbsp;&nbsp; Przypisuje *Buildera* do *Directora*. \
&nbsp;&nbsp;&nbsp;&nbsp; Wywołuje jedną z operacji konstruowania produktu *Directora*. \
&nbsp;&nbsp;&nbsp;&nbsp; Odbiera *Produkt Wynikowy* od *Buildera*. \
![](https://github.com/Ptysiek/resources/blob/master/WzorceProjektowe/ClassicBuilder/Client.png) 

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
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

    // Make guitar for Queen band:
    director(new BrianMayGuitar_builder);
    Guitar* rockmanGuitar = director.ConstructGuitar();

    // Make guitar for Motorhead band:
    director(new LemmyKilmisterGuitar_builder);
    Guitar* metalheadGuitar = director.ConstructGuitar();
    
    // And one for me: [same as for motorhead]
    Guitar* myguitar = director.ConstructGuitar();
    
    return 0;
}

```  

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
### Podsumowanie [Classic Builder]
&nbsp;&nbsp;&nbsp;&nbsp; - _Wzorzec Kreacyjny_ [ang. Creational Patterns] \
&nbsp;&nbsp;&nbsp;&nbsp; - Odseparowanie *Procesu konstruowania produktów* od *Produktów* \
&nbsp;&nbsp;&nbsp;&nbsp; - Podział _Procesu konstruowania produktów_ na _Etapy_. \
&nbsp;&nbsp;&nbsp;&nbsp; - Zmniejszenie monstrualnej ilości argumentów w konstruktorze _Produktu_.

<br/>

**Zalety**: \
&nbsp;&nbsp;&nbsp;&nbsp; - Hermetyczność kodu. \
&nbsp;&nbsp;&nbsp;&nbsp; - Wielokrotne wykorzystanie kodu. \
&nbsp;&nbsp;&nbsp;&nbsp; - Zwiększenie czytelności kodu. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (Możliwość schludnego konstruowania złożonych _produktów_ etap po etapie). \
&nbsp;&nbsp;&nbsp;&nbsp; - Znaczne zwiększenie elastyczności kodu. \
&nbsp;&nbsp;&nbsp;&nbsp; - Unikamy obiektów tworzących samych siebie.

<br/>

**Wady**: \
&nbsp;&nbsp;&nbsp;&nbsp; - Rozrastanie się struktury projektu o nowe pliki.

<br/>
<br/>
<br/>

![](https://github.com/Ptysiek/resources/blob/master/Orn.png)
![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)