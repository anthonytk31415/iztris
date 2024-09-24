#pragma once
#include <vector>
#include <utility>

/** 
 * Izmino class, represents a single Iztris piece (also known as a izmino). 
 * It encapsulates the shape, orientation, and behavior of an Iztris piece.
*/

class Izmino {
public:
    /** 
     * @enum Shape
     * @brief Represents the different shapes that an Izmino can be.
     */
    enum class Shape { I, O, T, S, Z, J, L };

    /** 
     * @brief Constructor for Izmino.
     * @param shape The shape of the Izmino.
     */
    Izmino(Shape shape);

    /** 
     * @brief Rotates the Izmino.
     * @param clockwise Whether to rotate clockwise or counterclockwise.
     */
    void rotate(bool clockwise = true);

    /** 
     * @brief Gets the shape of the Izmino.
     * @return The shape of the Izmino.
     */
    Shape getShape() const;

    /** 
     * @brief Gets the blocks of the Izmino.
     * @return The blocks of the Izmino.
     */
    std::vector<std::vector<bool>> getBlocks() const;

    /**
     * @brief Gets the size of the Izmino.
     * @return The size of the Izmino.
     */
    std::pair<int, int> getSize() const;

    /** 
     * @brief Sets the position of the Izmino.
     * @param x The x position.
     * @param y The y position.
     */
    void setPosition(int x, int y);

    /** 
     * @brief Gets the position of the Izmino.
     * @return The position of the Izmino.
     */
    std::pair<int, int> getPosition() const;

    

private:
    /** 
     * @brief The shape of the Izmino.
     */
    Shape shape;

    /** 
     * @brief The blocks of the Izmino.
     */
    std::vector<std::vector<bool>> blocks;
    /** 
     * @brief The x position of the Izmino.
     */
    int x;

    /** 
     * @brief The y position of the Izmino.
     */
    int y;

    /** 
     * @brief Initializes the shape of the Izmino.
     */
    void initializeShape();
};