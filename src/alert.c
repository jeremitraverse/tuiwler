#include "alert.h"
#include <ncurses.h>


void write_alert(char* msg) {
    mvprintw(57, 0, msg);
    refresh();
}

void delete_alert() {
    mvprintw(85, 0, "%*s", 85, "");
    refresh();
}