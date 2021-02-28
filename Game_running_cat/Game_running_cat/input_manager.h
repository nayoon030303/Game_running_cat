#pragma once

class InputManager
{
public:
	char key[256];
	char prevKey[256];
	char prevMouseWheel;
	char mouseWheel;

	void Update()
	{
		for (int i = 0; i < 256; ++i)
		{
			prevKey[i] = key[i];
		}
		//mouseWheel = 0;
	}
};