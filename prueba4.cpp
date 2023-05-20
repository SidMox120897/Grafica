
#include <SDL2/SDL.h>
#include <stdio.h>

#include <iostream>

int main(int argc, char* argv[]) {

    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        0,
        0,
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_SHOWN                  // flags - see below
    );

    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    bool game_is_still_running=1;
    while (game_is_still_running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                game_is_still_running = 0;
            }
            if(event.type == SDL_MOUSEMOTION){
                std::cout<<"Se mueve el mouse\n";
            }
            event.button.state = SDL_RELEASED;
            if(event.type == SDL_MOUSEBUTTONDOWN){
                std::cout<<"Presiona Mouse\n";
            }

            if(event.type == SDL_MOUSEBUTTONUP){
                std::cout<<"Solto Mouse\n";
            }
            if(event.type == SDL_KEYDOWN){
                std::cout<<"Se Preciono tecla\n";
                if(event.key.keysym.sym==SDLK_0){
                    std::cout<<"0\n";
                }
                if(event.key.keysym.sym==SDLK_a){
                    std::cout<<"a\n";
                }
            }
            if(event.type == SDL_KEYUP){
                std::cout<<"Se Solto tecla\n";
            }

            const Uint8* state =SDL_GetKeyboardState(NULL) ;
            if(state[SDL_SCANCODE_RIGHT]){
                std::cout<<"Derecha\n";
            }
            if(state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_DOWN]){
                std::cout<<"Derecha Abajo\n";
            }
        }
    }

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}