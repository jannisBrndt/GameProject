#pragma once
#include <memory>

class Monster;
class Item;

enum class RoomType {
	EMPTY,
	MONSTER,
	ITEM,
	TRAP,
	BOSS
};

class Room {
	private:
		RoomType type;
		bool cleared;

		std::unique_ptr<Monster> monster;
		std::unique_ptr<Item> item;
		bool trap;

		void handleMonsterEncounter();
		void handleItemDiscovery();
		void handleTrap();
	public:
		Room(RoomType type);

		// Getters
		RoomType getType() const;
		bool isCleared() const;

		// Room Actions
		void enterRoom(); // Handle what happens when entering room
		void clearRoom(); // Mark room as cleared
};
