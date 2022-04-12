#include "Guarana.hpp"

void Guarana::rysowanie() const {
	std::cout << "+";
}
void Guarana::akcja() {
	int los = rand() % 10;
	if (los == 0) {
		bool success = false;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (swiat.dodajOrganizm(position.x + i, position.y + j, Typ::GUARANA)) {
					success = true;
					break;
				}
			}
			if (success)
				break;
		}
	}
}
bool Guarana::eatenBy(Organizm& organizm) {
	organizm.zwiekszSile(3);
	return false;
}