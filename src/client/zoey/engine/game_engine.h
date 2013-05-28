#ifndef GAME_ENGINE_
#define GAME_ENGINE_

#include "import\irrlicht\irrlicht.h"
#include "include\utils\singleton.h"
#include <tchar.h>

#ifdef _IRR_WINDOWS_
#pragma comment(lib,"../../../import/irrlicht.lib")
#endif

class GameEngine
    : public Singleton<GameEngine>
{
    friend Singleton<GameEngine>;
public:
    GameEngine();
    virtual ~GameEngine();

    bool Initialize(TCHAR* lpszText, int Width, int Height,
        irr::video::E_DRIVER_TYPE TDriverType, bool IsFull);

    void Close();

    bool IsDone();

    void Update();

    void Render();

private:
    irr::IrrlichtDevice* m_irrDevice;
    irr::video::IVideoDriver* m_VideoDriver;
    bool m_IsDone;
};

#endif