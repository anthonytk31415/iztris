#include "Izmino.hpp"

Izmino::Izmino(Shape shape) : shape(shape), x(0), y(0) {
    initializeShape();
}

void Izmino::rotate(bool clockwise) {
    if (shape == Shape::O) {
        // O piece doesn't rotate
        return;
    }

    int n = blocks.size();
    int m = blocks[0].size();

    // Create a new matrix for the rotated piece
    std::vector<std::vector<bool>> rotated(m, std::vector<bool>(n, false));

    if (clockwise) {
        // Clockwise rotation
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rotated[j][n-1-i] = blocks[i][j];
            }
        }
    } else {
        // Counter-clockwise rotation
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rotated[m-1-j][i] = blocks[i][j];
            }
        }
    }

    // Update the blocks with the rotated piece
    blocks = rotated;

    // Handle I and O pieces specially
    if (shape == Shape::I) {
        // Adjust position for I piece to maintain its center of rotation
        if (n == 4) {  // vertical to horizontal
            y += 1;
            x -= 1;
        } else {  // horizontal to vertical
            y -= 1;
            x += 1;
        }
    }
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
    - Rendering the piece on the game board
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