/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "World.h";

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/*
    Game Loop -> take input (press A to add new object, press P to pause),
        updates the world
        draws the world

    Update
    1. Calculate all the forces for each object
    2. Update the positions, velocities, acc. 
    Note - Somewhere need to check for collision


*/

int main(int argc, char* args[]) {

    World* world = new World();
    if (world->Initialize()) {
        world->WorldLoop();
    }
    return 0;
    //SDL_Window* window = NULL;
    //window = SDL_CreateWindow
    //(
    //    "Jeu de la vie", SDL_WINDOWPOS_UNDEFINED,
    //    SDL_WINDOWPOS_UNDEFINED,
    //    800,
    //    600,
    //    SDL_WINDOW_SHOWN
    //);

    //// Setup renderer
    //SDL_Renderer* renderer = NULL;
    //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //// Set render color to red ( background will be rendered in this color )
    //SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    //// Clear winow
    //SDL_RenderClear(renderer);

    //const int width{ 800 };
    //const int height{ 600 };
    //int rangeLeft = width / 4;
    //int rangeRight = width / 2;

    //float ballx = static_cast<float>(rangeLeft + rand() % (rangeRight - rangeLeft));
    //float bally = static_cast<float>(rand() % height);

    //int thickness = 15;

    //// Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
    //SDL_Rect r{
    //    static_cast<int>(ballx - thickness / 2),
    //    static_cast<int>(bally - thickness / 2),
    //    thickness,
    //    thickness
    //};

    //// Set render color to blue ( rect will be rendered in this color )
    //SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    //// Render rect
    //SDL_RenderFillRect(renderer, &r);

    //// Render the rect to the screen
    //SDL_RenderPresent(renderer);

    // Wait for 5 sec
    /*SDL_Delay(5000);

    SDL_DestroyWindow(window);
    SDL_Quit();*/

    return EXIT_SUCCESS;
}