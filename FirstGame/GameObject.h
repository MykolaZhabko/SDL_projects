#include <iostream>
#include <SDL2/SDL.h>
#include "LoaderParams.h"
//#include "TextureManager.h"

#ifndef ___GameObject___
#define ___GameObject___


class GameObject {
public:

	
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual	void clean() = 0;

protected:
	GameObject(const LoaderParams* pParams) {} 
	virtual ~GameObject() {}
};
#endif // !___GameObject___