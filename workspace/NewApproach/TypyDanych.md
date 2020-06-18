# Typy Danych
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Teorii]]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Praktyki]]() 

**Alternatywna Nawigacja:**  
&nbsp;&nbsp;&nbsp;&nbsp; - [link 1]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [link 2]() \
&nbsp;&nbsp;&nbsp;&nbsp; - [link 3]()


<br/><br/>
-------------
### Typy Podstawowe - Całkowitoliczbowe
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **short** \
&nbsp;&nbsp;&nbsp;&nbsp; - przynajmniej 16bitów, 2bajty. \
&nbsp;&nbsp;&nbsp;&nbsp; - pełna nazwa: [ang.] Short Integer - Krótka liczba całkowita.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **int** \
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
### Typy Złożone


<br/><br/>
-------------
### Typ Pusty - Void
&nbsp;&nbsp;&nbsp;&nbsp; - Wykorzystywany głównie przy funkcjach nie zwracających wartości. \
&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala na tworzenie wskaźników zdolnych do trzymania adresu zmiennej każdego typu.
```Cpp
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
```Cpp
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
### Akapit 3


<br/><br/>
-------------
![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
