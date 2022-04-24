#include "Zwierze.hpp"

class Antylopa : public Zwierze {
public:
	Antylopa(Swiat& swiat, int x, int y) : Zwierze(swiat, x, y, 4, 4, 'A') {}
	Position kolizja(Organizm* other) override;
	void rysowanie() const override;
	void akcja() override;
	Zachowanie obronil(int otherSila) override;
	void wypisz() const override { std::cout << "Antylopa"; }
};
