#pragma once
#include "Organizm.h"


class Roslina : public Organizm
{
public:
	void Akcja(Organizm *&napastnik,int kol, int wier);
	void Kolizja(Organizm *&napastnik, bool atak, int kol, int wier);
	virtual void Rysuj() {};
	Roslina(int wiek, int sila, int inicjatywa, int x, int y, char gatunek, Swiat &swiat): Organizm( wiek,  sila,  inicjatywa,  x,  y,  gatunek,  swiat) {};
};

