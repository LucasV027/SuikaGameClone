#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include <SDL2/SDL.h>

#include "../Application/Renderer.h"
#include "../Core/Fruit.h"
#include "../Core/Solver.h"

class Application
{
public:
    Application(const char *windowName, int width, int height, int maxFPS);

    void Run();

    ~Application();

private:
    void handleEvents();

private:
    // Window & parameters
    int windowWidth;
    int windowHeight;
    SDL_Window *window = NULL;
    Renderer myRenderer;
    int maxFPS;

    //
    bool isRunning;

    //
    SDL_Event event;

    // Game logic
    Solver mySolver;
    std::vector<Fruit> fruits;
};
