
#include "general.h"

#define tileSize 16
uint8_t screenW = 160;
uint8_t screenH = 160;

uint8_t myPalette;
uint8_t frame;
uint8_t animFrame;
uint8_t srcY = 0;
uint8_t walking = 0;
uint8_t previousGamepad;



void anim();
void initLevel();
void input();
void setPalette();

const uint8_t* level = level1;

uint8_t tileAt (int tileX, int tileY) {
    return level[tileY*LEVEL_WIDTH + tileX];
}

void start(){
    
    myPalette = 1;
    initLevel();
    //hero.x=screenW/2;
    //hero.y=screenH/2;
}

void update () {

    walking = 0;
    

    setPalette();
    input();
        
        
       

    anim();
    *DRAW_COLORS = 0x1230;

    for (int y = 0; y < LEVEL_HEIGHT; y++){
        for(int x = 0; x < LEVEL_WIDTH; x++){
            uint8_t tile = tileAt(x, y);
            if (tile == TILE_WALL){
                blitSub(tiles,x*tileSize, y*tileSize, tileSize,tileSize,0,0,48,tilesFlags);
            }
            if (tile == TILE_DOOR){
                blitSub(tiles,x*tileSize, y*tileSize, tileSize,tileSize,32,0,48,tilesFlags);
            }
        }
    }

    blitSub(hero_sp, hero.x, hero.y, hero.w, hero.h, animFrame*16, srcY, 64, heroFlags);
    

    
}


void setPalette() {

    //set pallete
    if (myPalette == 0){
        //blue
        //background
        PALETTE[0] = 0x433455;
        //character
        PALETTE[2] = 0xc5ccb8;
        
    } if (myPalette == 1){
        //magenta
        //background
        PALETTE[2] = 0x433455;
        //character
        PALETTE[0] = 0xc5ccb8;
    }
}

void initLevel () {
    for (int y = 0; y < LEVEL_HEIGHT; y++){
        for (int x = 0; x < LEVEL_WIDTH; x++){
            uint8_t tile = tileAt(x,y);
            if (tile == TILE_SPAWN){
                hero.x = x*tileSize;
                hero.y = y*tileSize;
                return;
            }
        }
    }
}

void anim(){
if (walking){
            animFrame = ((frame/8) % 4);
        } else if(!walking){
            animFrame = 1;
        }
}

void input(){
    
    uint8_t gamepad = *GAMEPAD1;

    uint8_t pressedThisFrame = gamepad & (gamepad ^ previousGamepad);    
    previousGamepad = gamepad;

    if (gamepad & BUTTON_DOWN) {
        if (hero.y < screenH-hero.h){
            srcY=0;
            hero.y++;
            walking=1;
            frame++;
        }
        
    }

    if (gamepad & BUTTON_UP) {
        if (hero.y > 0){
            srcY=32;
            hero.y--;
            walking=1;
            frame++;
        }
        
    }

    if (gamepad & BUTTON_RIGHT) {
        if (hero.x < screenH-hero.w){
            srcY=48;
            hero.x++;
            walking=1;
            frame++;
        }
        
    }

    if (gamepad & BUTTON_LEFT) {
        if (hero.x > 0){
            srcY=16;
            hero.x--;
            walking=1;
            frame++;
        }
        
    }

    if (pressedThisFrame & BUTTON_1){
        if (myPalette == 0){
            myPalette =1;
        }else{myPalette=0;}
    }
}