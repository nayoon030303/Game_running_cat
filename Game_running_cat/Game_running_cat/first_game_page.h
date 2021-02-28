#pragma once
#include "page.h"
#include "first_game_page_background.h"
#include "first_game_page_ui.h"

class FirstGamePage :public Page
{
public:
	FirstGamePage();
	void Render()override;
	void Update() override;

	/* Update */
	

	/* Render */
	
	FirstGamePageBackground firstGamePageBackground;
	FirstGamePageUI firstGamePageUi;

	bool isPlaying;
	int time;
	


	
};