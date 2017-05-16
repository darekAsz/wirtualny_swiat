#include "stdafx.h"

#include "Antylopa.h"
#include "Zwierze.h"
#include "Swiat.h"
#include<iostream>

void Antylopa::Rysuj() {
	std::cout << 'a';
}

void Antylopa::Akcja(Organizm *&obronca, int kol, int wier) {

	for (int i = 0; i<2; i++)
		Zwierze::Akcja(obronca, kol, wier);		//daw pola sie porusza
}

void Antylopa::Kolizja(Organizm *&obronca, bool atak, int kol, int wier) {
	if (atak == true)
		Zwierze::Kolizja(obronca, true, kol, wier);
	else
		this->ucieczka(this->wspx, this->wspy, obronca, kol, wier);
}

void Antylopa::ucieczka(int x, int y, Organizm *&napastnik, int kol, int wier) {
	int szansa = (std::rand() % 2) + 0;
	int bylyX = this->wspx;
	int bylyY = this->wspy;
	bool uciekla = false;

	if (szansa == 0) {
		if (this->sw.sprawdz_indeks(x - 1, y - 1) == -1) { // lewo gora
			if (x - 1 >= 0 && x - 1 <kol+21 && y - 1 >= 0 && y - 1<wier+20) {
				this->wspx=x-1;
				this->wspy = y - 1;
				uciekla = true;
			}
		}


		else if (this->sw.sprawdz_indeks(x, y - 1) == -1) { // gora
			if (x >= 0 && x <kol+21 && y - 1 >= 0 && y - 1<wier+21) {
				this->wspx = x;
				this->wspy=y-1;
				uciekla = true;
			}
		}



		else if (this->sw.sprawdz_indeks(x + 1, y - 1) == -1) { // prawo gora
			if (x + 1 >= 0 && x + 1 <kol+21 && y - 1 >= 0 && y - 1<wier+21) {
				this->wspx=x;
				this->wspy=y-1;
				uciekla = true;
			}
		}



		else if (this->sw.sprawdz_indeks(x - 1, y) == -1) { // lewo
			if (x - 1 >= 0 && x - 1 <kol+21 && y >= 0 && y<wier+21) {
				this->wspx=x-1;
				this->wspy=y;
				uciekla = true;
			}
		}



		else if (this->sw.sprawdz_indeks(x + 1, y) == -1) { // prawo
			if (x + 1 >= 0 && x + 1 <kol+21 && y >= 0 && y<wier+21) {
				this->wspx=x+1;
				this->wspy=y;
				uciekla = true;
			}
		}



		else if (this->sw.sprawdz_indeks(x - 1, y + 1) == -1) { // lewo dol
			if (x - 1 >= 0 && x - 1 <kol+21 && y + 1 >= 0 && y + 1<wier+21) {
				this->wspy=y+1;
				uciekla = true;
			}
		}



		else if (this->sw.sprawdz_indeks(x, y + 1) == -1) { // dol
			if (x >= 0 && x <kol+21 && y + 1 >= 0 && y + 1<wier+21) {
				this->wspx=x;
				this->wspy=y+1;
				uciekla = true;
			}
		}



		else if (this->sw.sprawdz_indeks(x + 1, y + 1) == -1) { // prawo dol
			if (x + 1 >= 0 && x + 1 <kol+21 && y + 1 >= 0 && y + 1<wier+21) {
				this->wspx=x+1;
				this->wspy=y+1;
				uciekla = true;
			}
		}
	}



	if (uciekla) { // antylopie udalo sie uciec
		napastnik->wspx = bylyX;
		napastnik->wspy = bylyY;
		std::cout << this->gatunek << " uciekla" << std::endl;
	}
	else {
		int indeksAntylopy = this->sw.sprawdz_indeks(this->wspx, this->wspy);
		napastnik->wspx = this->wspx;
		napastnik->wspy = this->wspy;
		std::cout << napastnik->gatunek << " zjadl " << this->gatunek << std::endl;
		this->sw.organizmy[indeksAntylopy] = NULL;
	}
}