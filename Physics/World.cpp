#include "World.h"
#include "Actor.h"
#include "Transform.h"
#include "Rigidbody.h"
#include <iostream>
#include <chrono>

World::World() : mIsRunning(true), mWindow(nullptr), mRenderer(nullptr), mDesiredFrameRate(60), mShowFrameRate(true), mTicks(0) {

	Actor* actor = new Actor();
	Vector2 pos(100.0f, 100.0f);
	Vector2 scale(20.0f, 20.0f);
	actor->AddComponent(new Transform(pos, scale));
	Vector2 initialVelocity(10.0f, 20.0f);
	actor->AddComponent(new Rigidbody(1.0f, initialVelocity));

	mActors.push_back(actor);
}

void World::displayFrameRate() {
	if (!mShowFrameRate) {
		return;
	}
	int curFrameRate = 1000 / (SDL_GetTicks() - mTicks);
	system("CLS");
	std::cout << "Frame Rate: " << curFrameRate << std::endl;
}

bool World::Initialize() {
	mWindow = SDL_CreateWindow
	(
		"New Cube (C),  Quit (Esc)", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		800,
		600,
		SDL_WINDOW_SHOWN
	);

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

	return true;
}

void World::clampFrameRate() {
	//if cpu fast: while loop will clamp the frame rate
	//else if slow: deltaTime will be more 
	float frameDuration = 1000.0f / mDesiredFrameRate; // in ms
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicks + frameDuration));
}

float World::calcDeltaTimeMicro() {
	return (SDL_GetTicks() - mTicks) / 1000.0f; //in microseconds
}

void World::ProcessInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				mIsRunning = false;
			}
			if (event.key.keysym.sym == SDLK_c) {
				//spawn new object
			}
		}
	}
}

void World::Update() {

	clampFrameRate();
	displayFrameRate();
	float deltaTime = calcDeltaTimeMicro();
	mTicks = SDL_GetTicks();

	for (Actor* actor : mActors) {
		actor->Update(deltaTime);
	}
}

void World::ProcessOutput() {
	// Set render color to red ( background will be rendered in this color )
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);

	// Clear winow
	SDL_RenderClear(mRenderer);

	const int width{ 800 };
	const int height{ 600 };
	int rangeLeft = width / 4;
	int rangeRight = width / 2;

	float ballx = static_cast<float>(rangeLeft + rand() % (rangeRight - rangeLeft));
	float bally = static_cast<float>(rand() % height);

	int thickness = 15;

	// Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
	SDL_Rect r{
		static_cast<int>(ballx - thickness / 2),
		static_cast<int>(bally - thickness / 2),
		thickness,
		thickness
	};

	// Set render color to earth blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor(mRenderer, 40, 122, 184, 255);

	// Render rect
	//SDL_RenderFillRect(mRenderer, &r);

	//go through array of actors and display them
	for (Actor* actor : mActors) {
		actor->Draw(mRenderer);
	}

	// Render the rect to the screen
	SDL_RenderPresent(mRenderer);
}

void World::WorldLoop() {

	while (mIsRunning) {
		ProcessInput();
		Update();
		ProcessOutput();
	}
	Shutdown();
}

void World::Shutdown() {
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}
