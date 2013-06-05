#pragma once
#include "struct/s_map.h"
#include "import\tinyxml-2.6.2\tinyxml.h"
#include "include\utils\singleton.h"

class CMapTileTexture
    : public Singleton<CMapTileTexture>
{
    friend Singleton<CMapTileTexture>;
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

    bool _Parse(TiXmlDocument& doc);

private:
    MapTileTexturePool      m_poolTile;
};
