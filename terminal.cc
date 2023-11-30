#include "terminal.h"

char Terminal::reader() const {
    char command;
    while (true) {
        if (kbhit()) {
            command = getch();
            break;
        }
    }
    return tolower(command);
}