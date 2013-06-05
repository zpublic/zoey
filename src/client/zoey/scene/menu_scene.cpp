#include "stdafx.h"
#include "menu_scene.h"

MenuScene::MenuScene()
    : m_Graphics(NULL)
{
    m_Graphics = GraphicsEngine::Instance();
    
}


MenuScene::~MenuScene()
{

}

void MenuScene::Update()
{

}

void MenuScene::Output()
{
    m_Graphics->DrawImage("Text", 0, 0);
}

void MenuScene::Reset()
{
    
}