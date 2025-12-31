#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>
#include <algorithm>
#include <cctype>

#define SDL_MAIN_HANDLED
#include <SDL3\SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

using namespace std;

namespace colorCode {
    const SDL_Color CYAN = { 0, 255, 255, 255 };
    const SDL_Color RED = { 255, 0, 0, 255 };
    const SDL_Color YELLOW = { 255, 255, 0, 255 };
    const SDL_Color GRAY = { 128, 128, 128, 255 };
    const SDL_Color PURPLE = { 255, 0, 255, 255 };
    const SDL_Color GREEN = { 0, 255, 0, 255 };
    const SDL_Color ORANGE = { 255, 165, 0, 255 };
    const SDL_Color WHITE = { 255, 255, 255, 255 };
    const SDL_Color BLACK = { 0, 0, 0, 255 };
}

void getScreenSize(int& w, int& h) {
    SDL_DisplayID displayID = SDL_GetPrimaryDisplay();
    const SDL_DisplayMode* mode = SDL_GetCurrentDisplayMode(displayID);
    if (mode != nullptr) {
        w = mode->w;
        h = mode->h;
    }
}

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

class Game {
private:
    bool running;

public:
    Game() : running(true) {}

    bool isRunning() {
        return running;
    }

    void quit() {
        running = false;
    }

    void cmdList() {
        //  cout << colorCode::YELLOW << "list of commands: " << colorCode::WHITE << endl;
        //  cout << colorCode::GRAY << "help. (?) \nlook. (l) \nexamine. (ex) \ninventory. (inv) \nmove: \n north (n)\n south (s)\n east (e)\n west (w)\ndirection. (dir) \nattack. (a) \nquit." << colorCode::WHITE << endl;
        cout << endl;
    }

    void cmdUse(string cmd) {
        cmd = toLower(cmd);

        if (cmd == "look" || cmd == "l") {
            lookAround();
        }
        else if (cmd == "north" || cmd == "n" || cmd == "south" || cmd == "s" || cmd == "east" || cmd == "e" || cmd == "west" || cmd == "w") {
            move(cmd);
        }
        else if (cmd == "inventory" || cmd == "inv") {
            checkInv();
        }
        else if (cmd == "examine" || cmd == "ex") {
            string obj;
            cout << endl;
            //  cout << colorCode::GRAY << "what do you want to examine?" << colorCode::WHITE << endl;
            cin >> obj;
            examineObj(obj);
        }
        else if (cmd == "direction" || cmd == "dir") {

        }
        else if (cmd == "attack" || cmd == "a") {
            string enemy;
            cout << endl;
            //  cout << colorCode::GRAY << "who do you want to attack?" << colorCode::WHITE << endl;
            cout << endl;
            cin >> enemy;

            attackEnemy(enemy);
        }
        else if (cmd == "help" || cmd == "?") {
            cmdList();
        }
        else if (cmd == "quit") {
            running = false;
            cout << endl;
            // cout << colorCode::GRAY << "goodbye for now..." << colorCode::WHITE << endl;
        }
        else {
            cout << endl;
            // cout << colorCode::RED << "UNKNOWN COMMAND" << colorCode::WHITE << endl;
        }
    }

    void lookAround() {

    }
    void checkInv() {

    }
    void inventory() {

    }

    void move(string dir) {
        dir = toLower(dir);

        if (dir == "north" || dir == "n") {
            bool moveNorth = true;
        }
        else if (dir == "south" || dir == "s") {
            bool moveSouth = false;
        }
        else if (dir == "east" || dir == "e") {
            bool moveEast = false;
        }
        else if (dir == "west" || dir == "w") {
            bool moveWest = false;
        }
        else {
            //cout << colorCode::RED << "invalid direction" << colorCode::WHITE << endl;
        }
    }

    void examineObj(string obj) {

        toLower(obj);



    }

    void checkDir(bool move) {

        bool moveNorth = true;
        bool moveSouth = false;
        bool moveEast = false;
        bool moveWest = false;

        if (moveNorth = true) {
            bool facingNorth = true;
        }
        else if (moveSouth = true) {
            bool facingSouth = true;
        }
        else if (moveEast = true) {
            bool facingEast = true;
        }
        else if (moveWest = true) {
            bool facingWest = true;
        }

    }

    void attackEnemy(string enemy) {

        if (enemy == "god") {
            cout << endl;
            //cout << colorCode::RED << "smited :<" << colorCode::WHITE << endl;
        }
        else {
            cout << endl;
            cout << "dne" << endl;
        }

    }
};


void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//string getInput(string text, string color = colorCode::CYAN) {
   // string input;

  //  if (!text.empty()) {
   //     cout << color << text << colorCode::WHITE << endl;
   //     cout << endl;
  //  }
 //   cin >> input;
 //   input = toLower(input);
   // return input;
//}

//void checkValidity(string& input, string definition, string get, string color = colorCode::CYAN) {

   // input = toLower(input);

 //   while (input != definition) {
       // fakeClear();
//        cout << endl;
       // cout << color << "not currently an option..." << colorCode::WHITE << endl;
       // input = getInput(get, color);
//    }
//}

void invalidOption(string& input, string message) {


}

