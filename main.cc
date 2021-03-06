#include "player.h"
#include "level.h"
#include "timer.h"
const int FPS = 30;
int frame = 0;
bool cap = true;
Timer fps;
int main(){
    
    // This extra is for setting up the game and rendering images. Very useful. But you have to pass it a lot to get stuff done. Better than lots of lines of code.
    Extra extra;
    
    // This sets up the game. If you make your own game this would need to run at start
    extra.gettingStarted();
    
    // Setting up the character and passing the animetion sheet used. As of 08/26/18 This sheet only runs through walking animetion. To add more you will need to program the player file.
    string playerLoc = "src/catwalk.png";
    Player catplayer(extra.loadTexture(playerLoc, extra.getRen()));
    
    // This sets up the Level. I will be making this more dynamic soon...
    string grndLoc = "src/grass.png";
    Level level1(extra.loadTexture(grndLoc, extra.getRen()), extra.getHeight());
    
    // Array of levels.
    vector<Level*> levels = {&level1};
    int playerLevel = 0;
    
    // In the future this will be added to the level
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
            // handling the player movement and based on that everything else moves.
            catplayer.handleEvent(e);
        }

        // clear everything to rerender
        SDL_RenderClear(extra.getRen());

        // In the future the background will be handled by the level
        extra.renderTexture(bck, extra.getRen(), 0, 0, extra.getWidth(), extra.getHeight());
        
        // Sends extra to the current level to render things which may change in the future
        levels[playerLevel]->rend(extra);
        
        catplayer.anime(&extra, levels[playerLevel]);
        catplayer.update(&extra);
        SDL_RenderPresent(extra.getRen());
        
        // This is important, it makes sure my processor doesn't run this game as fast as it can. 
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
