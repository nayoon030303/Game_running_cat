#pragma once
#include <d3dx9.h>


class Tile
{
public:

	virtual void Render() = 0;
	virtual void Update() = 0;

	float posX;
	float posY;
	float width;
	float height;
	int speed;

	D3DXVECTOR2 getPos() { return { posX, posY }; }
	void setPos(float x, float y) { posX = x; posY = y; }
	D3DXVECTOR2 getSize() { return { width, height }; }

	
	
};