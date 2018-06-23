#include "level.h"

Level::Level(Extra &ex, vector<string> &groundStrings, vector<string> &enemyStrings, vector<string> &passiveStrings, vector<string> &pickupStrings, string background_image){
    
    background = ex.loadTexture(background_image, ex.getRen());
   
    for(int i = 0; i < groundStrings.size(); i++){
        groundTex.push_back(*(ex.loadTexture(groundStrings[i], ex.getRen())));
    }
    for(int i = 0; i < enemyStrings.size(); i++){
        enemyTex.push_back(*(ex.loadTexture(enemyStrings[i], ex.getRen())));
    }
    for(int i = 0; i < passiveStrings.size(); i++){
        passiveTex.push_back(*(ex.loadTexture(passiveStrings[i], ex.getRen())));
    }
    for(int i = 0; i < pickupStrings.size(); i++){
        pickupTex.push_back(*(ex.loadTexture(pickupStrings[i], ex.getRen())));
    }

}

void Level::move(Extra &ex, int newx){
    
}
void Level::rend(Extra &ex){
    
}
void Level::addGround(SDL_Rect &r){
    groundObjects.push_back(r);
}
void Level::addGround(SDL_Texture &t){
    groundObjectsTextures.push_back(t);
}
void Level::addEnemy(SDL_Rect &r){
    enemyObjects.push_back(r);
}
void Level::addEnemy(SDL_Texture &t){
    enemyObjectsTextures.push_back(t);
}
void Level::addPassive(SDL_Rect &r){
    passiveObjects.push_back(r);
}
void Level::addPassice(SDL_Texture &t){
    passiveObjectsTextures.push_back(t);
}
void Level::addTexGround(SDL_Texture &t){
    groundTex.push_back(t);
}
void Level::addTexEnemy(SDL_Texture &t){
    enemyTex.push_back(t);
}
void Level::addTexPassive(SDL_Texture &t){
    passiveTex.push_back(t);
}
