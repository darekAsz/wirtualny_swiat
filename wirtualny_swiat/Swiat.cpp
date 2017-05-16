#include "stdafx.h"
#include "Swiat.h"
#include "Organizm.h"
#include "Wilk.h"
#include "owca.h"
#include "antylopa.h"
#include "guarana.h"
#include "trawa.h"
#include "zolw.h"
#include "lis.h"
#include "mlecz.h"
#include "jagody.h"
#include "Czlowiek.h"

#include<vector>

#include "conio2.h"
#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int gat = 2;

void Swiat::stworz_swiat(int kol, int wier){
	//rysowanie planszy
	gotoxy(kol, wier);
	cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187;

	for (int i = 1; i <= 20; i++){
		gotoxy(kol, wier + i);
		cout << (char)186;
		gotoxy(kol + 21, wier + i);
		cout << (char)186;
	}
	gotoxy(kol, wier + 21);
	cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188;

	//komunikaty
	gotoxy(kol, wier + 25);
	cout << "Komunikaty";

	gotoxy(kol, wier + 26);
	cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187;

	for (int i = 27; i <= 30; i++){
		gotoxy(kol, wier + i);
		cout << (char)186;
		gotoxy(kol + 41, wier + i);
		cout << (char)186;
	}

	gotoxy(kol, wier + 31);
	cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188;

	//organizmy	
	Organizm *organizm = NULL;


	for (int i = (kol + 1); i <= (kol + 20); i++){
		for (int j = (wier + 1); j <=( wier + 20); j++){
			int x = 0, y = 0;
			for (int d = 0; d < this->organizmy.size(); d++) {
				if (this->organizmy[d]->wspx == i && this->organizmy[d]->wspy == j){
					organizm = organizmy[d];
					x = i;
					y = j;

					break;
				}
			}
			if (organizm){

				gotoxy(x, y);
				organizm->Rysuj();
			}
			else{
				gotoxy(x, y);
			//	cout << ".";
			}
			organizm = NULL;

		}

	}

}
	void Swiat::NowyOrg(int x, int y, char gatun){
		Organizm* dodaj ;

		if (gatun == 'w'){
			
			dodaj = new Wilk(x, y, *this);
			organizmy.push_back(dodaj);
			cout << organizmy.size();		
			 //dodaje nowy element na koñcu kontenera vector. 
		}
		if (gatun == 'o'){
		dodaj = new Owca(x, y, *this);	//stworz nowy obiekt
		organizmy.push_back(dodaj);		//dodaj na koncu listy
		}
		if (gatun == 'l'){
		dodaj = new Lis(x, y, *this);
		organizmy.push_back(dodaj);
		}
		if (gatun == 'z'){
		dodaj = new Zolw(x, y, *this);
		organizmy.push_back(dodaj);
		}
		if (gatun == 'a'){
		dodaj = new Antylopa(x, y, *this);
		organizmy.push_back(dodaj);
		}
		if (gatun == 't'){
		dodaj = new Trawa(x, y, *this);
		organizmy.push_back(dodaj);
		}
		if (gatun == 'm'){
		dodaj = new Mlecz(x, y, *this);
		organizmy.push_back(dodaj);
		}
		if (gatun == 'g'){
		dodaj = new Guarana(x, y, *this);
		organizmy.push_back(dodaj);
		}
		if (gatun == 'j'){
		dodaj = new Jagody(x, y, *this);
		organizmy.push_back(dodaj);
		}
		if (gatun == 'C'){
			dodaj = new Czlowiek(x, y, *this);
			organizmy.push_back(dodaj);
		}
	
	}

	void Swiat::OrganizmyPoczatek(int kol, int wier) {
		this->ktora_tura = 0;
		int ilosc_org_na_poczatku = 10;
		srand(time(NULL));

		for (int i = 0; i<ilosc_org_na_poczatku; i++) {
			int x = (std::rand() % 20) + (kol + 1);
			int y = (std::rand() % 20) + (wier + 1);
			int gatunek = (std::rand() % 9) + 0;

			if (gatunek == 0 )  NowyOrg(x, y, 'w');
			 if (gatunek == 1) NowyOrg(x, y, 'o');
			if (gatunek == 2) NowyOrg(x, y, 'l');
			if (gatunek == 3) NowyOrg(x, y, 'z');
			if (gatunek == 4) NowyOrg(x, y, 'a');
			if (gatunek == 5) NowyOrg(x, y, 't');
			if (gatunek == 6) NowyOrg(x, y, 'm');
			 if (gatunek == 7) NowyOrg(x, y, 'g');
			if (gatunek == 8) NowyOrg(x, y, 'j');
			if (gat == 2){
				NowyOrg(x, y, 'C');
				gat++;
			}

		}
	}
	int Swiat::sprawdz_indeks(int x, int y) {
		int indeks = -1;
		for (int i = 0; i<this->organizmy.size(); i++) {
			if (this->organizmy[i] != NULL) {
				if (this->organizmy[i]->wspx == x && this->organizmy[i]->wspy == y) {
					indeks = i;		//zwraca indeks organizmu ktory jest na danym polu
					break;
				}
			}
		}
		return indeks;
	}


	bool Swiat::Porinicj(Organizm *a, Organizm *b) {
		if (a->inicjatywa == b->inicjatywa)return (a->wiek< b->wiek);
		else return (a->inicjatywa > b->inicjatywa);}
	
	void Swiat::wyczysc_zabite() {
		for (int i = 0; i<this->organizmy.size(); i++) {
			if (this->organizmy[i] == NULL) {
				this->organizmy.erase(this->organizmy.begin() + i);
				--i;
			}
		}
	}			

	void Swiat::wykonajTure(int kol, int wier) {
		Organizm *atakowany = NULL;
		bool atak = true;
		this->ktora_tura++;
		std::sort(this->organizmy.begin(), this->organizmy.end(), this->Porinicj);
		for (int i = 0; i<this->organizmy.size(); i++) {
			if (this->organizmy[i] != NULL && this->organizmy[i]->wiek != ktora_tura) {
				this->organizmy[i]->Akcja(atakowany, kol, wier);		//wykonanie akcji po kolei
				if (this->organizmy[i]->gatunek != 't' && this->organizmy[i]->gatunek != 'g' && this->organizmy[i]->gatunek != 'm'){
					this->organizmy[i]->Kolizja(atakowany, atak, kol, wier);		//sprawdzanie kolizji			
				}		
			}
		}
		this->wyczysc_zabite();
		this->stworz_swiat(kol,wier);
	}
