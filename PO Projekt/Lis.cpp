#include "Lis.hpp"

void Lis::rysowanie() const {
	std::cout << "L";
}
Position Lis::kolizja(Organizm* other) {
	if (Lis* w = dynamic_cast<Lis*>(other)) {
		bool success = false;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (swiat.dodajOrganizm(position.x + i, position.y + j, Typ::LIS)) {
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
void Lis::akcja() {
	Position newPosition{ -1, -1 };
	int addX = 0;
	int addY = 0;
	do {
		addX = 0;
		addY = 0;
		while (addX == 0 && addY == 0) {
			addX = rand() % 3 - 1;
			addY = rand() % 3 - 1;
		}
		newPosition.x = position.x + addX;
		newPosition.y = position.y + addY;
		if (swiat.getSila(newPosition) < sila) {
			newPosition = swiat.ruszOrganizm(position, newPosition);
		}
	} while (newPosition == graniceMapy);
	if (!(newPosition == martwy)) {
		position = newPosition;
	}
}