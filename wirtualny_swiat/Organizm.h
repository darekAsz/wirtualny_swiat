#pragma once
class Swiat;

class Organizm

{public:
	char gatunek;
	int sila;
	int wiek;
	int inicjatywa;
	int wspx=8;
	int wspy=6;
	Swiat &sw;
	virtual void Akcja(Organizm *&obronca,int kol, int wier){};
	virtual void Kolizja(Organizm *&obronca, bool atak, int kol, int wier){};
	virtual void rysowanie(){};
	void miejsce_nowy(int x, int y,int kol,int wier);
	virtual void Rysuj() {};
	Organizm(int wiek, int sila, int inicjatywa, int x, int y, char gat, Swiat &sw);
};

