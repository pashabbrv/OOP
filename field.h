#ifndef OOP_HEADERS_FIELD_H_
#define OOP_HEADERS_FIELD_H_

#include "cell.h"
#include "player.h"

#define MIN_LENGTH 5
#define MIN_WIDTH 5

class Field {
 public:
    bool valid(int x, int y) const;
    void set_start(int x, int y);
    void set_exit(int x, int y);
    int get_exit_x() const;
    int get_exit_y() const;
    int get_width() const;
    int get_length() const;
    void print_settings();
    void print_field(Player& player) const;
    Cell& get_cell(int x, int y) const;
    Field(int width = MIN_WIDTH, int length = MIN_LENGTH);
    Field(const Field& other);
    Field &operator = (const Field& other);
    Field(Field&& other) noexcept;
    Field &operator = (Field&& other) noexcept;
    ~Field();
 private:
    Cell **field_;
    int width_, length_;
    int start_x_, start_y_;
    int exit_x_, exit_y_;
};

#endif