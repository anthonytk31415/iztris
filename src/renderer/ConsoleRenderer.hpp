#pragma once

#include <vector>
#include "../board/Board.hpp"
#include "../izmino/Izmino.hpp"

class ConsoleRenderer {
public:
    ConsoleRenderer();
    
    void render(const Board& board, const Izmino& currentPiece);
    void renderGameOver();
    void renderScore(int score);
    void clear();

private:
    void renderBorder();
    void renderBoard(const Board& board);
    void renderPiece(const Izmino& piece);
    void setCursorPosition(int x, int y);
    
    static const char EMPTY_CELL = ' ';
    static const char FILLED_CELL = '█';
    static const char BORDER_VERTICAL = '│';
    static const char BORDER_HORIZONTAL = '─';
    static const char BORDER_CORNER = '┼';
    
    int boardOffsetX;
    int boardOffsetY;
};