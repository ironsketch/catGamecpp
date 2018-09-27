#include "level.h"
#include <cmath>

Level::Level(SDL_Texture *tex, int screenHeight){
    ground = tex;
    SDL_QueryTexture(ground, NULL, NULL, &groundwidth, &groundheight);
    groundY = screenHeight - groundheight;
    groundX = 0;
}

void Level::move(int newx){
    groundX -= newx;
}

int Level::getX(){
    return groundX;
}

int Level::getY(){
    return groundY;
}

void Level::rend(Extra ex){
    levelCollides.clear();
    for(int i = groundX; i < ex.getWidth(); i += groundwidth){
        ex.renderTexture(ground, ex.getRen(), i, groundY, nullptr);    
        SDL_Rect *tmp = new SDL_Rect;
        tmp->x = i; tmp->y = groundY; tmp->w = groundwidth; tmp->h = groundheight;
        levelCollides.push_back(*tmp);
    }
}

SDL_Texture* Level::groundTex(){
    return ground;
}

vector<SDL_Rect> &Level::getVector(){
    return levelCollides;
}
