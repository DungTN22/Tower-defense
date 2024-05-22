#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

const int width=800;
const int height=800;

int main(int arcv,char*argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG);
    SDL_Window *window= SDL_CreateWindow("Tower Defense",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
    SDL_Event event;
    while(true){
        if(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                break;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    IMG_Quit();
    return EXIT_SUCCESS;
}