#include "global.h"
#include "game_system.h"
#include "math_util.h"
#include "tile_ground.h"
#include "tile_bridge.h"
#include "tile.h"


GameSystem::GameSystem()
{
	player = new Player();
	CreateMap();
}

void GameSystem::Update()
{
	float row_speed = 0;
	float column_speed = 0;
	float speed = 20;
	if (inputManager.key[VK_LEFT] == 1)
		row_speed = speed * 1;
	if (inputManager.key[VK_RIGHT] == 1)
		row_speed = speed * -1;
	if (inputManager.key[VK_UP] == 1)
		column_speed = speed * 1;
	if (inputManager.key[VK_DOWN] == 1)
		column_speed = speed * -1;
	/*for (int i = 0; i < tiles.size(); i++)
	{
		tiles[i]->setPos(tiles[i]->getPos().x + row_speed, tiles[i]->getPos().y + column_speed);
	}*/
	
	/*for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->setPos(enemys[i]->getPos().x + row_speed, enemys[i]->getPos().y + column_speed);
	}
	for (int i = 0; i < clouds.size(); i++)
	{
		clouds[i]->setStartPosY(clouds[i]->getStartPosY() + column_speed);
		clouds[i]->setPos(clouds[i]->getPos().x + row_speed, clouds[i]->getPos().y + column_speed);
	}*/
	//player->setPos(player->getPos().x + row_speed, player->getPos().y + column_speed);


	if (!player->getIsDead())
	{
		player->Update();
		for (int i = 0; i < tiles.size(); i++)
		{
			tiles[i]->Update();
		}
		

		player->isTouch_Bottom = false;
		player->isTouch_Top = false;
		for (int i = 0; i < tiles.size(); i++)
		{
			
			int playerX = player->getPos().x;
			int playerY = player->getPos().y;
			int playerWidth = player->getSize().x;
			int playerHeight = player->getSize().y;
			int tileX = tiles[i]->getPos().x;
			int tileY = tiles[i]->getPos().y;
			int tileWidth = tiles[i]->getSize().x;
			int tileHeight = tiles[i]->getSize().y;
			

			if (playerX + playerWidth > tileX && playerX < tileX + tileWidth)
			{

				//bottom
				if (playerY + playerHeight >= tileY && playerY + playerHeight <= tileY + tileHeight)
				{
					player->setPos(playerX, tileY - playerHeight);
					player->isJump = false;
					player->isTouch_Bottom = true;
				}
			}
			
		}
	}


}

void GameSystem::Render()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		tiles[i]->Render();
	}

	player->Render();
}

void GameSystem::MakeGround_Tile(float x, float y)
{
	Tile* new_tile = new TileGround(x, y);
	tiles.push_back(new_tile);
}

void GameSystem::MakeBridge_Tile(float x, float y)
{
	Tile* new_tile = new TileBridge(x, y);
	tiles.push_back(new_tile);
}

void GameSystem::CreateMap()
{
	
	MakeGround_Tile(0 * TILE_GROUND_WIDTH, START_BOTTOM);
	MakeGround_Tile(1 * TILE_GROUND_WIDTH, START_BOTTOM);
	MakeBridge_Tile(2 * TILE_GROUND_WIDTH, START_BOTTOM-100);
	/*MakeGround_Tile(1 * TILE_GROUND_WIDTH, START_BOTTOM);
	MakeGround_Tile(2 * TILE_GROUND_WIDTH, START_BOTTOM);
	MakeGround_Tile(3 * TILE_GROUND_WIDTH, START_BOTTOM);
	MakeGround_Tile(4 * TILE_GROUND_WIDTH, START_BOTTOM - 200);*/

}

void GameSystem::deleteData()
{
	delete player;
	player = new Player();
	
	int size = tiles.size();
	for (int i = 0; i < size; i++)
	{
		tiles.pop_back();
	}
	CreateMap();
}