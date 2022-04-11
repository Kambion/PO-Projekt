#pragma once

#include "Organizm.hpp"

class Roslina : public Organizm {
	void akcja() override;
	void kolizja() override;
	void rysowanie() const override;
};