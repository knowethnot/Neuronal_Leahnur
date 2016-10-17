#include "audiom_managis.hpp"

bool keyDown(int keypress)
{
	if (/*GetAsyncKeyState(*/keypress/*)*/ == 0)
	{
		return false;
	}
	else { return true; }
}

void Test_Audiom_Managis()
{
	AudiomManagis *play_audio = AudiomManagis::Instance();

	bool _quit = false;

	while (!_quit)
	{
		if  (keyDown(1))
		{
			play_audio->modFrequency(0);
			break;
		}
		else if (keyDown(2))
		{
			play_audio->lowFrequency(0);
			break;
		}
		else if (keyDown(3))
		{
			_quit = true;
			break;
		}

		play_audio->Update();
	}
}

int main()
{
	Test_Audiom_Managis();
	return 0;
}