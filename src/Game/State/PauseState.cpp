#include "../../../include/Game/State/InGameState.h"
#include "../../../include/Game/State/MainMenuState.h"
#include "../../../include/Game/State/PauseState.h"
#include "../../../include/Game/Core/GameLoop.h"
#include <iostream>

void PauseState::onEnter(GameLoop* game) {
	gameLoop = game;
	std::cout << "Game paused. You can resume or return to the main menu.\n";
}

void PauseState::onExit() {
	std::cout << "Resuming game...\n";
}

void PauseState::handleInput() {
	std::cout << "Press 'R' to resume or 'M' to return to the main menu: ";
	char choice;
	std::cin >> choice;

	switch (choice) {
		case 'R':
		case 'r':
			gameLoop->changeState(new InGameState());
			break;
		case 'M':
		case 'm':
			gameLoop->changeState(new MainMenuState());
			break;
		default:
			std::cout << "Invalid choice. Try again.\n";
			break;
	}
}

void PauseState::update() {
	// no dynamic updates required in the pause state
}

void PauseState::render() {
	std::cout << "Game is currently paused.\n";
}
