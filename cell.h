#ifndef OOP_HEADERS_CELL_H_
#define OOP_HEADERS_CELL_H_

#include "event.h"

class Cell {
 public:
    void set_access(bool access);
    bool get_access() const;
    bool get_event() const;
    void set_event(Event* event);
    void start_event(Controller& controller);
    Cell(const Cell& other) noexcept;
    Cell &operator = (const Cell& other);
    Cell(Cell&& other) noexcept;
    Cell &operator = (Cell&& other) noexcept;
    Cell(bool access = true);
    ~Cell();

 private:
    Event* event_ = nullptr;
    bool access_;
};

#endif