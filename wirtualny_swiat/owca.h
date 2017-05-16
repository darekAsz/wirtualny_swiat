#pragma once

#include "Zwierze.h"

class Owca : public Zwierze {
public:
	Owca(int x, int y, Swiat &swiat) : Zwierze(wiek, 4, 4,  x, y,'o', swiat) {};
	void Rysuj();
};