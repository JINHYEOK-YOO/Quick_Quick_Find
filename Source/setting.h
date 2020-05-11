#pragma once

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

int initialize(void); // SDL 초기 설정
SDL_Texture* loadImage(const char* path, SDL_Renderer* renderer); // 이미지를 텍스쳐로 불러오기
SDL_Texture* loadText(const char* msg, const char* fontFile, SDL_Color color, int fontSize, SDL_Renderer *ren); // 텍스트를 텍스쳐로 불러오기
int loadAllImage(void); // 모든 이미지 불러오기
void quitGame(void); // SDL 종료 설정