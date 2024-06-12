#include <iostream>
#include "main.h"
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <string>
#include <vector>
using namespace std;

const int SCREEN_WIDTH = 1050;
const int SCREEN_HEIGHT = 650;
const int IMAGE_WIDTH = SCREEN_WIDTH + 300;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
int speed = 0.1;
int CameraX = 0;
int textureWidthDiff = IMAGE_WIDTH - SCREEN_WIDTH;

SDL_Texture* loadTexture(const std::string& path) {
    // The final texture
    SDL_Texture* newTexture = NULL;

    // Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

bool initSDL()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Create window
    gWindow = SDL_CreateWindow("CA Project Group 4", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Create renderer
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (gRenderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Set renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Allows for (Initializes) Image Loading abilities using SDL_image library
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    return true;
}

void closeSDL()
{
    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    if (!initSDL()) {
        printf("Failed to initialize SDL!\n");
        return -1;
    }
  
    
    SDL_Texture* wallBackground = loadTexture("./wall.jpg");
    SDL_Texture* pictureFrame = loadTexture("./pictureframe.png");
    SDL_Texture* blenderImage = loadTexture("./blender.png");
    SDL_Texture* openglImage = loadTexture("./blender.png");

    // Main loop flag
    bool quit = false;

    // Event handler
    SDL_Event e;

    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear screen
        SDL_RenderClear(gRenderer);

        SDL_Rect wallDest = { 0, 0, 1050, 650 };
        SDL_RenderCopy(gRenderer, wallBackground, NULL, &wallDest);
        SDL_Rect frameDest = { 20, 150, 480, 350 };
        SDL_RenderCopy(gRenderer, pictureFrame, NULL, &frameDest);
        SDL_Rect frameDest2 = { 550, 150, 480, 350 };
        SDL_RenderCopy(gRenderer, pictureFrame, NULL, &frameDest2);
        SDL_Rect blenderDest = { 62, 195, 390, 252};
        SDL_RenderCopy(gRenderer, blenderImage, NULL, &blenderDest);
        SDL_Rect openglDest = { 592, 195, 390, 252 };
        SDL_RenderCopy(gRenderer, openglImage, NULL, &openglDest);


        // Update screen
        SDL_RenderPresent(gRenderer);
    }

    // Destroy textures
    SDL_DestroyTexture(wallBackground);
    SDL_DestroyTexture(pictureFrame);
    SDL_DestroyTexture(blenderImage);

    // Close SDL
    closeSDL();

    return 0;
}