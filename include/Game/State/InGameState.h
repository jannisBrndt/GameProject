#include "GameState.h"
#include "../Components/Dungeon.h"

class InGameState : public GameState {
	private:
		std::unique_ptr<Dungeon> dungeon;
	public:
		void onEnter(GameLoop* game) override;
		void onExit() override;
		void handleInput() override;
		void update() override;
		void render() override;
};
