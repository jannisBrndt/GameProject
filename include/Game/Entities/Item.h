#pragma once

#include <string>

class Item {
	private:
		std::string name;
		int healthBonus;
		int attackBonus;
		int defenseBonus;
	public:
		Item(const std::string& name, int healthBonus = 0, int attackBonus = 0, int defenseBonus = 0);
		
		// Getters
		const std::string& getName() const;
		int getHealthBonus() const;
		int getAttackBonus() const;
		int getDefenseBonus() const;
};
