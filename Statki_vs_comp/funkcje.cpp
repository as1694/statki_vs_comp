#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

void Wyswietl(int **tab, int rozmiar)
{//wyswietla tablice przechowujaca polozenie statkow
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}

void Wyswietl_pl(char **tab, int rozmiar)
{//wyswietla plansze
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}

void Morze(char **tab, int rozmiar)
{//przygotowuje plansze do gry
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			tab[i][j] = '-';
		}
	}
	tab[0][0] = '0';
	tab[1][0] = '1';
	tab[2][0] = '2';
	tab[3][0] = '3';
	tab[4][0] = '4';
	tab[5][0] = '5';
	tab[0][1] = '1';
	tab[0][2] = '2';
	tab[0][3] = '3';
	tab[0][4] = '4';
	tab[0][5] = '5';

	if (rozmiar > 6)
	{
		tab[0][6] = '6';
		tab[6][0] = '6';
		if (rozmiar > 7)
		{
			tab[0][7] = '7';
			tab[7][0] = '7';
			if (rozmiar > 8)
			{
				tab[0][8] = '8';
				tab[8][0] = '8';
				if (rozmiar > 9)
				{
					tab[0][9] = '9';
					tab[9][0] = '9';
				}
			}
		}
	}

}

void Morze_c(char **tab, int **tab_c, int rozmiar)
{//przygotowuje plansze do gry
	for (int i = 0; i < rozmiar - 1; i++)
	{
		for (int j = 0; j < rozmiar - 1; j++)
		{
			if (tab_c[i][j] == 0)
				tab[i + 1][j + 1] = '-';
			else
			{
				tab[i + 1][j + 1] = 's';
			}
		}
	}
	tab[0][0] = '0';
	tab[1][0] = '1';
	tab[2][0] = '2';
	tab[3][0] = '3';
	tab[4][0] = '4';
	tab[5][0] = '5';
	tab[0][1] = '1';
	tab[0][2] = '2';
	tab[0][3] = '3';
	tab[0][4] = '4';
	tab[0][5] = '5';

	if (rozmiar > 6)
	{
		tab[0][6] = '6';
		tab[6][0] = '6';
		if (rozmiar > 7)
		{
			tab[0][7] = '7';
			tab[7][0] = '7';
			if (rozmiar > 8)
			{
				tab[0][8] = '8';
				tab[8][0] = '8';
				if (rozmiar > 9)
				{
					tab[0][9] = '9';
					tab[9][0] = '9';
				}
			}
		}
	}

}

void Pudlo(char **tab, int x, int y)
{
	tab[x][y] = 'o';
	cout << "pudlo!" << endl;
	cout << endl;
}

void Traf(char **tab, int x, int y)
{
	tab[x][y] = 'x';
	cout << "zatopiony!" << endl;
	cout << endl;
}

void Statki(int **tab, int ile, int rozmiar)
{//rozstawia statki na planszy tab o rozmiarze, tak zeby zaden nie byl obok drugiego
	srand(time(NULL));
	int x, y;

	for (int i = 0; i < ile;)
	{
		x = rand() % (rozmiar - 1);
		y = rand() % (rozmiar - 1);

		if (x > 0 && x < rozmiar - 1 && y>0 && y < rozmiar - 1)
		{
			if (tab[x][y] == 1 || tab[x - 1][y] == 1 || tab[x + 1][y] == 1 || tab[x][y - 1] == 1 || tab[x][y + 1] == 1 || tab[x - 1][y - 1] == 1 || tab[x + 1][y - 1] == 1 || tab[x - 1][y + 1] == 1 || tab[x + 1][y + 1] == 1)
				continue;
			else
			{
				tab[x][y] = 1;
				i++;
			}
		}
		if (x == 0)
		{
			if (y == 0)
			{
				if (tab[x][y] == 1 || tab[x + 1][y] == 1 || tab[x][y + 1] == 1 || tab[x + 1][y + 1] == 1)
					continue;
				else
				{
					tab[x][y] = 1;
					i++;
				}
			}
			if (y == rozmiar - 1)
			{
				if (tab[x][y] == 1 || tab[x + 1][y] == 1 || tab[x][y - 1] == 1 || tab[x + 1][y - 1] == 1)
					continue;
				else
				{
					tab[x][y] = 1;
					i++;
				}
			}
			else
			{
				if (tab[x][y] == 1 || tab[x + 1][y] == 1 || tab[x][y - 1] == 1 || tab[x][y + 1] == 1 || tab[x + 1][y - 1] == 1 || tab[x + 1][y + 1] == 1)
					continue;
				else
				{
					tab[x][y] = 1;
					i++;
				}
			}
		}

		if (y == 0 && x != 0)
		{
			if (x == rozmiar - 1)
			{
				if (tab[x][y] == 1 || tab[x - 1][y] == 1 || tab[x][y + 1] == 1 || tab[x - 1][y + 1] == 1)
					continue;
				else
				{
					tab[x][y] = 1;
					i++;
				}
			}
			else
			{
				if (tab[x][y] == 1 || tab[x - 1][y] == 1 || tab[x + 1][y] == 1 || tab[x][y + 1] == 1 || tab[x - 1][y + 1] == 1 || tab[x + 1][y + 1] == 1)
					continue;
				else
				{
					tab[x][y] = 1;
					i++;
				}
			}
		}

		if (x == rozmiar - 1 && y != 0)
		{
			if (y == rozmiar - 1)
			{
				if (tab[x][y] == 1 || tab[x - 1][y] == 1 || tab[x][y - 1] == 1 || tab[x - 1][y - 1] == 1)
					continue;
				else
				{
					tab[x][y] = 1;
					i++;
				}
			}
			else
			{
				if (tab[x][y] == 1 || tab[x - 1][y] == 1 || tab[x][y - 1] == 1 || tab[x][y + 1] == 1 || tab[x - 1][y - 1] == 1 || tab[x - 1][y + 1] == 1)
					continue;
				else
				{
					tab[x][y] = 1;
					i++;
				}
			}
		}
		if (y == rozmiar - 1 && x != 0 && x != rozmiar - 1)
		{
			if (tab[x][y] == 1 || tab[x - 1][y] == 1 || tab[x + 1][y] == 1 || tab[x][y - 1] == 1 || tab[x - 1][y - 1] == 1 || tab[x + 1][y - 1] == 1)
				continue;
			else
			{
				tab[x][y] = 1;
				i++;
			}
		}
	}
}

