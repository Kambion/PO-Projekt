#include "Swiat.hpp"
#include "Zwierze.hpp"
#include "Roslina.hpp"

Swiat::Swiat(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY) {
	plansza = new Organizm**[sizeX];
	for (int i = 0; i < sizeX; i++) {
		plansza[i] = new Organizm*[sizeY];
	}
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			plansza[i][j] = nullptr;
		}
	}
}
Swiat::~Swiat() {
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			delete plansza[i][j];
		}
	}
	for (int i = 0; i < sizeX; i++) {
		delete[] plansza[i];
	}
	delete[] plansza;
}
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

}
void Swiat::dodajOrganizm(int x, int y, Organizmy organizm) {
	switch (organizm)
	{
	case Organizmy::ZWIERZE:
		plansza[x][y] = new Zwierze(*this);
		break;
	case Organizmy::ROSLINA:
		plansza[x][y] = new Roslina(*this);
		break;
	}
}
