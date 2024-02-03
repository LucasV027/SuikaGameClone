#pragma once

#include <vector>
#include <SDL2/SDL.h>

//
#include <iostream>
//

#include "../Core/Fruit.h"

class Renderer
{
public:
    Renderer();

    bool init(SDL_Window *window);

    void linkVector(std::vector<Fruit> *ptr);

    void render();

    ~Renderer();

    static SDL_Color getRGBColor(int input);

private:
    void SDL_RenderFillCircle(int x, int y, int radius);

private:
    SDL_Renderer *rRenderer;

    std::vector<Fruit> *fruits;
};
