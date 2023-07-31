#include "game.h"

int mouseX, mouseY;

int block = 0;
bool hold = false;
std::vector<Pixel*> world;

Game::Game()
{}

Game::~Game()
{}

void Game::Init(const char* title, int width, int height, int x, int y) 
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		running = false;
	} else {
		window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
		if(window == 0) {
			printf("Window wasn't created! SDL Error: %s\n", SDL_GetError());
			running = false;
		} else {
			renderer = SDL_CreateRenderer(window, -1, 0);
			if(renderer == 0) {
				printf("Renderer wasn't created! SDL Error:%s\n", SDL_GetError());
			} else {
				
			}
		}
	}
}

void Game::HandleEvent()
{

    SDL_PollEvent(&e);

	if(e.type == SDL_MOUSEMOTION) {
		SDL_GetMouseState(&mouseX, &mouseY);
	}
	if(e.type == SDL_MOUSEBUTTONDOWN)
	{
		if(e.button.button == SDL_BUTTON_LEFT) {
			hold = true;
		}
	} else if(e.type == SDL_MOUSEBUTTONUP) {
		if(e.button.button == SDL_BUTTON_LEFT) {
			hold = false;
		}
	}
	if(e.type == SDL_KEYDOWN) {
		if(e.key.keysym.sym == SDLK_q) { block = 1; } else { block = 0; }
	}

	switch (e.type) {
	case SDL_QUIT:
		running = false;
		break;
	
	default:
		break;
	}

}

void Game::Update()
{
	if(hold) world.push_back(new Pixel(mouseX/5, mouseY/5, 5, block == 0 ? "sand" : "rock"));
}

void Game::Render()
{
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);

	for(int i = 0; i < world.size(); i++) 
	{
		world[i]->update(renderer);
		world[i]->render(renderer);
	}

	SDL_RenderPresent(renderer);
}

void Game::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}