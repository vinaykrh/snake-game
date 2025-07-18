# snake-game
COMPANY: CODTECH IT SOLUTIONS PVT.LTD
*NAME: Vinay Kumar Hembram
INTERN ID:CT04DG1922 
DOMAIN: C++ LANGUAGE
DURATION: 4 WEEKS
MENTOR: NEELA SANTOSH KUMAR
paragraph: 

The provided C++ program is a complete implementation of the classic Snake game using the SDL (Simple DirectMedia Layer) graphics library. The game window is initialized to a size of 600x400 pixels, and the snake moves in increments of 10 pixels (defined by `blockSize`) across the screen. At the core of the program is the `Vector2Int` structure, which is used to represent the x and y coordinates of both the snake’s body blocks and the food. The game begins with the SDL library initializing a window and renderer. A vector is used to maintain the snake's body positions, and the snake initially starts from the center of the screen. The food is generated randomly within the screen bounds using the `rand()` function, ensuring it aligns with the block size grid.

The game responds to keyboard input through SDL events. The arrow keys control the snake’s movement direction by updating the `dx` and `dy` variables. Pressing `q` quits the game after a game-over, and `c` resets the game state after a collision. The game loop runs until the `gameOver` flag is set to true. It checks for keyboard inputs, updates the snake’s position based on the direction, and manages collision detection. If the snake hits the wall or itself, the game enters a paused state by setting `gameClose` to true. During each update, if the snake consumes the food (i.e., the head’s position equals the food’s position), the snake’s length increases and new food is randomly placed on the screen.

Rendering is handled in each loop iteration. If the game is in a paused state (`gameClose`), the screen turns white; otherwise, the game background is set to a light blue color. The food is displayed as a green block and the snake is drawn using black blocks via the `DrawSnake` function. The snake’s movement is visually achieved by pushing a new head block into the vector and erasing the tail when necessary, giving the effect of motion. Collision with itself is checked by comparing the head’s position with the rest of the body. The timing of movement is controlled using SDL’s `GetTicks()` function and a `snakeSpeed` delay (100 milliseconds), which keeps the game running at a consistent pace.

The code concludes by cleaning up SDL resources using `SDL_DestroyRenderer`, `SDL_DestroyWindow`, and `SDL_Quit()` before exiting the program. Overall, this program provides a foundational understanding of game development using SDL by combining graphics, input handling, real-time updates, and basic game mechanics. While the code lacks text rendering (as seen with the empty `DrawMessage` function), it demonstrates the essential features of the Snake game clearly and efficiently. It can be further enhanced with score tracking, sound effects, and a start/restart screen. This SDL-based project is suitable for beginners looking to explore C++ game development concepts such as vectors, rendering, and event handling in a structured yet simple way.
output : 











<img width="752" height="540" alt="Image" src="https://github.com/user-attachments/assets/86251cda-2de7-44bc-afad-e5e4a0392431" />
