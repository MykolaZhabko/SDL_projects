#ifndef ___GameStateMachine___
#define ___GameStateMachine___

#include "GameState.h"
#include <vector>

class GameStateMachine
{
public:
	void pushState(GameState *pState);
	void changeState(GameState *pState);
	void popState();

private:

	std::vector<GameState*>m_gameStates;
};

#endif // !___GameStateMachine___

