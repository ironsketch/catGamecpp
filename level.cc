#include "level.h"
#include <cmath>
using namespace std;

Level::Level(SDL_Texture *tex, int screenHeight){
    ground = tex;
    SDL_QueryTexture(ground, NULL, NULL, &groundwidth, &groundheight);
    groundY = screenHeight - groundheight;
    groundX = 0;
}

void Level::move(int newx){
    groundX += newx;
}

int Level::getX(){
    return groundX;
}

int Level::getY(){
    return groundY;
}

void Level::rend(Extra ex){
    //if(abs(mX) > width){
     //   mX /= width;
    //}
    for(int i = groundX; i < ex.getWidth(); i += groundwidth){
        ex.renderTexture(ground, ex.getRen(), i, groundY, nullptr);    
    }
}

SDL_Texture* Level::getTexture(){
    return ground;
}
