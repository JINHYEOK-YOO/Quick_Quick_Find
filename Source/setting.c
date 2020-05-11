#include "main.h"
#include "setting.h"

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 720;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture *background, *play, *gameover;
SDL_Texture *cardImg1, *cardImg2, *cardImg3, *cardImg4, *cardImg5, *cardImg6, *cardImg7, *cardImg8, *cardImg9,
			*cardImg10, *cardImg11, *cardImg12, *cardImg13, *cardImg14, *cardImg15, *cardImg16, *cardImg17, *cardImg18,
			*cardImg19, *cardImg20, *cardImg21, *cardImg22, *cardImg23, *cardImg24, *cardImg25, *cardImg26, *cardImg27,
			*cardImg28, *cardImg29, *cardImg30, *cardImg31, *cardImg32, *cardImg33, *cardImg34, *cardImg35, *cardImg36,
			*cardImg37, *cardImg38, *cardImg39, *cardImg40, *cardImg41, *cardImg42, *cardImg43, *cardImg44, *cardImg45,
			*cardImg46, *cardImg47, *cardImg48, *cardImg49, *cardImg50, *cardImg51, *cardImg52, *cardImg53, *cardImg54;
SDL_Texture *timer, *record;

/* SDL 초기 설정 */
int initialize()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	//Create window
	window = SDL_CreateWindow("Quick Quick Find!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	//Create renderer for window
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}
	// Initialize TTF
	if (TTF_Init() == -1)
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}
	return 0;
}
 /* 이미지를 텍스쳐로 불러오기 */
SDL_Texture* loadImage(const char* path, SDL_Renderer* renderer)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

/* 텍스트를 텍스쳐로 불러오기 */
SDL_Texture* loadText(const char* msg, const char* fontFile, SDL_Color color, int fontSize, SDL_Renderer *ren)
{
	TTF_Font *font = TTF_OpenFont(fontFile, fontSize);
	if (font == NULL) {
		printf("TTF_OpenFont\n");
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		return NULL;
	}

	SDL_Surface* surf = TTF_RenderText_Blended(font, msg, color);
	if (surf == NULL) {
		TTF_CloseFont(font);
		printf("TTF_RenderText\n");
		return NULL;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surf);
	if (tex == NULL) {
		printf("CreateTexture\n");
	}

	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return tex;
}

/* 모든 이미지 불러오기 */
int loadAllImage()
{
	if ((background = loadImage("images/background.jpg", renderer)) == NULL ||
		(play = loadImage("images/play.jpg", renderer)) == NULL ||
		(gameover = loadImage("images/Game_Over.jpg", renderer)) == NULL ||
		(cardImg1 = loadImage("images/01_Hearts_A.jpg", renderer)) == NULL ||
		(cardImg2 = loadImage("images/02_Hearts_2.jpg", renderer)) == NULL ||
		(cardImg3 = loadImage("images/03_Hearts_3.jpg", renderer)) == NULL ||
		(cardImg4 = loadImage("images/04_Hearts_4.jpg", renderer)) == NULL ||
		(cardImg5 = loadImage("images/05_Hearts_5.jpg", renderer)) == NULL ||
		(cardImg6 = loadImage("images/06_Hearts_6.jpg", renderer)) == NULL ||
		(cardImg7 = loadImage("images/07_Hearts_7.jpg", renderer)) == NULL ||
		(cardImg8 = loadImage("images/08_Hearts_8.jpg", renderer)) == NULL ||
		(cardImg9 = loadImage("images/09_Hearts_9.jpg", renderer)) == NULL ||
		(cardImg10 = loadImage("images/10_Hearts_10.jpg", renderer)) == NULL ||
		(cardImg11 = loadImage("images/11_Hearts_J.jpg", renderer)) == NULL ||
		(cardImg12 = loadImage("images/12_Hearts_Q.jpg", renderer)) == NULL ||
		(cardImg13 = loadImage("images/13_Hearts_K.jpg", renderer)) == NULL ||
		(cardImg14 = loadImage("images/14_Diamonds_A.jpg", renderer)) == NULL ||
		(cardImg15 = loadImage("images/15_Diamonds_2.jpg", renderer)) == NULL ||
		(cardImg16 = loadImage("images/16_Diamonds_3.jpg", renderer)) == NULL ||
		(cardImg17 = loadImage("images/17_Diamonds_4.jpg", renderer)) == NULL ||
		(cardImg18 = loadImage("images/18_Diamonds_5.jpg", renderer)) == NULL ||
		(cardImg19 = loadImage("images/19_Diamonds_6.jpg", renderer)) == NULL ||
		(cardImg20 = loadImage("images/20_Diamonds_7.jpg", renderer)) == NULL ||
		(cardImg21 = loadImage("images/21_Diamonds_8.jpg", renderer)) == NULL ||
		(cardImg22 = loadImage("images/22_Diamonds_9.jpg", renderer)) == NULL ||
		(cardImg23 = loadImage("images/23_Diamonds_10.jpg", renderer)) == NULL ||
		(cardImg24 = loadImage("images/24_Diamonds_J.jpg", renderer)) == NULL ||
		(cardImg25 = loadImage("images/25_Diamonds_Q.jpg", renderer)) == NULL ||
		(cardImg26 = loadImage("images/26_Diamonds_K.jpg", renderer)) == NULL ||
		(cardImg27 = loadImage("images/27_Clubs_A.jpg", renderer)) == NULL ||
		(cardImg28 = loadImage("images/28_Clubs_2.jpg", renderer)) == NULL ||
		(cardImg29 = loadImage("images/29_Clubs_3.jpg", renderer)) == NULL ||
		(cardImg30 = loadImage("images/30_Clubs_4.jpg", renderer)) == NULL ||
		(cardImg31 = loadImage("images/31_Clubs_5.jpg", renderer)) == NULL ||
		(cardImg32 = loadImage("images/32_Clubs_6.jpg", renderer)) == NULL ||
		(cardImg33 = loadImage("images/33_Clubs_7.jpg", renderer)) == NULL ||
		(cardImg34 = loadImage("images/34_Clubs_8.jpg", renderer)) == NULL ||
		(cardImg35 = loadImage("images/35_Clubs_9.jpg", renderer)) == NULL ||
		(cardImg36 = loadImage("images/36_Clubs_10.jpg", renderer)) == NULL ||
		(cardImg37 = loadImage("images/37_Clubs_J.jpg", renderer)) == NULL ||
		(cardImg38 = loadImage("images/38_Clubs_Q.jpg", renderer)) == NULL ||
		(cardImg39 = loadImage("images/39_Clubs_K.jpg", renderer)) == NULL ||
		(cardImg40 = loadImage("images/40_Spades_A.jpg", renderer)) == NULL ||
		(cardImg41 = loadImage("images/41_Spades_2.jpg", renderer)) == NULL ||
		(cardImg42 = loadImage("images/42_Spades_3.jpg", renderer)) == NULL ||
		(cardImg43 = loadImage("images/43_Spades_4.jpg", renderer)) == NULL ||
		(cardImg44 = loadImage("images/44_Spades_5.jpg", renderer)) == NULL ||
		(cardImg45 = loadImage("images/45_Spades_6.jpg", renderer)) == NULL ||
		(cardImg46 = loadImage("images/46_Spades_7.jpg", renderer)) == NULL ||
		(cardImg47 = loadImage("images/47_Spades_8.jpg", renderer)) == NULL ||
		(cardImg48 = loadImage("images/48_Spades_9.jpg", renderer)) == NULL ||
		(cardImg49 = loadImage("images/49_Spades_10.jpg", renderer)) == NULL ||
		(cardImg50 = loadImage("images/50_Spades_J.jpg", renderer)) == NULL ||
		(cardImg51 = loadImage("images/51_Spades_Q.jpg", renderer)) == NULL ||
		(cardImg52 = loadImage("images/52_Spades_K.jpg", renderer)) == NULL ||
		(cardImg53 = loadImage("images/53_Black_Joker.jpg", renderer)) == NULL ||
		(cardImg54 = loadImage("images/54_Colored_Joker.jpg", renderer)) == NULL)
	{
		return -1;
	}
	return 0;
}

