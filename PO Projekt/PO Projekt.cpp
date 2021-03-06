#include <iostream>
#include <time.h>
#include "Swiat.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "Projekt PO \n";
	std::cout << "Jakub Radgowski 188669 \n";
	std::cout << '\n';
	std::cout << "[N] - rozpocznij nowa symulacje\n";
	std::cout << "[L] - wczytaj symulacje\n";
	char input = getchar();
	int x = 20, y = 20;
	if (input == 'N') {
		std::cout << "Podaj wymiary planszy\n";
		std::cin >> x >> y;
		Swiat swiat(x, y);
		swiat.dodajOrganizm(3, 3, Typ::ZOLW);
		swiat.dodajOrganizm(2, 3, Typ::OWCA);
		swiat.dodajOrganizm(3, 2, Typ::WILK);
		swiat.dodajOrganizm(3, 4, Typ::TRAWA);
		swiat.dodajOrganizm(4, 3, Typ::ANTYLOPA);
		swiat.dodajOrganizm(2, 2, Typ::OWCA);
		swiat.dodajOrganizm(3, 7, Typ::GUARANA);
		swiat.dodajOrganizm(15, 5, Typ::OWCA);
		swiat.dodajOrganizm(15, 6, Typ::JAGODY);
		swiat.dodajOrganizm(14, 4, Typ::OWCA);
		swiat.dodajOrganizm(3, 14, Typ::TRAWA);
		swiat.dodajOrganizm(13, 14, Typ::TRAWA);
		swiat.dodajOrganizm(15, 15, Typ::BARSZCZ);
		swiat.dodajOrganizm(7, 7, Typ::LIS);
		swiat.dodajOrganizm(19, 7, Typ::MLECZYK);
		swiat.dodajOrganizm(16, 11, Typ::CZLOWIEK);
		swiat.symuluj();
	}
	else if (input == 'L') {
		std::fstream plik;
		plik.open("save_size.bin", std::ios::in | std::ios::binary);
		if (plik.is_open()) {
			plik.read((char*)&x, sizeof(x));
			plik.read((char*)&y, sizeof(y));
			plik.close();
		}
		Swiat swiat(x, y);
		swiat.wczytajStan();
		swiat.symuluj();
	}
	return 0;
}

