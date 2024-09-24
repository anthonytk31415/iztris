#include "Game.hpp"
#include <chrono>
#include <thread>
#include <random>

Game::Game(int boardWidth, int boardHeight) 
    : board(boardWidth, boardHeight),
      currentPiece(static_cast<Izmino::Shape>(rand() % 7)),  // Random initial piece
      renderer(),
      inputHandler()
{
    setupInputCallbacks();
    spawnNewPiece();
}

void Game::run() {
    while (true) {
        inputHandler.pollEvents();
        update();
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Game::update() {
    // Game logic here
    // For example: move the current piece down
    // If it can't move down, lock it in place and spawn a new piece
}

void Game::render() {
    renderer.render(board, currentPiece);
}

void Game::setupInputCallbacks() {
    inputHandler.setActionCallback(InputHandler::Action::MoveLeft, [this]() {
        // Move piece left if possible
        auto [x, y] = currentPiece.getPosition();
        if (board.isValidMove(currentPiece, x - 1, y)) {
            currentPiece.setPosition(x - 1, y);
        }
    });
    inputHandler.setActionCallback(InputHandler::Action::MoveRight, [this]() {
        // Move piece right if possible
        auto [x, y] = currentPiece.getPosition();
        if (board.isValidMove(currentPiece, x + 1, y)) {
            currentPiece.setPosition(x + 1, y);
        }
    });
    inputHandler.setActionCallback(InputHandler::Action::Rotate, [this]() {
        // Rotate piece if possible
        currentPiece.rotate();
        if (!board.isValidMove(currentPiece, currentPiece.getPosition().first, currentPiece.getPosition().second)) {
            currentPiece.rotate(false);  // Rotate back if not valid
        }
    });
    inputHandler.setActionCallback(InputHandler::Action::Drop, [this]() {
        // Drop piece to the bottom
        while (board.isValidMove(currentPiece, currentPiece.getPosition().first, currentPiece.getPosition().second + 1)) {
            auto [x, y] = currentPiece.getPosition();
            currentPiece.setPosition(x, y + 1);
        }
        board.placePiece(currentPiece);
        spawnNewPiece();
    });
    inputHandler.setActionCallback(InputHandler::Action::Quit, [this]() {
        // Quit game
        exit(0);
    });
}

void Game::spawnNewPiece() {
    currentPiece = Izmino(static_cast<Izmino::Shape>(rand() % 7));
    int startX = board.getWidth() / 2 - currentPiece.getSize().second / 2;
    currentPiece.setPosition(startX, 0);
    
    if (!board.isValidMove(currentPiece, startX, 0)) {
        // Game over condition
        renderer.renderGameOver();
        exit(0);
    }
}