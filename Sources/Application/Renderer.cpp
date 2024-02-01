#include "../Application/Renderer.h"

Renderer::Renderer() : rRenderer(nullptr), fruits(nullptr) {}

bool Renderer::init(SDL_Window *window)
{
    rRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!rRenderer)
    {
        return false;
    }

    return true;
}

void Renderer::linkVector(std::vector<Fruit> *ptr) { fruits = ptr; }

void Renderer::render()
{
    // Bg clearing
    SDL_SetRenderDrawColor(rRenderer, 48, 46, 43, 255);
    SDL_RenderClear(rRenderer);

    // Bg square
    SDL_SetRenderDrawColor(rRenderer, 0, 0, 0, 255);
    SDL_Rect bg{50, 50, 700, 700};
    SDL_RenderFillRect(rRenderer, &bg);

    // Fruit rendering
    for (const Fruit &fruit : *fruits)
    {
        Vec2Float fruitPosition = fruit.getPosition();
        SDL_SetRenderDrawColor(rRenderer, 0, 0, 255, 255);
        this->SDL_RenderFillCircle(fruitPosition.getX(), fruitPosition.getY(), fruit.getRadius());
    }

    SDL_RenderPresent(rRenderer);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(rRenderer);
}

void Renderer::SDL_RenderFillCircle(int x, int y, int radius)
{
    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = radius;
    d = radius - 1;
    status = 0;

    while (offsety >= offsetx)
    {

        status += SDL_RenderDrawLine(rRenderer, x - offsety, y + offsetx,
                                     x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(rRenderer, x - offsetx, y + offsety,
                                     x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(rRenderer, x - offsetx, y - offsety,
                                     x + offsetx, y - offsety);
        status += SDL_RenderDrawLine(rRenderer, x - offsety, y - offsetx,
                                     x + offsety, y - offsetx);

        if (status < 0)
        {
            status = -1;
            break;
        }

        if (d >= 2 * offsetx)
        {
            d -= 2 * offsetx + 1;
            offsetx += 1;
        }
        else if (d < 2 * (radius - offsety))
        {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else
        {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
}