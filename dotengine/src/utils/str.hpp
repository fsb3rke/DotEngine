#ifndef STR_HPP
#define STR_HPP

#include <string>

#define STR_SPACE ' '

namespace utils {
    // std::string intToSpace(int x);
    std::string intToSpace(int count) {
        return std::string(count, STR_SPACE);
    }
}

#endif