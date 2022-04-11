#pragma once
#include <iostream>
#include "Swiat.hpp"

class Swiat;

struct Position
{
	int x;
	int y;
};

class Organizm {
protected:
	int sila;
	int inicjatywa;
	Position position;
	Swiat& swiat;
public:
	Organizm(Swiat& swiat) : swiat(swiat){}
	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() const = 0;
};