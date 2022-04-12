#include "Swiat.hpp"
#include "Zwierze.hpp"
#include "Roslina.hpp"

void Swiat::rysujSwiat() {
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			if (plansza[j][i])
				plansza[j][i]->rysowanie();
			else
				std::cout << " ";
		}
		std::cout << '\n';
	}
}
void Swiat::wykonajTure() {
	for (Organizm* organizm : organizmy) {
		organizm->akcja();
	}
}
void Swiat::dodajOrganizm(int x, int y, Organizmy organizm) {
	switch (organizm)
	{
	case Organizmy::ZWIERZE:
		plansza[x][y] = std::make_unique<Zwierze>(*this, x, y);
		organizmy.push_back(plansza[x][y].get());
		break;
	case Organizmy::ROSLINA:
		plansza[x][y] = std::make_unique<Roslina>(*this, x, y);
		organizmy.push_back(plansza[x][y].get());
		break;
	}
}
Position Swiat::ruszOrganizm(Position position, Position newPosition) {
	//std::cout << "Old pos: " << position.x << " , " << position.y << '\n';
	//std::cout << "New pos: " << newPosition.x << " , " << newPosition.y << '\n';
	if (newPosition.x >= 0 && newPosition.y >= 0 && newPosition.x < sizeX && newPosition.y < sizeY) {
		if (plansza[newPosition.x][newPosition.y].get()){
			std::cout << "nope\n";
			plansza[position.x][position.y]->kolizja();
			return position;
		}
		else {
			std::cout << "ok\n";
			plansza[newPosition.x][newPosition.y] = std::move(plansza[position.x][position.y]);
			return newPosition;
		}
	}
	return Position{ -1, -1 };
}
