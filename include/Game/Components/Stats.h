#pragma once

class Stats {
	public:
		Stats(int health, int attack, int defense);

		// Getters
		int getHealth() const;
		int getAttack() const;
		int getDefense() const;

		// Modifiers
		void takeDamage(int damage);
		void restoreHealth(int amount);
		void increaseAttack(int amount);
		void increaseDefense(int amount);

		bool isAlive() const;


	private:
		int health;
		int maxHealth;
		int attack;
		int defense;
};
