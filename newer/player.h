#ifndef PLAYER_H
#define PLAYER_H
#include "extra.h"
#include "level.h"
class Player{
    public:
        Player(SDL_Texture *SDLtexture, int spriteSheetSize);
        void handleEvent(SDL_Event &e);
        void move(int screenSize, Level *l, vector<SDL_Rect> &v);
        void spriteAnime();
        vector<int> &collided(vector<SDL_Rect> &v);
        SDL_Rect* getClip();
        SDL_Texture* getTexture();
        int getY();
        int getX();
        int getVelocity();
        int getGravity();
        void changeX(int newX);
        void changeY(int newY);
        void changeVelocity(int newVelocity);
        void changeGravity(int newGravity);
    private:
        SDL_Texture *playerTexture;
        int playerX, playerY, playerTMPx, playerTMPy;
        int playerVelocity, playerGravity;
        int playerWidth, playerHeight;
        SDL_Rect playerCollision;
        bool playerMoving, playerForward, playerJumping;
        int playerSpriteSheetSize;
        int playerUseClip;
        vector<SDL_Rect> playerClips;
};
#endif
