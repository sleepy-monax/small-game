#include "game/Game.h"

void game_update()
{
}

void game_draw()
{
    DrawTextEx(GetFontDefault(), "World", (Vector2){2, 23}, GetFontDefault().baseSize, 1, (Color){0, 255, 255, 255});
    DrawTextEx(GetFontDefault(), "Hello", (Vector2){4, 0}, GetFontDefault().baseSize, 1, (Color){0, 255, 255, 255});
}