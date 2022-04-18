#pragma once
#include <memory>
#include <list>
#include "Organizm.hpp"
#include "Matrix.h"

constexpr int maxInicjatywa = 8;

struct Position;
class Organizm;

enum class Typ {
	WILK,
	OWCA,
	TRAWA,
	MLECZYK,
	GUARANA,
	JAGODY,
	BARSZCZ,
	LIS,
	ZOLW,
	ANTYLOPA,
	CZLOWIEK
};

class Swiat {
private:
	int sizeX;
	int sizeY;
	Matrix<std::unique_ptr<Organizm>> plansza;
	std::list<Organizm*> organizmy;
	void wykonajTure();
	void rysujSwiat();
	bool koniec = false;
public:
	void symuluj();
	void zakonczSymulacje();
	Swiat(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY), plansza(sizeX, sizeY) {}
	inline int getSizeX() { return sizeX; }
	inline int getSizeY() { return sizeY; }
	bool dodajOrganizm(int x, int y, Typ organizm);
	void usunOrganizm(Organizm* organizm);
	void zabij(int x, int y);
	int getSila(Position position);
	Position ruszOrganizm(Position position, Position newPosition);
};
