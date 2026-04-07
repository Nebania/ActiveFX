#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    // ⚠️ MUST be before window creation
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);

    SDL_Window* window = SDL_CreateWindow(
        "GL4ES Triangle",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_OPENGL
    );

    SDL_GLContext context = SDL_GL_CreateContext(window);

    int running = 1;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = 0;
        }

        // Clear screen
        glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw triangle (OLD OpenGL style)
        glBegin(GL_TRIANGLES);

            glColor3f(1, 0, 0);
            glVertex2f(0.0f, 0.5f);

            glColor3f(0, 1, 0);
            glVertex2f(-0.5f, -0.5f);

            glColor3f(0, 0, 1);
            glVertex2f(0.5f, -0.5f);

        glEnd();

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}