#include <gtest/gtest.h>
#include "../include/Game/Components/Dungeon.h"

TEST(DungeonTest, DungenInitialization) {
	
	int numRooms = 3;
	Dungeon dungeon(numRooms);

	// Enter first room
	dungeon.enterNextRoom();
	EXPECT_EQ(dungeon.getCurrentRoomIndex(), 1);
	EXPECT_FALSE(dungeon.isCleared());

	// Enter second room
	dungeon.enterNextRoom();
	EXPECT_EQ(dungeon.getCurrentRoomIndex(), 2);
	EXPECT_FALSE(dungeon.isCleared());

	// Enter last/boss room
	dungeon.enterNextRoom();
	EXPECT_EQ(dungeon.getCurrentRoomIndex(), 3);
	const Room& lastRoom = dungeon.getRoom(numRooms - 1);
	EXPECT_EQ(lastRoom.getType(), RoomType::BOSS);
	EXPECT_TRUE(dungeon.isCleared());
};
