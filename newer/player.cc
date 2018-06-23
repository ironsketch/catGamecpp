#include "extra.h"
#include "player.h"

Player::Player(SDL_Texture *SDLtexture, int spriteSheetSize){
    playerTexture = SDLtexture;
    playerX = 0;
    playerY = 0;
    playerTMPx = 0;
    playerTMPy = 0;
    playerVelocity = 7;
    playerGravity = 7;
    
    SDL_QueryTexture(catTexture, NULL, NULL, &playerWidth, &playerHeight);
    
    playerCollision.x = 0;
    playerCollision.y = 0;
    playerCollision.w = playerWidth / playerSpriteSheetSize;
    playerCollision.h = playerHeight;
    
    playerMoving = false;
    playerForward = true;
    playerJumping = false;
    
    playerSpriteSheetSize = spriteSheetSize;
    playerUseClip = 0;
    playerClips.resize(playerSpriteSheetSize);

    for(int i = 0; i < playerSpriteSheetSize; i++){
        playerClips[i].x = i * playerWidth / playerSpriteSheetSize;
        playerClips[i].y = 0;
        playerClips[i].w = playerWidth / playerSpriteSheetSize;
        playerClips[i].h = playerHeight;
    }
}
void Player::handleEvent(SDL_Event &e){
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0){
        switch(e.key.keysym.sym){
            case SDLK_d:
                playerMoving = true;
                playerForward = true;
                playerTMPx += playerVelocity;
                break;
            case SDLK_a:
                playerMoving = true;
                playerForward = false;
                playerTMPx -= playerVelocity;
                break;
            case SDLK_w:
                playerJumping = true;
                playerMoving = false;
                playerTMPy -= playerGravity;
                break;
            default:
                break;
        }
    } else if(e.type == SDL_KEYUP && e.key.repeat == ){
        switch(e.key.keysym.sym){
            case SDLK_d:
                playerMoving = false;
                playerTMPx -= playerVelocity;
                break;
            case SDLK_a:
                playerMoving = false;
                playerTMPx += playerVelocity;
                break;
            case SDLK_w:
                playerJumping = false;
                playerMoving = false;
                playerTMPy += playerGravity;
                break;
            default:
                break;
        }
    }
}
void Player::move(int screenSize, Level *l, vector<SDL_Rect> &v){
    vector<int> collidedWithR = collided(v);
    if((playerX + playerTMPx > 0) && (playerX + playerTMPx + (playerHeight / playerSpriteSheetSize) < (screenSize * .70))){
        if(collidedWithR[0] == 0 && !playerForward){    
            playerX += playerTMPx;
            playerCollision.x += playerTMPx;
        } else if(collidedWithR[1] == 0 && playerForward){
            playerX += playerTMPx;
            playerCollision.x += playerTMPx;
        }
        if(collidedWithR[2] == 0 && playerJumping){
            playerY += playerTMPy;
            playerCollision.y += playerTMPy;
        } else if(collidedWithR[3] == 0 && !playerJumping){
            playerY += playerTMPy;
            playerCollision.y += playerTMPy;
        }
    } else if(playerX + playerTMPx + (playerHeight / playerSpriteSheetSize)){
        if(collidedWithR[1] == 0 && playerForward){
            l->move(playerVelocity);
        }
        if(collidedWithR[2] == 0 && playerJumping){
            playerY += playerTMPy;
            playerCollision.y += playerTMPy;
        } else if(collidedWithR[3] == 0 && !playerJumping){
            playerY += playerTMPy;
            playerCollision.y += playerTMPy;
        }
    }
    spriteAnime();
}
void Player::spriteAnime(){
    if(playerMoving){
        if(playerForward){
            if(playerUseClip >= 5){
                playerUseClip = 0;
            } else {
                playerUseClip++;
            }
        } else if(!(playerForward)){
            if(playerUseClip >= 11){
                playerUseClip = 6;
            } else {
                playerUseClip++;
            }
        }
    }
}
vector<int> &Player::collided(vector<SDL_Rect> &v){
    int leftA, leftB, rightA, rightB, topA, topB, bottomA, bottomB;
    vector<int> collidedWith{0, 0, 0, 0};
    leftA = playerCollision.x;
    rightA = playerCollision.x + playerCollision.w;
    topA = playerCollision.y;
    bottomA = playerCollision.y + playerCollision.h;
    for(int i = 0; i < v.size(); i++){
        leftB = v[i].x;
        rightB = v[i].x + v[i].w;
        topB = v[i].y - 40;
        bottomB = v[i].y + v[i].h;
        if(bottomA <= topB){
            collidedeWith[3] = 1;    
        }
        if(topA >= bottomB){
            collidedeWith[2] = 1;
        }
        if(rightA <= leftB){
            collidedeWith[1] = 1;
        }
        if(leftA >= rightB){
            collidedeWith[0] = 1;
        }
    }
    return collidedWith;
}
SDL_Rect* Player::getClip(){
    return &playerClips[playerUseClip];
}
SDL_Texture* Player::getTexture(){
    return playerTexture;
}
int Player::getY(){
    return playerY;
}
int Player::getX(){
    return playerX;
}
int Player::getVelocity(){
    return playerVelocity;
}
int Player::getGravity(){
    return playerGravity;
}
void Player::changeX(int newX){
    playerX = newX;
}
void Player::changeY(int newY){
    playerY = newY;
}
