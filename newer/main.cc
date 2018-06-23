#include "player.h"
#include "level.h"
#include "timer.h"

const int FPS = 30;
Timer FPStimer;

// LEVEL 1 //
vector<string> level1_ground = {"src/grass.png"};
vector<string> level1_enemy = {"src/enemybird.png"};
vector<string> level1_passive = {"src/large_cloud.png", "src/small_cloud.png"};
vector<string> level1_pickup = {"src/cattreat.png", "src/catnip.png"};
string level1_background = "src/sky.png";

// Holds the information for the game window
// and functions for rendering images
int main(){
    Extra extra;
    extra.gettingStarted();
    
    SDL_Event e;
    bool quit = false;

    // Creating the player
    string catLoc = "src/catwalk.png";
    Player catplayer(extra.loadTexture(catLoc, extra.getRen()), 16);

    //  LEVEL 1
    Level level1(extra, level1_ground, level1_enemy, level1_passive, level1_pickup, level1_background);

    while(!quit){
        FPStimer.start();
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            switch(e.key.keysym.sym){
                case SDLK_ESCAPE:
                    quit = true;
                    break;
            }

            // Everything is dependent on what the user wants to do.
            catplayer.handleEvent(e);
        }

        SDL_RenderClear(extra.getRen());
        SDL_RenderPresent(extra.getRen());

        // I need to render level graphics, this includes upating 
        //      what is in the level new enemies new objects etc.
        // Render player this includes movement, gravity
        
        if(FPStimer.get_ticks() < 1000 / FPS){
            SDL_Delay( ( 1000 / FPS ) - FPStimer.get_ticks() );
        }
    }
    
    // Destroying everything for quit.
    extra.quitGame();
    return 0;
}
