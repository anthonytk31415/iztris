# iztris
Iztris is a puzzle game that draws inspiration from past block-type puzzle games. Try it! 


Steps: 
0. Set up your development environment:
    - Install a C++ compiler (e.g., GCC, Clang, or MSVC)
    - Choose an IDE or text editor (e.g., Visual Studio Code, CLion, or Code::Blocks)
1. Set up your development environment:
    - Install a C++ compiler (e.g., GCC, Clang, or MSVC)
    - Choose an IDE or text editor (e.g., Visual Studio Code, CLion, or Code::Blocks)
2. Plan your game structure:
    - Define the game board (typically a 2D array)
    - Create classes for Tetromino shapes
    - Design the game loop
3. Implement basic game components: 
    - Create a board class to represent the game grid
    - Implement Tetromino shapes and their movements
    - Develop game class to maange overall game state
4. Set up the main game loop:
    - Handle user input (keyboard controls)
    - Update game state (piece movement, rotation)
    - Check for collisions and line clears
    - Render the game board and current piece
5. Implement game mechanics:
   - Piece rotation
   - Collision detection
   - Line clearing and scoring
6. Piece spawning and game over conditions
7. Add a simple text-based or console graphics:
    - Use ASCII characters to represent blocks and empty spaces
    - Clear the console and redraw the game board each frame
8. Implement additional features:
    - Score tracking
    - Levels and increasing difficulty
    - Next piece preview
    - Basic sound effects (optional)
9. Optimize and refine:
    - Improve code structure and organization
    - Enhance performance if needed
10. Test thoroughly:
    - Play the game extensively
    - Fix any bugs or issues you encounter
11. (Optional) Enhance graphics:
    - If you want to go beyond console graphics, consider using a simple graphics library like SDL2 or SFML  




To do: 
- add tests
- comments to the code (DONE)
- do package manager stuff. 


#### review below: 

1. src/board/
Board.hpp
Board.cpp
Status: Implemented, but might need refinement for line clearing and scoring.
src/izmino/
Izmino.hpp
Izmino.cpp
Status: Implemented, but might need additional methods for rotation and collision detection.
src/game/
Game.hpp
Game.cpp
Status: Partially implemented. Might need refinement for game loop, level progression, and game over conditions.
src/renderer/
ConsoleRenderer.hpp
ConsoleRenderer.cpp
Status: Basic implementation, but might need enhancements for better visual representation.
src/input/
InputHandler.hpp
InputHandler.cpp
Status: Basic implementation, but might need refinement for smoother input handling.
src/utils/
Random.hpp
Random.cpp
Status: Implemented.
Areas that might need attention:
Main Game Loop:
Ensure there's a proper game loop in Game::run() that handles updates, rendering, and input processing.
Collision Detection:
Make sure there's robust collision detection in the Board class.
Piece Locking:
Implement logic to lock pieces in place when they can't move down further.
Line Clearing:
Ensure the line clearing logic in the Board class is fully implemented and tested.
Scoring System:
Refine the scoring system, possibly adding bonuses for multiple line clears.
Level Progression:
Implement a system to increase difficulty (speed) as the player clears more lines.
Game Over Condition:
Ensure there's a proper game over check and handling.
Pause Functionality:
Consider adding a pause feature.
High Score:
Think about implementing a high score system.
Main Function:
Ensure there's a main.cpp file that initializes and runs the game.
Additional considerations:
Error Handling:
Add more robust error handling throughout the codebase.
Comments and Documentation:
Ensure all classes and methods are well-commented for maintainability.
3. Testing:
Consider adding unit tests for critical components like piece rotation, collision detection, and line clearing.
Configuration:
Consider adding a configuration system for easily adjusting game parameters.
Sound Effects:
If desired, plan for how you might incorporate sound effects.



Testing: 

Install the Catch2 testing framework.
Set up your build system (e.g., CMake) to compile and run the tests.
Create a main test file that includes the Catch2 main function.



