#include "Roslina.hpp"

class Trawa : public Roslina {
public:
	Trawa(Swiat& swiat, int x, int y) : Roslina(swiat, x, y, 0) {}
	void akcja() override;
	void rysowanie() const override;
};
