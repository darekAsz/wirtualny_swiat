#include "stdafx.h"

#include "Swiat.h"
#include "Roslina.h"
#include <stdlib.h>


void Roslina::Akcja(Organizm *&napastnik,int kol, int wier) {
	int szansa = (std::rand() % 10) + 0;

	if (szansa == 0)
		this->miejsce_nowy(this->wspx, this->wspy, kol,  wier);
}

void Roslina::Kolizja(Organizm *&napastnik, bool atak, int kol, int wier) {
	if (napastnik != NULL) {
		if (this->sila > napastnik->sila) {
			int indeks = this->sw.sprawdz_indeks(napastnik->wspx, napastnik->wspy);
			this->sw.organizmy[indeks] = NULL;
		}
	}
}