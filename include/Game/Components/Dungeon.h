#pragma once
#include "Room.h"
#include <vector>

class Dungeon {
	private:
		std::vector<std::unique_ptr<Room>> rooms;
		int currentRoomIndex;
		void generateRooms(int numRooms);
		std::unique_ptr<Dungeon> dungeon;
	public:
		Dungeon(int numRooms);

		// Dungeon Actions
		void enterNextRoom();
		bool isCleared() const;

		// for testing
		int getCurrentRoomIndex() const;
		const Room& getRoom(int index) const;
};
