#pragma once
#include <vector>
#include <utility>

/** 
 * Izmino class, represents a single Iztris piece (also known as a izmino). 
 * It encapsulates the shape, orientation, and behavior of an Iztris piece.
*/

class Izmino {
public:
    enum class Shape { I, O, T, S, Z, J, L };
    
    Izmino(Shape shape);
    void rotate(bool clockwise = true);
    Shape getShape() const;
    std::vector<std::vector<bool>> getBlocks() const;
    std::pair<int, int> getSize() const;
    void setPosition(int x, int y);
    std::pair<int, int> getPosition() const;

private:
    Shape shape;
    std::vector<std::vector<bool>> blocks;
    int x, y; // position on the board
    void initializeShape();
};