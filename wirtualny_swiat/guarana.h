#pragma once

#include "Roslina.h"

class Guarana : public Roslina {
public:
	Guarana(int x, int y, Swiat &swiat) : Roslina(wiek, 0, 0,  x, y,'g', swiat) {};
	void Kolizja(Organizm *&napastnik, bool atak,int kol, int wier);
	void Rysuj();
};