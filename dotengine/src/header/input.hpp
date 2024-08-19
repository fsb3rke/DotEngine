#ifndef INPUT_HPP
#define INPUT_HPP

#ifdef _WIN32
#include <conio.h>
#endif

#define KEY_BACKSPACE 8
#define KEY_SPACE 32
#define KEY_ESC 27
#define KEY_DEL 127

#ifdef _WIN32
namespace Input {
    auto getKey = [](int key){return getch()==key;};
}
#endif

#endif