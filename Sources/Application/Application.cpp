#include "Application.h"

Application::Application(const char *windowName, int width, int height, int _maxFPS) : windowWidth(width), windowHeight(height), isRunning(true), maxFPS(_maxFPS)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        isRunning = false;
        return;
    }

    window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    if (!window)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        isRunning = false;
        return;
    }

    if (!myRenderer.init(window))
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        isRunning = false;
    }

    const int SCREEN_TICKS_PER_FRAME = 1000 / maxFPS;
    int frame = 0;

    myRenderer.linkVector(&fruits);
    mySolver.linkVector(&fruits);
}

Application::~Application()
{
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Application::handleEvents()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            std::cout << "Closing..." << std::endl;
            break;

        // WINDOW EVENTS //
        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_RESIZED)
            {
            }
            break;

        // KEYBOARD EVENTS //
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_q:
                isRunning = false;
                std::cout << "Closing..." << std::endl;
                break;

            default:
                break;
            }

        // MOUSE EVENTS //
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT) // LEFT CLICK
            {
                int mouseX = event.button.x;
                int mouseY = event.button.y;
                // std::cout << "Left click (X = " << mouseX << " ; Y = " << mouseY << ")" << std::endl;
                fruits.push_back(Fruit(mouseX, mouseY));
            }
            break;

        default:
            break;
        }
    }
}

void Application::Run()
{
    Uint64 currentFrame = SDL_GetPerformanceCounter();
    Uint64 lastFrame = 0;
    double deltaTime = 0;

    while (isRunning)
    {
        // Delta time calculation
        lastFrame = currentFrame;
        currentFrame = SDL_GetPerformanceCounter();
        deltaTime = (double)((currentFrame - lastFrame) * 1000 / (double)SDL_GetPerformanceFrequency());

        // Main loop
        handleEvents();
        mySolver.update(deltaTime * 0.08f);
        myRenderer.render();
    }
}