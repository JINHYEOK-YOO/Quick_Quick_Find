#include "main.h"
#include "setting.h"
#include "time_record.h"

double timeValue = 0.0;
char timeString[100];
char recordString[100];
SDL_Color textColor = { 64, 64, 64, 255 };
SDL_Rect timeRect = { 680, 135, 144, 64 };
SDL_Rect recordRect = { 858, 8, 54, 24 };
SDL_Texture *timer, *record;

/* �ð� ���� */
void timeElapse()
{
	timeValue += MSEC;
}

/* �ְ� ��� �ҷ����� */
void loadRecord()
{
	FILE* fp = fopen("record.txt", "rt");
	if (fp == NULL)
	{
		recordString[0] = '0';
		recordString[1] = '.';
		recordString[2] = '0';
		recordString[3] = '0';
		recordString[4] = '\0';
	}
	else
	{
		fscanf(fp, "%s", recordString);
		fclose(fp);
	}
}

/* �ְ� ��� ���� */
void saveRecord()
{
	if (timeValue < atof(recordString) || atof(recordString) == 0)
	{
		FILE* fp = fopen("record.txt", "wt");
		fprintf(fp, "%.2f", timeValue);
		fclose(fp);
	}
}

/* �ð� ��� */
void renderTime()
{
	sprintf(timeString, "%.2f", timeValue);
	timer = loadText(timeString, "fonts/erasbd.ttf", textColor, 64, renderer);
	SDL_RenderCopy(renderer, timer, NULL, &timeRect);
}

/* �ְ� ��� ��� */
void renderRecord()
{
	record = loadText(recordString, "fonts/erasbd.ttf", textColor, 24, renderer);
	SDL_RenderCopy(renderer, record, NULL, &recordRect);
}