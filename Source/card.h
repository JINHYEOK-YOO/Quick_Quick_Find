#pragma once
#include "main.h"

typedef struct
{
	SDL_Rect rect;
	Visible visible;
	int cardNum;
} Card;

void shuffle(Card cards[], int start, int end); // ī�� ����
void renderCard(Card cards[]); // ī�� ���