#pragma once

#include "Zwierze.h"

class Lis : public Zwierze {
public:
	Lis(int x, int y, Swiat &swiat) : Zwierze(wiek, 3, 7, x, y, 'l', swiat) {};
	void Rysuj();
};