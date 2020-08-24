# std::vector< DataType >
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
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.push_back(DataType)](#program-21-push_backtypdanych) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - [.shrink_to_fit( )](#program-25-shrink_to_fit)

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
### Rezerwowanie Pamięci, Tworzenie Elementów
###### `konstruktor(int)`, `konstruktor(int, DataType)` 
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


<br/><br/>
-------------
###### `.resize(int)` 
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
###### `.push_back(DataType)`
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
Console Output:
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
###### `.shrink_to_fit()`
&nbsp;&nbsp;&nbsp;&nbsp; - Zwalnia niewykorzystany nadmiar zarezerwowanej pamięci. \
&nbsp;&nbsp;&nbsp;&nbsp; - Realokuje pamięć bez usuwania elementów. \
&nbsp;&nbsp;&nbsp;&nbsp; - Wartość `capacity()` wektora staje się równa wartości `size()`.
```cpp
 vector<int> vector_D(112,1);
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
![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
