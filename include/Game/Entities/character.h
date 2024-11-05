#pragma once

#include "../Components/Stats.h"
#include <string>

class Character {
	public:
		// Constructor
		Character(const std::string& name, int health, int attack, int defense);
	
		// Getters
		Stats getStats() const;
		std::string getName() const;
		int getLevel() const;
		int getExperience() const;
		int getExperienceToNextLevel() const;

		// Actions
		void levelUp();
		void gainExperience(int xp);
		void takeDamage(int damage);
		void restoreHealth(int amount);
		bool isAlive() const;
		void displayStats() const;
		
	private:
		std::string name;
		Stats stats;
		int level;
		int experience;
		int experienceToNextLevel;

		int calculateExperienceForNextLevel() const;
};
