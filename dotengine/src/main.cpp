#include "header/engine.hpp"

int main() {
    DotEngine engine = *new DotEngine({15, 15}, "Berke", 1, '.');
    engine.initialize();

}