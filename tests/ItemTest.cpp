#include <gtest/gtest.h>
#include "../include/Game/Entities/Item.h"

TEST(ItemTest, ItemInitialization) {
	Item testItem("test", 11, 100, 1);

	EXPECT_EQ(testItem.getName(), "test");
	EXPECT_EQ(testItem.getHealthBonus(), 11);
	EXPECT_EQ(testItem.getAttackBonus(), 100);
	EXPECT_EQ(testItem.getDefenseBonus(), 1);
}

TEST(ItemTest, HealthBonus) {
	Item healthPotion("Health Potion", 50, 0, 0);
	EXPECT_EQ(healthPotion.getName(), "Health Potion");
	EXPECT_EQ(healthPotion.getHealthBonus(), 50);
}

TEST(ItemTest, AttackBonus) {
	Item sword("Sword", 0, 100, 0);
	EXPECT_EQ(sword.getName(), "Sword");
	EXPECT_EQ(sword.getAttackBonus(), 100);
}

TEST(ItemTest, DefenseBonus) {
	Item helmet("Helmet", 0, 0, 10);
	EXPECT_EQ(helmet.getName(), "Helmet");
	EXPECT_EQ(helmet.getDefenseBonus(), 10);
}
