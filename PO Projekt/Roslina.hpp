#pragma once

#include "Organizm.hpp"

class Roslina : public Organizm {
public:
	Roslina(Swiat& swiat, int x, int y, int sila, char litera) : Organizm(swiat, x , y, sila, 0, litera) {}
	Position kolizja(Organizm* other) override;
	bool eatenBy(Organizm& organizm) override { return false; }
};