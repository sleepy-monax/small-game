#include "Engine.h"

#include <raylib.h>
#include <raymath.h>

static Texture2D sprites;
static RenderTexture2D render;

void engineInit(void)
{
    SetTraceLogLevel(LOG_WARNING);
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(SCREEN_PHYSICAL_WIDTH, SCREEN_PHYSICAL_HEIGHT, "small-game");
    SetTargetFPS(60);

    render = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetTextureFilter(render.texture, FILTER_POINT);

    sprites = LoadTexture("sources/sprites.png");
}

void engineFini(void)
{
    UnloadTexture(sprites);
    UnloadRenderTexture(render);
    CloseWindow();
}

void engineBegin(void)
{
    BeginDrawing();
    ClearBackground(BLACK);

    BeginTextureMode(render);
    ClearBackground(BLUE);
}

void engineEnd(void)
{
    EndTextureMode();

    double scale = __min((double)SCREEN_PHYSICAL_WIDTH / SCREEN_WIDTH, (double)SCREEN_PHYSICAL_HEIGHT / SCREEN_HEIGHT);

    DrawTexturePro(
        render.texture,
        (Rectangle){
            0.0f,
            0.0f,
            (float)render.texture.width,
            (float)-render.texture.height,
        },
        (Rectangle){
            (GetScreenWidth() - ((float)SCREEN_WIDTH * scale)) * 0.5,
            (GetScreenHeight() - ((float)SCREEN_HEIGHT * scale)) * 0.5,
            (float)SCREEN_WIDTH * scale,
            (float)SCREEN_HEIGHT * scale,
        },
        (Vector2){
            0,
            0,
        },
        0.0f,
        WHITE);

    EndDrawing();
}

bool engineContinue(void)
{
    return !WindowShouldClose();
}

void spriteDraw(Sprite sprite, int x, int y)
{
    DrawTexturePro(sprites, (Rectangle){(sprite % 16) * 8, (sprite / 16) * 8, 8, 8}, (Rectangle){x, y, 8, 8}, (Vector2){0, 0}, 0, WHITE);
}