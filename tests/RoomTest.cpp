#include <gtest/gtest.h>
#include "../include/Game/Components/Room.h"

TEST(RoomTest, RoomInitialization) {
	Room emptyRoom(RoomType::EMPTY);
	EXPECT_EQ(emptyRoom.getType(), RoomType::EMPTY);
	EXPECT_TRUE(emptyRoom.isCleared());

	Room monsterRoom(RoomType::MONSTER);
	EXPECT_EQ(monsterRoom.getType(), RoomType::MONSTER);
	EXPECT_FALSE(monsterRoom.isCleared());

	Room bossRoom(RoomType::BOSS);
	EXPECT_EQ(bossRoom.getType(), RoomType::BOSS);
	EXPECT_FALSE(bossRoom.isCleared());

	Room itemRoom(RoomType::ITEM);
	EXPECT_EQ(itemRoom.getType(), RoomType::ITEM);
	EXPECT_FALSE(itemRoom.isCleared());

	Room trapRoom(RoomType::TRAP);
	EXPECT_EQ(trapRoom.getType(), RoomType::TRAP);
	EXPECT_FALSE(trapRoom.isCleared());
}
