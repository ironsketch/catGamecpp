#include "cat.h"
#include "level.h"

int main(){
    Extra extra;
    extra.gettingStarted();
    
    string catLoc = "src/gifcat_small.png";
    Cat catplayer(extra.loadTexture(catLoc, extra.getRen()));
    
    string grndLoc = "src/grass.png";
    Level level1(extra.loadTexture(grndLoc, extra.getRen()), extra.getHeight());
    
    string backgroundImage = "src/sky.png";
    SDL_Texture *bck = extra.loadTexture(backgroundImage, extra.getRen());
    if(bck == nullptr){
        extra.destroyer(bck);
        extra.quitGame();
        return 1;
    }
    
    SDL_Event e;
    bool quit = false;

    while(!quit){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            switch(e.key.keysym.sym){
                case SDLK_ESCAPE:
                    quit = true;
                    break;
            }
            catplayer.handleEvent(e);
        }
        SDL_RenderClear(extra.getRen());
        extra.renderTexture(bck, extra.getRen(), 0, 0, extra.getWidth(), extra.getHeight());
        level1.rend(extra);
        extra.renderTexture(catplayer.getTexture(), extra.getRen(), catplayer.getX(), catplayer.getY(), catplayer.getclip());
        SDL_RenderPresent(extra.getRen());
        catplayer.move(extra.getWidth(), level1);
    }
    extra.destroyer(catplayer.getTexture());
    extra.destroyer(bck);
    extra.quitGame();
    return 0;
}
