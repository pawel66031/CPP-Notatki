# std::vector< TypDanych > <br/> Praktyczne Zastosowania
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Teorii]](https://github.com/Ptysiek/CPP-Notatki/blob/master/workspace/NewApproach/std_vector.md) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Strona Praktyki]



**Alternatywna Nawigacja:**  
&nbsp;&nbsp;&nbsp;&nbsp; - [Wyświetlanie informacji o wybranym Vectorze](#1-Wyświetlanie-informacji-o-wybranym-Vectorze) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [operator[ ]](#program-11-operator-size--capacity-) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.size( )](#program-11-operator-size--capacity-) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.capacity( )](#program-11-operator-size--capacity-) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Rezerwowanie Pamięci](#2-Rezerwowanie-Pamięci) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.push_back(TypDanych)](#program-21-push_backtypdanych) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [konstruktor(int)](#program-22-podejście-1---konstruktorint) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.resize(int)](#program-23-podejście-2---resizeint) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.reserve(int)](#program-24-podejście-3---reserveint) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.shrink_to_fit( )](#program-25-shrink_to_fit)




<br/><br/>
-------------
### 1. Wyświetlanie informacji o wybranym Vectorze
###### [Program 1.1] `operator[]` `.size( )` `.capacity( )`
```cpp
template<typename T>
void showVector(const std::vector<T>& givenVector) {
    // It prints in vector values, 
    // number of elements and amount of reserved space.

    for (const auto& element : givenVector) {
        std::cout << element << " ";
    }

    std::cout << "\n"
              << "size: "       << givenVector.size()      << "\n"              // Amount of existing elements
              << "capacity: "   << givenVector.capacity()  << "\n"              // Amount of reserved space
              << "space free: " << givenVector.capacity() - givenVector.size(); // Amount of elements that can add before next realocation.     
 }
```
```cpp
vector<int> A;
// _________________________
// Wywołanie funkcji [Show]:
Show(A);    // size: 0        // W tym momencie vector [A] jest pusty. Nie posiada elementów.
            // capacity: 0    // Oraz nie ma dla nich zarezerwowanego miejsca w pamięci.
```

<br/><br/>
-------------
### 2. Rezerwowanie Pamięci
###### [Program 2.1] `.push_back(TypDanych)`
```cpp
 vector<int> B;

 // W tym momencie vector [B] jest pusty
 Show(B);    // size: 0
             // capacity: 0

 // Dodajemy jeden nowy element do vectora [B] 
 // - nowy element zostanie dodany na końcu vectora.
 B.push_back(int(100));
 Show(B);    // size: 1
             // capacity: 1

 // Dodajemy kolejny element do vectora [B] 
 B.push_back(-22);
 Show(B);    // size: 2
             // capacity: 2

 // Dodajemy jeszcze kolejny element do vectora [B] 
 B.push_back(3);
 Show(B);    // size: 3  !!!
             // capacity: 4  !!!
```



###### [Program 2.2] `Podejście 1 - konstruktor(int)`
```cpp
 vector<int> C(20000);
 Show(C);    // size: 20000
             // capacity: 20000
 // Nie tylko zarezerwowaliśmy miejsce w pamięci dla [20 000] elementów,
 // jednocześnie utworzyliśmy te elementy, dlatego [size: 20000].
 // Wszystkie te elementy są równe zero.
 
 // Elementy te możemy zmodyfikować, przykładowo, operatorem[].
 for (int i=0; i<C.size(); ++i)
     C[i] = i;
 
 // Inna wersja konstruktora pozwala nam na inicjalizację 
 // wszystkich elementów inną wartością niż [zero].  
 vector<int> CC(20000, -6);
 
 // W tym momencie wszystkie utworzone elementy 
 // vectora [CC] posiadają wartość [-6]:
 for (int i=0; i<CC.size(); ++i)
     std::cout << " " << CC[i];
```
      
###### [Program 2.3] `Podejście 2 - .resize(int)`
```cpp
 vector<int> D;
 // _____________
 // Scenariusz 1:   Vector D jest pusty, [size=0], [capacity=0].
 D.resize(20000);
 Show(D);    // size: 20000
             // capacity: 20000
 // Ponownie, utworzyliśmy [20 000] elementów o wartości równej zero.
 // Powstałe elementy możemy zmodyfikować tak samo jak w podejściu pierwszym z konstruktorem.
 
 // Te [20 000] elementów już teraz istnieje.
 // Oznacza to że użycie metody [.push_back(typDanych)] w tym 
 // momencie spowoduje utworzenie [20001] elementu, co spowoduje
 // ponowną realokacje do rozmiaru [20 000 * 2], czyli [40 000].

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

###### [Program 2.4] `Podejście 3 - .reserve(int)`
```cpp
 vector<int> E;

 // Zaczynamy, Vector E jest pusty, [size=0], [capacity=0].
 E.reserve(20000);
 Show(E);    // size: 0
             // capacity: 20000
 // Metoda [.reserve(int)] jedynie rezerwuje podaną ilość miejsca,
 // nie tworzy przy tym nowych elementów.

// Dlatego w tym momencie możemy utworzyć nowe elementy metodą [.push_back(typDanych)]
 for (int i=0; i<E.capacity(); ++i)   // Pamiętaj że [size()] jest równe [zero].
     E.push_back(i);

 Show(E);    // size: 20000
             // capacity: 20000

 // __________________________________________________________
 // Argument metody [.reserve(int)] określa minimalną ilość elementów w vectorze.
 // Nigdy nie ma problemu z zwiększeniem tej ilości.
 E.reserve(20111);

 // Zostanie wykonana realokacja do rozmiaru dokładnie [20 111] elementów. 
 // Zostaje tutaj pominięta zasada dwukrotności, czyli NIE zostanie 
 // zarezerwowane miejsce dla [40 000] elementów.
 
 // __________________________________________________________
 // Nie można zarezerwować mniej miejsca niż obecnie jest zarezerwowane w vectorze.
 // Obecny stan naszego vectora to:
 Show(E);    // size: 20000
             // capacity: 20111
 
 // Podanie mniejszej wartości NIE zmodyfikuje
 // ilości obiektów, ani ilości zarezerwowanego miejsca. 
 
 E.reserve(50);
 Show(E);    // size: 20000
             // capacity: 20111
```

###### [Program 2.5] `.shrink_to_fit()`
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

<br/><br/>
-------------
![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
