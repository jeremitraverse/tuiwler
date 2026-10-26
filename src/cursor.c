#include "cursor.h"
#include <stdlib.h>

static Cursor cursor;

void init_cursor() {
    cursor.x = 0;
    cursor.y = 0;
}

Cursor* get_cursor() {
    return &cursor;
}

Cursor* move_cursor(int y, int x) {
    cursor.y = y;
    cursor.x = x;

    return &cursor;
}