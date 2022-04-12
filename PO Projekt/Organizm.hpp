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

class Organizm {
protected:
	int sila;
	int inicjatywa;
	Position position;
	Swiat& swiat;
public:
	Organizm(Swiat& swiat, int x, int y) : swiat(swiat), position{ x, y }{}
	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() const = 0;
};