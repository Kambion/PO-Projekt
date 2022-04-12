#include <iostream>
#include <time.h>
#include "Swiat.hpp"

int main()
{
	srand(time(NULL));
	Swiat swiat(20, 20);
	swiat.dodajOrganizm(3, 3, Typ::WILK);
	swiat.dodajOrganizm(2, 3, Typ::OWCA);
	swiat.dodajOrganizm(3, 2, Typ::OWCA);
	swiat.dodajOrganizm(3, 4, Typ::OWCA);
	swiat.dodajOrganizm(4, 3, Typ::BARSZCZ);
	swiat.dodajOrganizm(2, 2, Typ::OWCA);
	swiat.dodajOrganizm(3, 7, Typ::GUARANA);
	swiat.dodajOrganizm(15, 5, Typ::OWCA);
	swiat.dodajOrganizm(15, 6, Typ::OWCA);
	swiat.dodajOrganizm(14, 4, Typ::OWCA);
	swiat.dodajOrganizm(7, 7, Typ::WILK);
	swiat.dodajOrganizm(19, 7, Typ::MLECZYK);

	swiat.rysujSwiat();
	for (int i = 0; i < 5; i++) {
		swiat.wykonajTure();
		std::cout << "***************************\n";
		swiat.rysujSwiat();
	}
}

