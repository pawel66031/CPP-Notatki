# Static

Funkcja *static* pozwala na wydłużenie "życia" zmiennej (pozostaje w pamięci do momentu wyłączania programu), gdzie domyślnie ustawiona zmienna jest usuwana w momencie, kiedy program dojdzie do odczytania końca funkcji, wtedy lokalne zmienne są od razu usuwane.

Róznica między zmienną ze *static* a bez niej:  
***Static***
```cpp
#include <iostream>

void zwiekszWartosc()
{
	static int wartosc = 1; // Zmienna ze staticem
	++wartosc;
	std::cout << wartosc << '\n';
}

int main()
{
	zwiekszWartosc();
	zwiekszWartosc();
	zwiekszWartosc();

	return 0;
}
```
W konsoli wypisze wartości:

2  
3  
4  

***Bez statica***
```cpp
#include <iostream>

void zwiekszWartosc()
{
	int wartosc = 1; // Zwykła zmienna
	++wartosc;
	std::cout << wartosc << '\n';
}

int main()
{
	zwiekszWartosc();
	zwiekszWartosc();
	zwiekszWartosc();

	return 0;
}
```
W konsoli wypisze wartości:

2  
2  
2  

Jak można dostrzec: program w momencie gdy dochodzi do deklaracji zmiennej z *static* w trakcie działania, gdy dostaje się po raz drugi do konstruktora *wartosc*, wtedy nie dochodzi do jej ponownej deklaracji z tego powodu, że jego wartość ze zmiennej *wartosc* została zapamiętana w pamięci, która zostanie ponownie wykorzystana. Gdyby nie było *static*, wtedy automatycznie po zakończeniu funkcji zmienna *wartosc* zostałaby zapomniana i nie byłoby możliwe wykonanie funkcji sumuj dla liczb w pamięci funkcji.

## Rada
> Przy definiowaniu zmiennej ze *static* najlepiej przed nazwą zmiennej dać przedrostek s_
> dla lepszej czytelności kodu.

Podczas tworzenia dużego projektu należy pamiętać, że zmienne *static* zostają dopiero po zakończeniu programu, więc należy pamiętać o jego ograniczaniu i nie nadużywania tych funkcji.
