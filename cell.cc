#include <iostream>

#include "cell.h"

void Cell::set_access(bool access) { access_ = access; }

bool Cell::get_access() const { return access_; }

bool Cell::get_event() const{
    return event_ != nullptr;
}

void Cell::set_event(Event* event){
    if(event_ != nullptr){
        delete event_;
    }
    event_ = event;
}

void Cell::start_event(Controller& controller){
    event_ -> realization(controller);
}

Cell::Cell(const Cell& other) noexcept {
    access_ = other.access_;
    if(other.event_ != nullptr)
        event_ = other.event_;
}

Cell& Cell::operator=(const Cell& other) {
    if (this != &other) {
        Cell tmp(other);
        std::swap(access_, tmp.access_);
        if (event_ != nullptr)
            delete event_;
        std::swap(event_, tmp.event_);
    }
    return *this;
}

Cell::Cell(Cell&& other) noexcept {
    std::swap(access_, other.access_);
    std::swap(event_, other.event_);
    other.access_ = 0;
    other.event_ = nullptr;
}

Cell& Cell::operator=(Cell&& other) noexcept {
    if (this != &other) {
        std::swap(access_, other.access_);
        if (event_ != nullptr)
            delete event_;
        std::swap(event_, other.event_);
        other.access_ = 0;
        other.event_ = nullptr;
    }
    return *this;
}

Cell::Cell(bool access) { access_ = access; }

Cell::~Cell() {
    if (event_ != nullptr) {
        delete event_;
    }
}