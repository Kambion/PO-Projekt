#include "Zwierze.hpp"

class Lis : public Zwierze {
public:
	Lis(Swiat& swiat, int x, int y) : Zwierze(swiat, x, y, 3, 7, 'L') {}
	Position kolizja(Organizm* other) override;
	void rysowanie() const override;
	void akcja() override;
	void wypisz() const override { std::cout << "Lis"; }
};
