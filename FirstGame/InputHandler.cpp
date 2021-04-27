#include "InputHandler.h"
#include <iostream>
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::initialiseJoysticks()
{
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	if (SDL_NumJoysticks()>0)
	{
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i);
			if (joy != NULL)
			{
				m_joysticks.push_back(joy);
			}
			else
			{
				std::cout << SDL_GetError();
			}
		}
		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoysticksInitialised = true;

		std::cout << "Initialized " << m_joysticks.size() << " joystick(s)\n";
	}
	else
	{
		m_bJoysticksInitialised = false;
	}
}


void InputHandler::clean()
{
	if (m_bJoysticksInitialised)
	{
		for (unsigned int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
}


void InputHandler::update() {
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			TheGame::Instance()->clean();
		}

		//START OF MOUSE EVENT HANDLING
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = true;
			}

			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = true;
			}

			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = true;
			}
		}

		if (event.type == SDL_MOUSEBUTTONUP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = false;
			}

			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = false;
			}

			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = false;
			}
		}

		if (event.type == SDL_MOUSEMOTION)
		{
			m_mousePosition->setX(event.motion.x);
			m_mousePosition->setY(event.motion.y);
		}
	
	}
}
