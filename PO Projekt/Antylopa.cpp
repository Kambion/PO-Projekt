#include "Antylopa.hpp"

void Antylopa::rysowanie() const {
	std::cout << "A";
}
Position Antylopa::kolizja(Organizm* other) {
	if (Antylopa* w = dynamic_cast<Antylopa*>(other)) {
		bool success = false;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (swiat.dodajOrganizm(position.x + i, position.y + j, Typ::ANTYLOPA)) {
					success = true;
					break;
				}
			}
			if (success)
				break;
		}
		return position;
	}
	else {
		if (other->silniejszy(sila)) {
			return martwy;
		}
		else {
			return other->getPosition();
		}
	}
}
void Antylopa::akcja() {
	Position newPosition{ -1, -1 };
	int addX = 0;
	int addY = 0;
	do {
		addX = 0;
		addY = 0;
		while (addX == 0 && addY == 0) {
			addX = rand() % 5 - 1;
			addY = rand() % 5 - 1;
		}
		newPosition.x = position.x + addX;
		newPosition.y = position.y + addY;
		newPosition = swiat.ruszOrganizm(position, newPosition);
	} while (newPosition == graniceMapy);
	if (!(newPosition == martwy)) {
		position = newPosition;
	}
}
Zachowanie Antylopa::obronil(int otherSila) {
	if (sila <= otherSila) {
		int los = rand() % 100;
		if (los < 50) {
			return Zachowanie::UCIEKA;
		}
	}
	return Zachowanie::WALCZY;
}