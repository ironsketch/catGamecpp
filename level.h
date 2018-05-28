#ifndef LEVEL_H
#define LEVEL_H
#include "extra.h"

class Level{
    public:
        Level(SDL_Texture *tex, int screenWidth);
        void move(int newx);
        int getX();
        int getY();
        void rend(Extra ex, int screenWidth);
        SDL_Texture* getTexture();
    private:
        SDL_Texture *ground;
        int mX, mY, width, height;
};

#endif
