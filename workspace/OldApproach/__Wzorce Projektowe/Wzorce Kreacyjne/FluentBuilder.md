# Fluent Builder 
&nbsp;&nbsp;&nbsp;&nbsp; - *Creational Patterns*

<br/>

**Powiązane Patterny:**  
   - [X] [Classic Builder](https://github.com/Ptysiek/CPP-Notatki/blob/master/__Wzorce%20Projektowe/ClassicBuilder.md) 

------------
<br/>

**Classic Fluent Builder** \
&nbsp;&nbsp;&nbsp;&nbsp; Odzielna klasa 

<br/>

**Inner Static Fluent Builder**  \
&nbsp;&nbsp;&nbsp;&nbsp; Umieszczamy go w klasie *Produktu* jako zagnieżdżoną klasę statyczną.

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
   - [X] [Classic Builder](https://github.com/Ptysiek/CPP-Notatki/blob/master/__Wzorce%20Projektowe/ClassicBuilder.md) 
   - [ ] [Singleton](#2-Fluent-Builder) 
   - [ ] [Bridge](#2-Fluent-Builder)

<br/>

![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)