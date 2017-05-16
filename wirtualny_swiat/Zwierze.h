#pragma once
#include "Organizm.h"
	

class Zwierze : public Organizm
{public:
	void Akcja(Organizm *&obronca,int kol,int wier);
	void Kolizja(Organizm *&obronca, bool atak,int kol, int wier);
	void Walka(Organizm *&obronca,int kol, int wier);
	virtual void Rysuj() {};

	Zwierze(int wiek, int sila, int inicjatywa,  int x, int y,char gatunek, Swiat &swiat);
};

