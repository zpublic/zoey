#pragma once
#include <map>

typedef struct tagMapTileTexture
{
    int             id;
    std::string     name;
    ITexture*       texture;
}MapTileTexture;

typedef std::map<int, MapTileTexture>           MapTileTexturePool;
typedef std::map<int, MapTileTexture>::iterator MapTileTexturePoolIt;

typedef struct tagMapTile
{
    int             floor;      ///> 底层tile纹理id
    int             obj;        ///> 物件tile纹理id
    DWORD           property;   ///> tile的特性（可否通过等）
}MapTile;
