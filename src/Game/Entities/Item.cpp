#include "../../../include/Game/Entities/Item.h"

Item::Item(const std::string& name, int healthBonus, int attackBonus, int defenseBonus)
	: name(name), healthBonus(healthBonus), attackBonus(attackBonus), defenseBonus(defenseBonus) {
}

const std::string& Item::getName() const { return name; }

int Item::getHealthBonus() const { return healthBonus; }

int Item::getAttackBonus() const { return attackBonus; }

int Item::getDefenseBonus() const { return defenseBonus; }
