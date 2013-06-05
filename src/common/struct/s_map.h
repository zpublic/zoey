#pragma once

#define MAP_XML_ROOT   "zoeymap"
#define MAP_XML_OBJECT "map"
#define MAP_TEXTRUE    "texture"
#define ID_OBJECT      "id"
#define NAME_OBJECT    "name"

#define MAP_TILE   "tile"
#define MAP_H_NUM  "h-num"
#define MAP_W_NUM  "w-num"
#define MAP_H_SPAN "w-span"
#define MAP_W_SPAN "h-span"

typedef struct tagMapTileTexture
{
    tagMapTileTexture()
    {
        id = 0;
        w_num = 1;
        h_num = 1;
        h_span = 0;
        w_span = 0;
    }
    ///> num纹理个数
    ///> span纹理之间的间隔
    int             h_num;
    int             w_num;
    int             h_span;
    int             w_span;
    int             id;
    std::string     name;
    std::string     texId;
}MapTileTexture;

typedef std::map<int, MapTileTexture>           MapTileTexturePool;
typedef std::map<int, MapTileTexture>::iterator MapTileTexturePoolIt;

typedef struct tagMapTile
{
    int             floor;      ///> 底层tile纹理id
    int             obj;        ///> 物件tile纹理id
    DWORD           property;   ///> tile的特性（可否通过等）
}MapTile;
