# Typy Danych
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Teorii]]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Praktyki]]() 

**Alternatywna Nawigacja:**  
&nbsp;&nbsp;&nbsp;&nbsp; - [Typy Podstawowe](https://github.com/Ptysiek/CPP-Notatki/blob/master/workspace/NewApproach/TypyDanych.md#typy-podstawowe---całkowitoliczbowe) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Całkowitoliczbowe](https://github.com/Ptysiek/CPP-Notatki/blob/master/workspace/NewApproach/TypyDanych.md#typy-podstawowe---całkowitoliczbowe) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Zmiennoprzecinkowe](https://github.com/Ptysiek/CPP-Notatki/blob/master/workspace/NewApproach/TypyDanych.md#typy-podstawowe---zmiennoprzecinkowe) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Typ Logiczny - Bool](https://github.com/Ptysiek/CPP-Notatki/blob/master/workspace/NewApproach/TypyDanych.md#typy-podstawowe---typ-logiczny) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Typ Znakowy - Char](https://github.com/Ptysiek/CPP-Notatki/blob/master/workspace/NewApproach/TypyDanych.md#typy-podstawowe---typ-znakowy) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Typy Złożone](https://github.com/Ptysiek/CPP-Notatki/blob/master/workspace/NewApproach/TypyDanych.md#typy-złożone) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Typ Pusty - Void](https://github.com/Ptysiek/CPP-Notatki/blob/master/workspace/NewApproach/TypyDanych.md#typ-pusty---void) 

<br/><br/>
-------------
### Typy Podstawowe - Całkowitoliczbowe
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **short** \
&nbsp;&nbsp;&nbsp;&nbsp; - przynajmniej 16bitów, 2bajty. \
&nbsp;&nbsp;&nbsp;&nbsp; - pełna nazwa: [ang.] Short Integer - Krótka liczba całkowita.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **int** \
&nbsp;&nbsp;&nbsp;&nbsp; - przynajmniej 16bitów, 2bajty. \
&nbsp;&nbsp;&nbsp;&nbsp; - rozmiar nie mniejszy niż short oraz nie większy niż long. short <= int <= long \
&nbsp;&nbsp;&nbsp;&nbsp; - pełna nazwa: [ang.] Integer - Liczba całkowita.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **long** \
&nbsp;&nbsp;&nbsp;&nbsp; - przynajmniej 32bity, 4bajty. \
&nbsp;&nbsp;&nbsp;&nbsp; - rozmiar nie mniejszy niż typ int. int <= long \
&nbsp;&nbsp;&nbsp;&nbsp; - pełna nazwa: [ang.] Long Integer - Długa liczba całkowita.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **long long** \
&nbsp;&nbsp;&nbsp;&nbsp; - przynajmniej 64bity, 8bajtów. \
&nbsp;&nbsp;&nbsp;&nbsp; - rozmiar nie mniejszy niż typ long. long <= long long.

<br/><br/>
-------------
### Typy Podstawowe - Zmiennoprzecinkowe
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **float** \
&nbsp;&nbsp;&nbsp;&nbsp; - zwykle 32bity, 4bajty.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **double** \
&nbsp;&nbsp;&nbsp;&nbsp; - zwykle 64bity, 8bajtów. \
&nbsp;&nbsp;&nbsp;&nbsp; - pełna nazwa: [ang.] Double Precision.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **long double** \
&nbsp;&nbsp;&nbsp;&nbsp; - zwykle 80bitów, 10bajtów. 

<br/>

&nbsp;&nbsp;&nbsp;&nbsp; - Typy zmiennoprzecinkowe nie posiadają wersji z specyfikatorem ***unsigned***. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Zawsze mogą trzymać ujemne wartości. \
&nbsp;&nbsp;&nbsp;&nbsp; - Zmienne typów zmiennoprzecinkowych mogą trzymać jedną z 4 specjalnych wartości: \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 0 (zero) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -0 (ujemne zero) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; inf \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -inf \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Nan (Not A Number)

<br/>

&nbsp;&nbsp;&nbsp;&nbsp; - Nan - występuje najczęściej gdy zrobimy coś nieodpowiedniego \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; jak wyciągnięcie pierwiastka z liczby ujemnej lub podzielenie wartości przez zero. \
&nbsp;&nbsp;&nbsp;&nbsp; - Porównanie dwóch wartości Nan zawsze zwróci **false**. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (Nan == Nan) => false

<br/>

&nbsp;&nbsp;&nbsp;&nbsp; - Todo: napisać o utracie precyzji.

<br/><br/>
-------------
### Typy Podstawowe - Typ Logiczny
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **bool** \
&nbsp;&nbsp;&nbsp;&nbsp; - Wystaczyłby mu jeden bit na określenie stanu *true* / *false*. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Przyjęło się jednak że w cpp pracujemy na pełnych Bajtach, \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; dlatego rozmiar typu bool wymaga minimum jednego Bajta, 8 bitów. \
&nbsp;&nbsp;&nbsp;&nbsp; - Pełna nazwa to [ang.] Boolean - Zmienna binarna, lub Zmienna dwójkowa.

<br/><br/>
-------------
### Typy Podstawowe - Typ Znakowy
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **char** \
&nbsp;&nbsp;&nbsp;&nbsp; - Wymaga minimum 1 Bajt pamięci. \
&nbsp;&nbsp;&nbsp;&nbsp; - Przyjmuje wartości od -128 do 127, \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; lub z specyfikatorem ***unsigned***: od 0 do 255.v\
&nbsp;&nbsp;&nbsp;&nbsp; - pełna nazwa: [ang.] Character - znak, lub symbol.

<br/><br/>
-------------
### Typy Złożone


<br/><br/>
-------------
### Typ Pusty - Void
&nbsp;&nbsp;&nbsp;&nbsp; - Wykorzystywany jedynie do napisania funkcji nie zwracających wartości. \
&nbsp;&nbsp;&nbsp;&nbsp; - Typem void w języku C oznacza się funkcje nie przyjmujące argumentów. Przykładowo: `int function(void) { }`. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; W cpp tego nie robimy. Poprawny przykład dla cpp: `int function() { }`. \
&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala na tworzenie wskaźników zdolnych do trzymania adresu zmiennej każdego typu.
```cpp
    int variable_a {5};
    double variable_b {2.};
    void* void_pointer;

    // _____________________________________________________
    void_pointer = &variable_a;

    std::cout << " " << variable_a
              << " " << *(static_cast<int*>(void_pointer));
    
    // _____________________________________________________
    void_pointer = &variable_b;

    std::cout << "\n"
              << "  " << variable_b
              << "  " << *(static_cast<double*>(void_pointer));
```
``` OUTPUT:
  5  5
  2  2
```
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Aby wyłuskać wartość z wskaźnika pustego typu, należy najpierw \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; przekonwertować go na wskaźnik typu który chcemy odebrać. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Dopiero po poinformowaniu kompilatora jakiego typu chcemy uzyskać wartość możemy \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; użyć **operatora wyłuskania**. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Przykład konwersji na **int\***:  `int* pointer = static_cast<int*>(void_pointer);` \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Przykład wyłuskania 1] :  `std::cout << *(pointer);` \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Przykład wyłuskania 2] :  `std::cout << *(static_cast<int*>(void_pointer));` 

