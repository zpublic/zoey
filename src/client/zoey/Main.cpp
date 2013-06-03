#include <stdafx.h>
#include "engine\game_engine.h"

int WINAPI WinMain (
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
    GameEngine::Instance()->Initialize(_T("zoey"), 800, 600,
        irr::video::EDT_OPENGL, false);
    while (GameEngine::Instance()->IsDone())
    {
        GameEngine::Instance()->Update();
        GameEngine::Instance()->Render();
    }
    return 0;
}