#include <iostream>
#include <time.h>
#include "Swiat.hpp"

int main()
{
	srand(time(NULL));
	Swiat swiat(20, 20);
	swiat.dodajOrganizm(3, 3, Organizmy::ZWIERZE);
	swiat.dodajOrganizm(2, 3, Organizmy::ZWIERZE);
	swiat.dodajOrganizm(3, 2, Organizmy::ZWIERZE);
	swiat.dodajOrganizm(3, 4, Organizmy::ZWIERZE);
	swiat.dodajOrganizm(4, 3, Organizmy::ZWIERZE);
	swiat.dodajOrganizm(2, 2, Organizmy::ZWIERZE);
	swiat.dodajOrganizm(3, 7, Organizmy::ROSLINA);
	swiat.dodajOrganizm(15, 5, Organizmy::ZWIERZE);
	swiat.rysujSwiat();
	for (int i = 0; i < 3; i++) {
		swiat.wykonajTure();
		std::cout << "***************************\n";
		swiat.rysujSwiat();
	}
}

