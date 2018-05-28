#include "extra.h"
#include "cat.h"

Cat::Cat(SDL_Texture *catT){
    mX = 50;
    mY = 50;
    mVelX = 0;
    mVelY = 0;
    useClip = 0;
    catTexture = catT;
    int w, h; 
    SDL_QueryTexture(catTexture, NULL, NULL, &w, &h);

    clips[0].x = 0;
    clips[0].y = 0;
    clips[0].w = w / 2;
    clips[0].h = h;

    clips[1].x = w / 2;
    clips[1].y = 0;
    clips[1].w = w / 2;
    clips[1].h = h;
}

int Cat::getX(){
    return mX;
}

int Cat::getY(){
    return mY;
}

void Cat::handleEvent(SDL_Event &e){
    int w, h;
    SDL_QueryTexture(catTexture, NULL, NULL, &w, &h);
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0){
        switch(e.key.keysym.sym){
            case SDLK_d:
                useClip = 0;
                mVelX += CAT_VEL;
                break;
            case SDLK_a:
                useClip = 1;
                mVelX -= CAT_VEL;
                break;
            default:
                break;
        }
    } else if(e.type == SDL_KEYUP && e.key.repeat == 0){
        switch(e.key.keysym.sym){
            case SDLK_d:
                mVelX -= CAT_VEL;
                break;
            case SDLK_a:
                mVelX += CAT_VEL;
                break;
            default:
                break;
        }
    }
}

void Cat::move(){
    mX += mVelX;
    mY += mVelY;
}

SDL_Texture* Cat::getTexture(){
    return catTexture;
}

SDL_Rect* Cat::getclip(){
    return &clips[useClip];
}
