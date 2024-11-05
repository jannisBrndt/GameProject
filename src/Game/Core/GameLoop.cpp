#include "../../../include/Game/Core/GameLoop.h"
#include "../../../include/Game/State/MainMenuState.h"
#include <iostream>

GameLoop::GameLoop() : currentState(nullptr) {
	changeState(new MainMenuState());
}

GameLoop::~GameLoop() {
	if (currentState) {
		delete currentState;
	} 
}

void GameLoop::run() {
	while (true) {
		currentState->handleInput();
		currentState->update();
		currentState->render();
	}
}

void GameLoop::changeState(GameState* newState) {
	if (currentState) {
		currentState->onExit();
		delete currentState;
	}
	currentState = newState;
	if (currentState) {
		currentState->onEnter(this);
	}
} 
