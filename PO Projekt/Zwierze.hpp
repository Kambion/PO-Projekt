#pragma once

#include "Organizm.hpp"

class Zwierze : public Organizm {
	void akcja() override;
	void kolizja() override;
	void rysowanie() const override;
};
