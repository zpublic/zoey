#include "stdafx.h"
#include "c_map_texture.h"
#include "include\utils\utils.h"
#include "import\tinyxml-2.6.2\tinyxml.h"
#include <atlbase.h>

CMapTileTexture* Singleton<CMapTileTexture>::m_pInst = NULL;

const wchar_t* pwszDefaultXml = L"res\\xml\\map_tile.xml";

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
    wchar_t filePath[MAX_PATH] = {0};
    ::GetModuleFileNameW(0, filePath, MAX_PATH);
    ::PathRemoveFileSpecW(filePath);
    ::PathAppendW(filePath, pwszXmlFile);
    if (XmlParse.LoadFile(CW2A(filePath)))
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
    TiXmlNode* tiFirst = tiRoot->FirstChild(MAP_TILE);
    if (tiFirst == NULL)
    {
        return false;
    }

     for (TiXmlElement* tiObject = tiFirst->ToElement();
        tiObject != NULL;
        tiObject = tiObject->NextSiblingElement())//读取当下元素中的所有属性
     {
         MapTileTexture pMap;
         if(utils::GetXmlIntAttribute(tiObject, ID_OBJECT, pMap.id)
             && utils::GetXmlStrAttributeA(tiObject, NAME_OBJECT, pMap.name)
            )
         {
            utils::GetXmlIntAttribute(tiObject, MAP_H_NUM, pMap.h_num);
            utils::GetXmlIntAttribute(tiObject, MAP_W_NUM, pMap.w_num);
            utils::GetXmlIntAttribute(tiObject, MAP_H_SPAN, pMap.h_span);
            utils::GetXmlIntAttribute(tiObject, MAP_W_SPAN, pMap.w_span);
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
