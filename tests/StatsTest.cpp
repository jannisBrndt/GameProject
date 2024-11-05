#include <gtest/gtest.h>
#include "../include/Game/Components/Stats.h"

TEST(StatsTest, Initialization) {
	Stats stats(100, 15, 5);
	EXPECT_EQ(stats.getHealth(), 100);
	EXPECT_EQ(stats.getAttack(), 15);
	EXPECT_EQ(stats.getDefense(), 5);
	EXPECT_TRUE(stats.isAlive());
};

TEST(StatsTest, TakeDamage) {
	Stats stats(100, 15, 5);
	stats.takeDamage(20);
	EXPECT_EQ(stats.getHealth(), 80);
	EXPECT_TRUE(stats.isAlive());

	stats.takeDamage(80);
	EXPECT_EQ(stats.getHealth(), 0);
	EXPECT_FALSE(stats.isAlive());
}

TEST(StatsTest, RestoreHealth) {
	Stats stats(100, 15, 5);
	stats.takeDamage(50);
	EXPECT_EQ(stats.getHealth(), 50);

	stats.restoreHealth(30);
	EXPECT_EQ(stats.getHealth(), 80);

	stats.restoreHealth(50); // should not exceed 100
	EXPECT_EQ(stats.getHealth(), 100);
}

TEST(StatsTest, IncreaseAttackAndDefense) {
	Stats stats(100, 15, 5);
	stats.increaseAttack(5);
	stats.increaseDefense(3);

	EXPECT_EQ(stats.getAttack(), 20);
	EXPECT_EQ(stats.getDefense(), 8);
}
