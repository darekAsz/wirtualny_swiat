#include "stdafx.h"
#include "Swiat.h"

#include "Trawa.h"
#include<iostream>

void Trawa::Rysuj() {
	std::cout << 't';
}

void Trawa::Kolizja(Organizm *&napastnik, bool atak, int kol, int wier) {

	int indeks_atakowany = this->sw.sprawdz_indeks(this->wspx, this->wspy);
	napastnik->wspx = this->wspx;
	napastnik->wspy = this->wspy;
	std::cout << napastnik->gatunek << " zjadl " << this->gatunek << std::endl;
	this->sw.organizmy[indeks_atakowany] = NULL;
}