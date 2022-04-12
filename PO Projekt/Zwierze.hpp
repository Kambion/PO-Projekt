#pragma once

#include "Organizm.hpp"

class Zwierze : public Organizm {
public:
	Zwierze(Swiat& swiat, int x, int y) : Organizm(swiat, x, y) {}
	void akcja() override;
	void kolizja() override;
	void rysowanie() const override;
};
