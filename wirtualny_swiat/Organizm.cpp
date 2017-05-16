#include "stdafx.h"
#include "conio2.h"
#include "Organizm.h"
#include "Swiat.h"

#include<iostream>
Organizm::Organizm(int wiek, int sila, int inicjatywa, int x, int y, char gat, Swiat &swiat) :
	 wiek(swiat.ktora_tura), sila(sila), inicjatywa(inicjatywa), wspx(x), wspy(y),gatunek(gat), sw(swiat) {};

int a;

void Organizm::miejsce_nowy(int x, int y,int kol, int wier) {
	if (a == 5)a = 0;
	if (this->gatunek != 'C'){
		if (this->sw.sprawdz_indeks(x - 1, y - 1) == -1) { // lewo gora
			if (x - 1 >= 0 && x - 1 < kol + 21 && y - 1 >= 0 && y - 1 < wier + 21) {

				this->sw.NowyOrg(x - 1, y - 1, this->gatunek);
				gotoxy(kol + 1, wier + 27 + a);
				std::cout << this->gatunek << " rozmnozyl sie na polu " << x << '/' << y << std::endl;
				a++;
				return;
			}
		}


		if (this->sw.sprawdz_indeks(x, y - 1) == -1) { // gora
			if (x >= 0 && x < kol + 21 && y - 1 >= 0 && y - 1 < wier + 21) {
				this->sw.NowyOrg(x, y - 1, this->gatunek);
				gotoxy(kol + 1, wier + 27 + a);

				std::cout << this->gatunek << " rozmnozyl sie na polu " << x << '/' << y << std::endl;
				a++;
				return;
			}
		}


		if (this->sw.sprawdz_indeks(x + 1, y - 1) == -1) { // prawo gora
			if (x + 1 >= 0 && x + 1 < kol + 21 && y - 1 >= 0 && y - 1 < wier + 21) {
				this->sw.NowyOrg(x + 1, y - 1, this->gatunek);
				gotoxy(kol + 1, wier + 27 + a);

				std::cout << this->gatunek << " rozmnozyl sie na polu " << x << '/' << y << std::endl;
				a++;
				return;
			}
		}


		if (this->sw.sprawdz_indeks(x - 1, y) == -1) { // lewo
			if (x - 1 >= 0 && x - 1 < kol + 21 && y >= 0 && y < wier + 21) {
				this->sw.NowyOrg(x - 1, y, this->gatunek);
				gotoxy(kol + 1, wier + 27 + a);

				std::cout << this->gatunek << " rozmnozyl sie na polu " << x << '/' << y << std::endl;
				a++;
				return;
			}
		}


		if (this->sw.sprawdz_indeks(x + 1, y) == -1) { // prawo
			if (x + 1 >= 0 && x + 1 < kol + 21 && y >= 0 && y < wier + 21) {
				this->sw.NowyOrg(x + 1, y, this->gatunek);
				gotoxy(kol + 1, wier + 27 + a);

				std::cout << this->gatunek << " rozmnozyl sie na polu " << x << '/' << y << std::endl;
				a++;
				return;
			}
		}


		if (this->sw.sprawdz_indeks(x - 1, y + 1) == -1) { // lewo dol
			if (x - 1 >= 0 && x - 1 < kol + 21 && y + 1 >= 0 && y + 1 < wier + 21) {
				this->sw.NowyOrg(x - 1, y + 1, this->gatunek);
				gotoxy(kol + 1, wier + 27 + a);

				std::cout << this->gatunek << " rozmnozyl sie na polu " << x << '/' << y << std::endl;
				a++;
				return;
			}
		}


		if (this->sw.sprawdz_indeks(x, y + 1) == -1) { // dol
			if (x >= 0 && x < kol + 21 && y + 1 >= 0 && y + 1 < wier + 21) {
				this->sw.NowyOrg(x, y + 1, this->gatunek);
				gotoxy(kol + 1, wier + 27 + a);

				std::cout << this->gatunek << " rozmnozyl sie na polu " << x << '/' << y << std::endl;
				a++;
				return;
			}
		}


		if (this->sw.sprawdz_indeks(x + 1, y + 1) == -1) { // prawo dol
			if (x + 1 >= 0 && x + 1 < kol + 21 && y + 1 >= 0 && y + 1 < wier + 21) {
				this->sw.NowyOrg(x + 1, y + 1, this->gatunek);
				gotoxy(kol + 1, wier + 27 + a);

				std::cout << this->gatunek << " rozmnozyl sie na polu " << x << '/' << y << std::endl;
				a++;
				return;
			}
		}
	}
}