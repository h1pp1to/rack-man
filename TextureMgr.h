#pragma once

#include <SDL2\SDL.h>

class TextureMgr
{
private:
	TextureMgr() = default;
	TextureMgr(const TextureMgr&) = delete;
	TextureMgr& operator=(const TextureMgr&) = delete;

	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;

	static const int WINDOW_WIDTH = 1080;
	static const int WINDOW_HEIGHT = 680;
public:
	~TextureMgr(){}
	static TextureMgr& Instance()
	{
		static TextureMgr *Instance = new TextureMgr;
		return *Instance;
	}

	void CreateWindow()
	{
		if (m_Window || m_Renderer)
		{
			return; //TODO(ErrorMgr)
		}

		m_Window = SDL_CreateWindow("Rack-Man",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

		m_Renderer = SDL_CreateRenderer(m_Window, (-1), NULL);
	}

	int GetWindowWidth() const { return WINDOW_WIDTH; }
	int GetWindowHeight() const { return WINDOW_HEIGHT; }

	SDL_Window* GetWindow()
	{
		return m_Window;
	}

	SDL_Renderer* GetRender()
	{
		return m_Renderer;
	}
};