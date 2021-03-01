#include "global.h"
#include "player.h"

#define CAT_NORMAL_WIDTH 160
#define CAT_NORMA_HEIGHT 165
#define CAT_DOWN_HEIGHT 115

Player::Player()
{
    width = CAT_NORMAL_WIDTH;
    height = CAT_NORMA_HEIGHT;
    posX = 20;
    jumpStartPosY = START_BOTTOM;
    posY = jumpStartPosY-height;
    
    speed = GRAVITY;
    isDead = false;
    jumpHeight = 0;
    jumpTime = 1.0f;
    isJump = false;
    isDown = false;
    jumpPower = 35.0f;
    state_time = 0;
    playerState = TEX_PLAER_NORMAL_1;

    isTouch_Bottom = false;
    isTouch_Top = false;
    isTouch_left = false;
    isTouch_right = false;
}

void Player::Update()
{
   
    posY += speed;
    state_time += 1;

   
    if (state_time > 20)
    {
        if (playerState != TEX_PLAER_JUMP_1)
        {
            playerState *= -1;
            state_time = 0;
        }
       
    }
    if (inputManager.key['A'] == 1 && !isTouch_left)
    {
        posX -= 10;
    }
    if (inputManager.key['D'] == 1 && !isTouch_right)
    {
        posX += 10;
    }
    if (inputManager.key['W'] == 1 && !isJump && isTouch_Bottom && !isTouch_Top) 
    {
        height = CAT_NORMA_HEIGHT;
        playerState = TEX_PLAER_JUMP_1;
        isJump = true;
        isDown = false;
        jumpTime = 1.0f;
       
        jumpStartPosY = posY + height;
    }
     
    else if (inputManager.key['S'] == 1 && !isJump && !isDown)
    {   
        height = CAT_DOWN_HEIGHT;
        playerState = TEX_PLAER_DOWN_1;  
        isDown = true;

    }
    else if (inputManager.prevKey['S'] == 1 && inputManager.key['S'] == 0)
    {
        jumpStartPosY = posY + height;

        height = CAT_NORMA_HEIGHT;
        playerState = TEX_PLAER_NORMAL_1;
        isDown = false;
        
        posY = jumpStartPosY - height;
        
    }

    
   
    if (isJump)
    {
        Jump();
        posY = jumpStartPosY + jumpHeight - height;
    }
    
    if (!isJump && playerState == TEX_PLAER_JUMP_1)
    {
        playerState = TEX_PLAER_NORMAL_1;
    }
   
  
}

void Player::Render()
{
  
    TextureElement* element = textureManager.GetTexture(playerState);

    RECT rc;
    D3DXVECTOR3 pos;
    D3DXVECTOR3 cen;

    element->sprite->Begin(D3DXSPRITE_ALPHABLEND);


    rc.left = 0;
    rc.top = 0;
    rc.right = width;
    rc.bottom = height;


    pos = { posX, posY, 0 };

    element->sprite->Draw(*element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

    element->sprite->End();


}

void Player::Jump()
{
    //이차함수
    jumpHeight = jumpTime * jumpTime - jumpPower * jumpTime;

    jumpTime += 1.0f;

    if (jumpTime >= jumpPower)
    {
  
        jumpTime = 1.0f;
        jumpHeight = 0.0f;
        
        playerState = TEX_PLAER_NORMAL_1;

        isJump = false;
    }
}

void Player::setPos(float x, float y)
{
	posX = x;
	posY = y;
}

D3DXVECTOR2 Player::getPos()
{
	return { posX, posY };
}
void Player::setSize(int w, int h)
{
	width = w;
	height = h;
}

D3DXVECTOR2 Player::getSize()
{
	return{ width,height };
}

void Player::setScore(int sc)
{
	score = sc;
}

int Player::getScore()
{
	return score;
}

void Player::setIsDead(bool dead)
{
	isDead = dead;
}

bool Player::getIsDead()
{
	return isDead;
}

bool Player::getIsDown()
{
    return isDown;
}

void Player::setIsDown(bool down)
{
    isDown = down;
}

void Player::setPlayerState(int state)
{
    playerState = state; 
}
