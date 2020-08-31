# std::vector< DataType >

**Wewnętrzna Nawigacja:**  
&nbsp;&nbsp;&nbsp;&nbsp; - [Wyświetlanie informacji o wybranym Vectorze](#wyświetlanie-informacji-o-wybranym-vectorze) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [operator[ ]](#wyświetlanie-informacji-o-wybranym-vectorze) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.size( )](#wyświetlanie-informacji-o-wybranym-vectorze) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.capacity( )](#wyświetlanie-informacji-o-wybranym-vectorze) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Rezerwowanie Pamięci, Tworzenie Elementów](#rezerwowanie-pamięci-tworzenie-elementów) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [konstruktor(int)](#rezerwowanie-pamięci-tworzenie-elementów) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.reserve(int)](#reserveint--up) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.resize(int)](#resizeint--up) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.push_back(DataType)](#push_backdatatype--up) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.shrink_to_fit( )](#shrink_to_fit--up) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Usuwanie Elementów](#usuwanie-elementów) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Usuwanie ostatniego elementu, .pop_back( )](#usuwanie-elementów) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Usuwanie elementu w czasie O(1)](#usuwanie-elementu-w-czasie-O1--up) \
&nbsp;&nbsp;&nbsp;&nbsp; - [Usuwanie Wielu Elementów](#usuwanie-wielu-elementów) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Styl Usuń-Wymaż (dla konkretnej wartości)](#usuwanie-wielu-elementów) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [Styl Usuń-Wymaż (dla kryterium)](#styl-usuń-wymaż-dla-kryterium--up)



&nbsp;
-------------
**Powiązane Notatki**  
&nbsp;&nbsp;&nbsp;&nbsp; - [Kontenery STL]() 

&nbsp;
-------------
**Powiązane Strony**  
&nbsp;&nbsp;&nbsp;&nbsp; - [cppreference.com/w/cpp/container/vector](https://en.cppreference.com/w/cpp/container/vector) 


<br/><br/>
-------------
### Wyświetlanie informacji o wybranym Vectorze
###### `operator[]`, `.size()`, `.capacity()` &nbsp;&nbsp;&nbsp;&nbsp; [[up]](#stdvector-datatype-)
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
### Rezerwowanie Pamięci, Tworzenie Elementów
###### `konstruktor(int)`, `konstruktor(int, DataType)` &nbsp;&nbsp;&nbsp;&nbsp; [[up]](#stdvector-datatype-)
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
###### `.reserve(int)` &nbsp;&nbsp;&nbsp;&nbsp; [[up]](#stdvector-datatype-)
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


<br/><br/>
-------------
###### `.resize(int)` &nbsp;&nbsp;&nbsp;&nbsp; [[up]](#stdvector-datatype-)
&nbsp;&nbsp;&nbsp;&nbsp; - Rezerwuje miejsce w pamięci na określoną ilość elementów, \
&nbsp;&nbsp;&nbsp;&nbsp; - Tworzy określoną liczbę elementów. \
&nbsp;&nbsp;&nbsp;&nbsp; - Nie może zmniejszyć ilości zarezerwowanego miejsca, \
&nbsp;&nbsp;&nbsp;&nbsp; - Może zmeniejszyć ilość istniejących elementów, \
&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala uniknąć wielokrotnych automatycznych realokacji pamięci. \
&nbsp;&nbsp;&nbsp;&nbsp; - Czas tworzenia elementów jest porównywalny do sposobu z wykorzystaniem konstruktora.
```cpp
std::vector<int> vector_C;
    // size: 0
    // capacity: 0
    // free space left: 0

vector_C.resize(3000);
    // 3000 elements with value equal zero were created.
    // size: 3000
    // capacity: 3000
    // free space left: 0
```
Obecnie `vector_C` posiada 3000 elementów. \
Ponowne wywołanie metody `resize(int)` z wartością **większą od obecnej ilości elementów spowoduje**: \
&nbsp;&nbsp;&nbsp;&nbsp; - Obecnie isteniejące elementy nie zostaną zmodyfikowane. \
&nbsp;&nbsp;&nbsp;&nbsp; - Na końcu wektora zostaną utworzone nowe elementy z wartością zero. \
&nbsp;&nbsp;&nbsp;&nbsp; - Wektor będzie posiadał tyle elementów ile podano w argumencie metody `resize(int)`. \
&nbsp;&nbsp;&nbsp;&nbsp; - W razie potrzeby automatyczne zostanie wykonana kolejna realokacja.
```cpp
std::vector<int> vector_CC(3,24);
    // 24 24 24 
    // size: 3
    // capacity: 3
    // free space left: 0
  
vector_CC.resize(10);
    // This resize(int) method creates 7 more elements.
    // Now vector_CC has ten elements.
    // 24 24 24 0 0 0 0 0 0 0 
    // size: 10
    // capacity: 10
    // free space left: 0
```
Obecnie `vector_CC` posiada w sobie 10 elementów. \
Ponowne wywołanie metody `resize(int)` z wartością **mniejszą od obecnej ilości elementów spowoduje**: \
&nbsp;&nbsp;&nbsp;&nbsp; - Obecnie isteniejące elementy zostaną bezpowrotnie skasowane. \
&nbsp;&nbsp;&nbsp;&nbsp; - Elementy wektora są kasowane od końca. \
&nbsp;&nbsp;&nbsp;&nbsp; - Wektor będzie posiadał tyle elementów ile podano w argumencie metody `resize(int)`. \
&nbsp;&nbsp;&nbsp;&nbsp; - Ilość zarezerwowanego miejsca nie zostanie zmniejszona. \
&nbsp;&nbsp;&nbsp;&nbsp; - Ilość elementów wektora zostanie zmniejszona.
```cpp
vector_CC;
    // 24 24 24 0 0 0 0 0 0 0 
    // size: 10
    // capacity: 10
    // free space left: 0
```
```cpp
vector_CC.resize(5);
    // Argument value(5) is smaller than vector_CC.size().
    // And so it erases last five elements.
    // 24 24 24 0 0 
    // size: 5
    // capacity: 10
    // free space left: 5
```


<br/><br/>
-------------
###### `.push_back(DataType)` &nbsp;&nbsp;&nbsp;&nbsp; [[up]](#stdvector-datatype-)
&nbsp;&nbsp;&nbsp;&nbsp; - Tworzy nowy element na końcu wektora. \
&nbsp;&nbsp;&nbsp;&nbsp; - Wywołuje konstruktor kopiujący DataType. `DataType(const DataTypeF& td) {}` \
```cpp
int someValue = 5;

 vector<int> vector_D;
    // size: 0
    // capacity: 0
    // free space left: 0
 
 vector_D.push_back(someValue);
    // Gives vector_D one element at the end
    // In this situation: Automate Memory Realocation Needed.
    // size: 1
    // capacity: 1
    // free space left: 0
```
W powyższym przykładzie posiadamy jeden wektor oraz dwie niezależne zmienne trzymające wartość `5`. \
&nbsp;&nbsp;&nbsp;&nbsp; - `someValue == 5` \
&nbsp;&nbsp;&nbsp;&nbsp; - `vector_D[1] == 5` \
Zmienna będąca częścią wektora posiada skopiowaną wartość z zmiennej `someValue`, nie jest jednak \
w żaden sposób powiązana z zmienną `someValue`. Zmienna będąca częścią wektora będzie istnieć \
tak długo jak nie zostanie skasowana z wektora lub tak długo jak sam wektor istnieje. \
Modyfikacja jednej nie ma wpływu na drugą.

<br/>

Przykład pokazujący budowę konstruktora kopiująccego: 
```cpp
class DataType {
    std::string constructorLOG_;

public:
    // DEFAULT CONSTRUCTOR:
    DataType(): constructorLOG_("[DefaultConstructor]") { }

    // COPY CONSTRUCTOR:    
    DataType(const DataType& dt): constructorLOG_("[CopyConstructor]") { }
    
    std::string getCLog() const { return constructorLOG_; }
};


int main() {
    DataType obj_a;

    std::vector<DataType> vctr;
    vctr.push_back(obj_a);

    std::cout << obj_a.getCLog() << "\n"        // [DefaultConstructor]
              << vctr[0].getCLog() << "\n";     // [CopyConstructor]

    return 0;
}
```
```
[DefaultConstructor]
[CopyConstructor]
```
Dodanie elementu do wektora polega na utworzeniu kopii tego obiektu w odpowiednim miejscu wektora. \
W tym celu wywoływany jest konstruktor kopiujący obiektu umieszczanego w wektorze.

Każde przesunięcie elementu w inne miejsce wektora wymaga utworzenia kopii tego elementu w szukanym miejscu, \
a następnie skasowanie instancji tego elementu z poprzedniego miejsca. \
Operacja przesuwania elementu po wektorze wymaga jednorazowego wywołania konstruktora kopiującego oraz destruktora przesuwanego elementu.

Realokacja pamięci wektora polega na przemieszczeniu wszystkich elementów wektora w odpowiednie miejsce.
Wymaga to wywołania algorytmu wyszukującego odpowiednio dużą ilość miejsca oraz
wywołania konstruktora kopiującego i destruktora dla każdego elementu wektora.


<br/><br/>
-------------
###### `.shrink_to_fit()` &nbsp;&nbsp;&nbsp;&nbsp; [[up]](#stdvector-datatype-)
&nbsp;&nbsp;&nbsp;&nbsp; - Zwalnia niewykorzystany nadmiar zarezerwowanej pamięci. \
&nbsp;&nbsp;&nbsp;&nbsp; - Realokuje pamięć bez usuwania elementów. \
&nbsp;&nbsp;&nbsp;&nbsp; - Wartość `capacity()` wektora staje się równa wartości `size()`.
```cpp
vector<int> vector_E(112,1);
vector_E.reserve(200);
    // size: 112
    // capacity: 200
    // free space left: 88
 
vector_E.shrink_to_fit();
    // size: 112
    // capacity: 112
    // free space left: 0
```

<br/><br/>
-------------
### Usuwanie Elementów
###### `Usuwanie ostatniego elementu`, `.pop_back()` &nbsp;&nbsp;&nbsp;&nbsp; [[up]](#stdvector-datatype-)
```cpp
std::vector<int> vctr {1, 2, 3, 4, 5, 6};
showVector(vctr);
    // 1 2 3 4 5 6
    // size: 6
    // capacity: 6
    // free space left: 0

if (!vctr.empty()) {
    vctr.pop_back();
}
showVector(vctr);
    // 1 2 3 4 5
    // size: 5
    // capacity: 6
    // free space left: 1
```
Metoda `.pop_back()` służąca do usuwania ostatniego elementu kontenera. \
**Należy sprawdzać czy kontener nie jest pusty**. \
Wywołanie metody na pustym wektorze skutkuje niezdefiniowanym zachowaniem. \
W najlepszym wypadku po wypisaniu `Segmentation fault (core dumped)` program zostanie przerwany. 


<br/><br/>
-------------
###### `Usuwanie elementu w czasie O(1)` &nbsp;&nbsp;&nbsp;&nbsp; [[up]](#stdvector-datatype-)


<br/><br/>
-------------
### Usuwanie Wielu Elementów
###### `Styl Usuń-Wymaż dla konkretnej wartości` &nbsp;&nbsp;&nbsp;&nbsp; [[up]](#stdvector-datatype-)
```
value to erase: 0
1, 0, 2, 0, 3, 0, 0, 4, 0, 5        // Input
1, 2, 3, 4, 5, 0, 0, 4, 0, 5        // Partial Result After [Step1]
1, 2, 3, 4, 5                       // Final Result After [Step2]
```
```cpp
int valueToErase = 0;

std::vector<int> vctr {1, 0, 2, 0, 3, 0, 0, 4, 0, 5};
showVector(vctr);
    // 1 0 2 0 3 0 0 4 0 5
    // size: 10
    // capacity: 10
    // free space left: 0

// [Step1]
const auto new_end (remove(begin(vctr), end(vctr), valueToErase));    
showVector(vctr);
    // 1 2 3 4 5 0 0 4 0 5
    // size: 10
    // capacity: 10
    // free space left: 0
    
// [Step2]
vctr.erase(new_end, end(vctr));
showVector(vctr);
    // 1 2 3 4 5 
    // size: 5
    // capacity: 10
    // free space left: 5
    
// [Step3]
vctr.shrink_to_fit();
showVector(vctr);
    // 1 2 3 4 5 
    // size: 5
    // capacity: 5
    // free space left: 0
```
**[Step1]**  
&nbsp;&nbsp;&nbsp;&nbsp; - Wywołujemy funkcję `std::remove(iterator, iterator, const DataType&)`. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Jako argumenty podajemy iteratory na początek i koniec wektora `vctr`. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Obecnym `DataType` jest `int`, podajemy wartość którą chcemy skasować. `0` `(zero)` \
&nbsp;&nbsp;&nbsp;&nbsp; - Funkcja `std::remove()` przemieszcza wszystkie elementy niebędące zerem na początek wektora. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Nie modyfikuje przy tym kolejności elementów. \
&nbsp;&nbsp;&nbsp;&nbsp; - Na koniec `std::remove()` zwraca iterator będący nowym iteratorem końca. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Oznacza to że między iteratorami `begin(vctr)` a `new_end` znajdują się wszystkie \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; oczekiwane elementy wektora których wartość nie jest równa podanemu jako argument `0`. 

**[Step2]**  
&nbsp;&nbsp;&nbsp;&nbsp; - Wymazuje wszystkie elementy z przedziału iteratorów `new_end` oraz `end(vctr)`. \
&nbsp;&nbsp;&nbsp;&nbsp; - W tym momencie elementy są kasowane, a iteratory `new_end  ==  end(vctr)`. \
&nbsp;&nbsp;&nbsp;&nbsp; - Ilość zarezerwowanego miejsca przez wektor nie zostaje zmniejszona. `capacity() == 10`. 

**[Step3]**  
&nbsp;&nbsp;&nbsp;&nbsp; - Zmniejsza ilość zarezerwowanego przez wektor miejsca do minimum. `size()  ==  capacity()`. \
&nbsp;&nbsp;&nbsp;&nbsp; - Może spowodować realokacje pamięci.


<br/><br/>
-------------
###### `Styl Usuń-Wymaż dla kryterium` &nbsp;&nbsp;&nbsp;&nbsp; [[up]](#stdvector-datatype-)
```
value to erase: all even numbers
1, 2, 3, 4, 5, 6, 7, 8, 9, 0        // Input
1, 3, 5, 7, 9, 6, 7, 8, 9, 0        // Partial Result After [Step1]
1, 3, 5, 7, 9                       // Final Result After [Step2]
```
```cpp
std::vector<int> vctr {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
showVector(vctr);
    // 1 2 3 4 5 6 7 8 9 0 
    // size: 10
    // capacity: 10
    // free space left: 0

// [StepZero]
const auto even ([](int i) { return (i % 2 == 0); });

// [Step1]
const auto new_end (remove_if(begin(vctr), end(vctr), even)); 
showVector(vctr);
    // 1 3 5 7 9 6 7 8 9 0 
    // size: 10
    // capacity: 10
    // free space left: 0

// [Step2]
vctr.erase(new_end, end(vctr));    
showVector(vctr);
    // 1 3 5 7 9 
    // size: 5
    // capacity: 10
    // free space left: 5
    
// [Step3]
vctr.shrink_to_fit();
showVector(vctr);
    // 1 3 5 7 9 
    // size: 5
    // capacity: 5
    // free space left: 0
```
**[StepZero]**  
&nbsp;&nbsp;&nbsp;&nbsp; - Tworzymy wyrażenie lambda sprawdzające parzystość liczby.

**[Step1]**  
&nbsp;&nbsp;&nbsp;&nbsp; - Korzystamy z `std::remove_if()` pozwalające na użycie lambdy z poprzedniego kroku. \
&nbsp;&nbsp;&nbsp;&nbsp; - Wynik jest taki sam jak przy wykorzystaniu `std::remove()`.

**[Step2]**  
&nbsp;&nbsp;&nbsp;&nbsp; - Wymazuje wszystkie elementy z przedziału iteratorów `new_end` oraz `end(vctr)`. \
&nbsp;&nbsp;&nbsp;&nbsp; - W tym momencie elementy są kasowane, a iteratory `new_end  ==  end(vctr)`. \
&nbsp;&nbsp;&nbsp;&nbsp; - Ilość zarezerwowanego miejsca przez wektor nie zostaje zmniejszona. `capacity() == 10`. 

**[Step3]**  
&nbsp;&nbsp;&nbsp;&nbsp; - Zmniejsza ilość zarezerwowanego przez wektor miejsca do minimum. `size()  ==  capacity()`. \
&nbsp;&nbsp;&nbsp;&nbsp; - Może spowodować realokacje pamięci.



<br/><br/>
-------------
### Teoria
&nbsp;&nbsp;&nbsp;&nbsp; - Wektor przechowywuje obiekty obok siebie w jednym ogromnym obszarze pamięci. \
&nbsp;&nbsp;&nbsp;&nbsp; - Należy go stosować zawsze zamiast zwykłej tablicy. \
&nbsp;&nbsp;&nbsp;&nbsp; - Jest optymalny, oferuje zwiększony komfort i bezpiecczeństwo. \
&nbsp;&nbsp;&nbsp;&nbsp; - Wektor posiada zmienną wielkość. \
&nbsp;&nbsp;&nbsp;&nbsp; - Pozwala dodawać nowe elementy bez każdorazowej realokacji pamięci.

<br/><br/>
-------------
![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
