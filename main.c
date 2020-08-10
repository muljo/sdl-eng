#include <stdio.h>
#include <SDL.h>

static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;

typedef struct paddlepongt
{
	int x;
	int y;
	int width;
	int height;
	int dy;
} paddle;




SDL_Window* window = NULL;

SDL_Surface* screen_surface = NULL;

SDL_Renderer* renderer = NULL;

SDL_Texture* texture = NULL;

/**
 * Initialises the engine
 * Creates a window and renderer to draw on 
 * @return whether the engine was initialised successfully.
 */
int init();
/**
 * Cleans up the engine
 * Called before the program exits
 * 
 */
void close();

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
	return success;
}
void close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = NULL;
	window = NULL;
	SDL_Quit();
	return 0;
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
		SDL_Rect rect_one = 
		{
			WINDOW_WIDTH 	/ 8, 	// x
			WINDOW_HEIGHT 	/ 8,	// y
			WINDOW_WIDTH 	/ 8,	// width
			WINDOW_HEIGHT 	/ 8		// height
		};
		SDL_Rect rect_two =
		{
			rect_one.x + rect_one.w,
			rect_one.y + rect_one.h,
			rect_one.w,
			rect_one.h
		};
		const int line_length = WINDOW_WIDTH / 1.5 - WINDOW_WIDTH / 2;
		const int originX = WINDOW_WIDTH / 1.5;
		const int originY = WINDOW_HEIGHT / 2;
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
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(renderer);

			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
			

			SDL_RenderDrawLine(renderer,
					originX,
					originY,
					originX  + line_length,
					originY);

			SDL_SetRenderDrawColor(renderer, 0x00, 0x80, 0x00, 0xFF);
			SDL_RenderDrawLine(renderer,
					originX,
					originY + line_length,
					originX + line_length,
					originY + line_length);
			SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
			SDL_RenderDrawLine(renderer,
					originX,
					originY,
					originX,
					originY + line_length);

			SDL_SetRenderDrawColor(renderer, 0x30, 0x80, 0xC0, 0xFF);
			SDL_RenderDrawLine(renderer,
					originX + line_length,
					originY,
					originX + line_length,
					originY + line_length);
			SDL_RenderPresent(renderer);
		}
	}
	close();
	return 0;
}
