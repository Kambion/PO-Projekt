#include "Barszcz.hpp"

void Barszcz::rysowanie() const {
	std::cout << "!";
}
void Barszcz::akcja() {
	int los = rand() % 10;
	if (los == 0) {
		bool success = false;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (swiat.dodajOrganizm(position.x + i, position.y + j, Typ::BARSZCZ)) {
					success = true;
					break;
				}
			}
			if (success)
				break;
		}
	}
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i != 0 || j != 0) {
				swiat.zabij(position.x + i, position.y + j);
			}
		}
	}
}
bool Barszcz::eatenBy(Organizm& organizm) {
	swiat.usunOrganizm(this);
	return true;
}