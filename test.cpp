#include <SDL.h>
#include <cmath>
#include <chrono>
#include <thread>

// Window and renderer
SDL_Window* window;
SDL_Renderer* renderer;

// Triangle vertices (centered around origin)
struct Vec2 { float x, y; };
Vec2 triangle[3] = {{-50.f, -50.f}, {50.f, -50.f}, {0.f, 50.f}};

// Rotation angle in radians
float angle = 0.0f;

// Triangle position on screen
int centerX = 400;
int centerY = 300;

// Rotate a point around origin
Vec2 rotate(Vec2 p, float a) {
    float c = cosf(a);
    float s = sinf(a);
    return {p.x * c - p.y * s, p.x * s + p.y * c};
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Rotating Triangle",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              800, 600,
                              SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    SDL_Event event;

    while (running) {
        // Poll events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Rotate triangle vertices
        Vec2 rotated[3];
        for (int i = 0; i < 3; i++)
            rotated[i] = rotate(triangle[i], angle);

        // Draw triangle
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(renderer,
                           centerX + rotated[0].x, centerY + rotated[0].y,
                           centerX + rotated[1].x, centerY + rotated[1].y);
        SDL_RenderDrawLine(renderer,
                           centerX + rotated[1].x, centerY + rotated[1].y,
                           centerX + rotated[2].x, centerY + rotated[2].y);
        SDL_RenderDrawLine(renderer,
                           centerX + rotated[2].x, centerY + rotated[2].y,
                           centerX + rotated[0].x, centerY + rotated[0].y);

        SDL_RenderPresent(renderer);

        // Increment rotation
        angle += 0.02f;

        // Limit FPS (~60)
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}