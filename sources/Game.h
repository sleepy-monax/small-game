#pragma once

#include "Common.h"

/* --- Tile ----------------------------------------------------------------- */

#define TILE_SIZE 8

#define BACKGROUND_TILE_LIST(__ENTRY) \
    __ENTRY(VOID)                     \
    __ENTRY(WATER)                    \
    __ENTRY(SAND)                    \
    __ENTRY(DIRT)                     \
    __ENTRY(GRASS)

typedef enum
{
#define BACKGROUND_TILE_ENUM_ENTRY(__tile) TILE_##__tile,
    BACKGROUND_TILE_LIST(BACKGROUND_TILE_ENUM_ENTRY)
        __BACKGROUND_TILE_COUNT
} BackgroundTileName;

/* --- Level ---------------------------------------------------------------- */

#define LEVEL_SIZE (256)

#define LEVEL_LIST(__ENTRY) \
    __ENTRY(OVERWORLD)      \
    __ENTRY(CAVE)           \
    __ENTRY(DEEP_CAVE)      \
    __ENTRY(DUNGEON)        \
    __ENTRY(HELL)

typedef enum
{
#define LEVEL_ENUM_ENTRY(__entry) LEVEL_##__entry,
    LEVEL_LIST(LEVEL_ENUM_ENTRY)
        __LEVEL_COUNT
} LevelName;

typedef struct
{
    BackgroundTileName background[LEVEL_SIZE][LEVEL_SIZE];
} Level;

/* --- Game State ----------------------------------------------------------- */

typedef struct
{
    Level levels[__LEVEL_COUNT];
} GameState;

GameState *gameCreate(void);

void gameDestroy(GameState *state);

void gameUpdate(GameState *state);

void gameDraw(GameState *state);
