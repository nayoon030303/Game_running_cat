#pragma once
#include "global.h"
#include "page.h"

class TitlePage :public Page
{
public:
	TitlePage();

	void Render()override;
	void Update()override;

	/*Update*/
	void StartButtonUpdate(POINT pt);
	void ExitButtonUpdate(POINT pt);

	/*Render*/
	void BackgroundRender();
	void StartButtonRender();
	void ExitButtonRender();

	int startButtonState;
	int exitButtonState;

protected:
private:


};