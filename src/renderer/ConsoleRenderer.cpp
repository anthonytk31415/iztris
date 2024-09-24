#include "ConsoleRenderer.hpp"
#include <iostream>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

ConsoleRenderer::ConsoleRenderer() : boardOffsetX(5), boardOffsetY(2) {
    clear();
}

void ConsoleRenderer::render(const Board& board, const Izmino& currentPiece) {
    clear();
    renderBorder();
    renderBoard(board);
    renderPiece(currentPiece);
    renderScore(board.getScore());  // Assuming Board has a getScore method
}

void ConsoleRenderer::renderGameOver() {
    setCursorPosition(boardOffsetX + 5, boardOffsetY + 10);
    std::cout << "Game Over!";
}

void ConsoleRenderer::renderScore(int score) {
    setCursorPosition(boardOffsetX + 25, boardOffsetY);
    std::cout << "Score: " << std::setw(6) << score;
}

void ConsoleRenderer::clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ConsoleRenderer::renderBorder() {
    // Implement border rendering
}

void ConsoleRenderer::renderBoard(const Board& board) {
    auto grid = board.getGrid();  // Assuming Board has a getGrid method
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[y].size(); ++x) {
            setCursorPosition(boardOffsetX + x, boardOffsetY + y);
            std::cout << (grid[y][x] ? FILLED_CELL : EMPTY_CELL);
        }
    }
}

void ConsoleRenderer::renderPiece(const Izmino& piece) {
    auto blocks = piece.getBlocks();
    auto [pieceX, pieceY] = piece.getPosition();
    for (int y = 0; y < blocks.size(); ++y) {
        for (int x = 0; x < blocks[y].size(); ++x) {
            if (blocks[y][x]) {
                setCursorPosition(boardOffsetX + pieceX + x, boardOffsetY + pieceY + y);
                std::cout << FILLED_CELL;
            }
        }
    }
}

void ConsoleRenderer::setCursorPosition(int x, int y) {
#ifdef _WIN32
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    std::cout << "\033[" << y + 1 << ";" << x + 1 << "H";
#endif
}