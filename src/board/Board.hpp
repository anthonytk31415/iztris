#pragma once
#include <vector>
#include "../izmino/Izmino.hpp"

class Board {
public:
    Board(int width = 10, int height = 20);
    
    bool isValidMove(const Izmino& piece, int x, int y) const;
    void placePiece(const Izmino& piece);
    void clearLines();
    int getWidth() const;
    int getHeight() const;
    const std::vector<std::vector<int>>& getGrid() const;
    int getScore() const;

private:
    std::vector<std::vector<int>> grid;
    int width;
    int height;
    int score;

    bool isLineComplete(int y) const;
    void removeLine(int y);
};