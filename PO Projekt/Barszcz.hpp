#include "Roslina.hpp"

class Barszcz : public Roslina {
public:
	Barszcz(Swiat& swiat, int x, int y) : Roslina(swiat, x, y, 10) {}
	void akcja() override;
	void rysowanie() const override;
	bool eatenBy(Organizm& organizm) override;
	void wypisz() const override { std::cout << "Barszcz"; }
};
