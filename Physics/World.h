#pragma once
#include <SDL.h>
#include <vector>
#include "Actor.h"

class World {
	void displayFrameRate();
	void clampFrameRate();
	float calcDeltaTimeMicro();
public:
	bool mIsRunning;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	std::vector<Actor*> mActors;
	Uint32 mTicks;
	int mDesiredFrameRate;
	bool mShowFrameRate;

	World();
	bool Initialize();
	void ProcessInput();
	void Update();
	void ProcessOutput();
	void WorldLoop();
	void Shutdown();
};

