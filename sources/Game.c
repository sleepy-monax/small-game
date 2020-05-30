#include "Game.h"
#include "Engine.h"

GameState *gameCreate(void)
{
    return __create(GameState);
}

void gameDestroy(GameState *state)
{
    free(state);
}

void gameUpdate(GameState *state)
{
    __unused(state);
}

void gameDraw(GameState *state)
{
    __unused(state);

    for (int x = 0; x < LEVEL_SIZE; x++)
    {
        for (int y = 0; y < LEVEL_SIZE; y++)
        {
            spriteDraw(SPRITE_SAND, x * TILE_SIZE, y * TILE_SIZE);
        }
    }
}