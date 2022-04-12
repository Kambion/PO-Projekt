#pragma once

#include "Organizm.hpp"

class Zwierze : public Organizm {
public:
	Zwierze(Swiat& swiat, int x, int y, int sila, int inicjatywa) : Organizm(swiat, x, y, sila, inicjatywa) {}
	void akcja() override;
	void rysowanie() const override;
	bool eatenBy(Organizm& organizm) override { return false; }
};
