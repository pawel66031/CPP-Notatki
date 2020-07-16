# std::vector< TypDanych > 
&nbsp;&nbsp;&nbsp;&nbsp; - [Strona Teorii] \
&nbsp;&nbsp;&nbsp;&nbsp; - [[Strona Praktyki]](https://github.com/Ptysiek/CPP-Notatki/blob/master/workspace/NewApproach/praktyka_std_vector.md) 

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

&nbsp;&nbsp;&nbsp;&nbsp; - Kontener sekwencyjny STL, przechowujący tablice o zmiennej wielkości. \
&nbsp;&nbsp;&nbsp;&nbsp; - Pojemność vectora jest zarządzana automatycznie, zwiększana bądź zmniejszana w razie potrzeby. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Vectory zwykle alokują na zapas więcej pamięci niż potrzeba. \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Dzięki temu nie muszą realokować całej pamięci przy każdym nowym elemencie. \
&nbsp;&nbsp;&nbsp;&nbsp; - Realokacje są kosztownymi operacjami pod względem wydajności. Unikać! \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Kiedy się da, ręcznie rezerwować za wczasu tyle pamięci ile potrzeba. \
&nbsp;&nbsp;&nbsp;&nbsp; - Najczęściej stosowany termin w polskich publikacjach to *Kontener*, lub *Wektor*.



<br/><br/>
-------------
### 2. Rezerwowanie Pamięci
Przed każdym WIELOKROTNYM użyciem metody `.push_back( )` \
należy unikać kilkukrotnych realokacji vectora. \
W kodzie wyżej, automatycznie doszło aż do trzech realokacji vectora.
   
Automatyczna realokacja rezerwuje dwukrotność obecnie zarezerwowanej pamięci. 
   - Przykład 1 \
      Jeżeli w vectorze posiadamy zarezerwowane miejsce dla [500] elementów, \
      wtedy możemy dowolnie dodawać elementy aż do pięcsetnego. \
      Jeżeli jednak w vectorze już będziemy mieli dane [500] elementów, \
      dodanie pięćset-pierwszego [501] elementu będzie wymagało realokacji pamięci. \
      Nowy rozmiar vectora będzie przystosowany do trzymania [500*2] = [1000] elementów. 
      
   - Przykład 2 \
      Zakładając że nigdy nie alokujemy pamięci ręcznie, wtedy \
      rezerwowane będzie tyle miejsca w pamięci, ile wynosi \
      najmniejsza potęga dwójki w której zmieści się ilość elementów vectora. \
      Dzieje się tak ponieważ: 

1 * [2] = 2 | 4 * [2] = 8 | 16 * [2] = 32
------------- | -------------  | ------------- 
**2 * [2] = 4** | **8 * [2] = 16** | **32 * [2] = 64 ...**
	
<br/>
	
Ilość zarezerwowanego <br/> miejsca w pamięci <br/> `V.capacity( )` | Ilość wykonanych <br/> realokacji pamięci | Minimalna możliwa <br/> ilość wywołań metody <br/> `V.push_back(int(value))`
------------- | -------------  | ------------- 
0 | 0 | -
1 | 1 | 1
2 | 2 | 2
4 | 3 | 3
8 | 4 | 5
16 | 5 | 9
32 | 6 | 17
64 | 7 | 33
128 | 8 | 65
256 | 9 | 129
516 | 10 | 257
1024 | 11 | 517
2048 | 12 | 1025
4096 | 13 | 2049
8192 | 14 | 4097
16 384 | 15 | 8193
32 768 | 16 | 16 385
	
Oznacza to, że wypełnienie vectora o przykładowo [20 000] elementów \
używając tylko i wyłącznie metody `.push_back( )` będzie wymagało 16 realokacji. \
16 realokacji to zdecydowanie za dużo.

Każda realokacja jest czasochłonną operacją. Należy UNIKAĆ zbyt częstych **realokacji vectora**. \
Podane w przykładzie pod tabelą [20 000] możemy zarezerwować wykonując jedynie **jedną** realokacje:

<br/><br/>
-------------
![](https://github.com/Ptysiek/resources/blob/master/Ver2.PNG)
