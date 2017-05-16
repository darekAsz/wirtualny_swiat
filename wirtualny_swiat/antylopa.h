#pragma once

#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa(int x, int y, Swiat &swiat) : Zwierze(wiek, 4, 4,  x, y,'a', swiat) {};
	void Rysuj();


	void Akcja(Organizm *&obronca,int kol, int wier);

	void Kolizja(Organizm *&obronca, bool atak,int kol, int wier);
	void ucieczka(int x, int y, Organizm *&napastnik,int kol, int wier);
};