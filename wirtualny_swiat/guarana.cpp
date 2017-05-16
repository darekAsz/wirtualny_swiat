#include "stdafx.h"
#include "Swiat.h"

#include "guarana.h"
#include<iostream>

void Guarana::Rysuj() {
	std::cout << 'g';
}

void Guarana::Kolizja(Organizm *&atakujacy, bool atak,int kol, int wier) {
	atakujacy->sila=atakujacy->sila + 3;
	//int iAtakowany = this->sw.OrganizmNaPolu(this->wspx, this->wspy);
	//atakujacy->wspx = this->wspx;
	//atakujacy->wspy = this->wspy;
	//std::cout << atakujacy->gatunek << " zjadl " << this->gatunek << std::endl;
	//this->sw.organizmy[iAtakowany] = NULL;

}