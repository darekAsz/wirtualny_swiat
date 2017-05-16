#pragma once

#include "Zwierze.h"

class Zolw : public Zwierze {
public:
	Zolw(int x, int y, Swiat &swiat) : Zwierze(wiek, 2, 1, x, y, 'z', swiat) {};

	void Rysuj();
};