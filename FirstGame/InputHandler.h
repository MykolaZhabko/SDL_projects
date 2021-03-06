#include <SDL2/SDL.h>
#include <SDL2/SDL_mouse.h>
#include <vector>
#include <iostream>
#include "Vector2D.h"



#ifndef ___InputHandler___
#define  ___InputHandler___

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};


class InputHandler
{
public:
	


	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}

		return s_pInstance;
	}

	void update();
	void clean();

	void initialiseJoysticks();
	bool joysticksInitialised() {
		return m_bJoysticksInitialised;
	}

	//MOUSE METHODS
	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}

	Vector2D* getMousePosition()
	{
		return m_mousePosition;
	}
	
	//keyboard
	bool isKeyDown(SDL_Scancode key);


private:
	InputHandler() {
		m_mousePosition = (Vector2D*)malloc(sizeof(Vector2D) * 1);
		
 		for (int i = 0; i < 3; i++)
		{
			m_mouseButtonStates.push_back(false);
		}
	}
	~InputHandler() { delete m_mousePosition; }

	static InputHandler* s_pInstance;

	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialised;

	//MOUSE MEMBERS
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;

	//keyboard events
	
	Uint8* m_keystate;
	const Uint8* m_keystates;

	//private functions to handle different event types
	
	//handle keybord events
	void onKeyDown();
	void onKeyUp();

	//handle mouse events
	void onMouseMove(SDL_Event &event);
	void onMouseButtonDown(SDL_Event &event);
	void onMouseButtonUp(SDL_Event &event);

	//handle joysticks events
	void onJoystickAxisMove(SDL_Event& event) 
	{
		//implement later
	}
	void onJoystickButtonDown(SDL_Event& event)
	{
		//implement later
	}
	void onJoystickButtonUp(SDL_Event& event)
	{
		//implement later
	}


};

typedef InputHandler TheInputHandler;

#endif // !___InputHandler___