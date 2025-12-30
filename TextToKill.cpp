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

using namespace std;

enum Color {
    CYAN,
    RED,
    YELLOW,
    GRAY,
    PURPLE,
    GREEN,
    ORANGE,
    RESET
};

namespace colorCode {
    const string CYAN = "\033[1;36m";
    const string RED = "\033[31m";
    const string YELLOW = "\033[1;33m";
    const string GRAY = "\033[1;30m";
    const string PURPLE = "\033[1;35m";
    const string GREEN = "\033[1;32m";
    const string ORANGE = "\033[38;5;208m";
    const string RESET = "\033[0m";
}

int temp() {
    
    // uh like make this yknow shabong da shaboing later ifyaknowaddamean
    int temp = 100;

    return temp;

}

#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/ioctl.h>  
    #include <unistd.h>
#endif

void getTerminalSize(int& rows, int& cols) {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    rows = w.ws_row;
    cols = w.ws_col;
#endif
}

void setCursorPosition(int row, int col) {
#ifdef _WIN32
    COORD pos = {static_cast<SHORT>(col), static_cast<SHORT>(row) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
#else
    cout << "\033[" << (row + 1) << ";" << (col + 1) << "H" << std::flush;
#endif
}

void printTopRight(const string& text, int& temperature) {
    int rows, cols;
    getTerminalSize(rows, cols);

    string tempStr = to_string(temperature);
    int totalLen = text.length() + tempStr.length();
    int targetCol = cols - totalLen;
    if (targetCol < 0) targetCol = 0;

    // Move cursor to a different position so it doesn't interfere
    setCursorPosition(0, targetCol);
    cout << colorCode::CYAN << text << temperature << std::flush;
}

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void fakeClear() {
    int temp = 100;

    cout << "\033[2J";
    printTopRight("Temp: ", temp);
    setCursorPosition(0, 0);
}

class Game {
private:
    bool running;

public:
    Game() : running(true) {}

    bool isRunning() {
        return running;
    }


    void cmdList() {
        fakeClear();
        cout << colorCode::YELLOW << "list of commands: " << colorCode::RESET << endl;
        cout << colorCode::GRAY << "help. (?) \nlook. (l) \nexamine. (ex) \ninventory. (inv) \nmove: \n north (n)\n south (s)\n east (e)\n west (w)\ndirection. (dir) \nattack. (a) \nquit." << colorCode::RESET << endl;
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
            cout << colorCode::GRAY << "what do you want to examine?" << colorCode::RESET << endl;
            cin >> obj;
            examineObj(obj);
        }
        else if (cmd == "direction" || cmd == "dir") {
            
        }
        else if (cmd == "attack" || cmd == "a") {
            string enemy;
            cout << endl;
            cout << colorCode::GRAY << "who do you want to attack?" << colorCode::RESET << endl;
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
            cout << colorCode::GRAY << "goodbye for now..." << colorCode::RESET << endl;
        }
        else {
            cout << endl;
            cout << colorCode::RED << "UNKNOWN COMMAND" << colorCode::RESET << endl;
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
            cout << colorCode::RED << "invalid direction" << colorCode::RESET << endl;
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
            cout << colorCode::RED << "smited :<" << colorCode::RESET << endl;
        }
        else {
            cout << endl;
            cout << "dne" << endl;
        }

    }
};

class Object {
private:
    

public:
    

};

class Area {
private:


public:


};

class Actor {
private:


public:


};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

string getInput(string text, string color = colorCode::CYAN) {
    string input;
    
    if (!text.empty()) {
        cout << color << text << colorCode::RESET << endl;
        cout << endl;
    }
    cin >> input;
    input = toLower(input);
    return input;
}

void checkValidity(string& input, string definition, string get, string color = colorCode::CYAN) {
    
    input = toLower(input);

    while (input != definition) {
        fakeClear();
        cout << endl;
        cout << color << "not currently an option..." << colorCode::RESET << endl;
        input = getInput(get, color);
    }
}

void invalidOption(string& input, string message) {

    
}

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        cout << "ERROR";
        return -1;
    }

    SDL_Window* window;
    SDL_Renderer* renderer;
    const int WINDOW_SIZE_X = 100;
    const int WINDOW_SIZE_Y = 100;
    window = SDL_CreateWindow("Test SDL3", WINDOW_SIZE_X, WINDOW_SIZE_Y, SDL_WINDOW_BORDERLESS);
    renderer = SDL_CreateRenderer(window, NULL);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_DisplayID displayID = SDL_GetDisplayForWindow(window);
    SDL_Rect displayRect;
    if (SDL_GetDisplayUsableBounds(displayID, &displayRect)) {
        //cout << "x: " << displayRect.x << ", y: " << displayRect.y << ", w: " << displayRect.w << ", h: " << displayRect.h;

        int speedX = 10;
        int speedY = 10;
        bool running = true;

        for (int i = 0; running && i < 1000; i++) {
            SDL_Event e;
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_EVENT_QUIT) {
                    running = false;
                }
                // handle other events if needed (keyboard, etc.)
            }

            int posX, posY;
            SDL_GetWindowPosition(window, &posX, &posY);

            if (posX+WINDOW_SIZE_X > displayRect.w || posX < 0) {
                speedX = -speedX;
            }
            if (posY+WINDOW_SIZE_Y > displayRect.h || posY < 0) {
                speedY = -speedY;
            }

            SDL_SetWindowPosition(window, posX + speedX, posY + speedY);
            SDL_Delay(10);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    int temp = 100;

    string Input = getInput("type 'start' to begin.", colorCode::GRAY);
    checkValidity(Input, "start", "type 'start' to begin.", colorCode::GRAY);
    clearScreen();
    printTopRight("Temp: ", temp);
    setCursorPosition(0, 0);
    cout << colorCode::GRAY << "you are in a thick pine forest. \nit appears to be morning. \nthere's light snow." << colorCode::RESET << endl;
    cout << endl;

    Game game;

    while (game.isRunning()) {
        string cmd = getInput("", colorCode::GRAY);
        game.cmdUse(cmd);
    }


    return 0;

}
