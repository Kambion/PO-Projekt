#include "Zwierze.hpp"

class Wilk : public Zwierze {
public:
	Wilk(Swiat& swiat, int x, int y) : Zwierze(swiat, x, y, 9, 5) {}
	Position kolizja(Organizm* other) override;
	void rysowanie() const override;
	void wypisz() const override { std::cout << "Wilk"; }
};
