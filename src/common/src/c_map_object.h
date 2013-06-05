#ifndef MAP_OBJECT_POOL_
#define MAP_OBJECT_POOL_

#include "src\common\struct\s_map.h"
#include "import\tinyxml-2.6.2\tinyxml.h"
#include <string>

class CMapObjectPool
{
public:
    CMapObjectPool();
    ~CMapObjectPool();

    bool Push(const std::string& strPath);

    bool Pop(const std::string& strId);

private:
    bool _Parse(const std::string& strPath);

private:
    MapObjectPool m_ObjectPool;
};

#endif