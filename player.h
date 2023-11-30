#ifndef OOP_HEADERS_PLAYER_H_
#define OOP_HEADERS_PLAYER_H_

class Player {
 public:
    void set_health(int health);
    void set_score(int score);
    void set_x_coord(int x_coord);
    void set_y_coord(int y_coord);
    int get_health() const;
    int get_score() const;
    int get_x_coord() const;
    int get_y_coord() const;
    void print_settings();
    Player();

 private:
    const int kMinHealth = 0;
    const int kMaxHealth = 100;
    const int kMinScore = 0;
    const int kMinX = 0;
    const int kMinY = 0;
    int health_;
    int score_;
    int x_coord_, y_coord_;
};

#endif