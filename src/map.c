#include "map.h"
#include "cursor.h"
#include <ncurses.h>
#include "util.h"
#include "alert.h"


typedef struct {
    bool collide;
    char icon;
} Tile;

typedef struct {
    int start_x;
    int start_y;
    int height;
    int width;
} Room;

typedef struct {
    Tile tiles[51][101];
} Map;

void draw_map(Map* m);
void fill_map(Map* m);
void mine_rooms(Map *m);
void mine_middle_room(Map *m);
void mine_room(Map* m, int sizey, int sizex, int starting_point);
void draw_player(int posy, int posx);

void init_map() {
    Map m;
    fill_map(&m);
    Tile t = m.tiles[50][100];
    
    mine_middle_room(&m);
    /*
    // mine_rooms(&m);
    for (int i = 0; i < 8; ++i) {
        int room_height = rand_between(MIN_ROOM_SIZE, MAX_ROOM_HEIGHT);
        int room_width = rand_between(MIN_ROOM_SIZE, MAX_ROOM_WIDTH);
        int pos = rand_between(0, COLS - room_width);
        mine_room(&m, room_height, room_width, pos);
    }
    
    */
    draw_map(&m);
    draw_player(LINES/2, COLS/2);
}

void fill_map(Map* m) {
    size_t nb_lignes = sizeof(m->tiles) / sizeof(m->tiles[0]);
    size_t nb_colonnes = sizeof(m->tiles[0]) / sizeof(m->tiles[0][0]);
    for(int y = 0; y < nb_lignes; ++y) {
        for(int x = 0; x < nb_colonnes; ++x) {
            Tile t;
            t.collide = true;
            t.icon = '#';
            m->tiles[y][x] = t;
        }
    }
}    

void draw_map(Map* m) {
    char message[50];

    int map_min_y = LINES/2 - DN_HEIGHT / 2;
    int map_min_x = COLS/2 - DN_WIDTH / 2;

    for(int y = 0; y < DN_HEIGHT; ++y) {
        for(int x = 0; x < DN_WIDTH; ++x) {
            Tile t = m->tiles[y][x];
            mvaddch(y + map_min_y, x + map_min_x, t.icon);
        }
    }
    refresh();
}

void draw_player(int posy, int posx) {
    mvaddch(posy, posx, '@');
}

void mine_middle_room(Map* m) {
    int min_y = (DN_HEIGHT / 2) - 5;
    int max_y= (DN_HEIGHT / 2) + 5;
    int min_x = (DN_WIDTH / 2) - 5;
    int max_x= (DN_WIDTH / 2) + 5;

    for(int y = min_y; y < max_y; ++y){
        for (int x = min_x; x < max_x; ++x) {
            Tile t;
            t.collide = false;
            t.icon = '.';
            m->tiles[y][x] = t;
        }
    }

    refresh();
}

void mine_rooms(Map* m) {
}

void mine_room(Map* m, int sizey, int sizex, int starting_point) {
    int endy = sizey + starting_point;
    int endx = sizex + starting_point;
    for(int y = starting_point; y < endy; ++y){
        for (int x = starting_point; x < endx; ++x) {
            Tile t;
            t.collide = false;
            t.icon = '.';
            m->tiles[y][x] = t;
        }
    }
}