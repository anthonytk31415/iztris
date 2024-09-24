#include "InputHandler.hpp"
#include <iostream>
#include <termios.h>
#include <unistd.h>

InputHandler::InputHandler() {
    // Set up terminal for immediate input without echo
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void InputHandler::pollEvents() {
    char ch;
    if (read(STDIN_FILENO, &ch, 1) == 1) {
        handleKeyPress(ch);
    }
}

void InputHandler::setActionCallback(Action action, std::function<void()> callback) {
    callbacks[static_cast<int>(action)] = callback;
}

void InputHandler::handleKeyPress(char key) {
    switch (key) {
        case 'a': if (callbacks[static_cast<int>(Action::MoveLeft)]) callbacks[static_cast<int>(Action::MoveLeft)](); break;
        case 'd': if (callbacks[static_cast<int>(Action::MoveRight)]) callbacks[static_cast<int>(Action::MoveRight)](); break;
        case 'w': if (callbacks[static_cast<int>(Action::Rotate)]) callbacks[static_cast<int>(Action::Rotate)](); break;
        case 's': if (callbacks[static_cast<int>(Action::Drop)]) callbacks[static_cast<int>(Action::Drop)](); break;
        case 'q': if (callbacks[static_cast<int>(Action::Quit)]) callbacks[static_cast<int>(Action::Quit)](); break;
    }
}