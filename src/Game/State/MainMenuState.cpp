#include "../../../include/Game/State/MainMenuState.h"
#include "../../../include/Game/State/InGameState.h"
#include "../../../include/Game/Core/GameLoop.h"
#include <iostream>

void MainMenuState::onEnter(GameLoop* game) {
	gameLoop = game;
	std::cout << "Entering Main Menu\n";
}

void MainMenuState::onExit() {
	std::cout << "Exiting Main Menu\n";
}

void MainMenuState::handleInput() {
	std::cout << "1: Start new Game\n";
	std::cout << "2: Load Game (not implemented)\n";
	std::cout << "3: Quit\n";
	std::cout << "Choose an option: ";

	int choice = 0;
	std::cin >> choice;

	switch (choice) {
		case 1:
			// transition to InGameState
			gameLoop->changeState(new InGameState());
			break;
		case 2:
			std::cout << "Load Game is not implemented yet.\n";
			break;
		case 3:
			exit(0);
			break;
		default:
			std::cout << "Invalid choice. Try again.\n";
			break;
	}
}

void MainMenuState::update() {
	// no dynamic updates required in main menu
}

void MainMenuState::render() {
	std::cout << "Welcome to Dungeon Conqueror!\n";
}
