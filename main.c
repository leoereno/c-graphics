#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 320
#define HEIGHT 200

// sometimes 'int' might not give a 32 bytes in older architectures
uint32_t framebuffer[WIDTH * HEIGHT];

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Event event;

    window = SDL_CreateWindow(
        "Title", 
        WIDTH, 
        HEIGHT, 
        0);
    
    renderer = SDL_CreateRenderer(
        window,
        NULL
    );

    texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_XRGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        WIDTH,
        HEIGHT
    );

    uint8_t is_running = 1;

    while (is_running) {
        
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                is_running = 0;
            }
        }
       
        framebuffer[16500] = 0x00FF00;

        SDL_UpdateTexture(
            texture,
            NULL,
            framebuffer,
            //PITCH = width of texture in bytes
            WIDTH * sizeof(uint32_t)
        );

        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

