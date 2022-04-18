#include "Swiat.hpp"
#include "Roslina.hpp"
#include "Wilk.hpp"
#include "Owca.hpp"
#include "Trawa.hpp"
#include "Mlecyk.hpp"
#include "Guarana.hpp"
#include "Jagody.hpp"
#include "Barszcz.hpp"
#include "Lis.hpp"
#include "Zolw.hpp"
#include "Antylopa.hpp"
#include "Czlowiek.hpp"

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
	for (int i = maxInicjatywa; i >= 0; i--) {
		for (Organizm* organizm : organizmy) {
			if (organizm != nullptr) {
				if (organizm->getInicjatywa() == i) {
					organizm->akcja();
				}
			}
		}
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
			case Typ::LIS:
				plansza[x][y] = std::make_unique<Lis>(*this, x, y);
				organizmy.push_back(plansza[x][y].get());
				break;
			case Typ::ZOLW:
				plansza[x][y] = std::make_unique<Zolw>(*this, x, y);
				organizmy.push_back(plansza[x][y].get());
				break;
			case Typ::ANTYLOPA:
				plansza[x][y] = std::make_unique<Antylopa>(*this, x, y);
				organizmy.push_back(plansza[x][y].get());
				break;
			case Typ::CZLOWIEK:
				plansza[x][y] = std::make_unique<Czlowiek>(*this, x, y);
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
	if (newPosition.x >= 0 && newPosition.y >= 0 && newPosition.x < sizeX && newPosition.y < sizeY) {
		if (plansza[newPosition.x][newPosition.y].get()){
			Zachowanie other = plansza[newPosition.x][newPosition.y]->obronil(getSila(position));
			bool end = false;
			if (other == Zachowanie::BRONI) {
				plansza[newPosition.x][newPosition.y]->wypisz();
				std::cout << " obronil sie przed ";
				plansza[position.x][position.y]->wypisz();
				std::cout << '\n';
				return position;
			}
			else if (other == Zachowanie::WALCZY) {
				Position kolizja = plansza[position.x][position.y]->kolizja(plansza[newPosition.x][newPosition.y].get());
				if (kolizja == newPosition) {
					if (plansza[newPosition.x][newPosition.y]->eatenBy(*plansza[position.x][position.y])) {
						kolizja = martwy;
					}
					plansza[position.x][position.y]->wypisz();
					std::cout << " zjadl ";
					plansza[newPosition.x][newPosition.y]->wypisz();
					std::cout << '\n';
					usunOrganizm(plansza[newPosition.x][newPosition.y].get());
					if (kolizja == martwy)
						usunOrganizm(plansza[position.x][position.y].get());
					else
						plansza[newPosition.x][newPosition.y] = std::move(plansza[position.x][position.y]);
				}
				else if (kolizja == martwy) {
					plansza[newPosition.x][newPosition.y]->wypisz();
					std::cout << " zabil ";
					plansza[position.x][position.y]->wypisz();
					std::cout << '\n';
					plansza[newPosition.x][newPosition.y]->eatenBy(*plansza[position.x][position.y]);
					usunOrganizm(plansza[position.x][position.y].get());
				}
				return kolizja;
			}
			else {
				bool success = false;
				for (int i = -1; i <= 1; i++) {
					for (int j = -1; j <= 1; j++) {
						Position freePos = newPosition;
						freePos.x += i;
						freePos.y += j;
						if (freePos.x >= 0 && freePos.y >= 0 && freePos.x < sizeX && freePos.y < sizeY) {
							if (!(plansza[newPosition.x + i][newPosition.y + j].get())) {
								plansza[newPosition.x][newPosition.y]->wypisz();
								std::cout << " uciekl przed ";
								plansza[position.x][position.y]->wypisz();
								std::cout << '\n';
								plansza[freePos.x][freePos.y] = move(plansza[newPosition.x][newPosition.y]);
								plansza[freePos.x][freePos.y]->setPosition(freePos);
								success = true;
								break;
							}
						}
					}
					if (success)
						break;
				}
				if (success) {
					plansza[newPosition.x][newPosition.y] = move(plansza[position.x][position.y]);
					return newPosition;
				}
				else {
					usunOrganizm(plansza[newPosition.x][newPosition.y].get());
					plansza[newPosition.x][newPosition.y] = move(plansza[position.x][position.y]);
					return newPosition;
				}
			}
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
int Swiat::getSila(Position position) {
	if (position.x >= 0 && position.y >= 0 && position.x < sizeX && position.y < sizeY) {
		if (plansza[position.x][position.y].get()) {
			return plansza[position.x][position.y]->getSila();
		}
	}
	return 0;
}
