#pragma once

class GameLoop;

class GameState {
	public:
		virtual ~GameState() = default;

		virtual void onEnter(GameLoop* Game) = 0;
		virtual void onExit() = 0;
		virtual void handleInput() = 0;
		virtual void update() = 0;
		virtual void render() = 0;
	protected:
		GameLoop* gameLoop;
};
