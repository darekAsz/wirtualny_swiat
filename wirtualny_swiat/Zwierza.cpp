#include "stdafx.h"

#include "Swiat.h"
#include "Zwierze.h"
#include <stdlib.h>
#include <iostream>


Zwierze::Zwierze(int wiek, int sila, int inicjatywa, int x, int y,char gatunek, Swiat &swiat) 
: Organizm(wiek, sila, inicjatywa,  x, y,gatunek, swiat) {};



void Zwierze::Akcja(Organizm *&obronca,int kol, int wier) {
	
	int X = this->wspx;
	int Y = this->wspy;
	int iThis = sw.sprawdz_indeks(X, Y);
	int indeks_obroncy;
	
		int liczba = rand() % 8;		//losowanie ruchu jednostki
		//switch (los) {
		if (liczba == 0){	// w lewo i w gore
			X--;
			Y--;
		}

		else if(liczba==1)	// w gore
			Y--;

		else if (liczba == 2){		// w prawo i w gore
			X++;
			Y--;
		}

		else if (liczba==3)	// w lewo
			X--;

		else if (liczba==4)	// w prawo
			X++;

		else if (liczba == 5){	// w lewo i w dol
			X--;
			Y++;
		}

		else if (liczba==6)	// w dol
			Y++;

		else if (liczba == 7){	// w prawo i w dol
			X++;
			Y++;
		}

	







	if (X > kol && X <(kol+20) && Y > wier && Y<(wier+20)) {
		indeks_obroncy = sw.sprawdz_indeks(X, Y);
		if (indeks_obroncy != -1) {						//jesli na tym polu jest jakis organizm
			obronca = sw.organizmy[indeks_obroncy];		//atakowany-ten co jest na tym polu
		}
		else {				//jesli nie ma nikogo na tym polu to przesun tam
			obronca = NULL;
			if (this->gatunek == 'z')		//dla zolwia 1/4
			{
				liczba = rand() % 4;
				if (liczba == 0){
					this->wspx = X;
					this->wspy = Y;
				}
			}
			else {
				this->wspx = X;
				this->wspy = Y;
			}
		}
	}
	}

void Zwierze::Kolizja(Organizm *&obronca, bool atak,int kol, int wier) {

	if (obronca != NULL) {

		if (this->gatunek == obronca->gatunek) {		//rozmnazanie
			int indeks_obroncy = sw.sprawdz_indeks(obronca->wspx, obronca->wspy);
			miejsce_nowy(sw.organizmy[indeks_obroncy]->wspx, sw.organizmy[indeks_obroncy]->wspy, kol, wier);
		}

		else {		//walka
			if (this->sila >= obronca->sila && obronca->gatunek == 'a') {		//dla antylopy
				Organizm *napastnik = this;
				obronca->Kolizja(napastnik, false, kol, wier);
			}
			/*else if (this->sila >= atakowany->sila && atakowany->gatunek == 'm') {
				Organizm *atakujacy = this;
				atakowany->Kolizja(atakujacy, true,kol,wier);
			}*/
			else if (this->sila >= obronca->sila && obronca->gatunek == 't') {		//dla trawy
				Organizm *napastnik = this;
				obronca->Kolizja(napastnik, true, kol, wier);
			}
			

			else
				this->Walka(obronca, kol,  wier);		//dla reszty walka
		}
	}
}

