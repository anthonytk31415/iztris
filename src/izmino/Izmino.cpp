#include "Izmino.hpp"

Izmino::Izmino(Shape shape) : shape(shape), x(0), y(0) {
    initializeShape();
}

void Izmino::rotate(bool clockwise) {
    // Implement rotation logic here
    // This will rotate the blocks vector
}

Izmino::Shape Izmino::getShape() const {
    return shape;
}

std::vector<std::vector<bool>> Izmino::getBlocks() const {
    return blocks;
}

std::pair<int, int> Izmino::getSize() const {
    if (blocks.empty()) return {0, 0};
    return {blocks.size(), blocks[0].size()};
}

void Izmino::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

std::pair<int, int> Izmino::getPosition() const {
    return {x, y};
}
/**
 * The getSize() method is designed to return the dimensions of the bounding box that contains the Izmino piece. 
 * This is useful for:
    - Collision detection
    Rendering the piece on the game board
    Calculating rotations and movements
 */
void Izmino::initializeShape() {
    switch (shape) {
        case Shape::I:
            blocks = {{1, 1, 1, 1}};
            break;
        case Shape::O:
            blocks = {{1, 1},
                      {1, 1}};
            break;
        case Shape::T:
            blocks = {{1, 1, 1},
                      {0, 1, 0}};
            break;
        case Shape::S:
            blocks = {{0, 1, 1},
                      {1, 1, 0}};
            break;
        case Shape::Z:
            blocks = {{1, 1, 0},
                      {0, 1, 1}};
            break;
        case Shape::J:
            blocks = {{1, 0, 0},
                      {1, 1, 1}};
            break;
        case Shape::L:
            blocks = {{0, 0, 1},
                      {1, 1, 1}};
            break;
    }
}