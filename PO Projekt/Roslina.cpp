#include <iostream>
#include "Roslina.hpp"

void Roslina::rysowanie() const {
	std::cout << "R";
}
Position Roslina::kolizja(Organizm* other) {
	return martwy;
}
void Roslina::akcja() {

}