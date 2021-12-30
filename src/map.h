#pragma once

#include "general.h"

//level size
#define LEVEL_WIDTH 15
#define LEVEL_HEIGHT 15

//tiles
//void
#define TILE_EMPTY 0
//Wall
#define TILE_WALL 1
//player spawn
#define TILE_SPAWN 2
//level exit
#define TILE_EXIT 3
//enemy spawn (maybe)
#define TILE_ENEMY_SPAWN 4

extern const uint8_t level1[];
