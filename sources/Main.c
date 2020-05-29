
#include "engine/Screen.h"
#include "game/Game.h"

int main(void)
{
    SetTraceLogLevel(LOG_WARNING);
    SetConfigFlags(FLAG_VSYNC_HINT);

    InitWindow(SCREEN_PHYSICAL_WIDTH, SCREEN_PHYSICAL_HEIGHT, "small-game");

    RenderTexture2D target = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetTextureFilter(target.texture, FILTER_POINT);
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        game_update();

        double scale = __min((double)SCREEN_PHYSICAL_WIDTH / SCREEN_WIDTH, (double)SCREEN_PHYSICAL_HEIGHT / SCREEN_HEIGHT);

        BeginDrawing();
        ClearBackground(BLACK);

        BeginTextureMode(target);
        ClearBackground(BLUE);

        game_draw();

        EndTextureMode();

        DrawTexturePro(
            target.texture,
            (Rectangle){
                0.0f,
                0.0f,
                (float)target.texture.width,
                (float)-target.texture.height,
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

    UnloadRenderTexture(target);
    CloseWindow();

    return 0;
}
