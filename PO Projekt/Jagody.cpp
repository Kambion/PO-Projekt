#include "Jagody.hpp"

void Jagody::rysowanie() const {
	std::cout << "x";
}
void Jagody::akcja() {
	int los = rand() % 10;
	if (los == 0) {
		bool success = false;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (swiat.dodajOrganizm(position.x + i, position.y + j, Typ::JAGODY)) {
					success = true;
					break;
				}
			}
			if (success)
				break;
		}
	}
}
bool Jagody::eatenBy(Organizm& organizm) {
	swiat.usunOrganizm(this);
	return true;
}