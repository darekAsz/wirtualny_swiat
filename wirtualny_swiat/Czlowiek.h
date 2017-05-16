#pragma once

#include "Zwierze.h"
#include <iostream>
class Czlowiek : public Zwierze
{
public:
	void Akcja(Organizm *&obronca, int kol, int wier);

	void Rysuj();

	Czlowiek(int x, int y, Swiat &swiat) : Zwierze(wiek, 5, 4, x, y, 'C', swiat) {};
};



