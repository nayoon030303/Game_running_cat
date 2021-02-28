#pragma once

#include <d3dx9.h>
#include <vector>

using namespace std;

class TextureElement
{
public:
	int id;
	LPDIRECT3DTEXTURE9* texture = new LPDIRECT3DTEXTURE9();
	ID3DXSprite* sprite;
};

class TextureManager
{
public:
	vector<TextureElement*> elements;

	void LoadTexture(const char* filename, int id);
	TextureElement* GetTexture(int id);

protected:
private:

};
