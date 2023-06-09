#include <iostream>
#include <SDL.h>
#include <vector>
#include "block.h"
#include "level.h"
#include<SDL_ttf.h>


using namespace std;

const int grid_size = 8;
const int box_size = 60;

bool IsPointInsideRect(int x, int y, SDL_Rect rect) {
    if (x >= rect.x && x <= rect.x + rect.w &&
        y >= rect.y && y <= rect.y + rect.h) {
        // the point is inside the rectangle
        return true;
    } else {
        // the point is outside the rectangle
        return false;
    }
}

bool isCarAtPosition(const vector<RedRect> &carObjects, int x, int y) {
    for (const auto &car: carObjects) {
        if (IsPointInsideRect(x, y, car.rect)) {
            return true;
        }
    }
    return false;
}

void setColor(int red, int green, SDL_Rect rect, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, red, green, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

std::vector<Level> generateLevels() {
    std::vector<Level> levels;

    // Level 1
    RedRect carGreen1 = {1, 1, 2, 1, false};
    RedRect carPurple1 = {1, 2, 1, 3, false};
    RedRect carOrange1 = {1, 5, 1, 2, false};
    RedRect carRed1 = {2, 3, 2, 1, true};
    RedRect carDarkBlue1 = {4, 2, 1, 3, false};
    RedRect carDarkGreen1 = {3, 6, 3, 1, false};
    RedRect carYellow1 = {6, 1, 1, 3, false};
    RedRect carBlue1 = {5, 5, 2, 1, false};
    std::vector<RedRect> carObjects1 = {carGreen1, carPurple1, carOrange1, carRed1, carDarkBlue1, carDarkGreen1,
                                        carYellow1, carBlue1};
    levels.emplace_back(carObjects1);

    // Level 2
    RedRect carGreen2 = {1, 1, 1, 2, false};
    RedRect carYellow2 = {4, 1, 3, 1, false};
    RedRect carRed2 = {1, 3, 2, 1, true};
    RedRect carOrange2 = {4, 2, 1, 2, false};
    RedRect carBlue2 = {5, 3, 1, 2, false};
    RedRect carDarkBlue2 = {1, 4, 3, 1, false};
    RedRect carPurple2 = {6, 2, 1, 3, false};
    RedRect carDarkGreen2 = {1, 6, 2, 1, false};
    RedRect carPink2 = {3, 5, 1, 2, false};
    RedRect carBlack2 = {4, 6, 2, 1, false};
    RedRect carDarkPurple2 = {5, 5, 2, 1, false};
    std::vector<RedRect> carObjects2 = {carGreen2, carYellow2, carRed2, carOrange2, carBlue2, carDarkBlue2, carPurple2,
                                        carDarkPurple2, carDarkGreen2, carPink2, carBlack2};
    levels.emplace_back(carObjects2);

    // Level 3
    RedRect carRed3 = {2, 3, 2, 1, true};
    RedRect carGreen3 = {2, 4, 2, 1, false};
    RedRect carOrange3 = {2, 5, 1, 2, false};
    RedRect carYellow3 = {4, 3, 1, 3, false};
    RedRect carBlue3 = {3, 6, 2, 1, false};
    RedRect carPurple3 = {6, 4, 1, 3, false};
    std::vector<RedRect> carObjects3 = {carRed3, carGreen3, carOrange3, carYellow3, carBlue3, carPurple3};
    levels.emplace_back(carObjects3);

    // Level 4
    RedRect carYellow4 = {1, 1, 1, 3, false};
    RedRect carRed4 = {2, 3, 2, 1, true};
    RedRect carPurple4 = {4, 1, 1, 3, false};
    RedRect carGreen4 = {3, 4, 1, 2, false};
    RedRect carDarkBlue4 = {4, 4, 3, 1, false};
    RedRect carTurkis4 = {3, 6, 3, 1, false};
    RedRect carOrange4 = {6, 5, 1, 2, false};
    std::vector<RedRect> carObjects4 = {carYellow4, carRed4, carPurple4, carGreen4, carDarkBlue4, carTurkis4,
                                        carOrange4};
    levels.emplace_back(carObjects4);

    // Level 21
    RedRect carGreen21 = {1,1,2,1, false};
    RedRect carOrange21 = {3,1,1,2,false};
    RedRect carYellow21 = {4,1,1,3,false};
    RedRect carPurple21 = {1,2,1,3,false};
    RedRect carBlue21 = {2,4,3,1,false};
    RedRect carRed21 = {2,3,2,1,true};
    RedRect carTurkis21 = {4,6,3,1,false};

    std::vector<RedRect> carObjects21 = {carGreen21,carOrange21,carYellow21,carPurple21,carBlue21,carRed21,carTurkis21};

    levels.emplace_back(carObjects21);

    //  Level 31
    RedRect carGreen31 = {1,1,2,1, false};
    RedRect carYellow31 = {4,1,3,1,false};
    RedRect carOrange31 = {4,2,1,2,false};
    RedRect carBlue31 = {5,2,2,1,false};
    RedRect carPink31 = {1,3,1,2,false};
    RedRect carRed31 = {2,3,2,1,true};
    RedRect carDarkGreen31 = {1,5,2,1,false};
    RedRect carDarkBlue31 = {3,4,1,3,false};
    RedRect carDarkPurple31 = {4,4,2,1, false};
    RedRect carPurple31 = {6,3,1,3,false};
    RedRect carTurkis31 = {4,6,3,1, false};

    std::vector<RedRect> carObjects31 = {carGreen31,carYellow31,carOrange31,carBlue31,carPink31,carRed31,carDarkGreen31,carDarkBlue31,
                                         carDarkPurple31,carPurple31,carTurkis31};

    levels.emplace_back(carObjects31);

    //  Level 40
    RedRect carDarkYellow40 = {1,1,1,3, false};
    RedRect carGreen40 = {2,1,2,1,false};
    RedRect carBlue40 = {2,2,1,2,false};
    RedRect carPink40 = {3,2,1,2,false};
    RedRect carOrange40 = {5,1,1,2,false};
    RedRect carRed40 = {4,3,2,1,true};
    RedRect carPurple40 = {6,2,1,3,false};
    RedRect carDarkBlue40 = {1,4,3,1,false};
    RedRect carDarkPurple40 = {4,4,1,2, false};
    RedRect carBlack40 = {5,5,2,1,false};
    RedRect carBeige40 = {1,6,2,1, false};
    RedRect carDarkGreen40 = {3,5,1,2,false};
    RedRect carYellow40 = {4,6,2,1, false};

    std::vector<RedRect> carObjects40 = {carDarkYellow40,carGreen40,carBlue40,carPink40,carOrange40,carRed40,carPurple40, carDarkBlue40,
                                         carDarkPurple40,carBlack40,carBeige40,carDarkGreen40,carYellow40};

    levels.emplace_back(carObjects40);








    return levels;
}

int main() {

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("My Window", 900, 800, 640, 640, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_INVALID);
    SDL_Event event;

    if (TTF_Init() == -1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        return 1;
    }
    TTF_Font* font = TTF_OpenFont("/Users/jonasluven/Documents/Hochschule/2D/Sprites/Source_Code_Pro/static/SourceCodePro-Bold.ttf", 15);
    if (font == nullptr) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        // Handle the error accordingly
    }


    int gridWidth = grid_size * box_size;
    int gridHeight = grid_size * box_size;
    int gridX = (640 - gridWidth) / 2;
    int gridY = (640 - gridHeight) / 2;
    int innerGrindXY = 145;
    int innerWH = 50;

    vector<SDL_Rect> outerBlock;
    vector<SDL_Rect> lines;


    int index = -1;

    // Load levels
    std::vector<Level> levels = generateLevels();
    int currentLevel = 0;
    std::vector<RedRect> carObjects = levels[currentLevel].getCarObjects();


    SDL_Rect boxRect = {gridX, gridY, box_size, box_size};
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            if (i == 0 || i == grid_size - 1 || j == 0 || j == grid_size - 1 && i != 3) {
                SDL_RenderFillRect(renderer, &boxRect);
                outerBlock.push_back(boxRect);
            } else {
                SDL_RenderDrawRect(renderer, &boxRect);
                lines.push_back(boxRect);
            }
            // GRIDXY = 240 + 60
            boxRect.x += box_size;
        }
        boxRect.x = gridX;
        boxRect.y += box_size;
    }

    //OUTLINE
    SDL_Rect outline = {gridX - 1, gridY - 1, 480 + 2, 480 + 2};
    lines.push_back(outline);

    //FIN
    SDL_Rect fin = {145 + (6) * 60, 145 + (2) * 60, 50, 50};

    int count = 0;

    //Indicators
    vector<SDL_Rect> Indicators;
    while (true) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                goto clean;
            }
            switch (event.type) {
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_RETURN) {
                        currentLevel = (currentLevel + 1) % levels.size();
                        carObjects = levels[currentLevel].getCarObjects();
                    } else if(event.key.keysym.sym == SDLK_r){
                        carObjects = levels[currentLevel].getCarObjects();
                        count = 0;
                    }
                    break;


                case SDL_MOUSEBUTTONDOWN:
                    int mouseX = event.button.x;
                    int mouseY = event.button.y;
                    //Indicator Detect & Move
                    if (index != -1) {
                        for(auto &ind : Indicators){
                            if (IsPointInsideRect(mouseX, mouseY,ind)){
                                carObjects[index].move(renderer,ind.x,ind.y);
                                count ++;
                                index = -1;
                            }
                        }

                    }  {
                        // Selected
                        for (int i = 0; i < carObjects.size(); i++) {
                            if (IsPointInsideRect(mouseX, mouseY, carObjects[i].rect)) {
                                index = i;
                                break;
                            }
                            if (!IsPointInsideRect(mouseX, mouseY, carObjects[i].rect)) {
                                index = -1;
                            }
                        }
                    }
                    break;

            }
        }
        //Load Level
        int red;
        for (int i = 0; i < carObjects.size(); i++) {
            if (carObjects[i].red) {
                red = i;
            }
        }
        if (SDL_HasIntersection(&carObjects[red].rect, &fin)) {
            currentLevel = (currentLevel + 1) % levels.size();
            carObjects = levels[currentLevel].getCarObjects();
            count = 0;
        }
        //Clear
        SDL_SetRenderDrawColor(renderer, 10, 26, 33, 255);
        SDL_RenderClear(renderer);
        //Code
        if (true) {
            // Text Render
            const char* level = "Level ";
            string f_level = level + to_string(currentLevel+1);

            const char* moves = "Moves ";
            string f_moves = moves + to_string(count);
            SDL_Color text_color = {255, 255, 255, 255}; // White text color

            SDL_Surface* text_surface = TTF_RenderText_Solid(font, f_level.c_str(), text_color);
            SDL_Surface* move_surface = TTF_RenderText_Solid(font,f_moves.c_str(),text_color);
            if (text_surface == nullptr) {
                printf("TTF_RenderText_Solid: %s\n", TTF_GetError());
                // Handle the error accordingly
            }

            SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
            SDL_Texture* moves_texture = SDL_CreateTextureFromSurface(renderer, move_surface);
            if (text_texture == nullptr) {
                printf("SDL_CreateTextureFromSurface: %s\n", SDL_GetError());
                // Handle the error accordingly
            }

            SDL_Rect text_rect;
            SDL_Rect moves_rect;
            text_rect.x = 10;
            text_rect.y = 10;
            text_rect.w = text_surface->w;
            text_rect.h = text_surface->h;

            moves_rect.x = text_rect.x;
            moves_rect.y = text_rect.y + text_surface->h;
            moves_rect.w = move_surface->w;
            moves_rect.h = move_surface->h;

            SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
            SDL_RenderCopy(renderer, moves_texture, NULL, &moves_rect);

            //Outlines
            SDL_SetRenderDrawColor(renderer, 114, 164, 172, 255);
            for (auto block: lines) {
                SDL_RenderDrawRect(renderer, &block);
            }

            //Border
            SDL_SetRenderDrawColor(renderer, 114, 164, 172, 255);
            for (auto block: outerBlock) {
                SDL_RenderFillRect(renderer, &block);
            }

            // Fin Block
            SDL_SetRenderDrawColor(renderer, 23, 255, 113, 255);
            SDL_RenderFillRect(renderer, &fin);

            //Cars
            for (int i = 0; i < carObjects.size(); i++) {
                if (index == i) {
                    carObjects[i].render(renderer, true);
                    Indicators = carObjects[i].drawIndicators(renderer, carObjects);
                } else {
                    carObjects[i].render(renderer, false);

                }
            }
        }

        //Render
        SDL_RenderPresent(renderer);
    }
    clean:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_CloseFont(font);
    TTF_Quit();

}
