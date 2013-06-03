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

bool GameEngine::Initialize(TCHAR* lpszText, int Width, int Height,video::E_DRIVER_TYPE TDriverType, bool IsFull)
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
        GraphicsEngine::Instance()->BeginScene(
            irr::video::SColor(255,100,101,140));
        ///> Test Draw
        GraphicsEngine::Instance()->RenderLine(10,52,0,0);
        char filePath[MAX_PATH] = {0};
        ::GetModuleFileNameA(0, filePath, MAX_PATH);
        ::PathRemoveFileSpecA(filePath);
        ::PathAppendA(filePath, "res\\images\\brick0.png");
        GraphicsEngine::Instance()->DrawImage(
            GraphicsEngine::Instance()->LoadTextrure(filePath),
            100, 0);

        GraphicsEngine::Instance()->EndScene();
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