#ifndef FUNKCJE_HPP
#define FUNKCJE_HPP

#include <iostream>
#include <string>

template <class TYP>
int partition(TYP *tablica, int p, int r) // dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
{
	TYP x = tablica[p], w; // obieramy x
	int i = p, j = r; // i, j - indeksy w tabeli
	while (true) // petla nieskonczona - wychodzimy z niej tylko przez return j
	{
		while (tablica[j] > x) // dopoki elementy sa wieksze od x
			j--;
		while (tablica[i] < x) // dopoki elementy sa mniejsze od x
			i++;
		if (i < j) // zamieniamy miejscami gdy i < j
		{
			w = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = w;
			i++;
			j--;
		}
		else // gdy i >= j zwracamy j jako punkt podzialu tablicy
			return j;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void quicksort(TYP *tablica, int p, int r) // sortowanie szybkie
{
	int q;
	if (p < r)
	{
		q = partition(tablica, p, r); // dzielimy tablice na dwie czesci; q oznacza punkt podzialu
		quicksort(tablica, p, q); // wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
		quicksort(tablica, q + 1, r); // wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif