#ifndef CAT_H
#define CAT_H
#include <vector>
#include "extra.h"
#include "level.h"

class Cat{
    public:
        static const int CAT_VEL = 5;
        Cat(SDL_Texture *tex);
        int getVel();
        int getX();
        int getY();
        void handleEvent(SDL_Event &e);
        void move(int screenSize, Level *l);
        SDL_Texture* getTexture();
        SDL_Rect* getclip();
        void spriteAnime();
        void gravity(vector<SDL_Rect> &v, int screenHeight);
        bool collided(vector<SDL_Rect> &v);
    private:
        SDL_Texture *catTexture;
        SDL_Rect clips[16];
        int catmX, catmY, catwidth, catheight;
        int mVelX, mVelY;
        int cat_gravity;
        int useClip;
        SDL_Rect catCollision;
        bool moving = false;
        bool forward = true;
};

#endif
