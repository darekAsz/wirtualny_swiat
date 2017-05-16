#include "stdafx.h"
#include "Swiat.h"

#include "jagody.h"
#include<iostream>

void Jagody::Rysuj() {
	std::cout << 'j';
}

//void Jagody::Kolizja(Organizm *&atakujacy, bool atak,int kol, int wier) {
//	int iAtakowany = this->sw.OrganizmNaPolu(this->wspx, this->wspy);
//	atakujacy->wspx = this->wspx;
//	atakujacy->wspy = this->wspy;
//	std::cout << atakujacy->gatunek << " zjadl " << this->gatunek << std::endl;
//	this->sw.organizmy[iAtakowany] = NULL;
//}