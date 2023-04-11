#include "level.h"

Level::Level(const std::vector<RedRect>& carObjects)
        : carObjects(carObjects) {
}

const std::vector<RedRect>& Level::getCarObjects() const {
    return carObjects;
}

