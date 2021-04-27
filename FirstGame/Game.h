#include "TextureManager.h"
#include "Player.h"
#include "GameObject.h"
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "InputHandler.h"
#include <iostream>
#include<stdlib.h>
#include <vector>

#ifndef __Game__
#define __Game__
class Game
{
public:

	~Game() {};

	// create the public instance function
	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	// simply set the running variable to true
	void init() {
		m_bRunning = true;
	}
	//void draw();
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	// a function to access the private running variable

	bool running() {
		return m_bRunning;
	}
	bool init(const char* title, int xpos, int ypos, int width, int
		height, bool fullscreen);

private:
	//make the constructor private
	Game() {};
	
	//create the s_pInstance member variable
	static Game* s_pInstance;




	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	GameObject* m_go;
	GameObject* m_player;

	std::vector<GameObject*> m_gameObjects;

	//GameObject* m_player;
	GameObject* m_enemy1;
	//GameObject* m_enemy2;
	//GameObject* m_enemy3;



	int m_currentFrame;

	bool m_bRunning;
};

typedef Game TheGame;
#endif /* defined(__Game__) */