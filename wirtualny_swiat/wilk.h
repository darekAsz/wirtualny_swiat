#pragma once

#include "Zwierze.h"

class Wilk : public Zwierze {
public:
	Wilk(int x, int y, Swiat &swiat) : Zwierze(wiek, 9, 5,  x, y,'w', swiat) {};
	void Rysuj();
};