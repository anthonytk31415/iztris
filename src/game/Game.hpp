#pragma once
#include "../board/Board.hpp"
#include "../izmino/Izmino.hpp"
#include "../renderer/ConsoleRenderer.hpp"
#include "../input/InputHandler.hpp"
#include "../utils/Random.hpp"

class Game {
public:
    Game(int boardWidth = 10, int boardHeight = 20);
    void run();

private:
    Board board;
    Izmino currentPiece;
    Izmino nextPiece;
    ConsoleRenderer renderer;
    InputHandler inputHandler;


    int level;
    int dropInterval;  // in milliseconds
    std::chrono::steady_clock::time_point lastDropTime;

    void update();
    void render();
    void setupInputCallbacks();
    void spawnNewPiece();
    void increaseDifficulty();
    void generateNextPiece();
};