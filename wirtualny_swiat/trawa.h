#pragma once

#include "Roslina.h"

class Trawa : public Roslina {
public:
	Trawa(int x, int y, Swiat &swiat) : Roslina(wiek, 0, 0, x, y,'t', swiat) {};
	void Kolizja(Organizm *&napastnik, bool atak, int kol, int wier);

	void Rysuj();
};