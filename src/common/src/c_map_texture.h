#pragma once
#include "s_map.h"

const wchar_t* pwszDefaultXml = L"res\\xml\\map_tile.xml";

class CMapTileTexture
{
public:
    CMapTileTexture();
    ~CMapTileTexture();

    ///> 从默认配置文件加载所有tile纹理
    bool Load();

    ///> 加载一个xml中所指定的tile纹理，可以加载多个xml
    bool LoadXml(const wchar_t* pwszXmlFile);

    ///> 获取对应id的tile纹理
    MapTileTexture* GetTile(int nId);

private:
    void Clear();

private:
    MapTileTexturePool      m_poolTile;
};
