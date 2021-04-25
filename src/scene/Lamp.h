#ifndef __LAMP_H__
#define __LAMP_H__

#include "RenderableObject.h"

class Lamp : public RenderableObject
{
public:
	Lamp(RenderData* rd);
	virtual ~Lamp();

	void update(float deltaTime) override;
};

#endif // !__LAMP_H__