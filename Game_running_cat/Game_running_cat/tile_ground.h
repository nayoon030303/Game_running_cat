#include "tile.h"

class TileGround :public Tile
{
public:
	TileGround(float x, float y);
	void Render(); 
	void Update();


};