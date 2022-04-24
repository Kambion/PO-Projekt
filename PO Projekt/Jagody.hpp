#include "Roslina.hpp"

class Jagody : public Roslina {
public:
	Jagody(Swiat& swiat, int x, int y) : Roslina(swiat, x, y, 99, 'J') {}
	void akcja() override;
	void rysowanie() const override;
	bool eatenBy(Organizm& organizm) override;
	void wypisz() const override { std::cout << "Jagody"; }
};
