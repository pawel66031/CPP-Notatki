# Konwencje Formatowania

<br/><br/>

### Przyjęte konwencje repozytorium
**&nbsp;&nbsp;&nbsp;&nbsp; - Język pisany:** &nbsp; Polski \
**&nbsp;&nbsp;&nbsp;&nbsp; - Nazwy plików:** &nbsp; CamelCase, Polskie (bez spolszczenia terminów technicznych) \
**&nbsp;&nbsp;&nbsp;&nbsp; - Tabulacja:** &nbsp; 4 spacje 

<br/>

### Tłumaczenia
&nbsp;&nbsp;&nbsp;&nbsp; - Poprzedzamy nawiasami kwadratowymi. \
&nbsp;&nbsp;&nbsp;&nbsp; - Umieszczamy odniesienie do strony: [AlternatywyNazewnicze](https://github.com/Ptysiek/CPP-Notatki/blob/master/workspace/NewApproach/AlternatywyNazewnicze.md) \
&nbsp;&nbsp;&nbsp;&nbsp; - Przykład: nawiasy klamrowe [ang. [braces](https://github.com/Ptysiek/CPP-Notatki/blob/master/workspace/NewApproach/AlternatywyNazewnicze.md#ang-braces)]

<br/>

### Budowa Strony
&nbsp;&nbsp;&nbsp;&nbsp; - Akapity rozpoczynamy tytułem z potrójnym hashem `###`. \
&nbsp;&nbsp;&nbsp;&nbsp; - Tytuł akapitu piszemy w Camel_spacja_Case. Rozpoczynamy każde słowo wielką literą. \
&nbsp;&nbsp;&nbsp;&nbsp; - Unikamy pod-akapitów, pod-tytułów, rozbudowywania hierarchii pliku. \
&nbsp;&nbsp;&nbsp;&nbsp; - Przykład:  [PustySzablon.md](https://github.com/Ptysiek/CPP-Notatki/blob/master/workspace/NewApproach/PustySzablon.md)

<br/>

### Budowa Strony Praktyki
&nbsp;&nbsp;&nbsp;&nbsp; - Poprzedzamy nazwę pliku słowem:  `praktyka_`. \
&nbsp;&nbsp;&nbsp;&nbsp; - Przykład:  [praktyka_PustySzablon.md]()

<br/>

### Formatowanie Kodu
**&nbsp;&nbsp;&nbsp;&nbsp; - Język pisany:** &nbsp; Angielski 

&nbsp;&nbsp;&nbsp;&nbsp; - Egyptian braces - Klamra otwierająca w tej samej lini co jej nagłówek. \
&nbsp;&nbsp;&nbsp;&nbsp; - Zawsze piszemy klamry, również przy bloku jednej instrukcji. \
&nbsp;&nbsp;&nbsp;&nbsp; - `Not cuddled else`. Pisanie `else` w osobnej lini niż poprzednia klamra zamykająca.

&nbsp;&nbsp;&nbsp;&nbsp; - Jedna spacja po makrodefinicji: `#include` \
&nbsp;&nbsp;&nbsp;&nbsp; - Zawsze jedna spacja przed klamrą otwierającą. \
&nbsp;&nbsp;&nbsp;&nbsp; - Brak spacji przed nawiasem funkcji lub metody. \
&nbsp;&nbsp;&nbsp;&nbsp; - Jedna spacja przed nawiasem instrukcji sterującej. `if`, `else if`, `for`, `while`, itd..

&nbsp;&nbsp;&nbsp;&nbsp; - Nazwy Typów, Aliasów, Klas: `CamelCase`. \
&nbsp;&nbsp;&nbsp;&nbsp; - Funkcje, Metody i Zmienne: rozpoczęty małą literą `camelCase`. \
&nbsp;&nbsp;&nbsp;&nbsp; - Stałe i Makra: `UPPER_CASE`, przykład: PI, INT_MIN, INT_MAX. \
&nbsp;&nbsp;&nbsp;&nbsp; - Wszystkie inne rzeczy: `snake_case`

&nbsp;&nbsp;&nbsp;&nbsp; - Prywatne pola wewnątrz klasy poprzedamy `m_`, przykład: m_data. \
&nbsp;&nbsp;&nbsp;&nbsp; - Podłoga `_` na początku wyrazu jest zarezerwowana dla kompilatora.
```Cpp
int example() {

    if (condition) {
        doSth();
    }
    else {
        doSthElse();
    }
    return -1;
}
```

<br/><br/><br/><br/>
