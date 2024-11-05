#include "../../../include/Game/Components/Stats.h"

Stats::Stats(int health, int attack, int defense) 
	: health(health), maxHealth(health), attack(attack), defense(defense) {}

int Stats::getHealth() const { return health; }
int Stats::getAttack() const { return attack; }
int Stats::getDefense() const { return defense; }

void Stats::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}

void Stats::restoreHealth(int amount) {
	int newHealth = health + amount;
	if (newHealth > maxHealth) {
		health = maxHealth;
	} else {
		health = newHealth;
	}

}

void Stats::increaseAttack(int amount) {
	attack += amount;
}

void Stats::increaseDefense(int amount) {
	defense += amount;
}

bool Stats::isAlive() const {
	return health > 0;
}
