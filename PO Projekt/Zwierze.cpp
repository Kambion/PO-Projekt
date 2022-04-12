#include <iostream>
#include "Zwierze.hpp"

void Zwierze::rysowanie() const{
	std::cout << "Z";
}
void Zwierze::akcja() {
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
