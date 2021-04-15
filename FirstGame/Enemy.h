#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"


#ifndef ___Enemy___
#define ___Enemy___


class Enemy : public SDLGameObject
{
public:

	Enemy(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
};

#endif // !___Enemy___