#include "card.h"
#include "setting.h"

SDL_Texture *cardImg1, *cardImg2, *cardImg3, *cardImg4, *cardImg5, *cardImg6, *cardImg7, *cardImg8, *cardImg9,
			*cardImg10, *cardImg11, *cardImg12, *cardImg13, *cardImg14, *cardImg15, *cardImg16, *cardImg17, *cardImg18,
			*cardImg19, *cardImg20, *cardImg21, *cardImg22, *cardImg23, *cardImg24, *cardImg25, *cardImg26, *cardImg27,
			*cardImg28, *cardImg29, *cardImg30, *cardImg31, *cardImg32, *cardImg33, *cardImg34, *cardImg35, *cardImg36,
			*cardImg37, *cardImg38, *cardImg39, *cardImg40, *cardImg41, *cardImg42, *cardImg43, *cardImg44, *cardImg45,
			*cardImg46, *cardImg47, *cardImg48, *cardImg49, *cardImg50, *cardImg51, *cardImg52, *cardImg53, *cardImg54;

/* 카드 섞음 */
void shuffle(Card cards[], int start, int end)
{
	int temp, i;
	for (i = 0; i < (end - start); i++)
	{
		int n = rand() % (end - start) + start;

		temp = cards[n].cardNum;
		cards[n].cardNum = cards[end - 1 - i].cardNum;
		cards[end - 1 - i].cardNum = temp;
	}
}

