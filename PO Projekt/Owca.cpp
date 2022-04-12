#include "Owca.hpp"

void Owca::rysowanie() const {
	std::cout << "O";
}
Position Owca::kolizja(Organizm* other) {
	if (Owca* w = dynamic_cast<Owca*>(other)) {
		bool success = false;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (swiat.dodajOrganizm(position.x + i, position.y + j, Typ::OWCA)) {
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