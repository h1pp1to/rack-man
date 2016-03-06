#include "TextureMgr.h"
#include "TimerMgr.h"
#include <iostream>
using namespace std;

#undef main
int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	TextureMgr::Instance().CreateWindow();

	bool bRunning = true;
	while (bRunning)
	{
		SDL_Event Event;
		while (SDL_PollEvent(&Event))
		{
			switch (Event.type)
			{
				case SDL_QUIT:
				{
					bRunning = false;
				}
				default: break;
			}
		}

		SDL_SetRenderDrawColor(TextureMgr::Instance().GetRender(), 0, 0, 0, 255);
		SDL_RenderClear(TextureMgr::Instance().GetRender());
		SDL_RenderPresent(TextureMgr::Instance().GetRender());
	}





	return 0;
}