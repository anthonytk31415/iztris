#pragma once
#include <functional>

class InputHandler {
public:
    
    /** 
     * @enum Action
     * @brief Represents the possible actions that can be triggered by input.
     */
    enum class Action {
        MoveLeft,
        MoveRight,
        Rotate,
        Drop,
        Quit
    };

    /** 
     * @brief Constructor for InputHandler.
     */
    InputHandler();

    /** 
     * @brief Polls for input events.
     */
    void pollEvents();

    /** 
     * @brief Sets a callback for a specific action.
     * @param action The action to set the callback for.
     * @param callback The callback function to be executed when the action occurs.
     */
    void setActionCallback(Action action, std::function<void()> callback);

private:
    /** 
     * @brief Array to store callbacks for each action.
     */
    std::function<void()> callbacks[5];  // One for each Action

    /** 
     * @brief Handles key presses.
     * @param key The key pressed.
     */
    void handleKeyPress(char key);
};