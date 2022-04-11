#pragma once

#include "Organizm.hpp"

class Zwierze : public Organizm {
public:
	Zwierze(Swiat& swiat) : Organizm(swiat) {}
	void akcja() override;
	void kolizja() override;
	void rysowanie() const override;
};
