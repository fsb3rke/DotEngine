#ifndef STR_HPP
#define STR_HPP

#include <string>

namespace utils {
    // std::string intToSpace(int x);
    auto intToSpace = [](int x){std::string space;for(int i=0;i<x;++i){space+=' ';}return space;};
}

// std::string utils::intToSpace(int x) {
//     std::string space;
//     for (int i = 0; i < x; ++i) {
//         space += ' ';
//     }
    
//     return space;
// }

#endif