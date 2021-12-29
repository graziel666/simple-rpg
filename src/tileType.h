#pragma once
#include <stdint.h>

enum class TileType : uint8_t{
  None,
  Wall,
  //WallTorch, //testing something
  Chest,
  Torch,
  Door,
  Water,

};


//returns "true" if solid
constexpr bool isSolid(TileType tileType){
    //all is solid except none and door
    return(tileType != TileType::None, tileType != TileType::Door);
}

constexpr uint8_t getTileIndex(TileType tileType){
  //convert TileType into index for array
  return static_cast<uint8_t>(tileType);
}
