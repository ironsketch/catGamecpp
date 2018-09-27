#include "player.h"

Player::Player(SDL_Texture *playerT){
    playermX = 50;
    playermY = 50;
    mVelX = 0;
    mVelY = 0;
    player_gravity = 10;
    useClip = 0;
    playerTexture = playerT; 
    SDL_QueryTexture(playerTexture, NULL, NULL, &playerwidth, &playerheight);

    for(int i = 0; i < 16; i++){
        clips[i].x = i * playerwidth / 16;
        clips[i].y = 0;
        clips[i].w = playerwidth / 16;
        clips[i].h = playerheight;
    }
    
    playerCollision.w = playerwidth / 16;
    playerCollision.h = playerheight;
}

int Player::getVel(){
    return player_VEL;
}

int Player::getX(){
    return playermX;
}

int Player::getY(){
    return playermY;
}

void Player::handleEvent(SDL_Event &e){
    if(e.type == SDL_KEYDOWN){
        switch(e.key.keysym.sym){
            case SDLK_d:
                mVelX += player_VEL;
                break;
        }
    }
}

/* void Player::handleEvent(SDL_Event &e){
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0){
        moving = true;
        switch(e.key.keysym.sym){
            case SDLK_d:
                forward = true;
                mVelX += player_VEL;
                break;
            case SDLK_a:
                forward = false;
                mVelX -= player_VEL;
                break;
            case SDLK_w:
                mVelY -= player_VEL;
                break;
            default:
                break;
        }
    } else if(e.type == SDL_KEYUP && e.key.repeat == 0){
        moving = false;
        switch(e.key.keysym.sym){
            case SDLK_d:
                mVelX -= player_VEL;
                break;
            case SDLK_a:
                mVelX += player_VEL;
                break;
            case SDLK_w:
                mVelY += player_VEL;
                break;
            default:
                break;
        }
    }
} */

void Player::move(int screenSize, Level *l){
    if((playermX + mVelX > 0) && (playermX + mVelX + (playerwidth / 16) < (screenSize * .70))){
        playermX += mVelX;
        playerCollision.x += mVelX; 
    } else if(playermX + mVelX + (playerwidth / 16) >= (screenSize * .70)){
        l->move(player_VEL);
    }
}

SDL_Texture* Player::getTexture(){
    return playerTexture;
}

SDL_Rect* Player::getclip(){
    return &clips[useClip];
}

void Player::spriteAnime(){
    if(moving){
        if(forward){
            if(useClip >= 7 || useClip >= 8){
                useClip = 0;
            } else {
                useClip++;
            }
        } else if(!(forward)){
            if(useClip >= 15 || useClip <= 7){
                useClip = 8;
            } else {
                useClip++;
            }
        }
    }
}

void Player::gravity(vector<SDL_Rect> &v, int screenHeight){
    //if(!collided(v)){ 
        //playermY += player_gravity;
        //playerCollision.y += player_gravity;
    //}
    collided(v);
}

bool Player::collided(vector<SDL_Rect> &v){
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    int playerMid = (playerCollision.x + playerCollision.w) / 2;
    int diff;

    leftA = playerCollision.x;
    rightA = playerCollision.x + playerCollision.w;
    topA = playerCollision.y;
    bottomA = playerCollision.y + playerCollision.h;
    for(int i = 0; i < v.size(); i++){
        leftB = v[i].x;
        rightB = v[i].x + v[i].w;
        topB = v[i].y - 40;
        bottomB = v[i].y + v[i].h;
        if(v[i].x <= playerMid && (v[i].x + v[i].w) >= playerMid){
            if(bottomA <= topB){
                diff = topB - bottomA;
                if(diff < player_gravity){
                    playermY += diff;
                    playerCollision.y += diff;
                    return true;
                } else {
                    playermY += player_gravity;
                    playerCollision.y += player_gravity;
                    return true;
                }
            }
        }
    }
    return false;
}
void Player::update(Extra *ext){
    ext->renderTexture(getTexture(), ext->getRen(), getX(), getY(), getclip());
}
void Player::anime(Extra *ext, Level *lvl){
    spriteAnime();
    move(ext->getWidth(), lvl);
    gravity(lvl->getVector(), ext->getHeight());
}