void Zwierze::Walka(Organizm *&obronca,int kol, int wier) {
	if (this->sila > obronca->sila) {
		if (obronca->gatunek != 'z')		//rozne od zolwia
		{
			Organizm *napastnik = this;
			if (obronca->gatunek == 'g'){		//guarana
				obronca->Kolizja(napastnik, true, kol, wier);
			}
			if (obronca->gatunek == 'm'){		//mlecz
				obronca->Kolizja(napastnik, true, kol, wier);
			}
			if (obronca->gatunek == 'j') {		//jagody
				obronca->Kolizja(napastnik, true, kol, wier);
			}

			int indeks_obroncy = sw.sprawdz_indeks(obronca->wspx, obronca->wspy);		//usuwanie slabszego i przesuwanie silniejszego
			this->wspx = obronca->wspx;
			this->wspy = obronca->wspy;
			if (obronca->gatunek != 'j')std::cout << this->gatunek << " zjadl " << obronca->gatunek << std::endl;
			if (obronca->gatunek == 'j') {		//jesli zjadl jagode to obaj gina
				int iobrony = sw.sprawdz_indeks(this->wspx, this->wspy);
				std::cout << this->gatunek << " ginie bo zjadl jagode " << std::endl;

				sw.organizmy[iobrony] = NULL;
			}

			sw.organizmy[indeks_obroncy] = NULL;
		}
		else {
			if (this->sila > 5){		//silniejsze od zolwia
				Organizm *napastnik = this;
				int indeks_obroncy = sw.sprawdz_indeks(obronca->wspx, obronca->wspy);
				this->wspx = obronca->wspx;
				this->wspy = obronca->wspy;
				std::cout << this->gatunek << " zjadl " << obronca->gatunek << std::endl;
			}
			if (this->sila <= 5){		//slabsze niz moc zolwia
				cout << this->gatunek << "jest na slaby dla " << obronca->gatunek << endl;
				if (sw.sprawdz_indeks(this->wspx - 1, this->wspy - 1)==-1){
					this->wspx = this->wspx - 1;
					this->wspy = this->wspy - 1;
				}
				else if (sw.sprawdz_indeks(this->wspx , this->wspy - 1) == -1){
					this->wspy = this->wspy - 1;
				}
				else if (sw.sprawdz_indeks(this->wspx + 1, this->wspy - 1) == -1){
					this->wspx = this->wspx + 1;
					this->wspy = this->wspy - 1;
				}
				else	if (sw.sprawdz_indeks(this->wspx - 1, this->wspy ) == -1){
					this->wspx = this->wspx - 1;
				}
				else 	if (sw.sprawdz_indeks(this->wspx +1, this->wspy ) == -1){
					this->wspx = this->wspx + 1;
				}
				else 	if (sw.sprawdz_indeks(this->wspx - 1, this->wspy + 1) == -1){
					this->wspx = this->wspx - 1;
					this->wspy = this->wspy + 1;
				}
				else		if (sw.sprawdz_indeks(this->wspx , this->wspy + 1) == -1){
					this->wspy = this->wspy + 1;
				}
				else	if (sw.sprawdz_indeks(this->wspx + 1, this->wspy + 1) == -1){
					this->wspx = this->wspx + 1;
					this->wspy = this->wspy + 1;
				}
			}
		}
	}
	else if (this->sila < obronca->sila) {		//jesli atakujacy jest slabszy
		int indeks = this->sw.sprawdz_indeks(this->wspx, this->wspy);
		std::cout << obronca->gatunek << " zjadl " << this->gatunek << std::endl;
		sw.organizmy[indeks] = NULL;
	}
	else {
		// walke wygrywa atakuj¹cy, jesli organizmy maja ta sama sile
		int indeks_obroncy = sw.sprawdz_indeks(obronca->wspx, obronca->wspy);
		this->wspx = obronca->wspx;
		this->wspy = obronca->wspy;
		std::cout << this->gatunek << " zjadl " << obronca->gatunek << std::endl;
		sw.organizmy[indeks_obroncy] = NULL;
	}
}












//
//
//
//
//
//
//
//void akcja(int a, int kol, int wier){	//a-srand od 1 do 4
//	//bool czyruszyl = false;
//	//while (czyruszyl == false){
//	if (a == 1 && this->wspy <= wier);	//dla 1-gora
//	if (a == 1 && this->wspy > wier){
//		wspy--;
//		//	czyruszyl = true;
//	}
//
//	if (a == 2 && this->wspx >= kol + 21);		//dla 2- w prawo
//	if (a == 2 && this->wspx < kol + 21){
//		wspx++;
//		//czyruszyl = true;
//	}
//
//	if (a == 3 && this->wspy >= wier + 21);		//dla 3- w dol
//	if (a == 3 && this->wspy < wier + 21){
//		wspy--;
//		//	czyruszyl = true;
//	}
//
//	if (a == 4 && this->wspx <= kol);		//dla 4- w lewo
//	if (a == 4 && this->wspx > kol + 21){
//		wspx--;
//		//czyruszyl = true;
//		//	}
//
//	}
//}
//
//
//
//void kolizja(){
//	if (s.tab[wspx][wspy] == gatunek){
//		wspx = poprz_x;
//		wspy = poprz_y;
//
//
//
//
//
//	}
//
//}