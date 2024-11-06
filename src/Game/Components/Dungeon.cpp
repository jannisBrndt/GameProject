#include "../../../include/Game/Components/Dungeon.h"
#include <cstdlib>
#include <memory>
#include <iostream>
#include <stdexcept>

Dungeon::Dungeon(int numRooms)
	: currentRoomIndex(0) {
		generateRooms(numRooms);
}

void Dungeon::generateRooms(int numRooms) {
	for (int i = 0; i < numRooms; ++i) {
		RoomType type;

		if (i == numRooms - 1) {
			type = RoomType::BOSS;
		} else {
			int randomType = std::rand() % 4;
			type = static_cast<RoomType>(randomType);
		}

		rooms.push_back(std::make_unique<Room>(type));
	}
}

void Dungeon::enterNextRoom() {
	if (currentRoomIndex < rooms.size()) {
		std::cout << "Entering room " << currentRoomIndex + 1 << "...\n";
		rooms[currentRoomIndex]->enterRoom();

		if (rooms[currentRoomIndex]->isCleared()) {
			currentRoomIndex++;
		}
	} else {
		std::cout << "You have cleared the dungeon!\n";
	}
}

bool Dungeon::isCleared() const {
	return currentRoomIndex >= rooms.size();
}

int Dungeon::getCurrentRoomIndex() const {
	return currentRoomIndex;
}

const Room& Dungeon::getRoom(int index) const {
	if (index < 0 || index >= rooms.size()) {
		throw std::out_of_range("Room index is out of range.");
	}
	return *rooms[index];
}
