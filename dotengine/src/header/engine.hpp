#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <string>
#include <iostream>
#include <vector>
#include "../utils/str.hpp"
#include "input.hpp"
#include "engine_def.h"
#include <chrono>
#include <thread>


class DotEngine {
public:                     // {x, y}
    explicit DotEngine(std::vector<int> screenSize=DEFAULT_SCREEN_SIZE, std::string screenTitle=DEFAULT_SCREEN_TITLE, int spacing=DEFAULT_SPACING, char screenChar=DEFAULT_SCREEN_CHAR, int refreshRate=DEFAULT_REFRESH_RATE) {
        this->screenSize = screenSize;
        this->screenTitle = screenTitle;
        this->screenChar = screenChar;
        this->spacing = spacing;
        this->refreshRate = refreshRate;
        this->tableSize = this->screenSize[0] * this->screenSize[1];
    }
    
    void initialize() {
        this->window.resize(this->screenSize[0], std::vector<char>(this->screenSize[1], this->screenChar));
        this->renderWindow();
    }

    int getTableSize() {
        return this->tableSize;
    }

    void changeRefreshRate(int newRefreshRate) {
        this->refreshRate = newRefreshRate;
    }

    void renderWindow() {
        std::string output;

        for (long unsigned int i = 0; i < this->window.size(); ++i) {
            for (long unsigned int j = 0; j < this->window.at(i).size(); ++j) {
                output += this->window.at(i).at(j) + utils::intToSpace(this->spacing);
            }
            output += '\n';
        }

        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        std::cout << output;

        // Refresh Rate Section
        auto start = std::chrono::high_resolution_clock::now();
        while (1) {
            auto now = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);
            if (elapsed.count() >= this->refreshRate)
                break;
        }
    }

    char getChar(int row, int column) {
        return this->window.at(row).at(column);
    }

    char getChar(int pos) {
        int row = pos / this->screenSize[0];
        int column = pos % this->screenSize[0];

        return this->window.at(row).at(column);
    }

    void changeChar(int column, int pos, char newChar) {
        this->window.at(column).at(pos) = newChar;
    }

private:
    std::vector<int> screenSize;
    std::string screenTitle;
    bool isResizable;
    std::vector<std::vector<char>> window;
    char screenChar;
    int spacing;
    int refreshRate;
    int tableSize;
};

#endif