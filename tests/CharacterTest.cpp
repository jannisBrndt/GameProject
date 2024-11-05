#include <gtest/gtest.h>
#include "../include/Game/Entities/character.h"

TEST(CharacterTest, Initialization) {
    	Character character("Hero", 100, 15, 5);
    	EXPECT_EQ(character.getName(), "Hero");
    	EXPECT_EQ(character.getStats().getHealth(), 100); // Assuming default health is 100
    	EXPECT_EQ(character.getStats().getAttack(), 15);  // Assuming default attack is 15
	EXPECT_EQ(character.getStats().getDefense(), 5);  // Assuming default defense is 5
	EXPECT_EQ(character.getLevel(), 1);
	EXPECT_EQ(character.getExperience(), 0);
}

TEST(CharacterTest, TakeDamageAndIsAlive) {
	Character character("Hero", 100, 15, 5);
	character.takeDamage(20);
	EXPECT_EQ(character.getStats().getHealth(), 80);
	EXPECT_TRUE(character.isAlive());

	character.takeDamage(80);
	EXPECT_EQ(character.getStats().getHealth(), 0);
	EXPECT_FALSE(character.isAlive());
}

TEST(CharacterTest, RestoreHealth) {
	Character character("Hero", 100, 15, 5);
	character.takeDamage(50);
	character.restoreHealth(30);
	EXPECT_EQ(character.getStats().getHealth(), 80);

	character.restoreHealth(50); // should not exceed maxHealth (curr level 1)
	EXPECT_EQ(character.getStats().getHealth(), 100);
}

TEST(CharacterTest, LevelingUp) {
	Character character("Hero", 100, 15, 5);
	character.gainExperience(100); // level up to level 2
	EXPECT_EQ(character.getLevel(), 2);
	EXPECT_EQ(character.getExperience(), 0);
	
	// Check if stats have increased (levelup increasing stats)
	EXPECT_GE(character.getStats().getHealth(), 100);
	EXPECT_GE(character.getStats().getAttack(), 15);
	EXPECT_GE(character.getStats().getDefense(), 5);
	
	// Gain experience, not enough to level up
	character.gainExperience(50);
	EXPECT_EQ(character.getLevel(), 2);
	EXPECT_EQ(character.getExperience(), 50);
}

TEST(CharacterTest, MultipleLevelUps) {
	Character character("Hero", 100, 15, 5);

	character.gainExperience(500); // level up twice
	EXPECT_EQ(character.getLevel(), 3);
	EXPECT_EQ(character.getExperience(), 0);

	EXPECT_EQ(character.getStats().getAttack(), 15 + 2);
	EXPECT_EQ(character.getStats().getDefense(), 5 + 2);
}