int IleStatkow(int rozmiar, int IlStatkow)
{
	int granica;
	if (rozmiar == 5)
		granica = 1;
	if (rozmiar == 6)
		granica = 2;
	if (rozmiar == 7)
		granica = 3;
	if (rozmiar == 8)
		granica = 4;
	if (rozmiar == 9)
		granica = 5;

	switch (granica)
	{
	case 1:
		do
		{
			cout << "ile chcesz miec statkow? 1-4" << endl;
			cin >> IlStatkow;
			cout << endl;
			return IlStatkow;
		} while (IlStatkow > 4); break;
	case 2:
		do
		{
			cout << "ile chcesz miec statkow? 1-8" << endl;
			cin >> IlStatkow;
			cout << endl;
			return IlStatkow;
		} while (IlStatkow > 8); break;
	case 3:
		do
		{
			cout << "ile chcesz miec statkow? 1-8" << endl;
			cin >> IlStatkow;
			cout << endl;
			return IlStatkow;
		} while (IlStatkow > 8); break;
	case 4:
		do
		{
			cout << "ile chcesz miec statkow? 1-11" << endl;
			cin >> IlStatkow;
			cout << endl;
			return IlStatkow;
		} while (IlStatkow > 11); break;
	case 5:
		do
		{
			std::cout << "ile chcesz miec statkow? 1-11" << endl;
			cin >> IlStatkow;
			cout << endl;
			return IlStatkow;
		} while (IlStatkow > 11); break;
	default:
	{
		return 0;
		break;
	}
	}
}

void GRA(int rozmiar, int **tab, int **tab_c, char **plansza, char **plansza_c, int rozmiarP, int nSt)
{
	//srand(time(NULL));
	int x, y, Licz = 0;
	int trafienia = 0;
	int trafienia_c = 0;
	char Wsp[3];
	int wsp[2];
	
	do
	{
		do {
			cout << "podaj wspolrzedne celu np. 12" << endl;
			//cin >> x;
			//cin >> y;
			cin >> Wsp;
			cout << endl;

			wsp[0] = static_cast<int>(Wsp[0]) - 48;
			wsp[1] = static_cast<int>(Wsp[1]) - 48;

		} while (wsp[0]<1 || wsp[0]>rozmiar || wsp[1]<1 || wsp[1]>rozmiar);

		system("cls"); //czysci ekran

		if (tab[wsp[0] - 1][wsp[1] - 1] == 0)
		{
			Pudlo(plansza, wsp[0], wsp[1]);
		}
		else
		{
			Traf(plansza, wsp[0], wsp[1]);
			trafienia++;
		}


		Licz++;
		//cout << "Plansza przeciwnika" << endl;
		Wyswietl_pl(plansza, rozmiarP);
		cout << endl;
		cout << "zostalo: " << nSt - trafienia << " do zestrzelenia" << endl;
		cout << endl;

		//cout << "Twoja plansza:" << endl;
		//_getch();
		do
		{
			x = rand() % (rozmiar - 1);
			y = rand() % (rozmiar - 1);
		} while (plansza_c[x + 1][y + 1] == 'o' || plansza_c[x + 1][y + 1] == 'x');

		cout << "Przeciwnik: ";
		if (tab_c[x][y] == 0)
		{
			Pudlo(plansza_c, x + 1, y + 1);
		}
		if (tab_c[x][y] == 1 && plansza_c[x + 1][y + 1] != 'x')
		{
			Traf(plansza_c, x + 1, y + 1);
			trafienia_c++;
		}
		Wyswietl_pl(plansza_c, rozmiarP);
		cout << endl;
		cout << "Przeciwnikowi zostalo: " << nSt - trafienia_c << " do zestrzelenia" << endl;
		cout << endl;
		//_getch();
	} while (trafienia < nSt && trafienia_c<nSt);

	if (nSt == trafienia)
	{
		system("cls");
		cout << "WYGRANA!" << endl;
		cout << endl;
		cout << "strzelales: " << Licz << " razy" << endl;
		cout << "Ty: Zatopiony!" << endl;
		Wyswietl_pl(plansza, rozmiarP);
		cout << endl;
		cout << "przeciwnik zestrzelil: " << trafienia_c << " statkow" << endl;
		Wyswietl_pl(plansza_c, rozmiarP);
	}
	else
	{
		system("cls");
		cout << "PRZEGRANA :(" << endl;
		cout << endl;
		cout << "Ty:" << endl;
		Wyswietl_pl(plansza, rozmiarP);
		cout << endl;
		cout << "przeciwnik:" << endl;
		Wyswietl_pl(plansza_c, rozmiarP);
	}
}
