#pragma once
#include<vector>

#include <iostream>
using namespace std;


class Organizm;

class Swiat
{public:
	
	int ktora_tura;
	char tab[1000][1000];
	static bool Porinicj(Organizm *pierwszy, Organizm *drugi);
vector <Organizm *> organizmy;
	void stworz_swiat(int kol, int wier);
	void wykonajTure(int kol,int wier);
	void OrganizmyPoczatek(int kol, int wier);
	void NowyOrg(int x, int y, char gat);
	void wyczysc_zabite();
	int sprawdz_indeks(int x, int y);
	
	

	
};