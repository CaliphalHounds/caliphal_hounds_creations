#include <SDL2/SDL.h>
#include <vector>
#include <SDL2/SDL_ttf.h>
#include <cstdlib>
#include <ctime>


const int SCREEN_WIDTH = 800;
const int SCREEN_WIDTH_2 = 1920;
const int SCREEN_HEIGHT = 600;
const int SCREEN_HEIGHT_2 = 1080;
const int PLAYER_WIDTH = 50;
const int PLAYER_HEIGHT = 50;
const int PLATFORM_WIDTH = 120;
const int PLATFORM_HEIGHT = 20;
const int GRAVITY = 1;
const int JUMP_STRENGTH = -22;
const int PLAYER_SPEED = 5;
const int PLATFORM_GAP = 120;
int hidden_jump_count = (rand() % 500) + 500;
int offset = 2025;
int MAX_JUMP_COUNT = hidden_jump_count ^ offset;
const int CAMERA_OFFSET = 200;

struct Platform {
    int x, y;
    Platform(int startX, int startY) : x(startX), y(startY) {}
};

std::vector<Platform> platforms = {
    {200, 450},
    {400, 350},
    {600, 250},
    {300, 150}
};

void generatePlatform(int cameraY) {
    int highestPlatformY = platforms.back().y; 
    while (highestPlatformY > cameraY - SCREEN_HEIGHT) {
        int newX = rand() % (SCREEN_WIDTH - PLATFORM_WIDTH);
        int newY = highestPlatformY - PLATFORM_GAP;
        platforms.push_back(Platform(newX, newY));
        highestPlatformY = newY;
    }
}

void FUN171130062012(SDL_Renderer* renderer, int startX, int startY, int size) {
    int mtx[6][124] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,1,1,0,0,1,1,0,0,1,0,0,0,0,1,1,0,0,1,1,0,1,0,0,0,0,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,1,1,0,1,1,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,1,1,0,0,1,1,1,0,1,1,0,0},
        {1,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0},
        {1,1,1,0,1,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,1,1,1,0,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1,0,0,1,1,1,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,1,0,0,1,1,1,1,0,1,0,1,1,0,0,0,1,0},
        {1,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0},
        {1,0,1,0,0,1,0,0,0,0,1,1,0,0,1,1,0,0,1,0,0,0,0,1,1,0,1,0,1,0,0,0,0,1,0,0,1,1,0,1,0,0,1,0,1,1,1,0,1,1,0,0,1,1,0,0,0,1,0,0,1,1,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,0,0,0,1,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,1,1,0,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,1,1,1,0,1,1,0,0}
    };
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 124; x++) {
            if (mtx[y][x] == 1) {
                SDL_Rect rect = {startX + x * size, startY + y * size, size, size};
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}

void FUN190320252011() {
    SDL_Window* flagWindow = SDL_CreateWindow("Flag", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
    SDL_Renderer* flagRenderer = SDL_CreateRenderer(flagWindow, -1, SDL_RENDERER_ACCELERATED);
    
    bool flagRunning = true;
    SDL_Event event;
    
    while (flagRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) flagRunning = false;
        }
        
        SDL_SetRenderDrawColor(flagRenderer, 0, 0, 0, 255);
        SDL_RenderClear(flagRenderer);
        FUN171130062012(flagRenderer, 150, 200, 10);
        SDL_RenderPresent(flagRenderer);
        SDL_Delay(16);
    }
    
    SDL_DestroyRenderer(flagRenderer);
    SDL_DestroyWindow(flagWindow);
}

int main(int argc, char* argv[]) {
    srand(time(0));
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window* window = SDL_CreateWindow("Jumploit", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    bool running = true;
    bool won = false;
    SDL_Event event;

    int velocityY = 0;
    bool onGround = false;
    int jumpCount = 0;
    int cameraY = 0;



    SDL_Rect player = {platforms[0].x + PLATFORM_WIDTH / 2 - PLAYER_WIDTH / 2, platforms[0].y - PLAYER_HEIGHT, PLAYER_WIDTH, PLAYER_HEIGHT};

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_SPACE && onGround) {
                    velocityY = JUMP_STRENGTH;
                    onGround = false;
                    jumpCount++;
                    if (jumpCount >= MAX_JUMP_COUNT) {
                        won = true;
                        running = false;
                    }
                }
            }
        }

        if (!won) {
            const Uint8* keys = SDL_GetKeyboardState(NULL);
            if (keys[SDL_SCANCODE_LEFT]) player.x -= PLAYER_SPEED;
            if (keys[SDL_SCANCODE_RIGHT]) player.x += PLAYER_SPEED;

            velocityY += GRAVITY;
            player.y += velocityY;

            if (player.y < cameraY + CAMERA_OFFSET) {
                cameraY = player.y - CAMERA_OFFSET;
                generatePlatform(cameraY);
            }
	    if (player.y > cameraY + SCREEN_HEIGHT) {
            	running = false; 
            }
            onGround = false;
            for (const auto& platform : platforms) {
                if (player.y + PLAYER_HEIGHT >= platform.y && player.y + PLAYER_HEIGHT <= platform.y + PLATFORM_HEIGHT &&
                    player.x + PLAYER_WIDTH > platform.x && player.x < platform.x + PLATFORM_WIDTH && velocityY > 0) {
                    player.y = platform.y - PLAYER_HEIGHT;
                    velocityY = 0;
                    onGround = true;
                }
            }
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect adjustedPlayer = {player.x, player.y - cameraY, PLAYER_WIDTH, PLAYER_HEIGHT};
        SDL_RenderFillRect(renderer, &adjustedPlayer);
        
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        for (const auto& platform : platforms) {
            SDL_Rect platRect = {platform.x, platform.y - cameraY, PLATFORM_WIDTH, PLATFORM_HEIGHT};
            SDL_RenderFillRect(renderer, &platRect);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    if (won) {
        FUN190320252011();
    }
    
    SDL_Quit();
    return 0;
}
