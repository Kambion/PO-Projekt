#pragma once
#include <memory>
#include <list>
#include "Organizm.hpp"
#include "Matrix.h"

struct Position;
class Organizm;

enum class Organizmy {
	ZWIERZE,
	ROSLINA
};

class Swiat {
public:
	Swiat(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY), plansza(sizeX, sizeY) {}
	inline int getSizeX() { return sizeX; }
	inline int getSizeY() { return sizeY; }
	void wykonajTure();
	void rysujSwiat();
	void dodajOrganizm(int x, int y, Organizmy organizm);
	Position ruszOrganizm(Position position, Position newPosition);
private:
	int sizeX;
	int sizeY;
	Matrix<std::unique_ptr<Organizm>> plansza;
	std::list<Organizm*> organizmy;
};
