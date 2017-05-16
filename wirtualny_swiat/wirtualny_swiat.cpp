#include "stdafx.h"
#include "conio2.h"
#include <iostream>
#include "Swiat.h"

using namespace std;
int kol = 15;
int wier =15 ;





int main()
{
	Swiat swiat = Swiat();
	swiat.OrganizmyPoczatek(kol,wier);
	swiat.stworz_swiat(kol,wier);
	int zn; //obsluga klawiszy
	zn = getch();
	while (/*std::cin.get() == '\n'*/zn != 'q') {
		system("cls");
		
		swiat.wykonajTure(kol,wier);
		zn = getch();

	}

 
	settitle("Darek Asztemborski 155021");						//wskx,wsky-uzyte w tablicy: tab[wsky][wskx
	textbackground(WHITE);
	textcolor(RED);
	
	
	cin.get();
	return 0;
}

