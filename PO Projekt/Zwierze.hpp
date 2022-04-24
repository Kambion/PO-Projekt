#pragma once

#include "Organizm.hpp"

class Zwierze : public Organizm {
public:
	Zwierze(Swiat& swiat, int x, int y, int sila, int inicjatywa, char litera) : Organizm(swiat, x, y, sila, inicjatywa, litera) {}
	void akcja() override;
	void rysowanie() const override;
	bool eatenBy(Organizm& organizm) override { return false; }
};
