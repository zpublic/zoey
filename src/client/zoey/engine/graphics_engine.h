#ifndef GFXENGINE_
#define GFXENGINE_

#include "include\utils\singleton.h"
#include "import\irrlicht\irrlicht.h"
#include "iengine.h"

class GraphicsEngine
    : public Singleton<GraphicsEngine>
    , public IEngine
{
    friend class Singleton<GraphicsEngine>;
public:
    GraphicsEngine();
    virtual ~GraphicsEngine();

    virtual bool Initialize(irr::video::IVideoDriver* pDriver);

public:
    void BeginScene();

    void EndScene();

    void Clear(DWORD color);

    void RenderLine(float x1, float y1,
        float x2, float y2,
        DWORD color = 0xFFFFFFFF,
        float z = 0.5f);

    void SetClipping( int x, int y, int w, int h);

    void SetClipping();

private:
    irr::video::IVideoDriver* m_Driver_ptr;
};

#endif