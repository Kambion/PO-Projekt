#pragma once

#include "Organizm.hpp"

class Roslina : public Organizm {
public:
	Roslina(Swiat& swiat) : Organizm(swiat) {}
	void akcja() override;
	void kolizja() override;
	void rysowanie() const override;
};