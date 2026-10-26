#include "gameloop.h"
#include "map.h"
#include <ncurses.h>

void move_char(int current_y, int current_x, int next_y, int next_x, char player);
bool is_colliding(int next_y, int next_x);
int game_loop() {
    char player = '@';
    int player_y = LINES/2;
    int player_x = COLS/2;

    int ch;
    while((ch = getch())) {
        bool game_over = false;
        int next_y;
        int next_x;
        switch (ch) {
        case 'q':
            game_over = true;
            break;
        case 'w':
            next_y = player_y - 1;
            
            if(is_colliding(next_y, player_x)) break;

            move_char(player_y, player_x, next_y, player_x, player);
            player_y = next_y;
            break;
        case 's':
            next_y = player_y + 1;

            if(is_colliding(next_y, player_x)) break;

            move_char(player_y, player_x, next_y, player_x, player);
            player_y = next_y;
            break;
        case 'd':
            next_x = player_x + 1;

            if(is_colliding(player_y, next_x)) break;

            move_char(player_y, player_x, player_y, next_x, player);
            player_x = next_x;
            break;
        case 'a':
            next_x = player_x - 1;

            if(is_colliding(player_y, next_x)) break;

            move_char(player_y, player_x, player_y, next_x, player);
            player_x = next_x;
            break;
        }

        if(game_over) return 1;
    }

    return 0;
}

void move_char(int current_y, int current_x, int next_y, int next_x, char player) {
    move(current_y, current_x);
    delch();
    mvaddch(next_y, next_x, player);
}

bool is_colliding(int next_y, int next_x) {
    chtype move = mvinch(next_y, next_x);

    char tile_char = move & A_CHARTEXT;

    switch (tile_char)
    {
    case '#': 
        return true;
    default:
        return false;
    }
}
