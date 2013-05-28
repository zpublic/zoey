#ifndef GAME_ENGINE_
#define GAME_ENGINE_

#include "import\irrlicht\irrlicht.h"
#include "include\utils\singleton.h"

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

    bool Ini(int Width, int Height,irr::video::E_DRIVER_TYPE TDriverType, bool IsFull);

    void Close();

    bool IsDone();

    void Update();

private:
    irr::IrrlichtDevice* m_irrDevice;
    bool m_IsDone;
};

#endif