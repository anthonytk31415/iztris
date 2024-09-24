#pragma once
#include <vector>
#include "../izmino/Izmino.hpp"

class Board {
public:
    Board(int width, int height);
    bool isValidMove(const Izmino& izmino, int x, int y) const;
    void placeTetromino(const Izmino& izmino, int x, int y);
    void clearLines();
    // Add more methods as needed

private:
    std::vector<std::vector<int>> grid;
    // Add more members as needed
};