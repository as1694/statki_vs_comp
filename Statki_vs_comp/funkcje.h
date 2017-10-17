#pragma once
void Wyswietl(int **tab, int rozmiar);

void Wyswietl_pl(char **tab, int rozmiar);

void Morze(char **tab, int rozmiar);

void Morze_c(char **tab, int **tab_c, int rozmiar);

void Pudlo(char **tab, int x, int y);

void Traf(char **tab, int x, int y);

void Statki(int **tab, int ile, int rozmiar);

int IleStatkow(int rozmiar, int IlStatkow);

void GRA(int rozmiar, int **tab, int **tab_c, char **plansza, char **plansza_c, int rozmiarP, int nSt);