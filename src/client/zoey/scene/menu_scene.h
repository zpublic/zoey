#ifndef MENU_SCENE_
#define MENU_SCENE_

#include "scene\scene.h"
#include "engine\scene_engine.h"
#include "engine\graphics_engine.h"

class MenuScene
    : public Scene
{
public:
    MenuScene();
    virtual ~MenuScene();

    virtual void Update();

    virtual void Output();

    virtual void Reset();
private:
    GraphicsEngine* m_Graphics;
};

#endif