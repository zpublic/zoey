#include "stdafx.h"
#include "c_map_object.h"
#include "include\utils\utils.h"

CMapObjectPool* Singleton<CMapObjectPool>::m_pInst = NULL;

CMapObjectPool::CMapObjectPool()
{
}

CMapObjectPool::~CMapObjectPool()
{
    for (auto it = m_ObjectPool.begin(); it != m_ObjectPool.end(); it++)
    {
        if (it->second)
        {
            delete it->second;
            it->second = NULL;
        }
    }
}

bool CMapObjectPool::Push(const std::string& strPath)
{
    return _Parse(strPath);
}

bool CMapObjectPool::Pop(const std::string& strId)
{
    return true;
}

bool CMapObjectPool::_Parse(const std::string& strPath)
{
    if (strPath.empty())
    {
        return false;
    }
    char filePath[MAX_PATH] = {0};
    ::GetModuleFileNameA(0, filePath, MAX_PATH);
    ::PathRemoveFileSpecA(filePath);
    ::PathAppendA(filePath, strPath.c_str());

    TiXmlDocument tiDoc;
    tiDoc.LoadFile(filePath);
    TiXmlElement* xmlRoot = tiDoc.RootElement();
    if ((!xmlRoot) || lstrcmpA(xmlRoot->Value(), MAP_XML_ROOT) != 0)
    {
        return false;
    }

    TiXmlNode* pMap = xmlRoot->FirstChild(MAP_OBJECT);
    if (!pMap)
    {
        return false;
    }

    for (TiXmlElement* pObj = pMap->ToElement();
        pObj != NULL;
        pObj = pMap->NextSiblingElement())
    {
        int MapTileId = 0;
        MapTile* pMapTile = new MapTile;
        if (utils::GetXmlIntAttribute(pObj, MAP_OBJECT_OBJ, pMapTile->obj)
            && utils::GetXmlIntAttribute(pObj, MAP_OBJECT_FLOOR, pMapTile->floor)
            && utils::GetXmlIntAttribute(pObj, MAP_OBJECT_PROPERTY, (int&)pMapTile->property)
            && utils::GetXmlIntAttribute(pObj, ID_OBJECT, MapTileId))
        {
            auto it = m_ObjectPool.find(MapTileId);
            if (it != m_ObjectPool.end())
            {
                delete it->second;
                it->second = NULL;
            }
            m_ObjectPool[MapTileId] = pMapTile;
        }
        else
        {
            delete pMapTile;
        }
        ///> 每个地图XML文件只允许存放一个MAP
        break;
    }

    return true;
}
