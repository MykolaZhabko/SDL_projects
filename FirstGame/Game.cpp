
#include "Game.h"
#include "Enemy.h"


Game* Game::s_pInstance = 0;


bool Game::init(const char* title, int xpos, int ypos, int width,
	int height, bool fullscreen)
{

	


	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);
		if (m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				TheInputHandler::Instance()->initialiseJoysticks();
				SDL_SetRenderDrawColor(m_pRenderer, 50, 0, 50, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}


		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}
	std::cout << "init success\n";

	//TheInputHandler::Instance()->initialiseJoysticks();
	
	//m_textureManager.load("assets/animate-alpha.png", "animate", m_pRenderer);
	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer)) {
		return false;
	}


	m_go = new Player(new LoaderParams(0, 500, 128, 82, "animate"));
	m_player = new Player(new LoaderParams(100, 500, 128, 82, "animate"));
	m_enemy1 = new Enemy(new LoaderParams(0, 0, 128, 82, "animate"));


	m_gameObjects.push_back(m_go);
	m_gameObjects.push_back(m_player);
	m_gameObjects.push_back(m_enemy1);

	m_bRunning = true; // everything inited successfully, start the main loop
	return true;

}


void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer tothe draw color


	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}

	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean() {
	std::cout << "cleaning game\n";
	//TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::quit()
{
	

}

void Game::handleEvents()
{

	TheInputHandler::Instance()->update();
}

void Game::update()
{


	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

		
}