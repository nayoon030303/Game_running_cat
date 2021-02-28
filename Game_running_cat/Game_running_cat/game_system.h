#pragma once
#include <vector>
#include "tile.h"
#include "player.h"

class GameSystem
{
public:
	GameSystem();
	
	void Update();
	void Render();

	void MakeGround_Tile(float x, float y);
	void MakeBridge_Tile(float x, float y);
	void CreateMap();
	void deleteData();

	int play_time;
	vector<Tile*> tiles;
	Player* player;
	
};