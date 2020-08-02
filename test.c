#include <stdio.h>
#include <SDL.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

SDL_Window* window = NULL;

SDL_Surface* screen_surface = NULL;

SDL_Renderer* renderer = NULL;

int init();
int close();
int init()
{
	int success = 1;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "SDL Init failed! SDL Error: %s\n", SDL_GetError());
		success = 0;
	} else 
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			fprintf(stderr, "Warning: Linear texture filtering not enabled!\n");
		}
		window = SDL_CreateWindow("muljo SDL Eng", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			fprintf(stderr, "SDL_CreateWindow() failed! SDL Error: %s\n", SDL_GetError());
			success = 0;
		} else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				fprintf(stderr, "SDL_CreateRenderer() failed! SDL Error: %s\n", SDL_GetError());
				success = 0;
			}
		}
	}
}
int close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = NULL;
	window = NULL;
	SDL_Quit();
}
int main(int argc, char* args[])
{
	if (!init())
	{
		fprintf(stderr, "Failed to initialise!\n");
	} else
	{
		int running = 1;
		SDL_Event e;
		while (running)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				switch (e.type)
				{
					case SDL_QUIT:
						running = 0;
						break;
				}
			}
		}
	}
	close();
	return 0;
}
