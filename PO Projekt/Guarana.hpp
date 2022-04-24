#include "Roslina.hpp"

class Guarana : public Roslina {
public:
	Guarana(Swiat& swiat, int x, int y) : Roslina(swiat, x, y, 0, 'G') {}
	void akcja() override;
	void rysowanie() const override;
	bool eatenBy(Organizm& organizm) override;
	void wypisz() const override { std::cout << "Guarana"; }
};
