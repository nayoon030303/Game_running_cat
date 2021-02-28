#include "page_manager.h"
#include "global.h"
#include "title_page.h"
#include "first_game_page.h"



void PageManager::CreateTitlePage()
{
	if (currentPage != nullptr)
	{
		if (currentPage->classType == FIRST_GAME_PAGE)
		{
			gameSystem.deleteData();
		}
		delete currentPage;
	}
	TitlePage* newPage = new TitlePage();
	currentPage = newPage;
}

void PageManager::CreateFirstGamePage()
{
	if (currentPage != nullptr)
	{
		if (currentPage->classType == FIRST_GAME_PAGE)
		{
			gameSystem.deleteData();
		}
		delete currentPage;
	}
	FirstGamePage* newPage = new FirstGamePage();
	currentPage = newPage;
}

void PageManager::Update()
{
	if (currentPage != nullptr)
	{
		currentPage->Update();
		/*if (pageState == FadeOut)
		{

			if (FadingCount >= 50)
			{
				//pageState = FadeIn;
			}
		}
		else if (pageState == FadeIn)
		{

			if (FadingCount <= 0)
			{
				//pageState = Playing;
			}
		}
		else
		{
			currentPage->Update();
		}*/

	}

}

void PageManager::Render()
{
	if (currentPage != nullptr)
	{
		currentPage->Render();
		/*if (pageState == FadeOut)
		{
			//prevPage->Render();
		}
		else if (pageState == FadeIn)
		{
			currentPage->Render();
		}
		else
		{
			currentPage->Render();
		}*/
	}
}