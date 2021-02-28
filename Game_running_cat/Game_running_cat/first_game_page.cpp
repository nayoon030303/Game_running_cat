#include "first_game_page.h"
#include "global.h"	



FirstGamePage::FirstGamePage()
{
	classType = FIRST_GAME_PAGE;
	gameSystem.CreateMap();
}

void FirstGamePage::Update()
{
	
	firstGamePageBackground.Update();
	firstGamePageUi.Update();
	gameSystem.Update();
	if (inputManager.key[VK_LEFT] == 1)
	{
		firstGamePageBackground.posX -= 10;
	}
}

void FirstGamePage::Render()
{
	firstGamePageBackground.Render();
	firstGamePageUi.Render();
	gameSystem.Render();

}
