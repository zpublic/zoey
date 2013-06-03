#include "stdafx.h"
#include "c_map_texture.h"
#include "include\utils\utils.h"
#include "import\tinyxml-2.6.2\tinyxml.h"
#include <atlbase.h>

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
    if (!pwszXmlFile)
    {
        return false;
    }
    TiXmlDocument XmlParse;
    if (XmlParse.LoadFile(CW2A(pwszXmlFile)))
    {
        return _Parse(XmlParse);
    }
    return true;
}

bool CMapTileTexture::_Parse(TiXmlDocument& doc)
{
    TiXmlElement* tiRoot = doc.RootElement();
    if (!tiRoot)
    {
        return false;
    }
    std::string sRootName = tiRoot->Value();
    if (sRootName != MAP_XML_ROOT)
    {
        return false;
    }
    TiXmlNode* tiFirst = tiRoot->FirstChild(MAP_XML_OBJECT);
    if (tiFirst == NULL)
    {
        return false;
    }

     for (TiXmlElement* tiObject = tiFirst->ToElement();
        tiObject != NULL;
        tiObject = tiObject->NextSiblingElement())//读取当下元素中的所有属性
     {
         MapTileTexture pMap;
         if(utils::GetXmlIntAttribute(tiObject, "id", pMap.id)
             && utils::GetXmlStrAttributeA(tiObject, "name", pMap.name)
             //&& utils::GetXmlStrAttributeA(tiObject, "texture", pMap.texture)
            )
         {
             m_poolTile[pMap.id] = pMap;
         }
     }
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
