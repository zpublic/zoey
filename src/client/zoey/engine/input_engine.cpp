#include "stdafx.h"
#include "input_Engine.h"

template<> InputEngine* Singleton<InputEngine>::m_pInst = NULL;

InputEngine::InputEngine()
{
    m_Key = Direction_Tail;
}

InputEngine::~InputEngine()
{
}

KeyState InputEngine::IsKey(int nKey)
{
    return Key_Up;
}

KeyState InputEngine::IsKey(int nFirstKey, int nSecondKey)
{
    return Key_Up;
}

PeopleDirection InputEngine::Get() const
{
    return m_Key;
}

void InputEngine::Update()
{

}

bool InputEngine::OnEvent(const irr::SEvent &TEvent)
{
    return true;
}