#include "stdafx.h"
#include "c_map_texture.h"


CMapTileTexture::CMapTileTexture()
{

}

CMapTileTexture::~CMapTileTexture()
{
    Clear();
}

bool CMapTileTexture::Load()
{
    Clear();
    return LoadXml(pwszDefaultXml);
}

bool CMapTileTexture::LoadXml( const wchar_t* pwszXmlFile )
{
    return true;
}

MapTileTexture* CMapTileTexture::GetTile( int nId )
{
    MapTileTexture* pTex = NULL;
    MapTileTexturePoolIt itFind = m_poolTile.find(nId);
    if (itFind != m_poolTile.end())
    {
        pTex = &itFind->second;
    }
    assert(pTex != NULL);
    return pTex;
}

void CMapTileTexture::Clear()
{
    m_poolTile.clear();
}