<br/><br/>

&nbsp;&nbsp;&nbsp;&nbsp; - **Wskaźnik na typ pusty Jest Złą Praktyką.** \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Należy jej unikać ponieważ zmniejsza czytelność kodu \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; oraz odbiera kompilatorowi możliwość wykrywania błędów.
```cpp
    double variable_c {6.37};
    void* void_pointer = &variable_c;

    // _____________________________________________________
    std::cout << "  " << variable_c
              << "  " << *(static_cast<int*>(void_pointer));
```
``` OUTPUT:
  6.37  [losowa wartość]
```
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; W powyższym przykładzie [losowa wartość], przykładowo: 125463346, \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; wynika z błędnej konwersji zmiennej *void_pointer* na typ **int\***. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; W ostatniej linijce wewnątrz std::cout  `static_cast<int*>(void_pointer)`.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Tego rodzaju błędy w kodzie bywają bardzo ciężkie do znalezienia. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **Kompilator zwykle ich nie wykrywa**. 


<br/><br/>
-------------
### Inne Typy Występujące W Języku CPP
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **std::size_t** \
&nbsp;&nbsp;&nbsp;&nbsp; - najczęściej jest to alias dla typu **unsigned int** \
&nbsp;&nbsp;&nbsp;&nbsp; - wielkość nie jest mniejsza niż 16bitów, 2Bajty 


<br/><br/>
-------------
### Aliasowanie Typów
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Czyli nadawanie własnych, dodatkowych nazw dla wybranego typu. \
&nbsp;&nbsp;&nbsp;&nbsp; - Tworzenie aliasów pozwala na skrócenie ilości kodu oraz zwiększenie poziomu jego czytelności. \
&nbsp;&nbsp;&nbsp;&nbsp; - Aliasowanie robi różnicę jedynie dla programistów. Dla kompilatora typ **int** jest tym samym co **alias na typ int**. \
&nbsp;&nbsp;&nbsp;&nbsp; - Kiedyś wykorzystywano do tego słowo kluczowe **typedef**, obecnie zaleca się używać **using**. \
&nbsp;&nbsp;&nbsp;&nbsp; - Na zasięg aliasu wpływają te same czynniki co na zasięg nazwy zmiennej. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Alias powstały wewnątrz bloku instrukcji będzie miał zasięg bloku instrukcji od miejsca jego utworzenia. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; To samo tyczy się pozostałych rodzai zasięgów.
```cpp
    typedef int WholeNumber;                // Old, Deprecated Practice
    using PositiveNumber = unsigned int;    // The Appropriate One
    
    WholeNumber variable_a;
    PositiveNumber variable_a;
```
```cpp
    std::vector<std::string> strVector;
    std::vector<std::string>::iterator strVectorPointer = strVector.begin();

    // _____________________________________________________ 
    // Alternative version with alias usage:
    using StrVector = std::vector<std::string>;
    using VectorIterator = std::vector<std::string>::iterator;

    StrVector strVector;
    VectorIterator strVectorPointer = strVector.begin();
```

<br/><br/>
-------------
![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
