#include <string>
#include <iostream>
#include <vector>

std::string intToSpace(int x) {
    std::string space;
    for (int i = 0; i < x; ++i) {
        space += ' ';
    }
    
    return space;
}

class DotEngine {
public:                     // {x, y}
    explicit DotEngine(std::vector<int> screen_size, std::string screen_title, int spacing, char defaultChar, bool isResizable) {
        this->screen_size = screen_size;
        this->screen_title = screen_title;
        this->isResizable = isResizable;
        this->defaultChar = defaultChar;
        this->spacing = spacing;
    }
    
    void initialize() {
        // initialize all elements;  {y}
        for(int i = 0; i < this->screen_size[1]; ++i) {
            this->window.push_back({});
            for (int j = 0; j < this->screen_size[0]; ++j) {
                this->window.at(i).push_back(this->defaultChar);
            }
        }
        
        this->renderWindow();
    }
    
private:
    std::vector<int> screen_size;
    std::string screen_title;
    bool isResizable;
    std::vector<std::vector<char>> window;
    char defaultChar;
    int spacing;
    
    void renderWindow() {
        for(int i = 0; i < this->window.size(); ++i) {
            for (int j = 0; j < this->window.at(i).size(); ++j) {
                std::cout << this->window.at(i).at(j) << intToSpace(this->spacing);
            }
            std::cout << std::endl;
        }
    }
};



int main() {
    DotEngine engine = *new DotEngine({15, 15}, "Berke", 1, '.', false);
    engine.initialize();
    
    
}