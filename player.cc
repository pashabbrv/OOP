#include <iostream>

#include "player.h"

void Player::set_health(int health) {
    if (health < kMinHealth) {
        health = kMinHealth;
    } else if (health > kMaxHealth) {
        health = kMaxHealth;
    }
    health_ = health;
}

void Player::set_score(int score) {
    if (score < kMinScore) {
        score = kMinScore;
    }
    score_ = score;
}

void Player::set_x_coord(int x_coord) { x_coord_ = x_coord; }

void Player::set_y_coord(int y_coord) { y_coord_ = y_coord; }

int Player::get_health() const { return health_; }

int Player::get_score() const { return score_; }

int Player::get_x_coord() const { return x_coord_; }

int Player::get_y_coord() const { return y_coord_; }

void Player::print_settings() {
    std::cout << "Health: " << health_
              << "  Score: " << score_ << std::endl;
    std::cout << "Coordinates X: " << x_coord_
              << "  Coordinates Y: " << y_coord_ << std::endl << std::endl;
}

Player::Player() {
    health_ = kMaxHealth;
    score_ = kMinScore;
    x_coord_ = kMinX;
    y_coord_ = kMinY;
}