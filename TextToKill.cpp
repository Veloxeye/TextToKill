#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>
#include <algorithm>
#include <cctype>

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


    void cmdList() {
        cout << endl;
        cout << colorCode::YELLOW << "list of commands: " << colorCode::RESET << endl;
        cout << colorCode::GRAY << "help. \nlook. \nexamine. \ninventory. \nmove. \ndirection. \nattack. \nquit." << colorCode::RESET << endl;
    }

    void cmdUse(string cmd) {
        cmd = toLower(cmd);

        if (cmd == "look") {
            lookAround();
        }
        else if (cmd == "move") {
            string dir;
            cout << endl;
            cout << colorCode::GRAY << "north, south, east, or west?" << colorCode::RESET << endl;
            cin >> dir;

            move(dir);
        }
        else if (cmd == "inventory") {
            checkInv();
        }
        else if (cmd == "examine") {
            string obj;
            cout << endl;
            cout << colorCode::GRAY << "what do you want to examine?" << colorCode::RESET << endl;
            cin >> obj;
            examineObj(obj);
        }
        else if (cmd == "direction") {
            checkDir();
        }
        else if (cmd == "attack") {
            string enemy;
            cout << endl;
            cout << colorCode::GRAY << "who do you want to attack?" << colorCode::RESET << endl;
            cin >> enemy;

            attackEnemy(enemy);
        }
        else if (cmd == "help") {
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

    void move(string dir) {
        dir = toLower(dir);
        
        if (dir == "north") {

        }
        else if (dir == "south") {

        }
        else if (dir == "east") {

        }
        else if (dir == "west") {

        }
        else {
            cout << colorCode::RED << "invalid direction" << colorCode::RESET << endl;
        }
    }

    void examineObj(string obj) {

    }

    void checkDir() {

    }

    void attackEnemy(string enemy) {

    }
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
    cout << endl;
    cout << color << text << colorCode::RESET << endl;
    cout << endl;
    cin >> input;
    input = toLower(input);
    return input;
}

void checkValidity(string& input, string definition, string get, string color = colorCode::CYAN) {
    
    input = toLower(input);

    while (input != definition) {
        cout << endl;
        cout << color << "not currently an option..." << colorCode::RESET << endl;
        input = getInput(get, color);
    }
}

void invalidOption(string& input, string message) {

    
}

int main(){

    string Input = getInput("type 'start' to begin.", colorCode::GRAY);
    checkValidity(Input, "start", "type 'start' to begin.", colorCode::GRAY);
    clearScreen();
    cout << colorCode::GRAY << "you are in a thick pine forest. \nit appears to be morning. \nthere's light snow." << colorCode::RESET << endl;
    
    Game game;

    while (game.isRunning()) {
        string cmd = getInput("", colorCode::GRAY);
        game.cmdUse(cmd);
    }

    return 0;
}
