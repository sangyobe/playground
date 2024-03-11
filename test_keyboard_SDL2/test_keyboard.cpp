#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;

// Window dimensions
static const int width = 800;
static const int height = 600;

static int initAll()
{
    if (SDL_Init(SDL_INIT_EVENTS) != 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }

    // Create an SDL window
    window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    if (window == 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }

    // Create a renderer (accelerated and in sync with the display refresh rate)
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }
    return (1);
}

static void closeAll()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main()
{
    initAll();

	bool quit = false;
	SDL_Event event;
	while(!quit){
		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_QUIT:
				quit = true;
				break;
            case SDL_KEYDOWN:
                printf("%d press!\n", event.key.keysym.sym);
                break;
            case SDL_KEYUP:
                printf("%d release!\n", event.key.keysym.sym);
                break;
			}
		}
		SDL_Delay(1);
	}

    closeAll();
    return (0);
}