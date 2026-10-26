#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

typedef struct {
    int y;
    int x;
} Cursor;

Cursor* get_cursor(void);
Cursor* move_cursor(int y, int x);
void init_cursor();

#endif