#include "Trawa.hpp"

void Trawa::rysowanie() const {
	std::cout << "#";
}
void Trawa::akcja() {
	int los = rand() % 10;
	if (los == 0) {
		bool success = false;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (swiat.dodajOrganizm(position.x + i, position.y + j, Typ::TRAWA)) {
					success = true;
					break;
				}
			}
			if (success)
				break;
		}
	}
}