/* 카드 출력 */
void renderCard(Card cards[])
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		if (cards[i].visible == VISIBLE)
		{
			switch (cards[i].cardNum)
			{
			case 1:
				SDL_RenderCopy(renderer, cardImg1, NULL, &cards[i].rect);
				break;
			case 2:
				SDL_RenderCopy(renderer, cardImg2, NULL, &cards[i].rect);
				break;
			case 3:
				SDL_RenderCopy(renderer, cardImg3, NULL, &cards[i].rect);
				break;
			case 4:
				SDL_RenderCopy(renderer, cardImg4, NULL, &cards[i].rect);
				break;
			case 5:
				SDL_RenderCopy(renderer, cardImg5, NULL, &cards[i].rect);
				break;
			case 6:
				SDL_RenderCopy(renderer, cardImg6, NULL, &cards[i].rect);
				break;
			case 7:
				SDL_RenderCopy(renderer, cardImg7, NULL, &cards[i].rect);
				break;
			case 8:
				SDL_RenderCopy(renderer, cardImg8, NULL, &cards[i].rect);
				break;
			case 9:
				SDL_RenderCopy(renderer, cardImg9, NULL, &cards[i].rect);
				break;
			case 10:
				SDL_RenderCopy(renderer, cardImg10, NULL, &cards[i].rect);
				break;
			case 11:
				SDL_RenderCopy(renderer, cardImg11, NULL, &cards[i].rect);
				break;
			case 12:
				SDL_RenderCopy(renderer, cardImg12, NULL, &cards[i].rect);
				break;
			case 13:
				SDL_RenderCopy(renderer, cardImg13, NULL, &cards[i].rect);
				break;
			case 14:
				SDL_RenderCopy(renderer, cardImg14, NULL, &cards[i].rect);
				break;
			case 15:
				SDL_RenderCopy(renderer, cardImg15, NULL, &cards[i].rect);
				break;
			case 16:
				SDL_RenderCopy(renderer, cardImg16, NULL, &cards[i].rect);
				break;
			case 17:
				SDL_RenderCopy(renderer, cardImg17, NULL, &cards[i].rect);
				break;
			case 18:
				SDL_RenderCopy(renderer, cardImg18, NULL, &cards[i].rect);
				break;
			case 19:
				SDL_RenderCopy(renderer, cardImg19, NULL, &cards[i].rect);
				break;
			case 20:
				SDL_RenderCopy(renderer, cardImg20, NULL, &cards[i].rect);
				break;
			case 21:
				SDL_RenderCopy(renderer, cardImg21, NULL, &cards[i].rect);
				break;
			case 22:
				SDL_RenderCopy(renderer, cardImg22, NULL, &cards[i].rect);
				break;
			case 23:
				SDL_RenderCopy(renderer, cardImg23, NULL, &cards[i].rect);
				break;
			case 24:
				SDL_RenderCopy(renderer, cardImg24, NULL, &cards[i].rect);
				break;
			case 25:
				SDL_RenderCopy(renderer, cardImg25, NULL, &cards[i].rect);
				break;
			case 26:
				SDL_RenderCopy(renderer, cardImg26, NULL, &cards[i].rect);
				break;
			case 27:
				SDL_RenderCopy(renderer, cardImg27, NULL, &cards[i].rect);
				break;
			case 28:
				SDL_RenderCopy(renderer, cardImg28, NULL, &cards[i].rect);
				break;
			case 29:
				SDL_RenderCopy(renderer, cardImg29, NULL, &cards[i].rect);
				break;
			case 30:
				SDL_RenderCopy(renderer, cardImg30, NULL, &cards[i].rect);
				break;
			case 31:
				SDL_RenderCopy(renderer, cardImg31, NULL, &cards[i].rect);
				break;
			case 32:
				SDL_RenderCopy(renderer, cardImg32, NULL, &cards[i].rect);
				break;
			case 33:
				SDL_RenderCopy(renderer, cardImg33, NULL, &cards[i].rect);
				break;
			case 34:
				SDL_RenderCopy(renderer, cardImg34, NULL, &cards[i].rect);
				break;
			case 35:
				SDL_RenderCopy(renderer, cardImg35, NULL, &cards[i].rect);
				break;
			case 36:
				SDL_RenderCopy(renderer, cardImg36, NULL, &cards[i].rect);
				break;
			case 37:
				SDL_RenderCopy(renderer, cardImg37, NULL, &cards[i].rect);
				break;
			case 38:
				SDL_RenderCopy(renderer, cardImg38, NULL, &cards[i].rect);
				break;
			case 39:
				SDL_RenderCopy(renderer, cardImg39, NULL, &cards[i].rect);
				break;
			case 40:
				SDL_RenderCopy(renderer, cardImg40, NULL, &cards[i].rect);
				break;
			case 41:
				SDL_RenderCopy(renderer, cardImg41, NULL, &cards[i].rect);
				break;
			case 42:
				SDL_RenderCopy(renderer, cardImg42, NULL, &cards[i].rect);
				break;
			case 43:
				SDL_RenderCopy(renderer, cardImg43, NULL, &cards[i].rect);
				break;
			case 44:
				SDL_RenderCopy(renderer, cardImg44, NULL, &cards[i].rect);
				break;
			case 45:
				SDL_RenderCopy(renderer, cardImg45, NULL, &cards[i].rect);
				break;
			case 46:
				SDL_RenderCopy(renderer, cardImg46, NULL, &cards[i].rect);
				break;
			case 47:
				SDL_RenderCopy(renderer, cardImg47, NULL, &cards[i].rect);
				break;
			case 48:
				SDL_RenderCopy(renderer, cardImg48, NULL, &cards[i].rect);
				break;
			case 49:
				SDL_RenderCopy(renderer, cardImg49, NULL, &cards[i].rect);
				break;
			case 50:
				SDL_RenderCopy(renderer, cardImg50, NULL, &cards[i].rect);
				break;
			case 51:
				SDL_RenderCopy(renderer, cardImg51, NULL, &cards[i].rect);
				break;
			case 52:
				SDL_RenderCopy(renderer, cardImg52, NULL, &cards[i].rect);
				break;
			case 53:
				SDL_RenderCopy(renderer, cardImg53, NULL, &cards[i].rect);
				break;
			case 54:
				SDL_RenderCopy(renderer, cardImg54, NULL, &cards[i].rect);
				break;
			default:
				break;
			}
		}
	}
}