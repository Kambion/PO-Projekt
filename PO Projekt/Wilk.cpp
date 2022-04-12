#include "Wilk.hpp"

void Wilk::rysowanie() const {
	std::cout << "W";
}
Position Wilk::kolizja(Organizm* other) {
	if (Wilk* w = dynamic_cast<Wilk*>(other)) {
		bool success = false;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (swiat.dodajOrganizm(position.x + i, position.y + j, Typ::WILK)) {
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