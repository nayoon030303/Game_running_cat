#include "texture_manager.h"
#include "global.h"

void TextureManager::LoadTexture(const char* filename, int id)
{
    TextureElement* element = new TextureElement();
    element->id = id;
    D3DXCreateSprite(g_pd3dDevice, &element->sprite);

    HRESULT hr = D3DXCreateTextureFromFileExA(g_pd3dDevice,
        filename, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0,
        D3DUSAGE_DYNAMIC,
        D3DFMT_UNKNOWN,
        D3DPOOL_DEFAULT,
        D3DX_DEFAULT,
        D3DX_DEFAULT,
        0,
        nullptr,
        nullptr, element->texture);

    elements.push_back(element);
}

TextureElement* TextureManager::GetTexture(int id)
{
    for (int i = 0; i < elements.size(); ++i)
    {
        if (elements[i]->id == id)
        {
            return elements[i];
        }
    }

    return nullptr;
}