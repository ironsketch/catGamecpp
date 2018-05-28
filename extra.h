#ifndef EXTRA_H
#define EXTRA_H
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>
#include <iostream>
using namespace std;

class Extra{
    public:
        int gettingStarted();
        SDL_Window* getWin();
        SDL_Renderer* getRen();
        int getHeight();
        int getWidth();
        void sdlError(ostream &os, const string &msg);
        SDL_Texture* loadTexture(const string &file, SDL_Renderer *ren);
        SDL_Texture* renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
        SDL_Texture* renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst,SDL_Rect * clip = nullptr);
        void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y,SDL_Rect *clip = nullptr);
        void destroyer(SDL_Window* win);
        void destroyer(SDL_Renderer* ren);
        void destroyer(SDL_Texture* tex);
        void quitGame();
    private:
        SDL_Renderer *renderer;
        SDL_Window *window;
        int HEIGHT = 600;
        int WIDTH = 800;
};

#endif
