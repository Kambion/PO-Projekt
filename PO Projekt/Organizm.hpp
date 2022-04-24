#pragma once
#include <iostream>
#include "Swiat.hpp"

class Swiat;

enum class Zachowanie {
	WALCZY,
	BRONI,
	UCIEKA
};

struct Position
{
	int x;
	int y;
	bool operator==(Position other) {
		return (x == other.x && y == other.y);
	}
};
constexpr Position graniceMapy{ -1,-1 };
constexpr Position martwy{ -2,-2 };

class Organizm {
protected:
	char type;
	int sila;
	int inicjatywa;
	Position position;
	Swiat& swiat;
public:
	friend std::fstream& operator<<(std::fstream& file, Organizm& organizm) {
		file.write(reinterpret_cast<char*>(&organizm.type), sizeof(char));
		file.write(reinterpret_cast<char*>(&organizm.position.x), sizeof(int));
		file.write(reinterpret_cast<char*>(&organizm.position.y), sizeof(int));
		file.write(reinterpret_cast<char*>(&organizm.sila), sizeof(int));
		return file;
	}
	Organizm(Swiat& swiat, int x, int y, int sila, int inicjatywa, char litera) : swiat(swiat), position{ x, y }, sila(sila), inicjatywa(inicjatywa), type(litera){}
	bool silniejszy(int otherSila) { return sila > otherSila; }
	virtual Zachowanie obronil(int otherSila) { return Zachowanie::WALCZY; }
	Position getPosition() { return position; }
	inline int getSila() { return sila; }
	inline int getInicjatywa() { return inicjatywa; }
	void zwiekszSile(int x) { sila += x; }
	void setPosition(Position pos) { position = pos; }
	void setSila(int strength) { sila = strength; }
	virtual bool eatenBy(Organizm& organizm) = 0;
	virtual void akcja() = 0;
	virtual Position kolizja(Organizm* other) = 0;
	virtual void rysowanie() const = 0;
	virtual void wypisz() const = 0;
};