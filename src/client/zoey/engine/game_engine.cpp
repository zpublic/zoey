#include "stdafx.h"
#include "game_engine.h"
#include "graphics_engine.h"

GameEngine* Singleton<GameEngine>::m_pInst = NULL;

using namespace irr;

GameEngine::GameEngine()
    : m_irrDevice(NULL)
    , m_VideoDriver(NULL)
{

}

GameEngine::~GameEngine()
{
    Close();
}

bool GameEngine::Ini(TCHAR* lpszText, int Width, int Height,video::E_DRIVER_TYPE TDriverType, bool IsFull)
{
    IEventReceiver* TEventReceiver = NULL;
    m_irrDevice = createDevice(TDriverType, irr::core::dimension2du(Width, Height),
        32, IsFull, false, false, TEventReceiver);
    if(m_irrDevice == NULL)
    {
        return false;
    }
    m_irrDevice->setWindowCaption(lpszText);
    m_irrDevice->setEventReceiver(TEventReceiver);
    m_VideoDriver = m_irrDevice->getVideoDriver();
    ///> ini engine
    if(!GraphicsEngine::Instance()->Initialize(m_VideoDriver))
    {
        return false;
    }
    return true;
}

bool GameEngine::IsDone()
{
    return m_IsDone;
}

void GameEngine::Update()
{
    if(!m_irrDevice || !m_irrDevice->run())
    {
        m_IsDone = false;
    }
}

void GameEngine::Render()
{
    if (m_VideoDriver)
    {
        m_VideoDriver->beginScene(true, true,
            irr::video::SColor(255,100,101,140));
        m_VideoDriver->endScene();
    }
}

void GameEngine::Close()
{
    if (m_irrDevice)
    {
        m_irrDevice->drop();
        m_irrDevice = NULL;
    }
}