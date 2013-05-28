#pragma once

class IMap
{
public:
    virtual ~IMap();

    ///> 属性相关（含name、id、size等）
    virtual wchar_t* GetName()                      = 0;
    virtual int GetId()                             = 0;
    virtual SIZE GetSize()                          = 0;
    
    ///> 渲染相关（将整个地图绘制出来）
    virtual Render(ITexture* pTarget)               = 0;
    
    ///> 地图内对象管理
    virtual void AddObject(IObject* pObject)        = 0;
    virtual void RemoveObject(IObject* pObject)     = 0;
    
    ///> 地图内事件管理
    virtual IndexedEvent* GetIndexedEvent(
        int nEventType,
        int nEventData)                             = 0;
};
