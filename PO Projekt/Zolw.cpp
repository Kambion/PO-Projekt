#include "Zolw.hpp"

void Zolw::rysowanie() const {
	std::cout << "Z";
}
Position Zolw::kolizja(Organizm* other) {
	if (Zolw* w = dynamic_cast<Zolw*>(other)) {
		bool success = false;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (swiat.dodajOrganizm(position.x + i, position.y + j, Typ::ZOLW)) {
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
void Zolw::akcja() {
	int ruch = rand() % 100;
	if (ruch < 75) {
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
			newPosition = swiat.ruszOrganizm(position, newPosition);
		} while (newPosition == graniceMapy);
		if (!(newPosition == martwy)) {
			position = newPosition;
		}
	}
}
Zachowanie Zolw::obronil(int otherSila) {
	if (otherSila < 5) {
		return Zachowanie::BRONI;
	}
	return Zachowanie::WALCZY;
}