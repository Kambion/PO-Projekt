#include <iostream>
#include "Swiat.hpp"

int main()
{
	Swiat swiat(20, 20);
	swiat.dodajOrganizm(3, 3, Organizmy::ZWIERZE);
	swiat.dodajOrganizm(3, 7, Organizmy::ROSLINA);
	swiat.dodajOrganizm(15, 5, Organizmy::ZWIERZE);
	swiat.rysujSwiat();
}

