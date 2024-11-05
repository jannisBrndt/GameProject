#include "../../../include/Game/State/GameOverState.h"
#include "../../../include/Game/State/MainMenuState.h"
#include "../../../include/Game/State/InGameState.h"
#include "../../../include/Game/Core/GameLoop.h"
#include <iostream>

void GameOverState::onEnter(GameLoop* game) {
	gameLoop = game;
	std::cout << "Game Over. You have been defeated.\n";
}

void GameOverState::onExit() {
	std::cout << "Exiting Game Over screen...\n";
}

void GameOverState::handleInput() {
	std::cout << "Press 'R' to restart or 'M' to return to the main menu: ";
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

void GameOverState::update() {
	// no dynamic updates required in the game over state
}

void GameOverState::render() {
	std::cout << "You lost. Better luck next time!\n";
}
