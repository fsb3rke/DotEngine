#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <string>
#include <iostream>
#include <vector>
#include "../utils/str.hpp"
#include "input.hpp"
#include "engine_def.h"

#define n(x) (x-1)

class DotEngine {
public:                     // {x, y}
    explicit DotEngine(std::vector<int> screenSize=DEFAULT_SCREEN_SIZE, std::string screenTitle=DEFAULT_SCREEN_TITLE, int spacing=DEFAULT_SPACING, char screenChar=DEFAULT_SCREEN_CHAR) {
        this->screenSize = screenSize;
        this->screenTitle = screenTitle;
        this->screenChar = screenChar;
        this->spacing = spacing;
    }
    
    void initialize() {
        // initialize all elements;  {y}
        for(int i = 0; i < this->screenSize[1]; ++i) {
            this->window.push_back({});
            for (int j = 0; j < this->screenSize[0]; ++j) {
                this->window.at(i).push_back(this->screenChar);
            }
        }
        
        this->renderWindow();
    }

    void renderWindow() {
        system("cls");
        for(long unsigned int i = 0; i < this->window.size(); ++i) {
            for (long unsigned int j = 0; j < this->window.at(i).size(); ++j) {
                std::cout << this->window.at(i).at(j) << utils::intToSpace(this->spacing);
            }
            std::cout << std::endl;
        }
    }

    char getChar(int column, int pos) {
        return this->window.at(column).at(pos);
    }

    char getChar(int pos) {
        int cursor = 0;
        int i, j;
        bool isFound = false;

        for (i = 0; i < this->screenSize[1] && !isFound; ++i) {
            for (j = 0; j < this->screenSize[0] && !isFound; ++j) {
                if (cursor == pos)
                    isFound = true;
                else
                    cursor++;
            }
            if (!isFound)
                cursor++;
        }

        return this->window.at(n(i)).at(n(j));
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
    


    // TODO: RENDER PAWNS;
};

#endif