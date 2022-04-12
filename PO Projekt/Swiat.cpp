#include "Swiat.hpp"
#include "Roslina.hpp"
#include "Wilk.hpp"
#include "Owca.hpp"
#include "Trawa.hpp"
#include "Mlecyk.hpp"
#include "Guarana.hpp"
#include "Jagody.hpp"
#include "Barszcz.hpp"

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
		if(organizm != nullptr)
			organizm->akcja();
	}
}
bool Swiat::dodajOrganizm(int x, int y, Typ organizm) {
	if (x >= 0 && y >= 0 && x < sizeX && y < sizeY) {
		if (!plansza[x][y]) {
			switch (organizm)
			{
			case Typ::WILK:
				plansza[x][y] = std::make_unique<Wilk>(*this, x, y);
				organizmy.push_back(plansza[x][y].get());
				break;
			case Typ::OWCA:
				plansza[x][y] = std::make_unique<Owca>(*this, x, y);
				organizmy.push_back(plansza[x][y].get());
				break;
			case Typ::TRAWA:
				plansza[x][y] = std::make_unique<Trawa>(*this, x, y);
				organizmy.push_back(plansza[x][y].get());
				break;
			case Typ::MLECZYK:
				plansza[x][y] = std::make_unique<Mleczyk>(*this, x, y);
				organizmy.push_back(plansza[x][y].get());
				break;
			case Typ::GUARANA:
				plansza[x][y] = std::make_unique<Guarana>(*this, x, y);
				organizmy.push_back(plansza[x][y].get());
				break;
			case Typ::JAGODY:
				plansza[x][y] = std::make_unique<Jagody>(*this, x, y);
				organizmy.push_back(plansza[x][y].get());
				break;
			case Typ::BARSZCZ:
				plansza[x][y] = std::make_unique<Barszcz>(*this, x, y);
				organizmy.push_back(plansza[x][y].get());
				break;
			}
			return true;
		}
	}
	return false;
}
void Swiat::usunOrganizm(Organizm* organizm) {
	Position position = organizm->getPosition();
	auto iter = std::find(organizmy.begin(), organizmy.end(), organizm);
	*iter = nullptr;
	plansza[position.x][position.y] = nullptr;
}
Position Swiat::ruszOrganizm(Position position, Position newPosition) {
	//std::cout << "Old pos: " << position.x << " , " << position.y << '\n';
	//std::cout << "New pos: " << newPosition.x << " , " << newPosition.y << '\n';
	if (newPosition.x >= 0 && newPosition.y >= 0 && newPosition.x < sizeX && newPosition.y < sizeY) {
		if (plansza[newPosition.x][newPosition.y].get()){
			Position kolizja = plansza[position.x][position.y]->kolizja(plansza[newPosition.x][newPosition.y].get());
			if(kolizja == newPosition){
				if (plansza[newPosition.x][newPosition.y]->eatenBy(*plansza[position.x][position.y])) {
					kolizja = martwy;
				}
				usunOrganizm(plansza[newPosition.x][newPosition.y].get());
				if(kolizja == martwy)
					usunOrganizm(plansza[position.x][position.y].get());
				else
					plansza[newPosition.x][newPosition.y] = std::move(plansza[position.x][position.y]);
			}
			else if(kolizja == martwy){
				plansza[newPosition.x][newPosition.y]->eatenBy(*plansza[position.x][position.y]);
				usunOrganizm(plansza[position.x][position.y].get());
			}
			return kolizja;
		}
		else {
			plansza[newPosition.x][newPosition.y] = std::move(plansza[position.x][position.y]);
			return newPosition;
		}
	}
	return graniceMapy;
}
void Swiat::zabij(int x, int y) {
	if (plansza[x][y].get()) {
		usunOrganizm(plansza[x][y].get());
	}
}
