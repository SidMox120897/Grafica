
#include <SDL2/SDL.h>

#include <stdio.h>
#include <iostream>
#include <vector>

#include "glad/include/glad/glad.h"
#include "Figuras/punto.h"
#include "Figuras/recta.h"
#include "Figuras/poligono.h"
#include "Figuras/circulo.h"


//g++ prueba5.cpp Figuras/punto.cpp  Figuras/recta.cpp glad/src/glad.c -I.glad/include -lSDL2 -ldl -Wall -o pixel



void Dibujar_Punto(float x, float y){
    glColor3ub(255,0,0);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2d(x,y);
    glEnd();
}



int main(int argc, char* argv[]) {



    SDL_Window *window;
    SDL_GLContext context;


    SDL_Init(SDL_INIT_VIDEO);

    punto cero=punto(0,0,0);
    cero.set_tamanio(4);
    cero.RGBf(0,0,255);


    circulo C= circulo(cero,75);
    circulo C2= circulo(cero,75/2);


    window = SDL_CreateWindow(
        "Proyecto SDL OPENGL",
        0,
        0,
        640,
        480,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );

    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    context=SDL_GL_CreateContext(window);
    gladLoadGLLoader(SDL_GL_GetProcAddress);

    bool game_is_still_running=1;
    while (game_is_still_running) {

        glViewport(0,0,640,480);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-640/2, 640/2,-480/2, 480/2,-1.0,1.0);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                game_is_still_running = 0;
            }
        }

        glClearColor(0.0f, 0.0f, 0.0f,1.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);


        C.dibujarBresenham();
        C2.dibujarPuntoMedio();


        SDL_GL_SwapWindow(window);



    }

    // Close and destroy the window
    SDL_DestroyWindow(window);
    SDL_GL_DeleteContext(context);
    // Clean up
    SDL_Quit();
    return 0;
}