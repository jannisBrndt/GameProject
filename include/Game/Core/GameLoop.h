#pragma once

#include "../State/GameState.h"

class GameLoop {
	public:
		GameLoop();
		~GameLoop();
		void run();
		void changeState(GameState* newState);
	private:
		GameState* currentState; 
};
