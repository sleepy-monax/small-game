#pragma once

#include "Common.h"

#define SCREEN_PIXEL (6)
#define SCREEN_WIDTH (160)
#define SCREEN_HEIGHT (120)
#define SCREEN_PHYSICAL_WIDTH (SCREEN_WIDTH * SCREEN_PIXEL)
#define SCREEN_PHYSICAL_HEIGHT (SCREEN_HEIGHT * SCREEN_PIXEL)

typedef enum
{
    SPRITE_VOID = 0,
    SPRITE_WATER,
    SPRITE_SAND,
    SPRITE_DIRT,
    SPRITE_GRASS
} Sprite;

void engineInit(void);
void engineFini(void);
void engineBegin(void);
void engineEnd(void);
bool engineContinue(void);

void spriteDraw(Sprite sprite, int x, int y);