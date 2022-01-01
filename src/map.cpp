
#include "map.h"

//setting easier names for the map

#define _ TILE_EMPTY
#define X TILE_WALL
#define D TILE_DOOR
#define S TILE_SPAWN
#define E TILE_EXIT
#define Z TILE_ENEMY_SPAWN

const uint8_t level1[] = {
    X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
    X,S,_,_,_,_,X,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,X,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,X,_,_,_,_,_,_,_,X,
    X,X,X,D,X,X,X,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,_,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,_,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,_,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,_,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,_,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,_,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,_,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,_,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,_,_,_,_,_,_,_,_,X,
    X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
};


