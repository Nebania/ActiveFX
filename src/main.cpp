#include <SDL2/SDL.h>
#include <stdio.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <ActiveForms/include/ActiveForms.h>
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

bool isRunning = true;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

ActiveForms forms;
void mainLoop()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        ImGui_ImplSDL2_ProcessEvent(&e);

        #ifndef __EMSCRIPTEN__
        if (e.type == SDL_QUIT)
            isRunning = false;
        #endif
    }

    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    // UI
    int w, h;
    SDL_GetWindowSize(window, &w, &h);

    ImGui::Begin("ActiveFX WindowMain", nullptr, ImGuiWindowFlags_NoTitleBar);
    ImGui::SetWindowPos(ImVec2(0, 0));
    ImGui::SetWindowSize(ImVec2(w, h));

    ImGui::Button("Hello ActiveFX", ImVec2(150, 70));
    ImGui::Text("Hello World");

    ImGui::End();

    ImGui::Render();

    ImGuiIO& io = ImGui::GetIO(); // ✅ correct place

    SDL_RenderSetScale(renderer,
        io.DisplayFramebufferScale.x,
        io.DisplayFramebufferScale.y);

    SDL_SetRenderDrawColor(renderer, 0, 128, 160, 255);
    SDL_RenderClear(renderer);

    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);

    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        return -1;

    // ✅ assign to global (NO redefinition)
    window = SDL_CreateWindow(
        "ActiveFX Content Player",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        880, 700,
        SDL_WINDOW_SHOWN
    );

    if (!window)
        return -1;

    // ✅ create renderer AFTER window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
        return -1;

    // ImGui setup
    ImGui::CreateContext();
    ImGui::StyleColorsLight();

    ImGuiStyle& style = ImGui::GetStyle();
    style.ScaleAllSizes(1.2f);
    style.FramePadding = ImVec2(10, 8);
    style.ItemSpacing  = ImVec2(12, 10);

    ImGuiIO& io = ImGui::GetIO(); // ✅ now safe
    io.FontGlobalScale = 1.1f;

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(mainLoop, 0, 1);
#else
    while (isRunning)
        mainLoop();
#endif

    // Cleanup
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}