#pragma once
#include <iostream>
#include "Swiat.hpp"

class Swiat;

struct Position
{
	int x;
	int y;
	bool operator==(Position other) {
		return (x == other.x && y == other.y);
	}
};
constexpr Position graniceMapy{ -1,-1 };
constexpr Position martwy{ -2,-2 };

class Organizm {
protected:
	int sila;
	int inicjatywa;
	Position position;
	Swiat& swiat;
public:
	Organizm(Swiat& swiat, int x, int y, int sila, int inicjatywa) : swiat(swiat), position{ x, y }, sila(sila), inicjatywa(inicjatywa){}
	bool silniejszy(int otherSila) { return sila > otherSila; }
	Position getPosition() { return position; }
	void zwiekszSile(int x) { sila += x; }
	virtual bool eatenBy(Organizm& organizm) = 0;
	virtual void akcja() = 0;
	virtual Position kolizja(Organizm* other) = 0;
	virtual void rysowanie() const = 0;
};