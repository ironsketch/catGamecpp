#ifndef LEVEL_H 
#define LEVEL_H
#include <vector>
#include "extra.h"

class Level{
    public:
        Level(Extra &ex, vector<string> &groundStrings, vector<string> &enemyStrings, vector<string> &passiveStrings, vector<string> &pickupStrings, string background_image);
        void move(Extra &ex, int newx);
        void rend(Extra &ex);
        void addGround(SDL_Rect &r);
        void addGround(SDL_Texture &t);
        void addEnemy(SDL_Rect &r);
        void addEnemy(SDL_Texture &t);
        void addPassive(SDL_Rect &r);
        void addPassice(SDL_Texture &t);
        void addTexGround(SDL_Texture &t);
        void addTexEnemy(SDL_Texture &t);
        void addTexPassive(SDL_Texture &t);
    private:
        SDL_Texture *background;
        SDL_Rect backgroundRect;
        vector<SDL_Texture> groundTex;
        vector<SDL_Texture> enemyTex;
        vector<SDL_Texture> passiveTex;
        vector<SDL_Texture> pickupTex;
        vector<SDL_Rect> groundObjects;
        vector<SDL_Texture> groundObjectsTextures;
        vector<SDL_Rect> enemyObjects;
        vector<SDL_Texture> enemyObjectsTextures;
        vector<SDL_Rect> passiveObjects;
        vector<SDL_Texture> passiveObjectsTextures;
        vector<SDL_Rect> pickUpObjects;
        vector<SDL_Texture> pickUpTextures;
};
#endif
