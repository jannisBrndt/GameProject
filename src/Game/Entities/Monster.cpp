#include "../../../include/Game/Entities/Monster.h"

Monster::Monster(const std::string& name, int health, int attack, int defense)
	: name(name), stats(health, attack, defense) {
}

const std::string& Monster::getName() const { return name; }

const Stats& Monster::getStats() const { return stats; }

void Monster::takeDamage(int damage) {
	stats.takeDamage(damage);
}

bool Monster::isAlive() const {
	return stats.isAlive();
}
