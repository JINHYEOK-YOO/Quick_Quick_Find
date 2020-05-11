#pragma once
#include "main.h"

typedef struct
{
	SDL_Rect rect;
	Visible visible;
	int cardNum;
} Card;

void shuffle(Card cards[], int start, int end); // 카드 섞음
void renderCard(Card cards[]); // 카드 출력