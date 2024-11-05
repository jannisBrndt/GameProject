#include "GameState.h"

class PauseState : public GameState {
	public:
		void onEnter(GameLoop* game) override;
		void onExit() override;
		void handleInput() override;
		void update() override;
		void render() override;
};