/* SDL 종료 설정 */
void quitGame()
{
	SDL_DestroyTexture(cardImg1);
	SDL_DestroyTexture(cardImg2);
	SDL_DestroyTexture(cardImg3);
	SDL_DestroyTexture(cardImg4);
	SDL_DestroyTexture(cardImg5);
	SDL_DestroyTexture(cardImg6);
	SDL_DestroyTexture(cardImg7);
	SDL_DestroyTexture(cardImg8);
	SDL_DestroyTexture(cardImg9);
	SDL_DestroyTexture(cardImg10);
	SDL_DestroyTexture(cardImg11);
	SDL_DestroyTexture(cardImg12);
	SDL_DestroyTexture(cardImg13);
	SDL_DestroyTexture(cardImg14);
	SDL_DestroyTexture(cardImg15);
	SDL_DestroyTexture(cardImg16);
	SDL_DestroyTexture(cardImg17);
	SDL_DestroyTexture(cardImg18);
	SDL_DestroyTexture(cardImg19);
	SDL_DestroyTexture(cardImg20);
	SDL_DestroyTexture(cardImg21);
	SDL_DestroyTexture(cardImg22);
	SDL_DestroyTexture(cardImg23);
	SDL_DestroyTexture(cardImg24);
	SDL_DestroyTexture(cardImg25);
	SDL_DestroyTexture(cardImg26);
	SDL_DestroyTexture(cardImg27);
	SDL_DestroyTexture(cardImg28);
	SDL_DestroyTexture(cardImg29);
	SDL_DestroyTexture(cardImg30);
	SDL_DestroyTexture(cardImg31);
	SDL_DestroyTexture(cardImg32);
	SDL_DestroyTexture(cardImg33);
	SDL_DestroyTexture(cardImg34);
	SDL_DestroyTexture(cardImg35);
	SDL_DestroyTexture(cardImg36);
	SDL_DestroyTexture(cardImg37);
	SDL_DestroyTexture(cardImg38);
	SDL_DestroyTexture(cardImg39);
	SDL_DestroyTexture(cardImg40);
	SDL_DestroyTexture(cardImg41);
	SDL_DestroyTexture(cardImg42);
	SDL_DestroyTexture(cardImg43);
	SDL_DestroyTexture(cardImg44);
	SDL_DestroyTexture(cardImg45);
	SDL_DestroyTexture(cardImg46);
	SDL_DestroyTexture(cardImg47);
	SDL_DestroyTexture(cardImg48);
	SDL_DestroyTexture(cardImg49);
	SDL_DestroyTexture(cardImg50);
	SDL_DestroyTexture(cardImg51);
	SDL_DestroyTexture(cardImg52);
	SDL_DestroyTexture(cardImg53);
	SDL_DestroyTexture(cardImg54);
	SDL_DestroyTexture(record);
	SDL_DestroyTexture(timer);
	SDL_DestroyTexture(play);
	SDL_DestroyTexture(background);


	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
}