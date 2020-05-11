#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 6
#define COL 9
#define SIZE (ROW*COL)

typedef enum { VISIBLE, INVISIBLE } Visible;
typedef enum { READY, PLAYING, OVER } State;

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture *background, *play, *gameover;
extern SDL_Texture *cardImg1, *cardImg2, *cardImg3, *cardImg4, *cardImg5, *cardImg6, *cardImg7, *cardImg8, *cardImg9,
					*cardImg10, *cardImg11, *cardImg12, *cardImg13, *cardImg14, *cardImg15, *cardImg16, *cardImg17, *cardImg18,
					*cardImg19, *cardImg20, *cardImg21, *cardImg22, *cardImg23, *cardImg24, *cardImg25, *cardImg26, *cardImg27,
					*cardImg28, *cardImg29, *cardImg30, *cardImg31, *cardImg32, *cardImg33, *cardImg34, *cardImg35, *cardImg36,
					*cardImg37, *cardImg38, *cardImg39, *cardImg40, *cardImg41, *cardImg42, *cardImg43, *cardImg44, *cardImg45,
					*cardImg46, *cardImg47, *cardImg48, *cardImg49, *cardImg50, *cardImg51, *cardImg52, *cardImg53, *cardImg54;
extern SDL_Texture *timer, *record;