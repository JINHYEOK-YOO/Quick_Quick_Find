/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

#include "main.h"
#include "setting.h"
#include "card.h"
#include "time_record.h"

/* 마우스 좌표가 Rect 내부 인지 확인 */
int checkMouseInRect(SDL_Rect rect, int x, int y)
{
    if(x < rect.x)
        return 0;
    else if(x > rect.x + rect.w)
        return 0;
    else if(y < rect.y)
        return 0;
    else if(y > rect.y + rect.h)
        return 0;
    
    return 1;
}

int main( int argc, char* args[] )
{
	initialize();

	int quit = 0;
	State game = READY;
	SDL_Event e;
	SDL_Rect backgroundRect = { 0,0,960,720 };
	SDL_Rect playRect = { 700, 220, 125, 55 };
	SDL_Rect gameoverRect = { 625, 210, 334, 72 };
	int i, row, col;
	int match = 0;
	int count = SIZE;
	Card cards[SIZE];
	Card deck[SIZE];

	srand((unsigned int)time(NULL));
	
	/* 카드 설정 */
	for (row = 0; row < ROW; row++)
		for (col = 0; col < COL; col++)
		{
			i = row * COL + col;
			cards[i].rect.w = 81;
			cards[i].rect.h = 108;
			cards[i].visible = INVISIBLE;
			cards[i].cardNum = i + 1;
		}
	for (row = 0; row < ROW / 2; row++)
		for (col = 0; col < COL; col++)
		{
			i = row * COL + col;
			cards[i].rect.x = 40 + 100 * col;
			cards[i].rect.y = 306 + 130 * row;
		}
	shuffle(cards, 0, SIZE);
	for (i = 0; i < SIZE; i++)
	{
		deck[i].rect.w = 95;
		deck[i].rect.h = 127;
		deck[i].rect.x = 435;
		deck[i].rect.y = 92;
		deck[i].visible = INVISIBLE;
		deck[i].cardNum = cards[i].cardNum;
	}
	shuffle(deck, 0, SIZE / 2);
	shuffle(deck, SIZE / 2 + 1, SIZE);

	if (loadAllImage() < 0)
	{
		printf("Failed to load texture image!\n");
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	loadRecord();

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = 1;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState( &x, &y );

                // Check if mouse is in button
                for(i = 0; i < SIZE; i++)
                {
					if (checkMouseInRect(playRect, x, y))
					{
						if (game == READY)
						{
							deck[match].visible = VISIBLE;
							for (i = 0; i < SIZE; i++)
								cards[i].visible = VISIBLE;
						}
						game = PLAYING;
						SDL_DestroyTexture(play);
					}

					if (checkMouseInRect(cards[i].rect, x, y))
					{
						if ((deck[match].cardNum == cards[i].cardNum) && (cards[i].visible == VISIBLE))
						{
							cards[i].visible = INVISIBLE;
							if (i < SIZE / 2)
							{
								cards[i + SIZE/2].rect.x = cards[i].rect.x;
								cards[i + SIZE/2].rect.y = cards[i].rect.y;
							}
							deck[match++].visible = INVISIBLE;
							if (match != SIZE)
								deck[match].visible = VISIBLE;
							count--;
						}
					}
                }
            }
			if (count == 0)
			{
				game = OVER;
				saveRecord();
				loadRecord();
			}
        }

        //Clear screen
        SDL_RenderClear( renderer );

        //Render images
		if (game == PLAYING)
		{
			timeElapse();
			renderTime();
		}
		SDL_RenderCopy(renderer, background, NULL, &backgroundRect);
		SDL_RenderCopy(renderer, play, NULL, &playRect);
		renderCard(cards);
		renderCard(deck);
		renderTime();
		renderRecord();

		if (game == OVER)
			SDL_RenderCopy(renderer, gameover, NULL, &gameoverRect);

        SDL_RenderPresent( renderer );
    }

	quitGame();

    return 0;
}