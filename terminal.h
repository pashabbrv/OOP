#ifndef OOP_HEADERS_TERMINAL_H_
#define OOP_HEADERS_TERMINAL_H_

#include <cctype>
#include <conio.h>

#include "input.h"

class Terminal : public Input {
 public:
    char reader() const override;
};

#endif