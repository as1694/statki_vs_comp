//gra w statki


#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include "funkcje.h"

using namespace std;


int main()
{
	cout<<"helllo"<<endl;
	int **tab, **tab_c, rozmiar;
	int nSt = 0;

	do
	{
		cout << "jak duza ma byc plansza 5-9?" << endl;
		cin >> rozmiar;
	} while (rozmiar < 5 || rozmiar > 9);

	tab = new int* [rozmiar]();
	for (int i = 0; i<rozmiar; i++)
		tab[i] = new int[rozmiar]();

	tab_c = new int *[rozmiar]();
	for (int i = 0; i<rozmiar; i++)
		tab_c[i] = new int[rozmiar]();

	//Wyswietl(tab, rozmiar);

	int rozmiarP = rozmiar + 1;

	char **plansza, **plansza_c;

	plansza = new char *[rozmiarP]();
	for (int i = 0; i<rozmiarP; i++)
		plansza[i] = new char[rozmiarP]();

	plansza_c = new char *[rozmiarP]();
	for (int i = 0; i<rozmiarP; i++)
		plansza_c[i] = new char[rozmiarP]();

	nSt = IleStatkow(rozmiar, nSt);

	Statki(tab, nSt, rozmiar);
	Statki(tab_c, nSt, rozmiar);

	Morze(plansza, rozmiarP);
	Morze_c(plansza_c, tab_c ,rozmiarP);

	//Wyswietl(tab, rozmiar);
	//....................................-- GRA --..........................................................

	Wyswietl_pl(plansza, rozmiarP);
	cout << endl;
	cout << "Twoja plansza" << endl;
	Wyswietl_pl(plansza_c, rozmiarP);

	GRA(rozmiar, tab,tab_c, plansza,plansza_c, rozmiarP, nSt);

	int* a = new int(5);
	delete a;

	_getch();
	return 0;
}