#include "extra.h"
#include "cat.h"

Cat::Cat(SDL_Texture *catT){
    catmX = 50;
    catmY = 50;
    mVelX = 0;
    mVelY = 0;
    cat_gravity = 10;
    useClip = 0;
    catTexture = catT; 
    SDL_QueryTexture(catTexture, NULL, NULL, &catwidth, &catheight);

    for(int i = 0; i < 16; i++){
        clips[i].x = i * catwidth / 16;
        clips[i].y = 0;
        clips[i].w = catwidth / 16;
        clips[i].h = catheight;
    }
    
    catCollision.w = catwidth / 16;
    catCollision.h = catheight;
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
                moving = true;
                forward = true;
                mVelX += CAT_VEL;
                break;
            case SDLK_a:
                moving = true;
                forward = false;
                mVelX -= CAT_VEL;
                break;
            case SDLK_w:
                moving = true;
                mVelY -= CAT_VEL;
                break;
            default:
                break;
        }
    } else if(e.type == SDL_KEYUP && e.key.repeat == 0){
        switch(e.key.keysym.sym){
            case SDLK_d:
                moving = false;
                mVelX -= CAT_VEL;
                break;
            case SDLK_a:
                moving = false;
                mVelX += CAT_VEL;
                break;
            case SDLK_w:
                moving = false;
                mVelY += CAT_VEL;
                break;
            default:
                break;
        }
    }
}

void Cat::move(int screenSize, Level *l){
    if((catmX + mVelX > 0) && (catmX + mVelX + (catwidth / 16) < (screenSize * .70))){
        catmX += mVelX;
        catCollision.x += mVelX; 
    } else if(catmX + mVelX + (catwidth / 16) >= (screenSize * .70)){
        l->move(CAT_VEL);
    }
}

SDL_Texture* Cat::getTexture(){
    return catTexture;
}

SDL_Rect* Cat::getclip(){
    return &clips[useClip];
}

void Cat::spriteAnime(){
    if(moving){
        if(forward){
            if(useClip >= 7){
                useClip = 0;
            } else {
                useClip++;
            }
        } else if(!(forward)){
            if(useClip >= 15){
                useClip = 8;
            } else {
                useClip++;
            }
        }
    }
}

void Cat::gravity(vector<SDL_Rect> &v, int screenHeight){
    //if(!collided(v)){ 
        //catmY += cat_gravity;
        //catCollision.y += cat_gravity;
    //}
    collided(v);
}

bool Cat::collided(vector<SDL_Rect> &v){
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    int catMid = (catCollision.x + catCollision.w) / 2;
    int diff;

    leftA = catCollision.x;
    rightA = catCollision.x + catCollision.w;
    topA = catCollision.y;
    bottomA = catCollision.y + catCollision.h;
    for(int i = 0; i < v.size(); i++){
        leftB = v[i].x;
        rightB = v[i].x + v[i].w;
        topB = v[i].y - 40;
        bottomB = v[i].y + v[i].h;
        if(v[i].x <= catMid && (v[i].x + v[i].w) >= catMid){
            if(bottomA <= topB){
                diff = topB - bottomA;
                if(diff < cat_gravity){
                    catmY += diff;
                    catCollision.y += diff;
                    return true;
                } else {
                    catmY += cat_gravity;
                    catCollision.y += cat_gravity;
                    return true;
                }
            }
        }
    }
    return false;
}
