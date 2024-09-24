#pragma once
#include <functional>

class InputHandler {
public:
    enum class Action {
        MoveLeft,
        MoveRight,
        Rotate,
        Drop,
        Quit
    };

    InputHandler();
    void pollEvents();
    void setActionCallback(Action action, std::function<void()> callback);

private:
    std::function<void()> callbacks[5];  // One for each Action
    void handleKeyPress(char key);
};