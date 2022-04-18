#pragma once
#include "Zwierze.hpp"

class Owca : public Zwierze {
public:
	Owca(Swiat& swiat, int x, int y) : Zwierze(swiat, x, y, 4, 4) {}
	Position kolizja(Organizm* other) override;
	void rysowanie() const override;
	void wypisz() const override { std::cout << "Owca"; }
};
