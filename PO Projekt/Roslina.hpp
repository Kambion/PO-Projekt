#pragma once

#include "Organizm.hpp"

class Roslina : public Organizm {
public:
	Roslina(Swiat& swiat, int x, int y) : Organizm(swiat, x , y, 0, 0) {}
	void akcja() override;
	Position kolizja(Organizm* other) override;
	void rysowanie() const override;
};