#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <cstdio>
#include <iostream>
#include "../headers/FlatMath.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h> 

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

bool init();
bool loadMedia();
void close();

FlatVector changeCoordinate(FlatVector vector);

void RenderVector(SDL_Renderer* renderer, int r, int g, int b, FlatVector vector);

SDL_Window* gWindow = nullptr;

SDL_Renderer* gRenderer = nullptr;

int main(int argc, char* argv[]){

    FlatVector Vector1(100,-120); 
    FlatVector Vector2(75, 35); 
    
    FlatVector Vector3 = Vector1 + Vector2;

    std::cout << Vector1 << " + " << Vector2 << " = " << Vector3 << "\n";

    //FlatVector sumVector = FlatVector1 + FlatVector2;

    //std::cout << sumVector << std::endl;
    //std::cout << FlatMath().Length(sumVector) << std::endl; 
    //std::cout << FlatMath().Normalize(sumVector) << std::endl; 
    //std::cout << FlatMath().Dot(FlatVector1,FlatVector2) << std::endl;

    if (!init()){
        printf("Failed to initialize! \n");
    } else {
        if (!loadMedia()) {
            printf("Failed to load media! \n");
        } else {
            SDL_Event e; 
            bool quit = false; 

            while (!quit) {
                while(SDL_PollEvent(&e) != 0){
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                }

                gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
                SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

                SDL_RenderClear(gRenderer);

                RenderVector(gRenderer, 0, 0, 0, Vector1);
                RenderVector(gRenderer, 0, 128, 0, Vector2);
                RenderVector(gRenderer, 128, 0, 128, Vector3);

                SDL_RenderPresent(gRenderer);
            }
        } 
    }

    close();
    return 0;
 }

bool init(){
    bool success = true; 

    if ( SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Could not initialize SDL! Error: %s\n", SDL_GetError());
        success = false;
    } else {
        gWindow = SDL_CreateWindow(
            "physiC window", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            SCREEN_WIDTH, 
            SCREEN_HEIGHT, 
            SDL_WINDOW_SHOWN);

        if (gWindow == NULL){
            printf("Could not initialize window! Error: %s\n", SDL_GetError());
        }
    }

    return success;
}

bool loadMedia(){
    bool success = true; 

    // not loading any media for now
    return success;
}

void close(){
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    gWindow = NULL;
    gRenderer = NULL;

    SDL_Quit();
}

FlatVector changeCoordinate(FlatVector vector){
    return FlatVector(vector.X+ (float)SCREEN_WIDTH/2, -vector.Y + (float)SCREEN_HEIGHT/2);
}

void RenderVector(SDL_Renderer* renderer, int r, int g, int b, FlatVector vector){
    thickLineRGBA(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, changeCoordinate(vector).X, changeCoordinate(vector).Y, 3, r, g, b, SDL_ALPHA_OPAQUE);
}
