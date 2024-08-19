#include "header/engine.hpp"


int main() {
    DotEngine engine = *new DotEngine({8, 8}, "Berke", 1, '.', 20);
    engine.initialize();

    int columnSum = 0;
    int posSum = 0;
    int charPos = 'a';

    while (engine.getChar(n(8), n(8)) == '.') {
        engine.changeChar(columnSum, posSum, (char)charPos);
        engine.renderWindow();

        posSum++;
        if (posSum > n(8)) {
            columnSum++;
            posSum = 0;
        }
        charPos++;
    }

    std::cout << charPos << std::endl;
    std::cout << engine.getTableSize() << std::endl;

    std::cout << engine.getChar(12) << std::endl;
    std::cout << engine.getChar(n(engine.getTableSize())) << std::endl;

    // engine.changeChar(2, 5, 'A');
    // engine.renderWindow();
}