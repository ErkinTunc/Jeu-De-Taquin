#include<stdio.h>
#include "src/include/SDL2/SDL.h"
#include "Code_Taquin.h"

const int WITH = 800, HEIGHT = 600;

int SDL_main(int argc, char *argv){

    SDL_Init( SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Hello SDL WORLD", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WITH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI );
    
    if(NULL == window){
        printf("Could not create window: ");
        return 1;
    }

    SDL_Event SDL_WindowEvent;

    int BoolA = 1; //Shows if it is true or false
    while( BoolA ){

        if ( SDL_Quit == SDL_WindowEvent.type){
            BoolA = 0; // Set BoolA to false to exit the loop
            break;
        }
    }

    SDL_DestroyWindow( window );
    SDL_Quit();

    return EXIT_SUCCESS;
}