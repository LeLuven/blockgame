#pragma once

#include <SDL.h>
#include <vector>

class RedRect {
public:
    SDL_Rect rect{};

    RedRect(int x, int y, int w, int h, bool red);

    ~RedRect();

    void move(SDL_Renderer *renderer, int x, int y);

    void render(SDL_Renderer *renderer, bool selected);

    std::vector<SDL_Rect> drawIndicators(SDL_Renderer *renderer, const std::vector<RedRect> &carObjects);

    bool isPointInside(int x, int y) const;


    bool horizontal;

    bool red;
private:

    int x, y, w, h;


};

