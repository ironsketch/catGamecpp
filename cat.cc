#include "extra.h"
#include "cat.h"

Cat::Cat(SDL_Texture *catT){
    catmX = 50;
    catmY = 50;
    mVelX = 0;
    mVelY = 0;
    useClip = 0;
    catTexture = catT; 
    SDL_QueryTexture(catTexture, NULL, NULL, &catwidth, &catheight);

    clips[0].x = 0;
    clips[0].y = 0;
    clips[0].w = catwidth / 2;
    clips[0].h = catheight;

    clips[1].x = catwidth / 2;
    clips[1].y = 0;
    clips[1].w = catwidth / 2;
    clips[1].h = catheight;
}

int Cat::getVel(){
    return CAT_VEL;
}

int Cat::getX(){
    return catmX;
}

int Cat::getY(){
    return catmY;
}

void Cat::handleEvent(SDL_Event &e){
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

void Cat::move(int screenSize, Level l){
    if((catmX + mVelX > 0) && (catmX + mVelX + (catwidth / 2) < (screenSize * .70))){
        catmX += mVelX;
    } else if(catmX + mVelX + (catwidth / 2) >= (screenSize * .70)){
        l.move(CAT_VEL);
        catmY += mVelY;
    }
}

SDL_Texture* Cat::getTexture(){
    return catTexture;
}

SDL_Rect* Cat::getclip(){
    return &clips[useClip];
}
