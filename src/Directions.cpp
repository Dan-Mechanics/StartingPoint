#include "bit_manipulation.h"
#include <iostream>
#include <array>
#include <string>
#include "Directions.h"

enum CardinalDirections {
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3,
    MAX_DIRECTIONS = 4
};

// Is this proper naming convention?
const std::array<std::string, 4> DIRECTION_NAMES = { "North", "South", "East", "West" };

Directions::Directions() = default;

int Directions::run() const {
    /*int32_t num = 6;
    std::cout << quickEvenOrOdd(10) << quickEvenOrOdd(11) << quickEvenOrOdd(3) << std::endl;
    printBits(11, 4);*/

    int8_t direction = 0;

    direction = setBit(direction, CardinalDirections::NORTH);
    printDirection(direction);

    direction = setBit(direction, CardinalDirections::EAST);
    printDirection(direction);

    return 0;
}

void Directions::printDirection(int8_t direction) const {
    for (int8_t i = 0; i < CardinalDirections::MAX_DIRECTIONS; i++)
    {
        if (getBit(direction, i))
            std::cout << DIRECTION_NAMES[i] << " ";
    }

    std::cout << std::endl;
}