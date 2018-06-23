#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "extra.h"

class Level{
    public:
        Level(SDL_Texture *tex, int screenWidth);
        void move(int newx);
        int getX();
        int getY();
        void rend(Extra ex);
        SDL_Texture* groundTex();
        vector<SDL_Rect> &getVector();
    private:
        vector<SDL_Rect> levelCollides;
        SDL_Texture *ground;
        int groundX, groundY, groundwidth, groundheight;        
};

#endif
