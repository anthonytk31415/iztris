#pragma once
#include "../board/Board.hpp"
#include "../izmino/Izmino.hpp"
#include "../renderer/ConsoleRenderer.hpp"
#include "../input/InputHandler.hpp"

class Game {
public:
    Game();
    void run();

private:
    Board board;
    Izmino currentPiece;
    ConsoleRenderer renderer;
    InputHandler inputHandler;

    void update();
    void render();
    void setupInputCallbacks();
};