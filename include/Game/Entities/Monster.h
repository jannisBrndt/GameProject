#pragma once

#include "../Components/Stats.h"
#include <string>

class Monster {
	private:
		std::string name;
		Stats stats;
	public:
		Monster(const std::string& name, int health, int attack, int defense);

		// Getters
		const std::string& getName() const;
		const Stats& getStats() const;

		// Combat actions
		void takeDamage(int damage);
		bool isAlive() const;
};
