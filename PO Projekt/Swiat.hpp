#pragma once
#include <memory>
#include "Organizm.hpp"

enum class Organizmy {
	ZWIERZE,
	ROSLINA
};

class Swiat {
public:
	Swiat(int sizeX, int sizeY);
	void wykonajTure();
	void rysujSwiat();
	void dodajOrganizm(int x, int y, Organizmy organizm);
	~Swiat();
private:
	int sizeX;
	int sizeY;
	Organizm*** plansza;
};
