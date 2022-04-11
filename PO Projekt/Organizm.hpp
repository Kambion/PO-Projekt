#pragma once
#include <iostream>

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
public:
	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() const = 0;
};