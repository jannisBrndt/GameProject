#include "../../../include/Game/Entities/character.h"
#include <iostream>

Character::Character(const std::string& name, int health, int attack, int defense) 
	: name(name), stats(health, attack, defense), level(1), experience(0), experienceToNextLevel(100) {}

void Character::displayStats() const {
	std::cout << "Name: " << name << "\n";
	std::cout << "Health: " << stats.getHealth() << "\n";
	std::cout << "Attack: " << stats.getAttack() << "\n";
	std::cout << "Defense: " << stats.getDefense() << "\n";
}

Stats Character::getStats() const {
	return stats;
}

std::string Character::getName() const {
	return name;
}

int Character::getLevel() const {
	return level;
}

int Character::getExperience() const {
	return experience;
}

void Character::gainExperience(int xp) {
	experience += xp;
	while (experience >= experienceToNextLevel) {
		experience -= experienceToNextLevel;
		levelUp();
	}
}

void Character::levelUp() {
	level++;
	experienceToNextLevel = calculateExperienceForNextLevel();

	stats.restoreHealth(10);
	stats.increaseAttack(1);
	stats.increaseDefense(1);

	std::cout << name << " leveled up to level " << level << "!\n";
}

int Character::calculateExperienceForNextLevel() const {
	return level * level * 100;
}

void Character::takeDamage(int damage) {
	stats.takeDamage(damage);
}

void Character::restoreHealth(int amount) {
	stats.restoreHealth(amount);
}

bool Character::isAlive() const {
	return stats.isAlive();
}

