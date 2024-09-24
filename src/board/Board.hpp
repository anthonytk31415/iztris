#ifndef BOARD_HPP
#define BOARD_HPP

#pragma once
#include <vector>
#include "../izmino/Izmino.hpp"

/** 
 * @class Board
 * @brief Represents the game board and handles game logic.
 * Things like: checking if a move is valid, placing a piece, removing lines, 
 * getting the score, and getting the grid.
 */
class Board {
public:
    /** 
     * @brief Constructor with default width and height.
     * @param width The width of the board.
     * @param height The height of the board.
     */
    Board(int width = 10, int height = 20);
    
    /** 
     * @brief Checks if a piece can be placed at a given position.
     * @param piece The piece to be placed.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @return true if the move is valid, false otherwise.
     */
    bool isValidMove(const Izmino& piece, int x, int y) const;
    
    /** 
     * @brief Places a piece on the board and triggers line clearing.
     * @param piece The piece to place on the board.
     */
    void placePiece(const Izmino& piece);

    /** 
     * @brief Clears completed lines and updates the score.
     */
    void clearLines();

    /** 
     * @brief Gets the width of the board.
     * @return The width of the board.
     */
    int getWidth() const;

    /** 
     * @brief Gets the height of the board.
     * @return The height of the board.
     */
    int getHeight() const;

    /** 
     * @brief Gets the grid of the board.
     * @return The grid of the board.
     */
    const std::vector<std::vector<int>>& getGrid() const;

    /** 
     * @brief Gets the score of the board.
     * @return The score of the board.
     */
    int getScore() const;

    /** 
     * @brief Gets the number of lines cleared.
     * @return The number of lines cleared.
     */
    int getLinesCleared() const;

private:
    std::vector<std::vector<int>> grid;
    int width;
    int height;
    int score;
    int linesCleared;

    /** 
     * @brief Checks if a line is complete.
     * @param y The y-coordinate to check.
     * @return true if the line is complete, false otherwise.
     */
    bool isLineComplete(int y) const;
    
    /** 
     * @brief Removes a line from the board.
     * @param y The y-coordinate of the line to remove.
     */
    void removeLine(int y);
};


#endif // BOARD_HPP