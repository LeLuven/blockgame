#include "block.h"
#include <SDL.h>
#include <vector>
#include <iostream>

RedRect::RedRect(int x, int y, int w, int h, bool rd)
    :x(x),y(y),w(w),h(h)
{
    rect.x = 145 + (x-1) * 60;
    rect.y = 145 + (y-1) * 60;
    rect.w = w * 50 + (w-1) * 10;
    rect.h = h * 50 + (h-1) * 10;
    red = rd;

    horizontal = w > h;
}

/*
int innerGrindXY = 145;
int innerWH = 50; ggf 10 + 40, da danach auch immer + 10
 */
void RedRect::render(SDL_Renderer* renderer, bool selected) {
    if (selected && red) {
        SDL_SetRenderDrawColor(renderer, 105, 0, 38, 255);
    } else if(!selected && red) {
        SDL_SetRenderDrawColor(renderer, 231,0,83,255);
    } else if(selected && !red){
        SDL_SetRenderDrawColor(renderer,2,46,117,255);
    } else if (!selected && !red){
        SDL_SetRenderDrawColor(renderer,6,96,246,255);
    }
    SDL_RenderFillRect(renderer, &rect);
}



std::vector<SDL_Rect> RedRect::drawIndicators(SDL_Renderer * renderer,const std::vector<RedRect>& carObjects) {
    int innerGrindXY = 145;
    int innerWH = 50;
    bool render;
    SDL_SetRenderDrawColor(renderer, 23, 255, 113, 255);
    SDL_Rect indicator = {innerGrindXY, innerGrindXY, innerWH, innerWH};
    std::vector<SDL_Rect> indicators;

    if (horizontal) {
        render = true;
        for (int i = x - 1; i >= 1; --i) {
            indicator.x = innerGrindXY + (i - 1) * 60;
            indicator.y = rect.y;
            for (const auto &carObject : carObjects) {
                if (SDL_HasIntersection(&indicator, &carObject.rect)) {
                    render = false;
                    break;
                }
            }
            if (render) {
                indicators.push_back(indicator);
            }
        }
        render = true;
        if(y == 3){
            for (int i = x + w; i <= 7; ++i) {
                indicator.x = innerGrindXY + (i - 1) * 60;
                indicator.y = rect.y;
                for (const auto &carObject : carObjects) {
                    if (SDL_HasIntersection(&indicator, &carObject.rect)) {
                        render = false;
                        break;
                    }
                }
                if (render) {
                    indicators.push_back(indicator);
                }
            }
        } else {
            render = true;
            for (int i = x + w; i <= 6; ++i) {
                indicator.x = innerGrindXY + (i - 1) * 60;
                indicator.y = rect.y;
                for (const auto &carObject : carObjects) {
                    if (SDL_HasIntersection(&indicator, &carObject.rect)) {
                        render = false;
                        break;
                    }
                }
                if (render) {
                    indicators.push_back(indicator);
                }
            }
        }
    } else {
        render = true;
        for (int i = y - 1; i >= 1; --i) {
            indicator.x = rect.x;
            indicator.y = innerGrindXY + (i - 1) * 60;
            for (const auto &carObject : carObjects) {
                if (SDL_HasIntersection(&indicator, &carObject.rect)) {
                    render = false;
                    break;
                }
            }
            if (render) {
                indicators.push_back(indicator);
            }
        }
        render = true;
        for (int i = y + h; i <= 6; ++i) {
            indicator.x = rect.x;
            indicator.y = innerGrindXY + (i - 1) * 60;
            for (const auto &carObject : carObjects) {
                if (SDL_HasIntersection(&indicator, &carObject.rect)) {
                    render = false;
                    break;
                }
            }
            if (render) {
                indicators.push_back(indicator);
            }
        }
    }
    if(!indicators.empty()){
        for(auto &ind : indicators){
            SDL_RenderDrawRect(renderer, &ind);
        }
    }
    return indicators;
}



bool RedRect::isPointInside(int x, int y) const {
    return x >= rect.x && x <= rect.x + rect.w &&
           y >= rect.y && y <= rect.y + rect.h;
}

void RedRect::move(SDL_Renderer *renderer, int xInd, int yInd) {
    if (horizontal) {
        if (rect.x < xInd) {
            x = (xInd - 145) / 60 + 1 - w + 1;
            rect.x = xInd - rect.w + 50;
        } else {
            x = (xInd - 145) / 60 + 1;
            rect.x = xInd;
        }
    } else {
        if (rect.y < yInd) {
            y = (yInd - 145) / 60 + 1 - h + 1;
            rect.y = yInd - rect.h + 50;
        } else {
            y = (yInd - 145) / 60 + 1;
            rect.y = yInd;
        }
    }
}







RedRect::~RedRect() = default;

