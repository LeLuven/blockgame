//
// Created by Jonas Luven on 08.04.23.
//

#ifndef BLOCKED_LEVEL_H
#define BLOCKED_LEVEL_H


#include <vector>
#include "block.h"

class Level {
public:
    Level(const std::vector<RedRect>& carObjects);

    const std::vector<RedRect>& getCarObjects() const;

private:
    std::vector<RedRect> carObjects;
};


#endif //BLOCKED_LEVEL_H