void bouncyWindowColonThree(int windowSizeX, int windowSizeY, const char* windowLabel, int speedX, int speedY, int durationMS) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    window = SDL_CreateWindow(windowLabel, windowSizeX, windowSizeY, SDL_WINDOW_BORDERLESS);
    renderer = SDL_CreateRenderer(window, NULL);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_DisplayID displayID = SDL_GetDisplayForWindow(window);
    SDL_Rect displayRect;
    if (SDL_GetDisplayUsableBounds(displayID, &displayRect)) {
        //cout << "x: " << displayRect.x << ", y: " << displayRect.y << ", w: " << displayRect.w << ", h: " << displayRect.h;

        bool running = true;

        for (int i = 0; running && i < durationMS / 10; i++) {
            SDL_Event e;
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_EVENT_QUIT) {
                    running = false;
                }
                //handle other events if needed (keyboard, etc.)
            }

            int posX, posY;
            SDL_GetWindowPosition(window, &posX, &posY);

            if (posX + windowSizeX > displayRect.w || posX < 0) {
                speedX = -speedX;
            }
            if (posY + windowSizeY > displayRect.h || posY < 0) {
                speedY = -speedY;
            }

            SDL_SetWindowPosition(window, posX + speedX, posY + speedY);
            SDL_Delay(10);
        }
    }

    SDL_DestroyWindow(window);
}

void textWindow(bool isResizeable, float horizontalPadding, float verticalPadding, const char* windowLabel, int charGridWidth, int charGridHeight, float fontSize, bool forceSquareCells, Game& game) {
    SDL_Window* window;
    SDL_Renderer* renderer;

    Uint32 windowFlags = SDL_WINDOW_MOUSE_FOCUS;

    if (isResizeable) { //sets window size to 800x600 and makes it resizeable
        windowFlags |= SDL_WINDOW_RESIZABLE;
        window = SDL_CreateWindow(windowLabel, 800, 600, windowFlags);
    }
    else { //fullscreens, no resizing
        int screenWidth, screenHeight;
        getScreenSize(screenWidth, screenHeight);
        windowFlags |= SDL_WINDOW_BORDERLESS;
        window = SDL_CreateWindow(windowLabel, screenWidth, screenHeight, windowFlags);
        SDL_SetWindowPosition(window, 0, 0);
    }

    renderer = SDL_CreateRenderer(window, NULL);

    TTF_Font* font = TTF_OpenFont("Resources/Fonts/luximr.ttf", fontSize); //open the font at path "Resources/Fonts/luximr.ttf", with font size passed to function

    SDL_Surface* surface;
    SDL_Texture* texture;
    while (game.isRunning()) { //decides if the game is running or not, if game gets quit window closes
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                game.quit();
            }
            if (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_ESCAPE) {
                game.quit();
            }
        }
        int renderWidth, renderHeight;
        SDL_GetCurrentRenderOutputSize(renderer, &renderWidth, &renderHeight);

        float leftPadding = horizontalPadding / 2.0f;
        float topPadding = verticalPadding / 2.0f;

        float availableWidth = renderWidth - horizontalPadding;
        float availableHeight = renderHeight - verticalPadding;

        float cellWidth = availableWidth / charGridWidth;
        float cellHeight = availableHeight / charGridHeight;

        if (forceSquareCells) {
            float cellSize = min(cellWidth, cellHeight);
            cellWidth = cellHeight = cellSize;

            float usedWidth = cellSize * charGridWidth;
            float usedHeight = cellSize * charGridHeight;

            leftPadding = (renderWidth - usedWidth) / 2.0f;
            topPadding = (renderHeight - usedHeight) / 2.0f;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (int x = 0; x < charGridWidth; x++) {
            for (int y = 0; y < charGridHeight; y++) {
                //Generate a grid square rect for the bounds of the char being rendered
                //add padding, then 
                SDL_FRect rect = { leftPadding + x * cellWidth, topPadding + y * cellHeight, cellWidth, cellHeight };

                //render the bounds rect in red
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderRect(renderer, &rect);


                surface = TTF_RenderText_Blended(font, "#", 1, { 255, 255, 255, 255 }); //Render text using the previously opened font, 
                texture = SDL_CreateTextureFromSurface(renderer, surface);

                float texW = 0, texH = 0;
                SDL_GetTextureSize(texture, &texW, &texH);
                SDL_FRect dst;
                dst.w = texW;
                dst.h = texH;
                //cout << "w: " << texW << ", h: " << texH;
                dst.x = rect.x + (rect.w - texW) / 2;
                dst.y = rect.y + (rect.h - texH) / 2;
                //cout << "x: " << dst.x << ", y: " << dst.y;

                SDL_RenderTexture(renderer, texture, NULL, &dst);
                SDL_DestroyTexture(texture);
                SDL_DestroySurface(surface);
            }
        }
        SDL_RenderPresent(renderer); //tell the renderer to actually display the things we've rendered
        SDL_Delay(16); // ~60 fps instead of 5000ms
    }

    //prevent memory leaks by closing and destroying used resources before closing the window
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}


int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        cout << "ERROR";
        return -1;
    }

    TTF_Init(); //initialize text rendering

    Game game; //game creation

    bool isResizeable = true;
    textWindow(isResizeable, 20, 20, "Text 2 Kill", 50, 50, 15, false, game);

    TTF_Quit();
    SDL_Quit();

    //string Input = getInput("type 'start' to begin.", colorCode::GRAY);
    //checkValidity(Input, "start", "type 'start' to begin.", colorCode::GRAY);
    //clearScreen();
    //printTopRight("Temp: ", temp);
   // setCursorPosition(0, 0);
    //cout << colorCode::GRAY << "you are in a thick pine forest. \nit appears to be morning. \nthere's light snow." << colorCode::WHITE << endl;
    cout << endl;

    return 0;

}
