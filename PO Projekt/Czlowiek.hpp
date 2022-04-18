#include "Zwierze.hpp"

enum class Input {
	UP,
	DOWN,
	RIGHT,
	LEFT,
	SPACE,
	NONE
};

class Czlowiek : public Zwierze {
private:
	bool cooldown = false;
	int tury = 0;
	bool active = false;
	Input readInput();
	void activateSkill();
	void handleSkill();
public:
	Czlowiek(Swiat& swiat, int x, int y) : Zwierze(swiat, x, y, 9, 8) {}
	void akcja() override;
	Position kolizja(Organizm* other) override;
	void rysowanie() const override;
	void wypisz() const override { std::cout << "Czlowiek"; }
};
