#include "Application.hpp"

void Shockwave::InitWindow(int w,int h){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "Initial Error:" << SDL_GetError() << std::endl;
    }
    window = SDL_CreateWindow("Shockwave Player",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,w,h,SDL_WINDOW_OPENGL);
    if(!window){
        std::cout << "Window Error:" << SDL_GetError() << std::endl;
    }
    gl = SDL_GL_CreateContext(window);

    SDL_GL_SetSwapInterval(1);
}

void Shockwave::Events(){
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT){
            isRunning = false;
        }
    }
}
void Shockwave::Display(){
    Events();
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(12.0);
    glBegin(GL_POINTS);
    {
        glVertex2f(102,0);
    }
    glEnd();

    SDL_GL_SwapWindow(window);
}
void Shockwave::Reshape() {
    int w, h;
    SDL_GetWindowSize(window, &w, &h);

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // 2D projection: left, right, bottom, top
    gluOrtho2D(-w,w,h,-h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void Shockwave::Quit(){
    SDL_GL_DeleteContext(gl);
    SDL_DestroyWindow(window);
}
void Shockwave::Start(){
    InitWindow(800,600);
    Reshape();
    while(isRunning){
        Shockwave::Display();
    }
    Quit();
}