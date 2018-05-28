#include "level.h"
#include <cmath>
using namespace std;

Level::Level(SDL_Texture *tex, int screenHeight){
    ground = tex;
    SDL_QueryTexture(ground, NULL, NULL, &width, &height);
    mY = screenHeight - height;
    mX = 0;
}

void Level::move(int newx){
    mX += newx;
}

int Level::getX(){
    return mX;
}

int Level::getY(){
    return mY;
}

void Level::rend(Extra ex, int screenWidth){
    //if(abs(mX) > width){
     //   mX /= width;
    //}
    for(int i = mX; i < screenWidth; i += width){
        ex.renderTexture(ground, ex.getRen(), i, mY, nullptr);    
    }
}

SDL_Texture* Level::getTexture(){
    return ground;
}
