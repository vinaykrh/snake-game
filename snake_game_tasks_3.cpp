#include <SDL.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

const int screenWidth = 600;
const int screenHeight = 400;
const int blockSize = 10;
const int snakeSpeed = 100;

struct Vector2Int {
    int x, y;
    bool operator==(const Vector2Int &other) const {
        return x == other.x && y == other.y;
    }
};

void DrawSnake(SDL_Renderer* renderer, const std::vector<Vector2Int>& snake) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (const auto& block : snake) {
        SDL_Rect rect = { block.x, block.y, blockSize, blockSize };
        SDL_RenderFillRect(renderer, &rect);
    }
}

void DrawMessage(SDL_Renderer* renderer, const std::string& msg) {}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Snake Game by vinay kr hembram",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        screenWidth, screenHeight, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event e;

    std::vector<Vector2Int> snake;
    Vector2Int head = { screenWidth / 2, screenHeight / 2 };
    Vector2Int food;
    int dx = 0, dy = 0;
    int snakeLength = 1;
    bool gameOver = false;
    bool gameClose = false;

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    food.x = (std::rand() % (screenWidth / blockSize)) * blockSize;
    food.y = (std::rand() % (screenHeight / blockSize)) * blockSize;

    Uint32 lastUpdate = SDL_GetTicks();

    while (!gameOver) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) gameOver = true;
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT: dx = -blockSize; dy = 0; break;
                    case SDLK_RIGHT: dx = blockSize; dy = 0; break;
                    case SDLK_UP: dx = 0; dy = -blockSize; break;
                    case SDLK_DOWN: dx = 0; dy = blockSize; break;
                    case SDLK_q: if (gameClose) gameOver = true; break;
                    case SDLK_c: if (gameClose) {
                        head = { screenWidth / 2, screenHeight / 2 };
                        snake.clear();
                        dx = dy = 0;
                        snakeLength = 1;
                        gameClose = false;
                        food.x = (std::rand() % (screenWidth / blockSize)) * blockSize;
                        food.y = (std::rand() % (screenHeight / blockSize)) * blockSize;
                    } break;
                }
            }
        }

        Uint32 current = SDL_GetTicks();
        if (current - lastUpdate < snakeSpeed) continue;
        lastUpdate = current;

        if (!gameClose) {
            head.x += dx;
            head.y += dy;

            if (head.x < 0 || head.y < 0 || head.x >= screenWidth || head.y >= screenHeight) {
                gameClose = true;
            }

            snake.push_back(head);
            if ((int)snake.size() > snakeLength) {
                snake.erase(snake.begin());
            }

            for (size_t i = 0; i < snake.size() - 1; ++i) {
                if (snake[i] == head) {
                    gameClose = true;
                    break;
                }
            }

            if (head == food) {
                snakeLength++;
                food.x = (std::rand() % (screenWidth / blockSize)) * blockSize;
                food.y = (std::rand() % (screenHeight / blockSize)) * blockSize;
            }
        }

        SDL_SetRenderDrawColor(renderer, 50, 153, 213, 255);
        SDL_RenderClear(renderer);

        if (gameClose) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
        } else {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_Rect foodRect = { food.x, food.y, blockSize, blockSize };
            SDL_RenderFillRect(renderer, &foodRect);
            DrawSnake(renderer, snake);
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
