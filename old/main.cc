#include "player.h"
#include "level.h"
#include "timer.h"
const int FPS = 30;
int frame = 0;
bool cap = true;
Timer fps;
int main(){
    Extra extra;
    extra.gettingStarted();
    
    string playerLoc = "src/catwalk.png";
    Player catplayer(extra.loadTexture(playerLoc, extra.getRen()));
    
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
        fps.start(); 
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            switch(e.key.keysym.sym){
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                case SDLK_RETURN:
                    cap = ( !cap );
                    break;
            }
            catplayer.handleEvent(e);
        }
        SDL_RenderClear(extra.getRen());
        extra.renderTexture(bck, extra.getRen(), 0, 0, extra.getWidth(), extra.getHeight());
        level1.rend(extra);

        extra.renderTexture(catplayer.getTexture(), extra.getRen(), catplayer.getX(), catplayer.getY(), catplayer.getclip());
        SDL_RenderPresent(extra.getRen());
        catplayer.move(extra.getWidth(), &level1);
        catplayer.gravity(level1.getVector(), extra.getHeight());
        catplayer.spriteAnime();
        frame++;
        if( ( cap == true ) && ( fps.get_ticks() < 1000 / FPS ) ){
            SDL_Delay( ( 1000 / FPS ) - fps.get_ticks() );
        }
    }
    extra.destroyer(catplayer.getTexture());
    extra.destroyer(bck);
    extra.quitGame();
    return 0;
}
