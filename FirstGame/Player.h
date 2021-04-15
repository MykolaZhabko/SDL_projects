#include "GameObject.h"
#include "SDLGameObject.h"

#ifndef __Player___
#define __Player___


class Player : public SDLGameObject 
{
public:
	
	Player(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
};

#endif // !__Player___