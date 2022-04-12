#include "Mlecyk.hpp"

void Mleczyk::rysowanie() const {
	std::cout << "@";
}
void Mleczyk::akcja() {
	for (int i = 0; i < 3; i++)
	{
		int los = rand() % 10;
		if (los == 0) {
			bool success = false;
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					if (swiat.dodajOrganizm(position.x + i, position.y + j, Typ::MLECZYK)) {
						success = true;
						break;
					}
				}
				if (success)
					break;
			}
		}
	}
}