#ifndef CAT_H
#define CAT_H
#include "extra.h"
#include "level.h"

class Cat{
    public:
        static const int CAT_WIDTH = 50;
        static const int CAT_HEIGHT = 50;
        static const int CAT_VEL = 3;
        Cat(SDL_Texture *tex);
        int getX();
        int getY();
        void handleEvent(SDL_Event &e);
        void move(int screenSize, Level l);
        SDL_Texture* getTexture();
        SDL_Rect* getclip();
    private:
        SDL_Texture *catTexture;
        SDL_Rect clips[2];
        int mX, mY, width, height;
        int mVelX, mVelY;
        int useClip;
};

#endif
