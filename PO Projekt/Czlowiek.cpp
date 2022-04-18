#include "Czlowiek.hpp"
#include <conio.h>

constexpr int klawisze[5] = {72, 80, 77, 75, 32};

void Czlowiek::rysowanie() const {
	std::cout << "Ω";
}
Position Czlowiek::kolizja(Organizm* other) {
	if (other->silniejszy(sila)) {
		return martwy;
	}
	else {
		return other->getPosition();
	}
}
Input Czlowiek::readInput() {
	std::cout << "Podaj kierunek lub aktywuj umiejetnosc[SPACE]\n";
	int input = _getch();
	Input key = Input::NONE;
	for (int i = 0; i < 5; i++) {
		if (klawisze[i] == input) {
			key = (Input)i;
			break;
		}
	}
	return key;
}
void Czlowiek::activateSkill() {
	if (!cooldown) {
		std::cout << "Umiejetnosc aktywowana\n";
		active = true;
	}
	else {
		std::cout << "Cooldown " << tury << "/5\n";
	}
}
void Czlowiek::handleSkill() {
	if (active) {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i != 0 || j != 0) {
					swiat.zabij(position.x + i, position.y + j);
				}
			}
		}
		tury++;
	}
	if (cooldown) {
		tury++;
	}
	if (tury == 5) {
		if (active) {
			std::cout << "Koniec umiejetnosc\n";
			active = false;
		}
		cooldown = !cooldown;
		tury = 0;
	}
}
void Czlowiek::akcja() {
	Position newPosition{ -1, -1 };
	int addX = 0;
	int addY = 0;
	do {
		addX = 0;
		addY = 0;
		Input input = readInput();
		switch (input)
		{
		case Input::UP:
			addY = -1;
			break;
		case Input::DOWN:
			addY = 1;
			break;
		case Input::LEFT:
			addX = -1;
			break;
		case Input::RIGHT:
			addX = 1;
			break;
		case Input::SPACE:
			activateSkill();
			break;
		default:
			break;
		}
		if (input != Input::SPACE && (addX != 0 || addY != 0)) {
			newPosition.x = position.x + addX;
			newPosition.y = position.y + addY;
			newPosition = swiat.ruszOrganizm(position, newPosition);
		}
		else {
			newPosition = graniceMapy;
		}
	} while (newPosition == graniceMapy);
	if (!(newPosition == martwy)) {
		position = newPosition;
		handleSkill();
	}
	else {
		std::cout << "***************************\n";
		std::cout << "\nKONIEC GRY\n";
		std::cout << "Czlowiek zostal zabity\n\n";
		std::cout << "***************************\n";
		exit(0);
	}
}