#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "level.h"

class Player{
    public:
        static const int player_VEL = 5;
        Player(SDL_Texture *tex);
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
        void update(Extra *ext);
        void anime(Extra *ext, Level *lvl);
    private:
        SDL_Texture *playerTexture;
        SDL_Rect clips[16];
        int playermX, playermY, playerwidth, playerheight;
        int mVelX, mVelY;
        int player_gravity;
        int useClip;
        SDL_Rect playerCollision;
        bool moving = false;
        bool forward = true;
};

#endif
