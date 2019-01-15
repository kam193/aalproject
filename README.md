# AAL Project
## Opis
Liczenie możliwości wypełniania siatki NxM z wolnymi i zablokowanymi polami blokami w kształcie 'L'.

## Kompilacja
Poleceniem `make`, dostępne wersje `release` i `debug`.

## Tryby uruchomieniowe
1. `-h` - wyświetla pomoc
2. `-m1` - rozwiązuje siatkę podaną na standardowe wyjście
3. `-m2 -n <size>`- generuje siatę o rozmiarze NxN
4. `-m3 -n <N> -k <K> -s <S> -r <R>` - wykonuje `K` testów dla rozmiarów od `N` zwiększając go o `S`, na każdym etapie `R` prób

## Format wejściowy
W pierwszej linii rozmiar siatki `N M` gdzie `N` - wysokość, `M` - szerokość, a w następnych `N` liniach po `M` znaków. Znak `#` oznacza pole zablokowane, znak `_` (lub dowolny inny) pole wolne. Przykładowe plansze znajdują się w katalogu `examples/`.

### Przykład 1
```
2 6
##__##
______
```

### Przykład 2
```
4 4
____
____
____
____
```

## Główne założenia
Algorytm próbuje wstawić w pola jedną z 32 możliwych ustawień litery L (złożenie obrotów i odbić z możlwością jednego z 4 pól składowych litery). Poprawność generowania indeksów dla każdego z ustawień sprawdzają testy uruchamiane przy kompilacji.