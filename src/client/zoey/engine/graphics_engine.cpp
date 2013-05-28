#include "stdafx.h"
#include "graphics_engine.h"

template<> GraphicsEngine* Singleton<GraphicsEngine>::m_pInst = NULL;

GraphicsEngine::GraphicsEngine()
{
    m_Driver_ptr = NULL;
}

GraphicsEngine::~GraphicsEngine()
{

}

void GraphicsEngine::SetClipping(int x, int y, int w, int h)
{
    if (!m_Driver_ptr)
    {
        return;
    }

}

void GraphicsEngine::SetClipping()
{
    if (!m_Driver_ptr)
    {
        return;
    }

}

void GraphicsEngine::BeginScene()
{
    if (!m_Driver_ptr)
    {
        return;
    }

}

void GraphicsEngine::EndScene()
{
    if (!m_Driver_ptr)
    {
        return;
    }

}

void GraphicsEngine::Clear(DWORD color)
{
    if (!m_Driver_ptr)
    {
        return;
    }

}

void GraphicsEngine::RenderLine(float x1, float y1,
        float x2, float y2,
        DWORD color,
        float z)
{
    if (!m_Driver_ptr)
    {
        return;
    }

}

bool GraphicsEngine::Initialize(irr::video::IVideoDriver* pDriver)
{
    if (m_Driver_ptr)
    {
        m_Driver_ptr = pDriver;
        return true;
    }
    return false;
}