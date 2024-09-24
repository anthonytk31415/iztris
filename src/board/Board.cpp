#include "Board.hpp"

Board::Board(int width, int height) : width(width), height(height), score(0) {
    grid.resize(height, std::vector<int>(width, 0));
}

bool Board::isValidMove(const Izmino& piece, int x, int y) const {
    auto blocks = piece.getBlocks();
    for (int i = 0; i < blocks.size(); ++i) {
        for (int j = 0; j < blocks[i].size(); ++j) {
            if (blocks[i][j]) {
                int newX = x + j;
                int newY = y + i;
                if (newX < 0 || newX >= width || newY >= height) {
                    return false;
                }
                if (newY >= 0 && grid[newY][newX]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Board::placePiece(const Izmino& piece) {
    auto blocks = piece.getBlocks();
    auto [x, y] = piece.getPosition();
    for (int i = 0; i < blocks.size(); ++i) {
        for (int j = 0; j < blocks[i].size(); ++j) {
            if (blocks[i][j]) {
                grid[y + i][x + j] = 1;
            }
        }
    }
    clearLines();
}

void Board::clearLines() {
    int linesCleared = 0;
    for (int y = height - 1; y >= 0; --y) {
        if (isLineComplete(y)) {
            removeLine(y);
            ++linesCleared;
            ++y; // Check the same line again
        }
    }
    // Update score based on lines cleared
    score += linesCleared * linesCleared * 100; // Simple scoring system
}

bool Board::isLineComplete(int y) const {
    for (int x = 0; x < width; ++x) {
        if (grid[y][x] == 0) {
            return false;
        }
    }
    return true;
}

void Board::removeLine(int y) {
    for (int i = y; i > 0; --i) {
        grid[i] = grid[i - 1];
    }
    grid[0] = std::vector<int>(width, 0);
}

int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}

const std::vector<std::vector<int>>& Board::getGrid() const {
    return grid;
}

int Board::getScore() const {
    return score;
}