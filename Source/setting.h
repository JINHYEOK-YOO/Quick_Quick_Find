#pragma once

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

int initialize(void); // SDL �ʱ� ����
SDL_Texture* loadImage(const char* path, SDL_Renderer* renderer); // �̹����� �ؽ��ķ� �ҷ�����
SDL_Texture* loadText(const char* msg, const char* fontFile, SDL_Color color, int fontSize, SDL_Renderer *ren); // �ؽ�Ʈ�� �ؽ��ķ� �ҷ�����
int loadAllImage(void); // ��� �̹��� �ҷ�����
void quitGame(void); // SDL ���� ����