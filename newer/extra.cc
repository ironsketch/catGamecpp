#include "extra.h"

int Extra::gettingStarted(){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        sdlError(cout, "SDL_Init");
        return 1;
    }
    if((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
        sdlError(cout, "IMG_Init");
        SDL_Quit();
        return 1;
    }
    window = SDL_CreateWindow("CatGame the Cat Game", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr){
        sdlError(cout, "CreateWindow");
        SDL_Quit();
        return 1;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr){
        sdlError(cout, "CreateRenderer");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
     return 0;
}

SDL_Window* Extra::getWin(){
    return window;
}

SDL_Renderer* Extra::getRen(){
    return renderer;
}

int Extra::getHeight(){
    return HEIGHT;
}

int Extra::getWidth(){
    return WIDTH;
}

void Extra::changeWindowSize(int newWidth, int newHeight){
    SDL_SetWindowSize(window, newWidth, newWidth);
    HEIGHT = newHeight;
    WIDTH = newWidth;
}

void Extra::sdlError(ostream &os, const string &msg){
    os << msg << " error: " << SDL_GetError() << endl;
}

SDL_Texture* Extra::loadTexture(const string &file, SDL_Renderer *ren){
    SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
    if(texture == nullptr){
        sdlError(cout, "LoadTexture");
    }
    return texture;
}

SDL_Texture* Extra::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h){
    SDL_Rect dst;
    dst.x = x; dst.y = y; dst.w = w; dst.h = h;
    SDL_RenderCopy(ren, tex, NULL, &dst);
    return tex;
}

SDL_Texture* Extra::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst, SDL_Rect *clip){
    SDL_RenderCopy(ren, tex, clip, &dst);
    return tex;
}

void Extra::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, SDL_Rect *clip){
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    if (clip != nullptr){
        dst.w = clip->w;
        dst.h = clip->h;
    } else {
        SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    }
    renderTexture(tex, ren, dst, clip);
}

void Extra::destroyer(SDL_Window* win){
    SDL_DestroyWindow(win);
}

void Extra::destroyer(SDL_Renderer* ren){
    SDL_DestroyRenderer(ren);
}

void Extra::destroyer(SDL_Texture* tex){
    SDL_DestroyTexture(tex);
}

void Extra::quitGame(){
    destroyer(renderer);
    destroyer(window);
    IMG_Quit();
    SDL_Quit();
}
