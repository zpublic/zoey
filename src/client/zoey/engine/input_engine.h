#ifndef INPUTENGINE_
#define INPUTENGINE_

#include "include\utils\singleton.h"
#include "engine\game_engine.h"
#include "iengine.h"
#include <vector>

typedef enum _KeyState
{
    Key_Down,
    Key_Up,
    Key_Fail,
}KeyState;

typedef enum _PeopleDirection
{
    Direction_Left,
    Direction_Right,
    Direction_Up,
    Direction_Down,
    Direction_Tail,
}PeopleDirection;

class InputEngine
    : public Singleton<InputEngine>
    , public IEngine
    , public irr::IEventReceiver
{
    friend class Singleton<Singleton>;
public:
    InputEngine();
    virtual ~InputEngine();

    virtual bool Initialize() {return false;};

    PeopleDirection Get() const;

    bool OnEvent(const irr::SEvent &TEvent);

    KeyState IsKey(int nKey);

    KeyState IsKey(int nFirstKey, int nSecondKey);

    void Update();

private:
    PeopleDirection m_Key;
};

#endif