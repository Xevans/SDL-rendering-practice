#include <SDL.h>

class Framework {
    private:
        int height;
        int width;
        SDL_Renderer *renderer = NULL;
        SDL_Window *window = NULL;
    
    public:
        Framework(int height_, int width_): height(height_), width(width_) {
            SDL_Init(SDL_INIT_VIDEO); // init SDL as Video
            SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // set draw color
            SDL_RenderClear(renderer); // clear newly created window
            SDL_RenderPresent(renderer); // reflects the changes done in the window
        }

        ~Framework() {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
        }
};


int main(int argc, char * argv[]) {

    // Creating the object by passing height and width values
    Framework fw(200, 400);

    SDL_Event event; // event variable

    // loop to check if the window has terminated using the close button in the window corner
    while(!(event.type == SDL_QUIT)) {
        SDL_Delay(10); // set delay for check
        SDL_PollEvent(&event);
    }
}