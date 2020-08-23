# std::vector< TypDanych >
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Teorii]](https://github.com/Ptysiek/CPP-Notatki/blob/master/workspace/NewApproach/std_vector.md) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Strona Praktyki]

&nbsp;
-------------
**Wewnętrzna Nawigacja:**  
&nbsp;&nbsp;&nbsp;&nbsp; - [Wyświetlanie informacji o wybranym Vectorze](#1-Wyświetlanie-informacji-o-wybranym-Vectorze) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [operator[ ]](#program-11-operator-size--capacity-) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.size( )](#program-11-operator-size--capacity-) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.capacity( )](#program-11-operator-size--capacity-) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Rezerwowanie Pamięci](#2-Rezerwowanie-Pamięci) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [konstruktor(int)](#program-22-podejście-1---konstruktorint) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.resize(int)](#program-23-podejście-2---resizeint) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.reserve(int)](#program-24-podejście-3---reserveint) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.push_back(TypDanych)](#program-21-push_backtypdanych) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.shrink_to_fit( )](#program-25-shrink_to_fit)

&nbsp;
-------------
**Powiązane Strony**  
&nbsp;&nbsp;&nbsp;&nbsp; - [Kontenery STL]() 



<br/><br/>
-------------
### Wyświetlanie informacji o wybranym Vectorze
###### `operator[]`, `.size( )`, `.capacity( )`
```cpp
// Prints all current values of givenVector, 
// number of existing elements, 
// the amount of reserved space,
// the number of items that can be added before next realocation.
template<typename T>
void showVector(const std::vector<T>& givenVector) {
    for (const auto& element : givenVector) {
        std::cout << element << " ";
    }

    std::cout << "\n"
              << "size: "            << givenVector.size()      << "\n"
              << "capacity: "        << givenVector.capacity()  << "\n"
              << "free space left: " << givenVector.capacity() - givenVector.size();
 }
```

<br/><br/>
-------------
### Rezerwowanie Pamięci  
###### `konstruktor(int)`, `konstruktor(int, TypDanych)` 
&nbsp;&nbsp;&nbsp;&nbsp; - Rezerwuje miejsce w pamięci na określoną ilość elementów, \
&nbsp;&nbsp;&nbsp;&nbsp; - Tworzy określoną ilość elementów domyślnie nadając im początkową wartość zero. \
&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala na inicjalizacje wartością inną od zera, drugi argument.
```cpp
std::vector<int> vector_A(4);
    // 0 0 0 0
    // size: 4
    // capacity: 4
    // free space left: 0
 
std::vector<int> vector_AA(6, -12);
    // -12 -12 -12 -12 -12 -12
    // size: 6
    // capacity: 6
    // free space left: 0
```


<br/><br/>
-------------
###### `.reserve(int)` 
&nbsp;&nbsp;&nbsp;&nbsp; - Rezerwuje miejsce w pamięci na określoną ilość elementów, \
&nbsp;&nbsp;&nbsp;&nbsp; - Nie tworzy elementów, \
&nbsp;&nbsp;&nbsp;&nbsp; - Nie może zmniejszyć ilości zarezerwowanego miejsca, \
&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala uniknąć wielokrotnych automatycznych realokacji pamięci.
```cpp
std::vector<int> vector_B;
    // size: 0
    // capacity: 0
    // free space left: 0

vector_B.reserve(200);
    // No elements were created.
    // But now you can create two hundred elements without multiple reallocations.
    // size: 0
    // capacity: 200
    // free space left: 200
```

Metoda `.reserve(int)` nie pozwala nam na zmniejszenie ilości zarezerwowanego miejsca. \
W sytuacji podania mniejszej wartości niż obecna kontener nie jest modyfikowany.
```cpp
vector_B.reserve(120);         // 120 is less than the current 200
    // The method does nothing if it receives a smaller argument than the currently reserved space.
    // It cannot reduce the reserved space of the vector.
    // size: 0
    // capacity: 200
    // free space left: 200
 ```
 
Metodą `.reserve(int)` możemy zwiększyć ilość zarezerwowanej pamięci do konkretnego rozmiaru, \
który nie musi być wielokrotnością dwójki lub dwukrotnością poprzedzającego rozmiaru.
 ```cpp
 vector_B.reserve(233);  
    // the reserved space will contain 233 elements. Not 256(2^8), Not 400(200*2).
    // size: 0
    // capacity: 233
    // free space left: 233
``` 

Niezależnie na ile elementów zostanie zarezerwowane miejsce w pamięci, po przekroczeniu limitu nastąpi automatyczna realokacja. \
Automatyczna realokajca dwukrotnie zwiększa ostatnią ilość zarezerwowanego miejsca. \
Przykładowo, jeżeli `(vector_A.capacity() == 233)`, i będziemy chcieli dodać 234 element, \
to w wyniku automatycznej realokacji ilość miejsca w wektorze zostanie zwiększona do, (233 * 2), 466 elementów .

**Unikamy automatycznych realokacji pamięci z powodów optymalizacyjnych** \
Jest to czasochłonna operacja polegająca na wyszukaniu odpowiedniego miejsca w pamięci zdolnego do pomieszczenia \
wszystkich elementów wektora w ciągłej, nieprzerwanej lini komórek pamięci, \
a następnie jeszcze przepisująca element po elemencie w takie odpowiednie miejsce. \
Operacja realokacji posiada własne usprawnienia zależne od systemu operacyjnego, \
nie należy jednak zakładać że takowe usprawnienia zostaną zastosowane w każdym przypadku. \
Dlatego zamiast wykonywać 26 lub więcej automatycznych realokacji zaleca się \
wykonać jednokrotną, ręczną realokację przed wprowadzaniem nowych elementów.


<br/>


      
      
      
      
      
      
      
      
<br/><br/>
-------------
###### `.resize(int)` 
&nbsp;&nbsp;&nbsp;&nbsp; - Rezerwuje miejsce w pamięci na określoną ilość elementów, \
&nbsp;&nbsp;&nbsp;&nbsp; - Tworzy określoną liczbę elementów. \
&nbsp;&nbsp;&nbsp;&nbsp; - Nie może zmniejszyć ilości zarezerwowanego miejsca, \
&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala uniknąć wielokrotnych automatycznych realokacji pamięci. \
&nbsp;&nbsp;&nbsp;&nbsp; - Czas tworzenia elementów jest porównywalny do sposobu z wykorzystaniem konstruktora.
```cpp
std::vector<int> vector_C;
    // size: 0
    // capacity: 0
    // free space left: 0

vector_C.resize(30000);
    // 30000 elements with value equal zero were created.
    // size: 30000
    // capacity: 30000
    // free space left: 0
```
Obecnie `vector_C` posiada w sobie 30000 elementów. \
Ponowne wywołanie metody `resize(int)` spowoduje: \
&nbsp;&nbsp;&nbsp;&nbsp; - W razie potrzeby automatyczne zostanie wykonana kolejna realokacja. \
&nbsp;&nbsp;&nbsp;&nbsp; - Nie zostaną zmodyfikowane już istniejące elementy. \
&nbsp;&nbsp;&nbsp;&nbsp; - Gdy podana wartośc jest większa od obecnej ilości elementów utworzy nowe elementy. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Gdy mniejsza nie zrobi nic.
      
      


 // _____________
 // Scenariusz 2:   Vector D jest nie pusty, dodajemy do niego więcej miejsca
 D.resize(55555);
 /*  - Nie zostaną zmodyfikowane już istniejące elementy.
     - Zostanie wykonana potrzebna realokacja.
       Wcześniejsza ilość zarezerwowanego miejsca to było [20 000]
       Dwukrotność poprzednio zarezerwowanego miejsca wynosi [40 000]
       Jeżeli chcemy zarezerwować więcej miejsca niż dana dwukrotność, 
       wtedy zarezerwuje nam dokładnie tyle miejsca, o ile poprosiliśmy. Czyli [55 555].
       Jeżeli jednak chcemy zarezerwować mniej niż [40 000], wtedy i tak zarezerwuje nam [40 000].
       W ten sposób vektor minimalizuje ilość automatycznych realokacji w przyszłości.
     - Nowe miejsce zostanie wypełnione nowymi elementami o wartości zero.  */

 // _____________
 // Scenariusz 3:   Vector D jest nie pusty, Zmniejszamy w nim ilość miejsca
 D.resize(100);
 /*  - Nie zostaną zmodyfikowane już istniejące, mieszczące się w przedziale elementy.
     - Elementy nie mieszczące się w przedziale zostaną bez powrotnie skasowane.
     - Nie zostanie wykonana realokacja pamięci.
       Oznacza to że w vectorze będzie [100] elementów - [size = 100]
       Jednocześnie będzie zarezerwowana ostatnia ilość pamięci - [capacity = 55 555]  */
```


###### `.shrink_to_fit()`
```cpp
 // Zwalnianie NADMIARU zarezerwowanej pamięci
 
 vector<int> F(112,1);
 F.reserve(200);
 Show(F);    // size: 112
             // capacity: 200
 
 // Metoda [.shrink_to_fit()] realokuje pamięć do ilości jej elementów.
 // Nie usuwa elementów. Wartość [capacity] staje się równa wartości [size].
 
 F.shrink_to_fit();
 Show(F);    // size: 112
             // capacity: 112
```





###### `.push_back(TypDanych)`
```cpp
int someValue = 5;

 vector<int> vector_A;
    // size: 0
    // capacity: 0
    // free space left: 0
 
 vector_A.push_back(someValue);
    // Gives vector_A one element at the end
    // In this situation: Automate Memory Realocation Needed.
    // size: 1
    // capacity: 1
    // free space left: 0
```





<br/><br/>
-------------
![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
