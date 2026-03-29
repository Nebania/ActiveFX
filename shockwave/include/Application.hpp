#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_events.h>
#include <GL/glu.h>
#include <cstdlib>
#include <ctime>
class Shockwave{
    public:
        SDL_Window* window;
        SDL_GLContext gl;
        SDL_Renderer* renderer;
        SDL_Event e;
        bool isRunning = true;
        void InitWindow(int w,int h);
        void Events();
        void Reshape();
        void Display();
        void Quit();
        void Start();
};

#endif