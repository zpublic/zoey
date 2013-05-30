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
    m_Driver_ptr->beginScene();
}

void GraphicsEngine::BeginScene(irr::video::SColor color)
{
    if (!m_Driver_ptr)
    {
        return;
    }
    m_Driver_ptr->beginScene(true, true, color);
}

void GraphicsEngine::EndScene()
{
    if (!m_Driver_ptr)
    {
        return;
    }
    m_Driver_ptr->endScene();
}

void GraphicsEngine::Clear(DWORD color)
{
    if (!m_Driver_ptr)
    {
        return;
    }
}

void GraphicsEngine::RenderLine(int x1, int y1,
        int x2, int y2,
        DWORD color)
{
    if (!m_Driver_ptr)
    {
        return;
    }
    m_Driver_ptr->draw2DLine(core::position2d<s32>(x1, y1),
        core::position2d<s32>(x2, y2), color);
}


TextureObject* GraphicsEngine::LoadTextrure(const io::path& filename)
{
    if (!m_Driver_ptr)
    {
        return NULL;
    }
    return m_Driver_ptr->getTexture(filename);
}

bool GraphicsEngine::DrawImage(const std::string& strId, int x, int y,
    DWORD color)
{
    if (!m_Driver_ptr)
    {
        return false;
    }
    ///> ÔÝÎÞ×ÊÔ´³Ø
    const video::ITexture* texture = NULL;
    if (!texture)
    {
        return false;
    }
    m_Driver_ptr->draw2DImage(texture, position2di(x, y),
        rect<s32>(0, 0, texture->getSize().Width, texture->getSize().Height),
        0, color, true);
    return true;
}

bool GraphicsEngine::DrawImage(TextureObject* iTex, int x, int y,
        DWORD color)
{
    if (!m_Driver_ptr)
    {
        return false;
    }
    if (!iTex)
    {
        return false;
    }
    m_Driver_ptr->draw2DImage(iTex, position2di(x, y),
        rect<s32>(0, 0, iTex->getSize().Width, iTex->getSize().Height),
        0, color, true);
    return true;
}

bool GraphicsEngine::Initialize(irr::video::IVideoDriver* pDriver)
{
    if (pDriver)
    {
        m_Driver_ptr = pDriver;
        return true;
    }
    return false;
}