#pragma once

#include "Roslina.h"

class Mlecz : public Roslina {
public:
	Mlecz(int x, int y, Swiat &swiat) : Roslina(wiek, 0, 0, x, y, 'm', swiat) {};
	void Kolizja(Organizm *&napastnik, bool atak,int kol, int wier);
	void Rysuj();
};