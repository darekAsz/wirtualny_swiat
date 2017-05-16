#include "stdafx.h"
#include "Swiat.h"
#include "Zwierze.h"
#include "Czlowiek.h"
#include <iostream>
#include "conio2.h"

int licz;
bool zdolnosc = false;
int pierwsza;
void Czlowiek::Akcja(Organizm *&atakowany, int kol, int wier) {
	int ruch;
	ruch = getch();
	int X = this->wspx;
	int Y = this->wspy;
	if (zdolnosc == true && licz<=5){
		licz++;
		this->sila=this->sila-1;
		cout << this->sila;

	}
	
	if ((ruch == 0x48) && (this->wspy > wier + 1))			//poruszanie w gore
	{	//this->wspy--;
		Y--;
	}
	else if ((ruch == 0x50) && (wspy<wier + 20)) 		//poruszanie w dol
	{
	//	this->wspy++;
		Y++;
	}
	else if ((ruch == 0x4b) && (this->wspx>kol + 1)) 		//poruszanie w lewo	
	{
		X--;
		//this->wspx--;
	}
	else if ((ruch == 0x4d) && (this->wspx < kol + 20)) 		//poruszanie w prawo
	{
		X++;
		//this->wspx++;
	}
	 if ((ruch == ' ') ) 		
	{
		if (zdolnosc == false);	
		{zdolnosc = true;
		int pierwsza = this->sila;
		this->sila = 10;


		}
	}
	if (licz == 5){
		zdolnosc = false;
		this->sila = pierwsza;
		licz = 0;
	}

	int iThis = sw.sprawdz_indeks(X, Y);
	int indeks_obronca;



	if (X > kol && X <= (kol + 20) && Y > wier && Y <= (wier + 20)) {
		indeks_obronca = sw.sprawdz_indeks(X, Y);
		if (indeks_obronca != -1) {						//jesli na tym polu jest jakis organizm
			atakowany = sw.organizmy[indeks_obronca];		//atakowany-ten co jest na tym polu
		}
		else {				//jesli nie ma nikogo na tym polu to przesun tam
			atakowany = NULL;
			

			this->wspx = X;
			this->wspy = Y;

			//}
		}

	}
}

void Czlowiek::Rysuj() {
	std::cout << 'C';
}
