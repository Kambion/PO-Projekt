#pragma once

#include "Organizm.hpp"

class Roslina : public Organizm {
public:
	Roslina(Swiat& swiat, int x, int y) : Organizm(swiat, x , y) {}
	void akcja() override;
	void kolizja() override;
	void rysowanie() const override;
};