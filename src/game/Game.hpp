#pragma once
#include "../board/Board.hpp"
#include "../izmino/Izmino.hpp"
// #include "../renderer/ConsoleRenderer.hpp"

class Game {
public:
    Game();
    void run();

private:
    Board board;
    Izmino currentPiece;
    // ConsoleRenderer renderer;
    // Add more members as needed

    void handleInput();
    void update();
    void render();
};