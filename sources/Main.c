
#include "Engine.h"
#include "Game.h"

int main(void)
{
    engineInit();

    GameState *state = gameCreate();

    while (engineContinue())
    {
        engineBegin();
        gameUpdate(state);
        gameDraw(state);
        engineEnd();
    }

    gameDestroy(state);

    engineFini();

    return 0;
}
