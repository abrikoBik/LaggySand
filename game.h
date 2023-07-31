#pragma once

#include "iostream"
#include "string"
#include "SDL.h"
#include "pixel.h"
#include "vector"

class Game
{

public:

    Game();

    ~Game();

    void Init(const char* title, int width, int height, int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED);
    void Render();
    void HandleEvent();
    void Update();
    void Clear();

    bool running = true;
private:

    SDL_Renderer* renderer = nullptr;
    SDL_Event e;
    SDL_Window* window = nullptr;

};