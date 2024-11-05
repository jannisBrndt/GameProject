#include "../../../include/Game/State/InGameState.h"
#include "../../../include/Game/State/PauseState.h"
#include "../../../include/Game/Core/GameLoop.h"
#include "../../../include/Game/State/MainMenuState.h"
#include "../../../include/Game/State/GameOverState.h"
#include "../../../include/Game/Components/Dungeon.h"
#include <iostream>
#include <memory>

void InGameState::onEnter(GameLoop* game) {
	gameLoop = game;
	
	dungeon = std::make_unique<Dungeon>(9);

	std::cout << "Entering the dungeon...\n";
}

void InGameState::onExit() {
	std::cout << "Exiting the dungeon...\n";
}

void InGameState::handleInput() {
	if (!dungeon->isCleared()) {

		std::cout << "Press 'N' to enter the next room, 'P' to pause, 'Q' to quit to main menu: \n";
		char choice;
		std::cin >> choice;

		switch (choice) {
			case 'N':
			case 'n':
				dungeon->enterNextRoom();
				break;
			case 'P':
			case 'p':
				gameLoop->changeState(new PauseState());
				break;
			case 'Q':
			case 'q':
				gameLoop->changeState(new MainMenuState());
				break;
			default:
				std::cout << "Invalid choice. Try again.\n";
				break;
		}
	}

}

void InGameState::update() {
	// game logic update, such as character movement, combat, etc
}

void InGameState::render() {
	std::cout << "You are in the dungeon. Prepare to face monsters!\n";
}
