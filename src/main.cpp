#include <SDL.h>
#include <cmath>

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

        void drawCircle(int center_x, int center_y, int radius_, int r_, int g_, int b_, int a_) {
            // set color to red with 100% opacity
            SDL_SetRenderDrawColor(renderer, r_, g_, b_, a_);

            // Drawing the circle
            for(int x = center_x - radius_; x <= center_x + radius_; x++) {
                for(int y = center_y - radius_; y <= center_y + radius_; y++) { // ((3 - (-1))^2 + (-2 - 4)^2) = 16
                    if ((std::pow(center_y - y, 2) + std::pow(center_x - x, 2)) <= std::pow(radius_,2)) { // 16 = 16 sp condition met
                        SDL_RenderDrawPoint(renderer, x, y); // drawing dots in a circle?
                    }
                }
            }

            // Render change to screen
            SDL_RenderPresent(renderer);
        }

        // Do a sqaure next
};


int main(int argc, char * argv[]) {

    // Creating the object by passing height and width values
    Framework fw(200, 400);

    // Calling function that draws a circle
    fw.drawCircle(200, 100, 50, 255, 0, 0, 255);
    fw.drawCircle(300, 200, 50, 100, 90, 150, 525);

    SDL_Event event; // event variable

    // loop to check if the window has terminated using the close button in the window corner
    while(!(event.type == SDL_QUIT)) {
        SDL_Delay(10); // set delay for check
        SDL_PollEvent(&event);
    }
}