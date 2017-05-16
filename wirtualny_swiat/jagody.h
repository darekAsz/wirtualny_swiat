#pragma once

#include "Roslina.h"

class Jagody : public Roslina {
public:
	Jagody(int x, int y, Swiat &swiat) : Roslina(wiek, 0, 0, x, y, 'j', swiat) {};
	//void Kolizja(Organizm *&atakujacy, bool atak,int kol, int wier);
	void Rysuj();
};