#pragma once

#include "wasm4.h"

//level size
#define LEVEL_WIDTH 15
#define LEVEL_HEIGHT 15

//tiles
//void
#define TILE_EMPTY 0
//Wall
#define TILE_WALL 1
//Door
#define TILE_DOOR 2
//player spawn
#define TILE_SPAWN 3
//level exit
#define TILE_EXIT 4
//enemy spawn (maybe)
#define TILE_ENEMY_SPAWN 5

extern const uint8_t level1[];

