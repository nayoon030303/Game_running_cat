#pragma once;
#include <d3dx9.h>

class Player
{
public:
	Player();
	void Update();
	void Render();

	void Jump();

	void setPos(float x, float y);
	D3DXVECTOR2 getPos();
	void setSize(int w, int h);
	D3DXVECTOR2 getSize();
	void setScore(int sc);
	int getScore();
	bool getIsDead();
	void setIsDead(bool dead);
	bool getIsDown();
	void setIsDown(bool dead);
	void setPlayerState(int state);


	float posX;
	float posY;
	float width;
	float height;
	float jumpStartPosY;
	float jumpHeight;
	float jumpTime;
	float jumpPower;
	float gravity;
	float speed;
	int score;
	int playerState;
	int state_time;

	bool isJump;
	bool isDown;
	bool isDead;
	
	bool isTouch_Bottom;
	bool isTouch_Top;
	bool isTouch_right;
	bool isTouch_left;
};