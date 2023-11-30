#include <iostream>

#include "field.h"

bool Field::valid(int x, int y) const {
    if (x < 0 || x >= length_ || y < 0 || y >= width_)
        return false;
    return true;
}

void Field::set_start(int x, int y) {
    if (valid(x, y) && field_[y][x].get_access()) {
        start_x_ = x;
        start_y_ = y;
    }
}

void Field::set_exit(int x, int y) {
    if (valid(x, y) && field_[y][x].get_access()) {
        exit_x_ = x;
        exit_y_ = y;
    }
}

int Field::get_exit_x() const { return exit_x_; }

int Field::get_exit_y() const { return exit_y_; }

int Field::get_width() const { return width_; }

int Field::get_length() const { return length_; }

void Field::print_settings(){
    std::cout << "Width: " << width_
              << "  Length: " << length_ << std::endl;
    std::cout << "Start X: " << start_x_
              << "  Start Y: " << start_y_ << std::endl;
    std::cout << "Exit X: " << exit_x_
              << "  Exit Y: " << exit_y_ << std::endl << std::endl;;
}

void Field::print_field(Player& player) const {
     for (int y = 0; y < width_; y++) {
        for (int x = 0; x < length_; x++) {
            if (player.get_x_coord() == x && player.get_y_coord() == y)
                std::cout << "* ";
            else if (field_[y][x].get_event()) 
                std::cout << "? ";
            else if (start_x_ == x && start_y_== y)
                std::cout << "0 ";
            else if (exit_x_ == x && exit_y_ == y)
                std::cout << "W ";
            else if (field_[y][x].get_access())
                std::cout << ". ";
            else if (!field_[y][x].get_access())
                std::cout << "# ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Cell& Field::get_cell(int x, int y) const {
    if (!valid(x, y))
        throw std::out_of_range("Error. Cell is out of field size");
    return field_[y][x];
}

Field::Field(int length, int width) {
    if(length < MIN_LENGTH){
        length_ = MIN_LENGTH;
    }
    if(width < MIN_WIDTH) {
        width_ = MIN_WIDTH;
    }

    length_ = length;
    width_ = width;

    field_ = new Cell*[width_];
    for (int i = 0; i < width_; i++) field_[i] = new Cell[length_];

    start_x_ = 0;
    start_y_ = 0;
    exit_x_ = length_ - 1;
    exit_y_ = width_ - 1;
}

Field::Field(const Field& other) {
    width_ = other.width_;
    length_ = other.length_;
    start_x_ = other.start_x_;
    start_y_ = other.start_y_;
    exit_x_ = other.exit_x_;
    exit_y_ = other.exit_y_;

    field_ = new Cell*[width_];
    for (int i = 0; i < width_; i++) {
        field_[i] = new Cell[length_];
        for (int j = 0; j < length_; j++) {
            field_[i][j] = other.field_[i][j];
        }
    }
}

Field& Field::operator=(const Field& other) {
    if (this == &other) {
        return *this;
    }

    if (field_ != nullptr) {
        for (int i = 0; i < width_; i++) {
            delete[] field_[i];
        }
        delete[] field_;
    }

    width_ = other.width_;
    length_ = other.length_;
    start_x_ = other.start_x_;
    start_y_ = other.start_y_;
    exit_x_ = other.exit_x_;
    exit_y_ = other.exit_y_;

    field_ = new Cell*[width_];
    for (int i = 0; i < width_; i++) {
        field_[i] = new Cell[length_];
        for (int j = 0; j < length_; j++) {
            field_[i][j] = other.field_[i][j];
        }
    }

    return *this;
}

Field::Field(Field&& other) noexcept {
    width_ = 0;
    length_ = 0;
    start_x_ = 0;
    start_y_ = 0;
    exit_x_ = 0;
    exit_y_ = 0;
    field_ = nullptr;

    std::swap(width_, other.width_);
    std::swap(length_, other.length_);
    std::swap(start_x_, other.start_x_);
    std::swap(start_y_, other.start_y_);
    std::swap(exit_x_, other.exit_x_);
    std::swap(exit_y_, other.exit_y_);
    std::swap(field_, other.field_);
}

Field& Field::operator=(Field&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    if (field_ != nullptr) {
        for (int i = 0; i < width_; i++) delete[] field_[i];
        delete[] field_;
    }

    std::swap(width_, other.width_);
    std::swap(length_, other.length_);
    std::swap(start_x_, other.start_x_);
    std::swap(start_y_, other.start_y_);
    std::swap(exit_x_, other.exit_x_);
    std::swap(exit_y_, other.exit_y_);
    std::swap(field_, other.field_);

    other.width_ = 0;
    other.length_ = 0;
    other.start_x_ = 0;
    other.start_y_ = 0;
    other.exit_x_ = 0;
    other.exit_y_ = 0;
    other.field_ = nullptr;
    
    return *this;
}

Field::~Field() {
    if (field_ != nullptr) {
        for (int i = 0; i < width_; i++) delete[] field_[i];
        delete[] field_;
    }
}