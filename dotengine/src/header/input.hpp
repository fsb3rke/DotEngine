#ifndef INPUT_HPP
#define INPUT_HPP

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#endif

#define KEY_BACKSPACE 8
#define KEY_SPACE 32
#define KEY_ESC 27
#define KEY_DEL 127

inline int m_getch(void) {
    #ifdef _WIN32
    return getch();
    #else
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
    #endif
}

#ifdef _WIN32
namespace Input {
    auto getKey = [](int key){return m_getch()==key;};
}
#endif

#endif
