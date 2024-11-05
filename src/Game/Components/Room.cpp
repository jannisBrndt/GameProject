#include "../../../include/Game/Components/Room.h"
#include "../../../include/Game/Entities/Monster.h"
#include "../../../include/Game/Entities/Item.h"
#include <iostream>
#include <memory>

Room::Room(RoomType type)
	: type(type), cleared(false), trap(false) {
		if (type == RoomType::MONSTER) {
			monster = std::make_unique<Monster>("Goblin", 50, 10, 5);
		} else if (type == RoomType::BOSS) {
			monster = std::make_unique<Monster>("Dragon", 200, 30, 15);
		} else if (type == RoomType::ITEM) {
			item = std::make_unique<Item>("Health Potion", 20);
		} else if (type == RoomType::TRAP) {
			trap = true; // activate a trap
		}
}

RoomType Room::getType() const { return type; }

bool Room::isCleared() const { return cleared; }

void Room::enterRoom() {
	switch (type) {
		case RoomType::MONSTER:
			handleMonsterEncounter();
			break;
		case RoomType::ITEM:
			handleItemDiscovery();
			break;
		case RoomType::TRAP:
			handleTrap();
			break;
		case RoomType::BOSS:
			handleMonsterEncounter();
			break;
		case RoomType::EMPTY:
			std::cout << "The room is empty.\n";
			break;
	}
}

void Room::clearRoom() { cleared = true; }

void Room::handleMonsterEncounter() {
	std::cout << "You encountered a " << monster->getName() << "!\n";
	// Combat logic here
	clearRoom();
}

void Room::handleTrap() {
	std::cout << "You triggered a trap!\n";
	// Add trap effects here
	clearRoom();
}

void Room::handleItemDiscovery() {
	std::cout << "You found a" << item->getName() << "!\n";
	// Add item pick up logic here
	clearRoom();
}
