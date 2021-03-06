#include "Zwierze.hpp"

class Zolw : public Zwierze {
public:
	Zolw(Swiat& swiat, int x, int y) : Zwierze(swiat, x, y, 2, 1, 'Z') {}
	Position kolizja(Organizm* other) override;
	void rysowanie() const override;
	void akcja() override;
	Zachowanie obronil(int otherSila) override;
	void wypisz() const override { std::cout << "Zolw"; }
};
