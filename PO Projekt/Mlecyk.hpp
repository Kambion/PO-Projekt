#include "Roslina.hpp"

class Mleczyk : public Roslina {
public:
	Mleczyk(Swiat& swiat, int x, int y) : Roslina(swiat, x, y, 0, 'M') {}
	void akcja() override;
	void rysowanie() const override;
	void wypisz() const override { std::cout << "Mleczyk"; }
};
