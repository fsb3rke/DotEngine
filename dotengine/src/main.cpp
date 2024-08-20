#include "header/engine.hpp"


int main() {
    DotEngine engine = *new DotEngine({10, 8}, "Berke", 1, '.', 20);
    engine.initialize();

    int columnSum = 0;
    int posSum = 0;
    int charPos = 'a';

    const int maxCol = 7;
    const int maxRow = 9;

    while (engine.getChar(maxRow, maxCol) == '.') {
        engine.changeChar(columnSum, posSum, (char)charPos);
        engine.renderWindow();

        posSum++;
        if (posSum > maxCol) {
            posSum = 0;
            columnSum++;
            if (columnSum > maxRow)
                break;
        }
        charPos++;
    }

    std::cout << charPos << std::endl;
    std::cout << engine.getTableSize() << std::endl;

    std::cout << engine.getChar(12) << std::endl;

    // engine.changeChar(2, 5, 'A');
    // engine.renderWindow();
}