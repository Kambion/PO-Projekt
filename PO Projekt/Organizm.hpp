#pragma once

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
	virtual void akcja();
	virtual void kolizja();
	virtual void rysowanie();
};