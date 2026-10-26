#include <ncurses.h>
#include "gameloop.h"
#include "cursor.h"
#include "map.h"

void move_char(int current_y, int current_x, int next_y, int next_x, char player);
int main() {
    initscr(); // start ncurses
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);

    init_cursor();
    init_map();

    
    int state = game_loop();

    if (state == 1) {
        endwin(); // stop ncurses
        return 0;
    }

    return 0;
}

