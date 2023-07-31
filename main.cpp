#include "iostream"
#include "SDL.h"
#include "game.h"

const int WIDTH = 800;
const int HEIGHT = 600;

Game* g = new Game();

int main(int argc, char* argv[])
{

    int FPS = 60;
    int frameDelay = 1000/FPS;

    Uint32 frameTime;
    int frameStart;

    g->Init("Sand Physics", WIDTH, HEIGHT);

    while(g->running)
    {
        frameStart = SDL_GetTicks();

        g->HandleEvent();
        g->Update();
        g->Render();

        frameTime = SDL_GetTicks() - frameStart;
        printf("Frame time - %i ms\n", frameTime);
        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    return 0;

}